#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

//员工类
class Emplayer{
private:
    string  m_Name;
    int     m_Salary;
public:
    Emplayer(string Name, int Salary){
        m_Name = Name;
        m_Salary = Salary;
    }
    string Showname() const {
        return m_Name;
    }
    int Showsalary() const {
        return m_Salary;
    }
};

//创建员工
void creat_Employer(vector<Emplayer>& v_emplyer){

    int salary = 0;
    string nameseed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        salary = 4000 + (rand() % 2000);//4000~5999
        string name = "员工";
        name += nameseed[i];
        Emplayer employer(name, salary);

        v_emplyer.push_back(employer);
    }
}

//分配部门
multimap<string,Emplayer> Department_allocation(const vector<Emplayer>&  v_emplyer){
    //部门编号1，2，3；美术策划研发
    int Department_key = 0;
    vector<string> department = {"美术","策划","研发"};
    multimap<string,Emplayer> Department_employer;
    for(vector<Emplayer>::const_iterator it = v_emplyer.begin();it!=v_emplyer.end();it++){
        Department_key = rand() % 3;
        Department_employer.insert(make_pair(department[Department_key],*it));
    }
    return Department_employer;
}
//打印员工信息
void Print_employer(const multimap<string,Emplayer>&  Department_employer){
    for(multimap<string,Emplayer>::const_iterator it = Department_employer.begin();it!=Department_employer.end();it++){
        cout<<"部门："<<(*it).first<<" 姓名: "<<it->second.Showname()<<" 薪酬: "<<it->second.Showsalary()<<endl;
    }
}

int main(){
    srand((unsigned int)time(NULL));

    //1.创建员工，容器
    vector<Emplayer> v_emplyer;
    creat_Employer(v_emplyer);

    //2.分配部门
    multimap<string,Emplayer> Department_employer;
    Department_employer = Department_allocation(v_emplyer);
    //3.打印员工信息
    Print_employer(Department_employer);
    return 0;
}