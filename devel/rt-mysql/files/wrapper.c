/*	$NetBSD: wrapper.c,v 1.1.1.1 2002/09/19 21:40:45 atatat Exp $ */

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <err.h>
#include <string.h>

#include "config.h"

int
main(int argc, char *argv[])
{
	char *name, *old, *ld_library_path;
	struct passwd *pw;
	struct group *gr;
	int l;

	name = strrchr(argv[0], '/');
	if (name == NULL)
		name = argv[0];
	else
		name++;

	if      (strcmp(name, "mason_handler.fcgi") == 0)
		argv[0] = RT_REAL_PATH "/mason_handler.fcgi";
	else if (strcmp(name, "mason_handler.scgi") == 0)
		argv[0] = RT_REAL_PATH "/real/";
	else if (strcmp(name, "rt") == 0)
		argv[0] = RT_REAL_PATH "/rt";
	else if (strcmp(name, "rt-mailgate") == 0)
		argv[0] = RT_REAL_PATH "/rt-mailgate";
	else if (strcmp(name, "rtadmin") == 0)
		argv[0] = RT_REAL_PATH "/rtadmin";
	else
		argv[0] = NULL;

	l = strlen(DATABASE_LIBRARY_PATH) + 1;
	old = getenv("LD_LIBRARY_PATH");
	if (old != NULL) {
		l += strlen(old) + 1;
		ld_library_path = malloc(l);
		snprintf(ld_library_path, l, "%s:%s",
		    DATABASE_LIBRARY_PATH, old);
	} else {
		ld_library_path = malloc(l);
		snprintf(ld_library_path, l, "%s", DATABASE_LIBRARY_PATH);
	}

	if (setenv("LD_LIBRARY_PATH", ld_library_path, 1) != -1 &&
	    (gr = getgrnam(RT_GROUP)) != NULL &&
	    setgid(gr->gr_gid) != -1 &&
	    setuid(getuid()) != -1)
		execv(argv[0], argv);

	errx(1, "permission denied");
}
