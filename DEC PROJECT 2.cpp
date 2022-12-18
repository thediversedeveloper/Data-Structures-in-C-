#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Define a Structure
struct Course {
    string courseNum;
    string courseName;
    vector<string> prerequisites;
    Course() {}
};

//String to call back
vector<string>tokenize(string s, string del = " "){
    vector<string> stringArray;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        stringArray.push_back(s.substr(start, end, - start));
    }
    stringArray.push_back(s.substr(start, end - start));
    
    return stringArray;
}

//Load and store file
vector<Course> LoadDataStructure(){                                                                                    

    ifstream fin("class.txt",ios::in);
    vector<Course> courses;
    string line;
    //loop
    while(1) {
        getline(fin,line);
        if(line=="-1")
        break;
        Course course;


vector<string> tokenizedinformation=tokenize(line,",");
course;courseNum=tokenizedinformation[0];
course;courseName=tokenizedinformation[1];
    for(int i=2;i<tokenizedinformation.size();i++) {
        course.prerequisites.push_back(tokenizedinformation[i]);
    }
    courses.push_back(course);

    fin.close();
    return courses;
    }

    //Print Course Information
    void printCourse(Course course) {
        string courseNum = course.courseNum;
        string courseName = course.name;
        vector<string>prerequisites=course.prerequisites;
        
        cout<<"Course Number: "<< courseNumber << endl;
        cout<<"Course Name: "<<courseName<<endl;
        cout<<"Prerequisites: ";
        for(int i=0;i<prerequisites.size();i++) {
            cout<<prerequisites[i]<<" ";
        }
        cout<<"\n\n";
    }

//Print Course List
    void printCourseList(vector<Course> courses) {
        int n=courses.size();

    for(int i=0;i<n-2;i++) {
        for(int j=0;j<n-i-1;j++)
    {
        if(courses[j].courseNum>courses[j+1].courseNum)
        {}
        swap(courses[j+1],courses[j]);
    } 
    }
    }

    //Traversal 
    for(int i=0;i<n;i++) 
    {
        printCourse(courses[i]);
    }
    }
    
    //Seraching for a Course
    void searchCourse(vector<Course> courses) {
        int n=courses.size();
        string courseNum;
        int f=0;
        
        cout<<"Enter courseNumber: ";
        cin>>courseNum;

        //Print Course if found
        for(int i=0;i<n;i++) {
        
        if(courses[i].courseNum==courseNum) {
                f=1;
                printCourse(courses[i]);
                break;
            }
        }
    if(f==0) {
        cout<<"Course with given course number not found\n";

    }
    }

    //Print Menu
    int main(int argc, char**argv){
        vector<Course> courses;
        cout<<"1. Load Data Structure\n";
        cout<<"2. Print Course List\n";
        cout<<"3. Print Course\n";
        cout<<"4. Exit\n";

        int ch;

        do{
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch) {
                case 1: courses=LoadDataStructure(); break;
                case 2: printCourseList(courses); break;
                case 3: searchCourse(courses); break;
                case 4: cout<<"Exit\n"; break;
                defualt: cout<<"Invalid Choise\n";
            }
        
        }while(ch!=4);
        
        return 0;
        
