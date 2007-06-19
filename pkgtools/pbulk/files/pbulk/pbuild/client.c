/* $NetBSD: client.c,v 1.1.1.1 2007/06/19 19:49:56 joerg Exp $ */

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
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pbuild.h"

void
client_mode(const char *client_port)
{
	struct sockaddr_in dst;
	uint32_t build_info_len;
	ssize_t recv_bytes, sent_bytes;
	char *build_info;
	int fd;

	if (parse_sockaddr_in(client_port, &dst))
		errx(1, "Could not parse addr/port");

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1)
		err(1, "Could not create socket");	
	if (connect(fd, (struct sockaddr *)&dst, dst.sin_len) == -1)
		err(1, "Could not connect socket");

loop:
	sent_bytes = atomic_write(fd, "G", 1);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes == 0)
		exit(0);
	if (sent_bytes != 1)
		errx(1, "Premature end of stream while writing to socket");

	recv_bytes = atomic_read(fd, &build_info_len, 4);
	if (recv_bytes == 0 || (recv_bytes == -1 && errno == ECONNRESET))
		exit(0);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes != 4)
		errx(1, "Premature end while reading build info from socket");
	build_info_len = ntohl(build_info_len);
	if (build_info_len < 10 || build_info_len > 0xffffff)
		errx(1, "Invalid build info length from master");

	build_info = xmalloc(build_info_len + 1);
	build_info[build_info_len] = '\0';
	recv_bytes = atomic_read(fd, build_info, build_info_len);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes != build_info_len || strlen(build_info) != build_info_len)
		errx(1, "Premature end of stream while reading path from socket");

	if (verbosity > 0) {
		const char *begin, *end;

		if (strncmp(build_info, "PKGNAME=", 8) != 0)
			err(1, "Inconsistent build info from server");
		begin = build_info + 8;
		if ((end = strchr(begin, '\n')) == NULL)
			err(1, "Inconsistent build info from server");
		printf("Building package %.*s", (int)(end - begin), begin);
		fflush(stdout);
	}

	if (build_package(build_info, build_info_len) == 0)
		sent_bytes = atomic_write(fd, "D", 1);
	else
		sent_bytes = atomic_write(fd, "F", 1);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes != 1)
		errx(1, "Premature end of stream while writing to socket");
	free(build_info);
	goto loop;
}
