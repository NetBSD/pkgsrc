/*-
 * Copyright (c) 2003-2007 Tim Kientzle
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include "cpio_platform.h"
#include <stdio.h>

#define	DEFAULT_BYTES_PER_BLOCK	(20*512)

/*
 * The internal state for the "cpio" program.
 *
 * Keeping all of the state in a structure like this simplifies memory
 * leak testing (at exit, anything left on the heap is suspect).  A
 * pointer to this structure is passed to most cpio internal
 * functions.
 */
struct cpio {
	/* Options */
	char		 *filename;
	char		  mode; /* -i -o -p */
	char		  compress; /* -j, -y, or -z */
	const char	 *format; /* -H format */
	int		  bytes_per_block; /* -b block_size */
	int		  verbose;   /* -v */
	int		  extract_flags; /* Flags for extract operation */
	char		  symlink_mode; /* H or L, per BSD conventions */
	const char	 *compress_program;
	int		  option_null; /* -0 --null */
	int		  option_list; /* -t */
	int		  option_link; /* -l */

	/* If >= 0, then close this when done. */
	int		  fd;

	/* Miscellaneous state information */
	struct archive	 *archive;
	const char	 *progname;
	int		  argc;
	char		**argv;
	int		  return_value; /* Value returned by main() */
};

void	cpio_errc(struct cpio *, int _eval, int _code,
	    const char *fmt, ...);
void	cpio_warnc(struct cpio *, int _code, const char *fmt, ...);
void	cpio_strmode(struct archive_entry *, char *);
int	process_lines(struct cpio *cpio, const char *pathname,
	    int (*process)(struct cpio *, const char *));

