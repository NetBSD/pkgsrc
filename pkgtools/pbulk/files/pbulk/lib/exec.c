/* $NetBSD: exec.c,v 1.1.1.1 2007/06/19 19:49:58 joerg Exp $ */

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

#include <err.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#include "pbulk.h"

#define UNCONST(x) ((void *)(uintptr_t)(x))

pid_t
fork_chdir_exec(const char *dir, const char *cmd, const char * const *argv, int *out)
{
	static const char chdir_err[] = "Cannot change directory to \"";
	static const char dup2_err[] = "Cannot reassign stdout of child";
	pid_t child;
	int output_pipe[2];

	if (pipe(output_pipe) == -1)
		err(1, "Cannot create pipe for output");

	if ((child = vfork()) != 0) {
		if (child == -1) {
			(void)close(output_pipe[0]);
			(void)close(output_pipe[1]);
		} else {
			*out = output_pipe[0];
			(void)close(output_pipe[1]);
		}
		return child;
	}

	(void)close(output_pipe[0]);
	if (chdir(dir) == -1) {
		(void)write(STDERR_FILENO, chdir_err, sizeof(chdir_err) - 1);
		(void)write(STDERR_FILENO, dir, strlen(dir));
		(void)write(STDERR_FILENO, "\".\n", 3);
		_exit(1);
	}
	if (output_pipe[1] != STDOUT_FILENO) {
		if (dup2(output_pipe[1], STDOUT_FILENO) == -1) {
			(void)write(STDERR_FILENO, dup2_err, sizeof(dup2_err) - 1);
			_exit(1);
		}
		(void)close(output_pipe[1]);
	}
	(void)execvp(cmd, UNCONST(argv));
	_exit(1);
	/* NOTREACHED */
}
