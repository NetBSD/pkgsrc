#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>
#include <unistd.h>

#include "util.h"

int main(int argc, char* argv[])
{
	int i;
	char *s;
	char emul[PATH_MAX];

	for(i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-ldl") == 0)
			argv[i] = "-licc11bsd";
		else if(strcmp(argv[i], "/usr/lib/crt1.o") == 0)
			argv[i] = "/usr/lib/crt0.o";
		else if(strcmp(argv[i], "/usr/lib64/crt1.o") == 0)
			argv[i] = "/usr/lib/crt0.o";
		else if(strcmp(argv[i], "/lib/ld-linux.so.2") == 0)
			argv[i] = "/usr/libexec/ld.elf_so";
		else if(strcmp(argv[i], "/lib64/ld-linux-x86-64.so.2") == 0)
			argv[i] = "/usr/libexec/ld.elf_so";
		else if(strncmp(argv[i], "/tmp/i", 6) == 0) {
			strlcpy(emul, EMULDIR, sizeof(emul));
			strlcpy(emul + EMULDIR_LEN, argv[i], sizeof(emul) - EMULDIR_LEN);
			move_tmpicc(emul);
		}
	}

	if((s = getenv("ICC11_REALLD")) == NULL)
		s = "ld";
	argv[0] = s;

	execvp(s, argv);

	s = strerror(errno);
	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, s, strlen(s));
	write(STDERR_FILENO, "\n", 1);
	return EXIT_FAILURE;
}
