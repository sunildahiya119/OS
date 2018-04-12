#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/types.h>
#include<semaphore.h>

void f1();
void f2();
void f3();
void f4();
int pen=0, paper=0, ques_paper=0;
sem_t s;
sem_t s1,s2,s3;
int main()
{
 sem_init(&s,0,1);
 sem_init(&s1,0,0);
 sem_init(&s2,0,0);
 sem_init(&s3,0,0);
 pthread_t p1,p2,p3,t1;
 pthread_create(&p1,NULL,f1,NULL);
 pthread_create(&p2,NULL,f2,NULL);
 pthread_create(&p3,NULL,f3,NULL);
 pthread_create(&t1,NULL,f4,NULL);
 pthread_join(p1,NULL);
 pthread_join(p2,NULL);
 pthread_join(p3,NULL);
 pthread_join(t1,NULL);
}
void f1()
{
while(1)
{
sem_wait(&s1);
sem_wait(&s);
int pen=1;
printf("First Student is running to  Completion his task\n\n");
printf("First student has its own pen\n");
sleep(3);
printf("Teacher Puts the Paper and Question_Paper on the Table\n ");
paper=paper+1;
ques_paper=ques_paper+1;
sleep(3);
printf("Value of shared variable i.e paper is %d\n",paper);
printf("Value of shared variable i.e ques_paper is %d\n",ques_paper);
printf("First student has completed his task successfully\n\n");
sleep(3);
sem_post(&s);
sem_post(&s2);
}
}
void f2()
{
while(1)
{

sem_wait(&s2);
sem_wait(&s);
int paper=1;
printf("Second student is running to completion his task\n\n");
printf("Second student has its own paper\n");
sleep(3);
printf("Teacher puts the pen and Question_Paper on the Table\n");
pen=pen+1;
ques_paper=ques_paper+1;
sleep(3);
printf("value of shared variable i.e pen %d\n",pen);
printf("value of shared variable i.e paper %d\n",ques_paper);
printf("Second student has completed his task successfully\n\n");
sleep(3);
sem_post(&s);
sem_post(&s3);
}
}
void f3()
{
while(1)
{
sem_wait(&s3);	
sem_wait(&s);
int ques_paper=1;
printf("Third student is running to completion his task\n\n");
printf("Third student has its own question paper\n");
sleep(3);
printf("Teacher puts the pen and paper on the table\n");
pen=pen+1;
paper=paper+1;
sleep(3);
printf("value of shared variable i.e pen is %d\n",pen);
printf("value of shared variable i.e paper is %d\n",paper);
printf("Third student has completed his task successfully\n\n");
sleep(3);
sem_post(&s);
sem_post(&s1);
}
}
void f4()
{
sem_wait(&s);
printf("********Teacher Has Infinite shared variable( Pen, Paper &  Ques_paper )*********\n");
printf("Teacher places shared Items on the table According to the students need :\n");
sleep(5);
sem_post(&s);
sem_post(&s1);
}


