/*	$NetBSD: getoldopt.c,v 1.4 2003/09/05 18:40:52 jlam Exp $	*/

/*
 * Plug-compatible replacement for getopt() for parsing tar-like
 * arguments.  If the first argument begins with "-", it uses getopt;
 * otherwise, it uses the old rules used by tar, dump, and ps.
 *
 * Written 25 August 1985 by John Gilmore (ihnp4!hoptoad!gnu) and placed
 * in the Public Domain for your edification and enjoyment.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif
#include <nbcompat.h>
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif
#if defined(__RCSID) && !defined(lint)
__RCSID("$NetBSD: getoldopt.c,v 1.4 2003/09/05 18:40:52 jlam Exp $");
#endif /* not lint */

#if HAVE_GETOPT_H
#include <getopt.h>
#endif
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#include "pax.h"
#include "extern.h"

int
getoldopt(int argc, char **argv, const char *optstring,
	struct option *longopts, int *idx)
{
	static char	*key;		/* Points to next keyletter */
	static char	use_getopt;	/* !=0 if argv[1][0] was '-' */
	char		c;
	char		*place;

	optarg = NULL;

	if (key == NULL) {		/* First time */
		if (argc < 2) return -1;
		key = argv[1];
		if (*key == '-')
			use_getopt++;
		else
			optind = 2;
	}

	if (!use_getopt) {
		c = *key++;
		if (c == '\0') {
			key--;
			use_getopt = 1;
		}
	}
	if (use_getopt) {
		if (longopts != NULL) {
			return getopt_long(argc, argv, optstring,
			    longopts, idx);
		} else {
			return getopt(argc, argv, optstring);
		}
	}

	place = strchr(optstring, c);

	if (place == NULL || c == ':') {
		fprintf(stderr, "%s: unknown option %c\n", argv[0], c);
		return('?');
	}

	place++;
	if (*place == ':') {
		if (optind < argc) {
			optarg = argv[optind];
			optind++;
		} else {
			fprintf(stderr, "%s: %c argument missing\n",
				argv[0], c);
			return('?');
		}
	}

	return(c);
}
