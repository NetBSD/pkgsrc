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
		if(strncmp(argv[i], "/tmp/i", 6) == 0) {
			strlcpy(emul, EMULDIR, sizeof(emul));
			strlcpy(emul + EMULDIR_LEN, argv[i], sizeof(emul) - EMULDIR_LEN);
			move_tmpicc(emul);
		}
	}

	if((s = getenv("ICC11_REALAS")) == NULL)
		s = "as";
	argv[0] = s;

	execvp(s, argv);

	s = strerror(errno);
	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, s, strlen(s));
	write(STDERR_FILENO, "\n", 1);
	return EXIT_FAILURE;
}
