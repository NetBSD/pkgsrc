/* $NetBSD: pscan.c,v 1.10 2016/06/20 17:54:43 joerg Exp $ */

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

#include <sys/stat.h>
#include <sys/uio.h>
#include <nbcompat/err.h>
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include <fcntl.h>
#include <nbcompat/limits.h>
#include <signal.h>
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>
#include <nbcompat/unistd.h>

#include "pbulk.h"
#include "pscan.h"

int verbosity;

static const char *bmake_path;
static const char *output_file;
const char *pkgsrc_tree;

static void	find_full_tree(void);
static void	read_limited_list(void);
static void	standalone_mode(void);

static void
usage(void)
{
	(void)fprintf(stderr, "usage: pbulk-scan -c <master> [ -v ] -M <make> <pkgsrc tree>\n");
	(void)fprintf(stderr, "usage: pbulk-scan [ -I <start> ] [ -L <old scan> ] [ -l ] [ -v ]\n"
			      "                  [ -m <port> ] -M <make> <pksgrc tree> <output file>\n");
	exit(1);
}

int
main(int argc, char **argv)
{
	const char *client_port = NULL, *last_scan = NULL, *master_port = NULL;
	const char *start_script = NULL;
	int ch, limited_scan;
	struct sigaction sa;

	setprogname("pbulk-scan");

	limited_scan = 0;

	while ((ch = getopt(argc, argv, "I:M:L:lc:m:v")) != -1) {
		switch (ch) {
		case 'I':
			start_script = optarg;
			break;
		case 'c':
			client_port = optarg;
			break;
		case 'L':
			last_scan = optarg;
			break;
		case 'l':
			limited_scan = 1;
			break;
		case 'm':
			master_port = optarg;
			break;
		case 'M':
			bmake_path = optarg;
			break;
		case 'v':
			++verbosity;
			break;
		default:
			usage();
		}
	}

#if !defined(__INTERIX)
	sa.sa_sigaction = NULL;
#endif
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	(void)sigemptyset(&sa.sa_mask);
	(void)sigaction(SIGPIPE, (struct sigaction *)&sa, NULL);

	argc -= optind;
	argv += optind;

	if (bmake_path == NULL)
		usage();

	if (client_port != NULL && master_port != NULL) {
		warnx("Only client mode or master mode can be active");
		usage();
	}

	if (client_port == NULL)
		read_old_scan(last_scan);

	if (client_port) {
		if (limited_scan != 0 || argc != 1)
			usage();
		pkgsrc_tree = argv[0];

		client_mode(client_port, bmake_path);
	}

	if (argc != 2)
		usage();

	pkgsrc_tree = argv[0];
	output_file = argv[1];

	if (limited_scan != 0)
		read_limited_list();

	if (master_port != NULL) {
		if (limited_scan == 0)
			add_job_full("find_full_tree");
		if (has_job())
			master_mode(master_port, start_script);
	} else {
		if (limited_scan == 0)
			find_full_tree();
		if (has_job())
			standalone_mode();
	}

	write_jobs(output_file);

	return 0;
}

char *
scan_pkglocation(const char *pkg_location)
{
	const char * extract_pbulk_index[] = {
		bmake_path,
		"pbulk-index",
		NULL
	};
	char *path, *buf;

	path = xasprintf("%s/%s", pkgsrc_tree, pkg_location);
	buf = read_from_child(path, bmake_path, extract_pbulk_index);
	free(path);

	return buf;
}

static void
read_limited_list(void)
{
	char location[PATH_MAX], *eos;

	while (fgets(location, PATH_MAX, stdin) != NULL) {
		eos = strchr(location, '\n');
		if (eos == NULL)
			err(1, "Incomplete or too long input line");
		if (location == eos)
			continue;
		if (*location == '#')
			continue;
		*eos = '\0';
		add_job_full(location);
	}
}

static void
find_full_tree(void)
{
	const char * extract_subdir[] = {
		bmake_path,
		"show-subdir-var",
		"VARNAME=SUBDIR",
		NULL
	};
	char *cat_path;
	char *buf, *buf_orig, *cat, *cat_orig;
	size_t buf_len, cat_len;

	buf = read_from_child(pkgsrc_tree, bmake_path, extract_subdir);

	if (buf == NULL)
		err(1, "Cannot extract categories");

	cat = cat_orig = buf;
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
			add_job(cat, cat_len, buf, buf_len);
			buf += buf_len;
		}
		free(buf_orig);

		cat += cat_len;
	}

	free(cat_orig);
}

static void
standalone_mode(void)
{
	struct scan_job *job;

	while ((job = get_job()) != NULL) {
		job->scan_output = scan_pkglocation(job->pkg_location);
		process_job(job, JOB_DONE);
	}
}
