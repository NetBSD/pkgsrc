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
#include <sys/wait.h>

#include <err.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PKGSRCDIR	"@PKGSRCDIR@"

static const char * const skip[] = {
	".", "..", "CVS", "bootstrap", "doc", "distfiles",
	"licenses", "mk", "packages", NULL
};

static void	pkgclean(const char *, const char *);
static int	checkskip(const struct dirent *);

int
main(int argc, char *argv[])
{
	const char *path, *work = "work";

	if ((path = getenv("PKGSRCDIR")) == NULL)
		path = PKGSRCDIR;

	if (argc > 1)
		work = argv[1];

	pkgclean(path, work);

	return 0;
}

static void
pkgclean(const char *path, const char *work)
{
	struct dirent **cat, **list;
	int status, ncat, nlist, i, j;
	char tmp[PATH_MAX];
	struct stat sb;
	pid_t pid;

	if ((ncat = scandir(path, &cat, checkskip, alphasort)) < 0)
		err(EXIT_FAILURE, "scandir: %s", path);

	for (i = 0; i < ncat; i++) {
		if (snprintf(tmp, sizeof(tmp), "%s/%s", path, cat[i]->d_name)
		    >= sizeof(tmp)) {
			warnx("filename too long: %s", tmp);
			continue;
		}
		if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
			continue;
		if ((nlist = scandir(tmp, &list, checkskip, alphasort)) < 0) {
			warn("scandir: %s", tmp);
			continue;
		}
		for (j = 0; j < nlist; j++) {
			if (snprintf(tmp, sizeof(tmp), "%s/%s/%s/%s", path,
			    cat[i]->d_name, list[j]->d_name, work) >= sizeof(tmp)) {
				warnx("filename too long: %s", tmp);
				continue;
			}
			if (stat(tmp, &sb) < 0 || !S_ISDIR(sb.st_mode))
				continue;
			(void)printf("Deleting %s\n", tmp);
			pid = fork();
			if (pid < 0) {
				warn("fork");
				continue;
			} else if (pid == 0)
				(void)execl("/bin/rm", "rm", "-rf", tmp, NULL);
			if (waitpid(pid, &status, 0) == -1)
				err(EXIT_FAILURE, "waitpid");
			if (WEXITSTATUS(status))
				warn("/bin/rm terminated abnormally");
			free(list[j]);
		}
		free(cat[i]);
	}
	free(list);
	free(cat);
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
