/* $NetBSD: pbuild.c,v 1.1.1.1 2007/06/19 19:49:56 joerg Exp $ */

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

#include <sys/wait.h>
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pbulk.h"
#include "pbuild.h"

int verbosity;

static const char *build_path;
static const char *build_cmd;

static void	standalone_mode(void);

static void
usage(void)
{
	(void)fprintf(stderr, "usage: pbulk-build -s <master>\n");
	(void)fprintf(stderr, "usage: pbulk-build [ -v ] -c <master> -b <build script>\n");
	(void)fprintf(stderr, "usage: pbulk-build [ -v ] [ -I <start> ] [ -r <report> ] -m <port> <tree scan> <success file> <error file>\n");
	(void)fprintf(stderr, "usage: pbulk-build [ -v ] [ -r <report> ] -b <build script> <tree scan> <success file> <error file>\n");
	exit(1);
}

int
main(int argc, char **argv)
{
	const char *stat_port;
	const char *client_port;
	const char *master_port;
	const char *report_file;
	const char *start_script;
	struct sigaction sa;
	int ch, modes;

	client_port = NULL;
	master_port = NULL;
	stat_port = NULL;
	start_script = NULL;
	report_file = NULL;
	modes = 0;

	while ((ch = getopt(argc, argv, "I:b:c:m:r:s:v")) != -1) {
		switch (ch) {
		case 'I':
			start_script = optarg;
			break;
		case 'b':
			build_path = optarg;
			break;
		case 'c':
			client_port = optarg;
			++modes;
			break;
		case 'm':
			master_port = optarg;
			++modes;
			break;
		case 'r':
			report_file = optarg;
			break;
		case 's':
			stat_port = optarg;
			++modes;
			break;
		case 'v':
			++verbosity;
			break;
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (modes > 1) {
		warnx("Only one of client mode, statistic mode or master mode can be active");
		usage();
	}

	sa.sa_sigaction = NULL;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	(void)sigemptyset(&sa.sa_mask);
	(void)sigaction(SIGPIPE, (struct sigaction *)&sa, NULL);

	if (build_path == NULL && (modes == 0 || client_port != NULL))
		usage();

	if (stat_port != NULL) {
		if (argc != 0)
			usage();
		stat_mode(stat_port);
	}

	if (master_mode == NULL) {
		build_cmd = strrchr(build_path, '/');
		if (build_cmd == NULL)
			build_cmd = build_path;
		else
			++build_cmd;
	}

	if (client_port != NULL) {
		if (argc != 0)
			usage();
		client_mode(client_port);
	}

	if (argc != 3)
		usage();

	if (verbosity >= 2)
		tzset();

	init_jobs(argv[0], argv[1], argv[2]);

	if (master_port != NULL)
		master_mode(master_port, start_script);
	else
		standalone_mode();

	if (report_file)
		finish_build(report_file);

	return 0;
}

int
build_package(const char *build_info, size_t len)
{
	int input[2];
	pid_t child;

	if (pipe(input) == -1)
		err(1, "Failed to create pipe");
	
	child = vfork();
	if (child == -1)
		err(1, "Failed to create child");
	if (child != 0) {
		ssize_t bytes_written;
		const char *begin;
		size_t bytes_left;
		int ret;

		(void)close(input[0]);
		begin = build_info;
		bytes_left = len;
		while (bytes_left > 0) {
			bytes_written = write(input[1], begin, bytes_left);
			if (bytes_written == -1 && errno == EPIPE)
				break;
			if (bytes_written <= 0) {
				(void)close(input[1]);
				(void)kill(child, SIGTERM);
				(void)waitpid(child, &ret, 0);
				return 1;
			}
			bytes_left -= bytes_written;
			begin += bytes_written;
		}
		(void)close(input[1]);
		(void)waitpid(child, &ret, 0);
		return ret;
	}

	(void)close(input[1]);
	if (dup2(input[0], 0) == -1) {
		const char err_msg[] = "dup failed for stdin\n";

		(void)write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
		_exit(255);
	}

	(void)execl(build_path, build_cmd, (char *)NULL);
	_exit(255);
}

static void
standalone_mode(void)
{
	struct build_job *job;

	while ((job = get_job()) != NULL) {
		if (build_package(job->begin, job->end - job->begin) == 0)
			process_job(job, JOB_DONE, 1);
		else
			process_job(job, JOB_FAILED, 1);
	}
}
