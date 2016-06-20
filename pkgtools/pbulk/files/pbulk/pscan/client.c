/* $NetBSD: client.c,v 1.6 2016/06/20 17:54:43 joerg Exp $ */

/*-
 * Copyright (c) 2007 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
 *
 * This code was developed as part of Google's Summer of Code 2007 program.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <nbcompat.h>

#include <sys/socket.h>
#include <nbcompat/err.h>
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>
#include <nbcompat/unistd.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pscan.h"

static void
find_full_tree_client(int fd, const char *bmake_path)
{
	const char * extract_subdir[] = {
		bmake_path,
		"show-subdir-var",
		"VARNAME=SUBDIR",
		NULL
	};
	char **pkgs;
	size_t i, allocated_pkgs, len_pkgs, len_pkgs_data;
	char *cat_path;
	char *buf, *buf_orig, *cat, *cat_orig;
	size_t buf_len, cat_len;
	uint32_t net_len_pkgs_data;
	ssize_t sent_bytes;

	buf = read_from_child(pkgsrc_tree, bmake_path, extract_subdir);

	if (buf == NULL)
		err(1, "Cannot extract categories");

	cat = cat_orig = buf;
	allocated_pkgs = len_pkgs = 0;
	len_pkgs_data = 0;
	pkgs = NULL;
	for (;;) {
		cat += strspn(cat, " \t\n");
		cat_len = strcspn(cat, " \t\n");
		if (cat_len == 0)
			break;

		cat_path = xasprintf("%s/%.*s", pkgsrc_tree, (int)cat_len, cat);
		buf_orig = buf = read_from_child(cat_path, bmake_path, extract_subdir);
		free(cat_path);
		if (buf == NULL) {
			warnx("Cannot extract subdirectories for %.*s", (int)cat_len, cat);
			cat += cat_len;
			continue;
		}

		for (;;) {
			buf += strspn(buf, " \t\n");
			buf_len = strcspn(buf, " \t\n");
			if (buf_len == 0)
				break;
			if (len_pkgs == allocated_pkgs) {
				if (allocated_pkgs == 0) {
					allocated_pkgs = 1024;
					pkgs = xmalloc(sizeof(*pkgs) *
					               allocated_pkgs);
				} else {
					allocated_pkgs *= 2;
					pkgs = xrealloc(pkgs,
					    sizeof(*pkgs) * allocated_pkgs);
				}
			}
			pkgs[len_pkgs] = xasprintf("%.*s/%.*s", (int)cat_len,
			    cat, (int)buf_len, buf);
			len_pkgs_data += strlen(pkgs[len_pkgs]) + 1;
			++len_pkgs;
			buf += buf_len;
		}
		free(buf_orig);

		cat += cat_len;
	}

	free(cat_orig);

	if (len_pkgs_data > 0xfffffffful)
		errx(1, "Directory list too large");
	net_len_pkgs_data = ntohl((uint32_t)len_pkgs_data);

	sent_bytes = atomic_write(fd, &net_len_pkgs_data, 4);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes != 4)
		errx(1, "Premature end of stream while writing to socket");
	for (i = 0; i < len_pkgs; ++i) {
		size_t l = strlen(pkgs[i]);
		sent_bytes = atomic_write(fd, pkgs[i], l);
		if (sent_bytes == -1)
			err(1, "Could not write to socket");
		if ((size_t)sent_bytes != l)
			errx(1, "Premature end of stream while writing to socket");
		sent_bytes = atomic_write(fd, "\n", 1);
		if (sent_bytes == -1)
			err(1, "Could not write to socket");
		if (sent_bytes != 1)
			errx(1, "Premature end of stream while writing to socket");
		free(pkgs[i]);
	}
	free(pkgs);
}

void
client_mode(const char *client_port, const char *bmake_path)
{
	uint16_t path_len;
	uint32_t net_output_len;
	ssize_t recv_bytes, sent_bytes;
	size_t output_len;
	char *path, *output;
	int fd;

	if ((fd = connect_sockaddr(client_port)) == -1)
		err(1, "Could not creation connection to %s", client_port);

loop:
	recv_bytes = atomic_read(fd, &path_len, 2);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes == 0) 
		exit(0);
	if (recv_bytes != 2)
		errx(1, "Premature end while reading path length from socket");
	path_len = ntohs(path_len);
	if (path_len == 0)
		exit(0);
	if (path_len < 3)
		errx(1, "Invalid path length from master");

	path = xmalloc(path_len + 1);
	path[path_len] = '\0';
	recv_bytes = atomic_read(fd, path, path_len);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes != path_len || strlen(path) != path_len)
		errx(1, "Premature end of stream while reading path from socket");

	if (strcmp(path, "find_full_tree") == 0) {
		free(path);
		find_full_tree_client(fd, bmake_path);
		goto loop;
	}

	if (path[0] == '/' ||
	    strchr(path, '/') == NULL ||
	    strchr(path, '/') != strrchr(path, '/') ||
	    memcmp(path, "../", 3) == 0 ||
	    memcmp(path + path_len - 3, "/..", 3) == 0)
		errx(1, "Invalid path from master");

	if (verbosity >= 1) {
		(void)printf("Scanning %s\n", path);
		(void)fflush(stdout);
	}

	output = scan_pkglocation(path);
	free(path);
	if (output != NULL)
		output_len = strlen(output);
	else
		output_len = 0;
	if (output_len > 0xfffffffful)
		errx(1, "Output too large");
	net_output_len = htonl((uint32_t)output_len);

	sent_bytes = atomic_write(fd, &net_output_len, 4);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes != 4)
		errx(1, "Premature end of stream while writing to socket");
	sent_bytes = atomic_write(fd, output, output_len);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if ((size_t)sent_bytes != output_len)
		errx(1, "Premature end of stream while writing to socket");
	free(output);
	goto loop;
}
