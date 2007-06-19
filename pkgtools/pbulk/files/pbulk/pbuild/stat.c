/* $NetBSD: stat.c,v 1.1.1.1 2007/06/19 19:49:56 joerg Exp $ */

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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pbuild.h"

void
stat_mode(const char *client_port)
{
	struct sockaddr_in dst;
	ssize_t recv_bytes, sent_bytes;
	char buf[7 * 4];
	struct build_stat st;
	uint32_t tmp;
	int fd;

	if (parse_sockaddr_in(client_port, &dst))
		errx(1, "Could not parse addr/port");

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1)
		err(1, "Could not create socket");	
	if (connect(fd, (struct sockaddr *)&dst, dst.sin_len) == -1)
		err(1, "Could not connect socket");

	sent_bytes = write(fd, "S", 1);
	if (sent_bytes == -1)
		err(1, "Could not write to socket");
	if (sent_bytes == 0)
		exit(0);
	if (sent_bytes != 1)
		errx(1, "Premature end of stream while writing to socket");

	recv_bytes = atomic_read(fd, &buf, 7 * 4);
	if (recv_bytes == 0 || (recv_bytes == -1 && errno == ECONNRESET))
		exit(0);
	if (recv_bytes == -1)
		err(1, "Could not read from socket");
	if (recv_bytes != 7 * 4)
		errx(1, "Premature end while reading statistics from socket");

	(void)memcpy(&tmp, buf, 4);
	st.open_jobs = ntohl(tmp);
	(void)memcpy(&tmp, buf + 4, 4);
	st.in_processing = ntohl(tmp);
	(void)memcpy(&tmp, buf + 8, 4);
	st.failed = ntohl(tmp);
	(void)memcpy(&tmp, buf + 12, 4);
	st.prefailed = ntohl(tmp);
	(void)memcpy(&tmp, buf + 16, 4);
	st.indirect_failed = ntohl(tmp);
	(void)memcpy(&tmp, buf + 20, 4);
	st.indirect_prefailed = ntohl(tmp);
	(void)memcpy(&tmp, buf + 24, 4);
	st.done = ntohl(tmp);

	(void)printf("Jobs not yet processed: %zu\n", st.open_jobs);
	(void)printf("Jobs currently in processing: %zu\n", st.in_processing);
	(void)printf("Successful builds: %zu\n", st.done);
	(void)printf("Failing builds: %zu\n", st.failed + st.prefailed + st.indirect_failed + st.indirect_prefailed);
	(void)printf("  Directly broken: %zu\n", st.failed);
	(void)printf("  Broken due to a broken dependency: %zu\n", st.indirect_failed);
	(void)printf("  Not build as explicitly marked broken: %zu\n", st.prefailed);
	(void)printf("  Broken due to an explicitly broken dependency: %zu\n", st.indirect_prefailed);

	exit(0);
}
