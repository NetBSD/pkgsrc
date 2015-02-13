#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
	char *newargs[] = {"@PERL5@", "@PREFIX@/share/BackupPC/cgi-bin/BackupPC_Admin", NULL };
	execve(newargs[0], newargs, envp);
}
