/*	$NetBSD: getoldopt.c,v 1.2 2003/06/23 13:39:01 grant Exp $	*/

/*
 * Plug-compatible replacement for getopt() for parsing tar-like
 * arguments.  If the first argument begins with "-", it uses getopt;
 * otherwise, it uses the old rules used by tar, dump, and ps.
 *
 * Written 25 August 1985 by John Gilmore (ihnp4!hoptoad!gnu) and placed
 * in the Public Domain for your edification and enjoyment.
 */

#include "nbcompat.h"

#ifdef HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif

#if defined(__RCSID) && !defined(lint)
__RCSID("$NetBSD: getoldopt.c,v 1.2 2003/06/23 13:39:01 grant Exp $");
#endif /* not lint */

#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "pax.h"
#include "extern.h"

int
getoldopt(int argc, char **argv, const char *optstring,
	struct option *longopts, int *idx)
{
	static char	*key;		/* Points to next keyletter */
	static char	argv1[64];

	if (key == NULL) {		/* First time */
		if (argc < 2) return -1;
		key = argv[1];
		if (*key != '-')
			(void)snprintf(argv[1] = argv1, sizeof(argv1), "-%s",
			    key);
	}

	if (longopts != NULL) {
		return getopt_long(argc, argv, optstring,
		    longopts, idx);
	} else {
		return getopt(argc, argv, optstring);
	}
}
