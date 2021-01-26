#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstring>
using namespace std;

struct stdn
{
    int roll,p_marks,c_marks,m_marks,cs_marks,e_marks;
    float per;
    char name[50];
    char grade;
};

class student
{
    stdn *stud = new stdn[100];
    int i;

    public:
        student()
        {
            int i;
            for(i=0;i<=100;i++)
            {
                stud[i].roll=0;
            }
        }

        void vline(char ch)  //function used for creating table
{
  for (int i=80;i>0;i--)
  cout<<ch;
}


        void calculate(int i)
        {


                stud[i].per=(stud[i].p_marks+stud[i].c_marks+stud[i].m_marks+stud[i].e_marks+stud[i].cs_marks)/5.0;

                if(stud[i].per>=80)
                {
                    stud[i].grade='A';
                }
                else if(stud[i].per>=80 && stud[i].per<=70)
                {
                    stud[i].grade='B';
                }
                else if(stud[i].per>=70 && stud[i].per<=55)
                {
                    stud[i].grade='C';
                }
                else if(stud[i].per>=55 && stud[i].per<=35)
                {
                    stud[i].grade='D';
                }
                else
                {
                    stud[i].grade='F';
                }

            cout<<"Percentage is: "<<stud[i].per<<endl;
            cout<<"Grade is: "<<stud[i].grade<<endl;

        }

        void result()
        {
            int a,no;
            char ans;
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout<<"RESULT MENU"<<endl;
            cout<<"1.Class Result"<<endl;
            cout<<"2.Student Report Card"<<endl;
            cout<<"3.Main menu"<<endl;
            cout<<"Please enter your choice"<<endl;
            cin>>no;
            switch(no)
            {
            case 1:
                class_result();
                break;
            case 2:
                int a;
                cout<<"Enter the roll no of student";
                cin>>a;
                display_spec(a);
                break;
            case 3:
                break;
            default:
                cout<<" ";
            }
        }

        void class_result()
        {
            int i;
            cout<<setw(49)<<"STUDENT DETAILS "<<endl;
            vline('*');
            //cout<<"---------------------------------------------------------------------------------"<<endl;
            cout<<"\nRoll no"<<setw(8)<<"Name"<<setw(20)<<"Physics"<<setw(10)<<"Chemistry"<<setw(10)<<"Maths"<<setw(10)<<"English"<<setw(5)<<"Computer"<<setw(5)<<"Percentage"<<setw(5)<<"Grade "<<endl;
            //cout<<"----------------------------------------------------------------------------------"<<endl;
             vline('*');
            for(i=1;i<=100;i++)
            {
                if(stud[i].roll!=0)
                {
                    cout<<stud[i].roll<<setw(3)<<stud[i].name<<setw(3)<<stud[i].p_marks<<setw(3)<<stud[i].c_marks<<setw(3)<<stud[i].m_marks<<setw(3)<<stud[i].e_marks<<setw(3)<<stud[i].cs_marks<<setw(3)<<stud[i].per<<setw(3)<<stud[i].grade<<endl;
                }
            }
        }

        void display_spec(int rno)
        {
            char ans;
            for(rno=1;rno<=100;rno++)
            {
                cout<<"Name: "<<stud[rno].name<<endl;
                cout<<"Marks in Physics "<<stud[rno].p_marks<<endl;
                cout<<"Marks in Chemistry "<<stud[rno].c_marks<<endl;
                cout<<"Marks in Maths "<<stud[rno].m_marks<<endl;
                cout<<"Marks in English "<<stud[rno].e_marks<<endl;
                cout<<"Marks in Computer "<<stud[rno].cs_marks<<endl;
                calculate(rno);

                cout<<"Do you want to see more records?"<<endl;
                cin>>ans;
                if(ans=='n' || ans=='N')
                {
                    result();
                    break;
                }
                else
                {
                    display_spec(rno);
                    break;
                }
            }
        }


        void display_marks(int rno)
        {
            char ans;

                cout<<"Name: "<<stud[rno].name<<endl;
                cout<<"Marks in Physics "<<stud[rno].p_marks<<endl;
                cout<<"Marks in Chemistry "<<stud[rno].c_marks<<endl;
                cout<<"Marks in Maths "<<stud[rno].m_marks<<endl;
                cout<<"Marks in English "<<stud[rno].e_marks<<endl;
                cout<<"Marks in Computer "<<stud[rno].cs_marks<<endl;
                calculate(rno);



        }



        void entry_menu()
        {
            int ch,rno;
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout<<"ENTRY MENU"<<endl;
            cout<<"1.Create Record"<<endl;
            cout<<"2.Display Record"<<endl;
            cout<<"3.Search Record"<<endl;
            cout<<"4.Modify Record"<<endl;
            cout<<"5.Delete Record"<<endl;
            cout<<"6.Main Menu"<<endl;
            cout<<"Please Enter Your Choice"<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                int a;
                cout<<"Enter the roll no of student";
                cin>>a;
                display_spec(a);
                break;
            case 4:
                int x;
                cout<<"Enter roll no of student";
                cin>>x;
                modify(x);
                break;
            case 5:
                deletestd();
                break;
            case 6:
                break;
            default:
                cout<<" "<<endl;
            }
        }
    void create()
    {
        char ans;
        for(i=1;i<=100;i++)
        {

            cout<<"Enter roll no. of student ";
            cin>>stud[i].roll;
            cout<<"Enter Name of student ";
            cin>>stud[i].name;
            cout<<"Enter marks in physics ";
            cin>>stud[i].p_marks;
            cout<<"Enter marks in chemistry ";
            cin>>stud[i].c_marks;
            cout<<"Enter marks in maths ";
            cin>>stud[i].m_marks;
            cout<<"Enter marks in english ";
            cin>>stud[i].e_marks;
            cout<<"Enter marks in computer ";
            cin>>stud[i].cs_marks;

            cout<<"Do you want to add new record?(Y/N)"<<endl;
            cin>>ans;

            if(ans=='n' || ans=='N')
            {
                entry_menu();
                break;
            }
        }
    }

    void display()
    {
        for(i=1;i<=100;i++)
        {
            if(stud[i].roll!=0)
            {
                cout<<"Roll No."<<stud[i].roll<<endl;
                cout<<"Name: "<<stud[i].name<<endl;
                cout<<"Marks in Physics "<<stud[i].p_marks<<endl;
                cout<<"Marks in Chemistry "<<stud[i].c_marks<<endl;
                cout<<"Marks in Maths "<<stud[i].m_marks<<endl;
                cout<<"Marks in English "<<stud[i].e_marks<<endl;
                cout<<"Marks in Computer "<<stud[i].cs_marks<<endl;
                calculate(i);
                cout<<"------------------------------------------------------------------------------"<<endl;
            }
        }
        entry_menu();

    }

    void modify(int rno)
    {
        char ans;
        cout<<"Are you sure you want to modify record?";
        cin>>ans;
        display_marks(rno);
        if(ans=='Y' || ans=='y')
        {
            cout<<"Name: ";
            cin>>stud[rno].name;
            cout<<"Marks in Physics: ";
            cin>>stud[rno].p_marks;
            cout<<"Marks in Chemistry: ";
            cin>>stud[rno].c_marks;
            cout<<"Marks in Maths: ";
            cin>>stud[rno].m_marks;
            cout<<"Marks in English: ";
            cin>>stud[rno].e_marks;
            cout<<"Marks in Computer: ";
            cin>>stud[rno].cs_marks;
            cout<<"----------------------------------------------------------------------------------------------------------------------------------------";

        }
        else if(ans=='N' || ans=='n')
        {
            entry_menu();
        }
        cout<<"New Record is :"<<endl;
        display_marks(rno);
        cout<<"Do you want to modify more records?y/n";
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            int x;
                cout<<"Enter roll no of student";
                cin>>x;
                modify(x);
        }
        else
        {
            entry_menu();
        }
    }

    void deletestd()
    {
        int rno;
        char ans;
        for(rno=0;rno<=100;rno++)
        {
            cout<<"Enter the roll no of student"<<endl;
            cin>>rno;
           stud[rno].roll=0;
           //stud[rno].name=(char*)malloc(100*sizeof(char)) ;
           strcpy(stud[rno].name,"");
           stud[rno].p_marks=0;
           stud[rno].c_marks=0;
           stud[rno].m_marks=0;
           stud[rno].e_marks=0;
           stud[rno].cs_marks=0;
           cout<<"-----------------------"<<endl;
           display_marks(rno);

            cout<<"Do you want to delete more records(Y/N)"<<endl;
            cin>>ans;

            if(ans=='n' || ans=='N')
            {
                entry_menu();
                break;
            }
            else if(ans=='Y' || ans=='y')
            {
                deletestd();
            }
            else
            {
                cout<<"Invalid Choice";
                entry_menu();
            }
        }
    }


};


int main()
{
    student s1;
    int ch;
    do
    {
        cout<<"MAIN MENU"<<endl;
        cout<<"1.Result Menu"<<endl;
        cout<<"2.Entry/Edit Menu"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Please Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            s1.result();
            break;
        case 2:
            s1.entry_menu();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Not a valid choice"<<endl;
        }
    }
    while(ch!=3);

    return 0;
}
