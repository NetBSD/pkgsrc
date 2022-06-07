/* $NetBSD: mkpath.c,v 1.1 2022/06/07 09:53:36 jperkin Exp $ */

/*
 * Copyright (c) 1983, 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Copy of mkpath() from NetBSD src/bin/mkdir/mkdir.c
 */
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <string.h>

int mkpath(char *path, mode_t mode, mode_t dir_mode);

/*
 * mkpath -- create directories.
 *	path     - path
 *	mode     - file mode of terminal directory
 *	dir_mode - file mode of intermediate directories
 */
int
mkpath(char *path, mode_t mode, mode_t dir_mode)
{
	struct stat sb;
	char *slash;
	int done, rv;

	done = 0;
	slash = path;

	for (;;) {
		slash += strspn(slash, "/");
		slash += strcspn(slash, "/");

		done = (*(slash + strspn(slash, "/")) == '\0');
		*slash = '\0';

		rv = mkdir(path, done ? mode : dir_mode);
		if (rv < 0) {
			/*
			 * Can't create; path exists or no perms.
			 * stat() path to determine what's there now.
			 */
			int	sverrno;

			sverrno = errno;
			if (stat(path, &sb) < 0) {
					/* Not there; use mkdir()s error */
				errno = sverrno;
				warn("%s", path);
				return -1;
			}
			if (!S_ISDIR(sb.st_mode)) {
					/* Is there, but isn't a directory */
				errno = ENOTDIR;
				warn("%s", path);
				return -1;
			}
		} else if (done) {
			/*
			 * Created ok, and this is the last element
			 */
			/*
			 * The mkdir() and umask() calls both honor only the
			 * file permission bits, so if you try to set a mode
			 * including the sticky, setuid, setgid bits you lose
			 * them. So chmod().
			 */
			if ((mode & ~(S_IRWXU|S_IRWXG|S_IRWXO)) != 0 &&
			    chmod(path, mode) == -1) {
				warn("%s", path);
				return -1;
			}
		}

		if (done) {
			break;
		}
		*slash = '/';
	}

	return 0;
}
