/*	$NetBSD: buwrapper.c,v 1.1 1999/01/04 22:37:30 tv Exp $	*/

#include <err.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

/*
 * Wrapper for binutils programs.
 *
 * This frontend sets the appropriate environment variables that tell
 * binutils programs which target will be used.
 */

static const char binsubdir[] = "libexec/binutils";

#define PATHLEN sizeof(PREFIX) + sizeof(binsubdir) + 20

int main(int argc, char **argv) {
	char path[PATHLEN], *p, *prog;

	/* quickly find last part of path component */
	if (p = strrchr(argv[0], '/'))
		p++;
	else
		p = argv[0];
	if (prog = strrchr(p, '-'))
		prog++;
	else
		prog = p;

	/* make program pathname */
	snprintf(path, PATHLEN, "%s/%s/%s", PREFIX, binsubdir, prog);

	/* set up environment */
	setenv("GNUTARGET", GNUTARGET, 1);
#ifdef LDEMULATION
	setenv("LDEMULATION", LDEMULATION, 1);
#endif
#ifdef LD_RPATH_LINK
	setenv("LD_RPATH_LINK", LD_RPATH_LINK, 1);
#endif

	/* run it! */
	execv(path, argv);

	/* we shouldn't get here. */
	err(EX_OSERR, "(buwrapper): exec %s", path);
}
