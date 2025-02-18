/* $NetBSD: mk-buildlink-symlinks.c,v 1.3 2025/02/18 15:20:24 wiz Exp $ */

/*
 * Copyright (c) 2022 Jonathan Perkin <jonathan@perkin.org.uk>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define	LINK_SEP	" -> "
#define LINK_SEP_LEN	4

extern int mkpath(char *, mode_t, mode_t);

int
main(int argc, char *argv[])
{
	char buf[4096], *eol, *line, *path1, *path2, *pdir;

	while ((line = fgets(buf, sizeof(buf), stdin)) != NULL) {
		if ((eol = strrchr(line, '\n')) != NULL)
			*eol = '\0';

		if ((path1 = strstr(line, LINK_SEP)) == NULL)
			errx(1, "Could not find separator");

		*path1 = '\0';
		path1 += LINK_SEP_LEN;

		if ((path2 = strdup(line)) == NULL)
			err(1, "strdup");

		/*
		 * The implementation notes for dirname() say that its argument
		 * may be modified, so ensure this operation comes after any
		 * other use of "line".
		 */
		if ((pdir = dirname(line)) == NULL)
			err(1, "dirname");

		if (access(pdir, F_OK) != 0) {
			if (mkpath(pdir, 0755, 0755) != 0)
				err(1, "mkpath: %s", pdir);
		}

		if (unlink(path2) != 0 && errno != ENOENT)
			warn("unlink: %s", path2);

		if (symlink(path1, path2) != 0)
			err(1, "symlink: %s -> %s", path2, path1);

		free(path2);
	}

	exit(0);
}
