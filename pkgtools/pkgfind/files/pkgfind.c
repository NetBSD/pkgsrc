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

#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include <ctype.h>
#include <err.h>
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

static void		pkgfind(const char *, const char *);
static void		showpkg(const char *, const char *, const char *);
static int		getcomment(const char *, char **);
static int		checkskip(const struct dirent *);
static int		subcasestr(const char *, const char *);
static void		usage(void);

int
main(int argc, char *argv[])
{
	const char *path;

	if (argc < 2)
		usage();

	if ((path = getenv("PKGSRCDIR")) == NULL)
		path = PKGSRCDIR;

	for (++argv; *argv != NULL; ++argv)
		pkgfind(path, *argv);

	return 0;
}

static void
pkgfind(const char *path, const char *pkg)
{
	struct dirent **cat, **list;
	int ncat, nlist, i, j;
	char tmp[PATH_MAX];
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
			if (subcasestr(list[j]->d_name, pkg))
				showpkg(path, cat[i]->d_name, list[j]->d_name);
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
	char *mk, *comment;

	(void)asprintf(&mk, "%s/%s/%s/Makefile", path, cat, pkg);
	if (mk == NULL)
		err(EXIT_FAILURE, "asprintf");

	comment = NULL;
	if (getcomment(mk, &comment) == 0) {
		free(mk);
		(void)asprintf(&mk, "%s/%s/%s/Makefile.common", path, cat, pkg);
		if (mk == NULL)
			err(EXIT_FAILURE, "asprintf");
		(void)getcomment(mk, &comment);
	}
	free(mk);

	if (comment != NULL)
		(void)printf("%s/%s: %s\n", cat, pkg, comment);
	else
		(void)printf("%s/%s: no description\n", cat, pkg);
}

static int
getcomment(const char *file, char **comment)
{
	char line[120], *p;
	size_t len;
	FILE *fp;

	if ((fp = fopen(file, "r")) == NULL)
		return 0;
	while (fgets(line, sizeof(line), fp) != NULL) {
		if ((p = strchr(line, '\n')) == NULL)
			continue;
		*p = '\0';
		if (strncmp(line, "COMMENT", 7))
			continue;
		p = line + 7;
		if (*++p == '=')
			p++;
		while (*p != '\0' && isspace((unsigned char)*p))
			p++;
		*comment = strdup(p);
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
subcasestr(const char *s, const char *find)
{
	size_t len, n;

	len = strlen(find);
	n = strlen(s) - len;

	do {
		if (strncasecmp(s, find, len) == 0)
			return 1;
	} while (*++s != '\0' && n-- > 0);

	return 0;
}

static void
usage(void)
{
	extern char *__progname;

	(void)fprintf(stderr, "Usage: %s keyword [...]\n", __progname);
	exit(EXIT_FAILURE);
}
