/*-
 * Copyright (c) 2003-2007 Tim Kientzle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in this position and unchanged.
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
 */


#include <sys/types.h>
__FBSDID("$FreeBSD$");

#include <sys/stat.h>

#include <archive.h>
#include <archive_entry.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cpio.h"

static int	copy_data(struct cpio *, struct archive *, struct archive *);
static void	out(struct cpio *);
static int	out_file(struct cpio *, const char *pathname);
static void	in(struct cpio *);
static void	list(struct cpio *);
static void	copy(struct cpio *);
static void	usage(struct cpio *);

int
main(int argc, char *argv[])
{
	struct cpio _cpio; /* Allocated on stack. */
	struct cpio *cpio;
	char opt;

	cpio = &_cpio;
	memset(cpio, 0, sizeof(*cpio));


	/* Need cpio->progname before calling cpio_warnc. */
	if (*argv == NULL)
		cpio->progname = "cpio";
	else {
		cpio->progname = strrchr(*argv, '/');
		if (cpio->progname != NULL)
			cpio->progname++;
		else
			cpio->progname = *argv;
	}

	cpio->mode = '\0';
	cpio->verbose = 0;
	cpio->compress = '\0';
	cpio->extract_flags = ARCHIVE_EXTRACT_TIME;
	cpio->extract_flags |= ARCHIVE_EXTRACT_NO_AUTODIR;
	cpio->extract_flags |= ARCHIVE_EXTRACT_NO_OVERWRITE_NEWER;
	cpio->bytes_per_block = 512;
	cpio->filename = NULL;

	while ((opt = getopt(argc, argv, "aBcdfilmoprtuv")) != -1) {
		switch (opt) {
		case 'a': /* POSIX 1997 */
			break;
		case 'B': /* POSIX 1997 */
			cpio->bytes_per_block = 5120;
			break;
		case 'c': /* POSIX 1997 */
			cpio->format = "odc";
			break;
		case 'd': /* POSIX 1997 */
			cpio->extract_flags &= ~ARCHIVE_EXTRACT_NO_AUTODIR;
			break;
		case 'f': /* POSIX 1997 */
			break;
		case 'i': /* POSIX 1997 */
			cpio->mode = opt;
			break;
		case 'l': /* POSIX 1997 */
			cpio->option_link = 1;
			break;
		case 'm': /* POSIX 1997 */
			break;
		case 'o': /* POSIX 1997 */
			cpio->mode = opt;
			break;
		case 'p': /* POSIX 1997 */
			cpio->mode = opt;
			break;
		case 'r': /* POSIX 1997 */
			/* Interactively rename files. */
			break;
		case 't': /* POSIX 1997 */
			cpio->option_list = 1;
			break;
		case 'u': /* POSIX 1997 */
			break;
		case 'v': /* POSIX 1997 */
			cpio->verbose++;
			break;
		default:
			usage(cpio);
		}
	}

	switch (cpio->mode) {
	case 'o':
		out(cpio);
		break;
	case 'i':
		if (cpio->option_list)
			list(cpio);
		else
			in(cpio);
		break;
	case 'p':
		copy(cpio);
		break;
	}

	return (0);
}

static void
out(struct cpio *cpio)
{
	cpio->archive = archive_write_new();
	switch (cpio->compress) {
	case 'j': case 'y':
		archive_write_set_compression_bzip2(cpio->archive);
		break;
	case 'z':
		archive_write_set_compression_gzip(cpio->archive);
		break;
	default:
		archive_write_set_compression_none(cpio->archive);
		break;
	}
	archive_write_set_format_cpio(cpio->archive);
	archive_write_open_file(cpio->archive, cpio->filename);

	process_lines(cpio, "-", out_file);

	archive_write_close(cpio->archive);
	archive_write_finish(cpio->archive);
}

static char buff[16384];

static int
out_file(struct cpio *cpio, const char *pathname)
{
	struct stat st;
	struct archive_entry *entry;
	int fd;
	ssize_t len;

	if (cpio->verbose)
		fprintf(stderr,"%s", pathname);
	entry = archive_entry_new();
	stat(pathname, &st);
	archive_entry_copy_stat(entry, &st);
	archive_entry_set_pathname(entry, pathname);
	archive_write_header(cpio->archive, entry);
	fd = open(pathname, O_RDONLY);
	len = read(fd, buff, sizeof(buff));
	while (len > 0) {
		archive_write_data(cpio->archive, buff, len);
		len = read(fd, buff, sizeof(buff));
	}
	close(fd);
	archive_entry_free(entry);
	if (cpio->verbose)
		fprintf(stderr,"\n");
	return (0);
}


static void
in(struct cpio *cpio)
{
	struct archive *a;
	struct archive_entry *entry;
	struct archive *ext;
	int r;

	ext = archive_write_disk_new();
	archive_write_disk_set_options(ext, cpio->extract_flags);
	a = archive_read_new();
	archive_read_support_compression_all(a);
	archive_read_support_format_all(a);

	if (archive_read_open_file(a, cpio->filename, cpio->bytes_per_block))
		cpio_errc(cpio, 1, archive_errno(a),
		    archive_error_string(a));
	for (;;) {
		r = archive_read_next_header(a, &entry);
		if (r == ARCHIVE_EOF)
			break;
		if (r != ARCHIVE_OK) {
			cpio_errc(cpio, 1, archive_errno(a),
			    archive_error_string(a));
		}
		if (cpio->verbose)
			fprintf(stdout, "%s\n", archive_entry_pathname(entry));
		r = archive_write_header(ext, entry);
		if (r != ARCHIVE_OK) {
			fprintf(stderr, "%s: %s\n",
			    archive_entry_pathname(entry),
			    archive_error_string(ext));
		} else {
			r = copy_data(cpio, a, ext);
		}
	}
	archive_read_close(a);
	archive_read_finish(a);
	archive_write_close(ext);
	archive_write_finish(ext);
	exit(0);
}

static int
copy_data(struct cpio *cpio, struct archive *ar, struct archive *aw)
{
	int r;
	size_t size;
	const void *block;
	off_t offset;

	for (;;) {
		r = archive_read_data_block(ar, &block, &size, &offset);
		if (r == ARCHIVE_EOF)
			return (ARCHIVE_OK);
		if (r != ARCHIVE_OK) {
			cpio_warnc(cpio, archive_errno(ar),
			    "%s", archive_error_string(ar));
			return (r);
		}
		r = archive_write_data_block(aw, block, size, offset);
		if (r != ARCHIVE_OK) {
			cpio_warnc(cpio, archive_errno(aw),
			    archive_error_string(aw));
			return (r);
		}
	}
}

static void
list(struct cpio *cpio)
{
	char mode[12];
	struct archive *a;
	struct archive_entry *entry;
	int r;

	a = archive_read_new();
	archive_read_support_compression_all(a);
	archive_read_support_format_all(a);

	if (archive_read_open_file(a, cpio->filename, cpio->bytes_per_block))
		cpio_errc(cpio, 1, archive_errno(a),
		    archive_error_string(a));
	for (;;) {
		r = archive_read_next_header(a, &entry);
		if (r == ARCHIVE_EOF)
			break;
		if (r != ARCHIVE_OK) {
			cpio_errc(cpio, 1, archive_errno(a),
			    archive_error_string(a));
		}
		if (cpio->verbose) {
			cpio_strmode(entry, mode);
			/* TODO: uname/gname lookups */
			/* TODO: Clean this up. */
			fprintf(stdout, "%s%3d %8s%8s " CPIO_FILESIZE_PRINTF " %s\n",
			    mode,
			    archive_entry_nlink(entry),
			    archive_entry_uname(entry),
			    archive_entry_gname(entry),
			    (CPIO_FILESIZE_TYPE)archive_entry_size(entry),
			    archive_entry_pathname(entry));
		} else
			fprintf(stdout, "%s\n", archive_entry_pathname(entry));
	}
	archive_read_close(a);
	archive_read_finish(a);
	exit(0);
}

static void
copy(struct cpio *cpio)
{
	(void)cpio; /* UNUSED */
}

static void
usage(struct cpio *cpio)
{
	const char *m = "Usage: cpio <options>\n";
	cpio_errc(cpio, 1, 0, m);
}
