/*      $NetBSD: binpatch.c,v 1.1.1.1 2004/07/23 03:37:26 atatat Exp $ */

/*
 * ------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Andrew Brown <atatat@NetBSD.org> wrote this file.  As long as you
 * retain this notice you can do whatever you want with this stuff.
 * If we meet some day, and you think this stuff is worth it, you can
 * buy me a beer in return.
 * ------------------------------------------------------------------------
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
die(int rc, const char *msg)
{
	if (rc)
		perror(msg);
	else
		fprintf(stderr, "%s\n", msg);
	exit(1);
}

static void
cvt(const char *s, const char *i, unsigned char *o, size_t l)
{
	int t, x;

	for (t = 0; t < l; t++) {
		x = i[2 * t];
		if (x >= '0' && x <= '9')
			x -= '0';
		else if (x >= 'a' && x <= 'f')
			x -= 'a' - 10;
		else if (x >= 'A' && x <= 'F')
			x -= 'A' - 10;
		else
			die(0, s);
		o[t] = x * 16;

		x = i[2 * t + 1];
		if (x >= '0' && x <= '9')
			x -= '0';
		else if (x >= 'a' && x <= 'f')
			x -= 'a' - 10;
		else if (x >= 'A' && x <= 'F')
			x -= 'A' - 10;
		else
			die(0, s);
		o[t] += x;
	}
}

int
main(int argc, char *argv[])
{
	struct stat st;
	char *key, *value;
	int f, i;
	unsigned char *buf, *get, *put;
	size_t lget, lput;
	off_t sz, cmp_off, skip_off;

	f = -1;
	get = put = NULL;
	lget = lput = 0;
	sz = cmp_off = skip_off = -1;

	while (--argc > 0) {
		key = *++argv;
		if ((value = strchr(key, '=')) == NULL)
			die(0, "value required");
		else
			*value++ = '\0';

		if (strcmp(key, "file") == 0) {
			f = open(value, O_RDWR);
			if (f == -1)
				die(1, "file");
		}
		else if (strcmp(key, "size") == 0) {
			char *t;
			errno = 0;
			sz = strtol(value, &t, 0);
			if (errno != 0)
				die(1, "size");
		}
		else if (strcmp(key, "offset") == 0) {
			char *t;
			errno = 0;
			cmp_off = strtol(value, &t, 0);
			if (errno != 0)
				die(1, "offset");
		}
		else if (strcmp(key, "compare") == 0) {
			lget = strlen(value);
			if (lget % 2 != 0)
				die(0, "compare");
			lget /= 2;
			get = malloc(lget);
			buf = malloc(lget);
			cvt("compare", value, get, lget);
		}
		else if (strcmp(key, "skip") == 0) {
			char *t;
			errno = 0;
			skip_off = strtol(value, &t, 0);
			if (errno != 0)
				die(1, "offset");
		}
		else if (strcmp(key, "replace") == 0) {
			lput = strlen(value);
			if (lput % 2 != 0)
				die(0, "replace");
			lput /= 2;
			put = malloc(lput);
			cvt("replace", value, put, lput);
		}
	}

	/*
	 * ./binpatch
	 *    file=${MOZILLA_HOME}/netscape
	 *    size=13823336
	 *    offset=0x008073e9
	 *    compare=6a00e82406a3ffe81f0ca3ff
	 *    skip=2
	 *    replace=9090909090
	 */

	if (f == -1)
		die(0, "file missing");
	if (get == NULL || lget == 0)
		die(0, "compare missing");
	if (put == NULL || lput == 0)
		die(0, "replace missing");
	if (sz == -1)
		die(0, "size missing");
	if (cmp_off == -1)
		die(0, "offset missing");
	if (skip_off == -1)
		die(0, "skip missing");
	if (skip_off < 0 ||
	    (skip_off == 0 && lput >= lget) ||
	    (skip_off > 0 && skip_off + lput > lget))
		die(0, "illegal skip");

	if (fstat(f, &st) == -1)
		die(1, "fstat");
	if (st.st_size != sz)
		die(0, "wrong size");
	if (lseek(f, cmp_off, SEEK_SET) == -1)
		die(1, "lseek");
	if (read(f, buf, lget) != lget)
		die(1, "read");
	if (memcmp(buf, get, lget) != 0)
		die(0, "instructions not found");
	if (lseek(f, cmp_off + skip_off, SEEK_SET) == -1)
		die(1, "lseek");
	if (write(f, put, lput) != lput)
		die(1, "write");
	if (close(f) != 0)
		die(1, "close");

	return (0);
}
