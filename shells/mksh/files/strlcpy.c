/*-
 * Copyright (c) 2006, 2008, 2009, 2013
 *	mirabilos <m@mirbsd.org>
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
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

#include "sh.h"

__RCSID("$MirOS: src/bin/mksh/strlcpy.c,v 1.10 2015/11/29 17:05:02 tg Exp $");

/*
 * Copy src to string dst of size siz. At most siz-1 characters
 * will be copied. Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
#undef strlcpy
size_t
strlcpy(char *dst, const char *src, size_t siz)
{
	const char *s = src;

	if (siz == 0)
		goto traverse_src;

	/* copy as many chars as will fit */
	while (--siz && (*dst++ = *s++))
		;

	/* not enough room in dst */
	if (siz == 0) {
		/* safe to NUL-terminate dst since we copied <= siz-1 chars */
		*dst = '\0';
 traverse_src:
		/* traverse rest of src */
		while (*s++)
			;
	}

	/* count does not include NUL */
	return ((size_t)(s - src - 1));
}
