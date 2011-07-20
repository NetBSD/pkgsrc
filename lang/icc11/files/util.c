#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "util.h"

// Relaxed error checking/reporting is fine because exec'd
// program will report a missing file if the function fails.
void move_tmpicc(const char* emul)
{
	char buf[1024];
	struct stat st;
	int bytes, src, dst;
	const char* real = emul + EMULDIR_LEN;
	const char* tail = real + (sizeof("/tmp/i") - 1);

	if(strncmp(tail, "cc", 2) != 0 && strncmp(tail, "po_icc", 6) != 0)
		return;

	if(stat(real, &st) == 0)
		return;

	if(stat(emul, &st) < 0 || !(st.st_mode & S_IFREG))
		return;

	src = open(emul, O_RDONLY, 0644);
	dst = open(real, O_WRONLY|O_CREAT|O_EXCL, st.st_mode);

	while((bytes = read(src, buf, sizeof(buf))) > 0) {
		if(write(dst, buf, bytes) != bytes) {
			bytes = -1;
			break;
		}
	}

	if(src >= 0)
		close(src);
	if(dst >= 0 && close(dst) < 0)
		bytes = -1;
	if(bytes < 0 || unlink(emul) < 0)
		unlink(real);
}
