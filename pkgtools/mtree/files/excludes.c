/*	$NetBSD: excludes.c,v 1.3 2003/12/20 04:54:56 grant Exp $	*/

/*
 * Copyright 2000 Massachusetts Institute of Technology
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that both the above copyright notice and this
 * permission notice appear in all copies, that both the above
 * copyright notice and this permission notice appear in all
 * supporting documentation, and that the name of M.I.T. not be used
 * in advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.  M.I.T. makes
 * no representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS
 * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
 * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif
#include <nbcompat.h>
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif

#if defined(__RCSID) && !defined(lint)
__RCSID("$NetBSD: excludes.c,v 1.3 2003/12/20 04:54:56 grant Exp $");
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_QUEUE_H
#include <sys/queue.h>
#endif

#if HAVE_FNMATCH_H
#include <fnmatch.h>
#endif
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif
#if HAVE_TIME_H
#include <time.h>
#endif
#if HAVE_UTIL_H
#include <util.h>
#endif

#include "extern.h"


/*
 * We're assuming that there won't be a whole lot of excludes,
 * so it's OK to use a stupid algorithm.
 */
struct exclude {
	LIST_ENTRY(exclude) link;
	const char *glob;
	int pathname;
};
static LIST_HEAD(, exclude) excludes;


void
init_excludes(void)
{

	LIST_INIT(&excludes);
}

void
read_excludes_file(const char *name)
{
	FILE *fp;
	char *line;
	struct exclude *e;

	fp = fopen(name, "r");
	if (fp == 0)
		err(1, "%s", name);

	while ((line = fparseln(fp, NULL, NULL, NULL,
	    FPARSELN_UNESCCOMM | FPARSELN_UNESCCONT | FPARSELN_UNESCESC))
	    != NULL) {
		if (line[0] == '\0')
			continue;

		if ((e = malloc(sizeof *e)) == NULL)
			mtree_err("memory allocation error");

		e->glob = line;
		if (strchr(e->glob, '/') != NULL)
			e->pathname = 1;
		else
			e->pathname = 0;
		LIST_INSERT_HEAD(&excludes, e, link);
	}
	fclose(fp);
}

int
check_excludes(const char *fname, const char *path)
{
	struct exclude *e;

	/* fnmatch(3) has a funny return value convention... */
#define MATCH(g, n) (fnmatch((g), (n), FNM_PATHNAME) == 0)

	e = LIST_FIRST(&excludes);
	while (e) {
		if ((e->pathname && MATCH(e->glob, path))
		    || MATCH(e->glob, fname)) {
			return (1);
		}
		e = LIST_NEXT(e, link);
	}
	return (0);
}
