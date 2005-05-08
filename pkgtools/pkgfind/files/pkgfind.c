/*
 * Copyright (c) 2004 Peter Postma <peter@pointless.nl>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/*
 * pancake@phreaker.net ** changes 2004/09/14
 *
 * -C search in comments
 * -c case sensitive
 * -q quiet, don't output comment
 * -x exact matches
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#ifdef NEED_LIBNBCOMPAT
#include <nbcompat.h>
#else
#include <err.h>
#endif

#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PKGSRCDIR	"/usr/pkgsrc"

static const char * const skip[] = {
	".", "..", "CVS", "bootstrap", "doc", "distfiles",
	"licenses", "mk", "packages", NULL
};

static void		pkgfind(const char *, const char *, int);
static void		showpkg(const char *, const char *, const char *);
static int		getstring(const char *, const char *, char **);
static int		checkskip(const struct dirent *);
static int		partialmatch(const char *, const char *);
static int		exactmatch(const char *, const char *);
static void		usage(void);

static int		(*match)(const char *, const char *);

static const char	*search;
static int		cflag, qflag;

int
main(int argc, char *argv[])
{
	const char *path;
	int ch, count = 0;

	setprogname("pkgfind");

	/* default matches are partial matches */
	match = partialmatch;
	/* no special searches by default */
	search = NULL;

	cflag = qflag = 0;

	while ((ch = getopt(argc, argv, "Ccn:Mqx")) != -1) {
		switch (ch) {
		case 'C':	/* search in comments */
			search = "COMMENT";
			break;
		case 'c':	/* case sensitive */
			cflag = 1;
			break;
		case 'n':
			count = atoi(optarg);
			break;
		case 'M':	/* search for maintainer */
			search = "MAINTAINER";
			break;
		case 'q':	/* quite, don't output comment */
			qflag = 1;
			break;
		case 'x':	/* exact matches */
			match = exactmatch;
			break;
		default:
			usage();
			/* NOTREACHED */
		}
	}
	argc -= optind;
	argv += optind;

	if (argc < 1)
		usage();

	if ((path = getenv("PKGSRCDIR")) == NULL)
		path = PKGSRCDIR;

	for (; *argv != NULL; ++argv)
		pkgfind(path, *argv, count);

	return 0;
}

static void
pkgfind(const char *path, const char *pkg, int count)
{
	struct dirent **cat, **list = NULL;
	int ncat, nlist, i, j;
	char tmp[PATH_MAX];
	char *text = NULL;
	struct stat sb;

	if ((ncat = scandir(path, &cat, checkskip, alphasort)) < 0)
		err(EXIT_FAILURE, "%s", path);

	for (i = 0; i < ncat; i++) {
		if (snprintf(tmp, sizeof(tmp), "%s/%s", path, cat[i]->d_name)
		    >= sizeof(tmp)) {
			warnx("filename too long");
			continue;
		}
		if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
			continue;
		if ((nlist = scandir(tmp, &list, checkskip, alphasort)) < 0) {
			warn("%s", tmp);
			continue;
		}
		for (j = 0; j < nlist; j++) {
			if (snprintf(tmp, sizeof(tmp), "%s/%s/%s", path,
			    cat[i]->d_name, list[j]->d_name) >= sizeof(tmp)) {
				warnx("filename too long");
				continue;
			}
			if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
				continue;
			if (search != NULL) {
				(void)strncat(tmp, "/Makefile", sizeof(tmp));
				if (getstring(tmp, search, &text) == 0)
					continue;
			} else {
				text = list[j]->d_name;
			}
			if ((*match)(text, pkg)) {
				showpkg(path, cat[i]->d_name, list[j]->d_name);
				if (count != 0 && --count < 1) {
					i = ncat;
					break;
				}
			}
			free(list[j]);
		}
		free(cat[i]);
	}
	free(list);
	free(cat);
}

static void
showpkg(const char *path, const char *cat, const char *pkg)
{
	char *mk, *comment = NULL;
	size_t len;

	len = strlen(path) + strlen(cat) + strlen(pkg) +
	   strlen("Makefile") + 3 + 1;

	if (!qflag) {
		if ((mk = malloc(len)) == NULL)
			err(EXIT_FAILURE, "malloc");
		(void)snprintf(mk, len, "%s/%s/%s/Makefile", path, cat, pkg);

		if (getstring(mk, "COMMENT", &comment) == 0) {
			if ((mk = realloc(mk, len + 7)) == NULL)
				err(EXIT_FAILURE, "malloc");
			(void)snprintf(mk, len+7, "%s/%s/%s/Makefile.common",
			    path, cat, pkg);
			(void)getstring(mk, "COMMENT", &comment);
		}
		free(mk);
	}

	if (comment != NULL)
		(void)printf("%s/%s: %s\n", cat, pkg, comment);
	else
		(void)printf("%s/%s\n", cat, pkg);
}

static int
getstring(const char *file, const char *string, char **nstring)
{
	char line[120], *p;
	FILE *fp;

	if ((fp = fopen(file, "r")) == NULL)
		return 0;
	while (fgets(line, sizeof(line), fp) != NULL) {
		if ((p = strchr(line, '\n')) == NULL)
			continue;
		*p = '\0';
		if (strncmp(line, string, strlen(string)) != 0)
			continue;
		p = line + strlen(string);
		if (*++p == '=')
			p++;
		while (*p != '\0' && isspace((unsigned char)*p))
			p++;
		if (*p == '\0')
			continue;
		*nstring = strdup(p);
		(void)fclose(fp);
		return 1;
	}
	(void)fclose(fp);
	return 0;
}

static int
checkskip(const struct dirent *dp)
{
	const char * const *p;

	for (p = skip; *p != NULL; p++)
		if (strcmp(dp->d_name, *p) == 0)
			return 0;
	return 1;
}

static int
partialmatch(const char *s, const char *find)
{
	size_t len, n;

	len = strlen(find);
	n = strlen(s) - len;

	do {
		if (cflag) {
			if (strncmp(s, find, len) == 0)
				return 1;
		} else {
			if (strncasecmp(s, find, len) == 0)
				return 1;
		}
	} while (*++s != '\0' && n-- > 0);

	return 0;
}

static int
exactmatch(const char *s, const char *find)
{
	if (cflag)
		return (strcmp(s, find) == 0);
	else
		return (strcasecmp(s, find) == 0);
}

static void
usage(void)
{
	(void)fprintf(stderr, "Usage: %s [-CcMqx] [-n number] keyword [...]\n",
	    getprogname());
	exit(EXIT_FAILURE);
}
