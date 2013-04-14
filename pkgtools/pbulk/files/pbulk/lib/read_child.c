/* $NetBSD: read_child.c,v 1.4 2013/04/14 17:03:30 dholland Exp $ */

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

#include <sys/wait.h>
#include <nbcompat/err.h>
#include <signal.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>

#include "pbulk.h"

char *
read_from_child(const char *dir, const char *cmd, const char * const *argv)
{
	char *buf;
	size_t buf_len, cur_len;
	ssize_t bytes_read;
	int fd, status;
	pid_t child;

	if ((child = fork_chdir_exec(dir, cmd, argv, &fd)) == -1)
		return NULL;

	cur_len = 0;
	buf_len = 4096;
	buf = xmalloc(buf_len + 1);

	while ((bytes_read = read(fd, buf + cur_len, buf_len - cur_len)) > 0) {
		cur_len += bytes_read;
		if (cur_len * 2 < buf_len)
			continue;
		buf_len *= 2;
		buf = xrealloc(buf, buf_len + 1);
	}
	if (bytes_read == -1) {
		warn("read failed");
		(void)close(fd);
		(void)kill(child, SIGTERM);
		(void)waitpid(child, &status, 0);
		exit(1);
	}

	(void)close(fd);
	(void)waitpid(child, &status, 0);

	if (status != 0 || memchr(buf, 0, cur_len) != NULL) {
		free(buf);
		return NULL;
	}

	buf[cur_len] = '\0';
	return buf;
}
