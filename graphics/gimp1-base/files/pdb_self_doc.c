/*	$NetBSD: pdb_self_doc.c,v 1.1.1.1 2004/03/29 22:06:49 xtraeme Exp $	*/

/*
 * C version of pdb_self_doc.el, makes some assumptions about the structure
 * of the pdb_dump file.
 *
 * Author: Todd Vierling <tv@pobox.com>
 * Copyright:  Do whatever you want with this code.  I offer no guarantee or
 * warranty of any kind.
 */

#include <ctype.h>
#ifdef __NetBSD__
#include <err.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __NetBSD__
#include <stdarg.h>
void errx (int rc, char *fmt,...)
{
     va_list ap;

     va_start (ap, fmt);
     fputs ("pdb_self_doc: ", stderr);
     vfprintf (stderr, fmt, ap);
     exit (rc);
}
#endif

int depth, line;

static struct ioarg {
	struct ioarg *next;
	char *hlist[3];
} **curioargs, *curioarg;

static struct procedure {
	char *hlist[7];
	struct ioarg *iargs;
	struct ioarg *oargs;
} procs[800], *curproc;

static char **hlist;

int hnum, hmax, inum, onum, iomode;
int nprocs;

#define wsspan(p) strspn(p, " \t\r\n")

static char *strndup(const char *x, int len) {
	char *p = malloc(len + 1);
	strncpy(p, x, len);
	p[len] = 0;
	return p;
}

static int proccompar(const void *a, const void *b) {
	return strcmp(((struct procedure *)a)->hlist[0],
		      ((struct procedure *)b)->hlist[0]);
}

int main(int argc, char **argv) {
	char buf[65536], *p;
	int i;

	while (fgets(buf, 65536, stdin)) {
		line++;
		p = buf + wsspan(buf);

		while (*p) {
			if (*p == '(') {
				depth++;
				p++;
				if (!curproc && depth > 1)
					errx(1, "depth > 1 without register-procedure on line %d\n", line);
				if (depth > 3)
					errx(1, "depth > 3 on line %d\n", line);
				if (depth == 1) {
					hnum = 0;
					hmax = 7;
				} else if (depth == 2) {
					hmax = 3;
					if (++iomode > 1)
						curioargs = &curproc->oargs;
					else
						curioargs = &curproc->iargs;
				} else if (depth == 3) {
					struct ioarg *arg = calloc(1, sizeof(*arg));
					*curioargs = curioarg = arg;
					curioargs = &arg->next;
					hnum = 0;
					hlist = arg->hlist;
				}
			} else if (*p == ')') {
				depth--;
				p++;
				if (depth == 0) {
					hnum = hmax = inum = onum = iomode = 0;
					curproc = NULL;
					hlist = NULL;
				} else if (depth == 1) {
					curioargs = NULL;
				} else if (depth == 2) {
					curioarg = NULL;
				}
			} else if (*p == '\"') {
				char *eq = ++p, *neq;

				if ((depth != 1) && (depth != 3))
					errx(1, "string with depth != 1 or 3 on line %d: %s\n", line, --p);
				if (!curproc)
					errx(1, "string without register-procedure on line %d\n", line);
				if (hnum >= hmax)
					errx(1, "too many strings on line %d\n", line);

				while ((neq = strchr(eq, '\"')) && (neq > p) && (neq[-1] == '\\')) {
					strcpy(neq - 1, neq);
					eq = neq;
				}
				if (!neq) {
					--p;
					if (!fgets(buf + strlen(buf), 65536 - strlen(buf), stdin))
						errx(1, "EOF in string at line %d\n", line);
					continue;
				}

				hlist[hnum++] = strndup(p, neq - p);
				p = ++neq;
			} else if (!strncmp(p, "register-procedure", 18)) {
				if (depth != 1)
					errx(1, "register-procedure at depth %d, line %d\n", depth, line);
				p += 18;
				curproc = &procs[nprocs++];
				hlist = curproc->hlist;
			} else {
				errx(1, "unknown token on line: %s\n", line, p);
			}
			p += wsspan(p);
		}
	}

	qsort(procs, nprocs, sizeof(procs[0]), proccompar);

	for (i = 0; i < nprocs; i++) {
		struct ioarg *arg;

		printf("@defun %s ", procs[i].hlist[0]);
		for (arg = procs[i].iargs; arg; arg = arg->next) {
			if (arg->next)
				printf("%s, ", arg->hlist[0]);
			else
				printf("%s", arg->hlist[0]);
		}
		printf("\n%s--@strong{%s}", procs[i].hlist[2], procs[i].hlist[6]);
		if (procs[i].iargs) {
			puts("\n\n@strong{Inputs}\n@itemize @bullet");
			for (arg = procs[i].iargs; arg; arg = arg->next) {
				arg->hlist[2][0] = toupper(arg->hlist[2][0]);
				printf("@item @emph{%s} (%s)--%s\n", arg->hlist[0],
				       arg->hlist[1], arg->hlist[2]);
			}
			puts("@end itemize");
		}
		if (procs[i].oargs) {
			puts("\n\n@strong{Outputs}\n@itemize @bullet");
			for (arg = procs[i].oargs; arg; arg = arg->next) {
				arg->hlist[2][0] = toupper(arg->hlist[2][0]);
				printf("@item @emph{%s} (%s)--%s\n", arg->hlist[0],
				       arg->hlist[1], arg->hlist[2]);
			}
			puts("@end itemize");
		}
		printf("@end defun\n@emph{%s}\n\n", procs[i].hlist[3]);
	}

	return 0;
}
