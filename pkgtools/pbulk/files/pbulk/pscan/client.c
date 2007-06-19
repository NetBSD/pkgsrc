/* $NetBSD: client.c,v 1.1.1.1 2007/06/19 19:49:57 joerg Exp $ */

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

#include <sys/socket.h>
#include <err.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pscan.h"

void
client_mode(const char *client_port)
{
	struct sockaddr_in dst;
	uint16_t path_len;
	uint32_t net_output_len;
	ssize_t recv_bytes, sent_bytes;
	size_t output_len;
	char *path, *output;
	int fd;

	if (parse_sockaddr_in(client_port, &dst))
		errx(1, "Could not parse addr/port");

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1)
		err(1, "Could not create socket");	
	if (connect(fd, (struct sockaddr *)&dst, dst.sin_len) == -1)
		err(1, "Could not connect socket");

loop:
	recv_bytes = atomic_read(fd, &path_len, 2);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes == 0) 
		exit(0);
	if (recv_bytes != 2)
		errx(1, "Premature end while reading path length from socket");
	path_len = ntohs(path_len);
	if (path_len < 3)
		errx(1, "Invalid path length from master");

	path = xmalloc(path_len + 1);
	path[path_len] = '\0';
	recv_bytes = atomic_read(fd, path, path_len);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes != path_len || strlen(path) != path_len)
		errx(1, "Premature end of stream while reading path from socket");
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

	sent_bytes = write(fd, &net_output_len, 4);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes != 4)
		errx(1, "Premature end of stream while writing to socket");
	sent_bytes = write(fd, output, output_len);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes != output_len)
		errx(1, "Premature end of stream while writing to socket");
	free(output);
	goto loop;
}
