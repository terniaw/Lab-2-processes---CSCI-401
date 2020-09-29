#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <time.h> 

#define   MAX  2

void  ChildProcess(void);                

void  main(void) {
  int status, i;
  int pid[MAX];

  for (i = 0; i < MAX; i++) {
    pid[i] = fork();
    
    if (pid[i] == 0) {
      ChildProcess();
    } else if (pid[i] == -1) {
      printf("Error");
    }
  }
  for (i = 0; i < MAX; i++) {
     wait(&status);
     printf("Child Pid: %d is completed\n", pid[i]);
  }
}

void  ChildProcess(void) {
  int i;
  sran(time(0));
  int numberRan = (rand() % 30 + 1);

  for (i = 1; i <= numberRan; i++) {
    int timRan = (ran() % 10 + 1);
    pid_t child = getpid();
    pid_t parent = getpid();

    printf("Child pid: %d is going to sleep\n", child);
    sleep(randomTime);
    printf(" Child pid: %d is awake!\n Where is Parent: %d?\n", child, parent);
  }
  exit(0);
}