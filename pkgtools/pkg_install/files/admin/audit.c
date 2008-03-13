/*	$NetBSD: audit.c,v 1.1 2008/03/13 16:35:30 joerg Exp $	*/

#if HAVE_CONFIG_H
#include "config.h"
#endif
#include <nbcompat.h>
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif
#ifndef lint
__RCSID("$NetBSD: audit.c,v 1.1 2008/03/13 16:35:30 joerg Exp $");
#endif

/*-
 * Copyright (c) 2008 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
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

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif
#if HAVE_ERR_H
#include <err.h>
#endif
#if HAVE_ERRNO_H
#include <errno.h>
#endif
#if HAVE_SIGNAL_H
#include <signal.h>
#endif
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif

#include "admin.h"
#include "lib.h"

static int check_eol = 0;
static int check_signature = 0;
static const char *limit_vul_types = NULL;

static struct pkg_vulnerabilities *pv;

static void
parse_options(int argc, char **argv)
{
	int ch;

	optreset = 1;
	optind = 0;

	while ((ch = getopt(argc, argv, "est")) != -1) {
		switch (ch) {
		case 'e':
			check_eol = 1;
			break;
		case 's':
			check_signature = 1;
			break;
		case 't':
			limit_vul_types = optarg;
			break;
		default:
			usage();
			/* NOTREACHED */
		}
	}
}

static int
check_exact_pkg(const char *pkg)
{
	const char *iter, *next;
	int ret;
	size_t i;

	ret = 0;
	for (i = 0; i < pv->entries; ++i) {
		if (ignore_advisories != NULL) {
			size_t url_len = strlen(pv->advisory[i]);
			size_t entry_len;

			for (iter = ignore_advisories; *iter; iter = next) {
				if ((next = strchr(iter, '\n')) == NULL) {
					entry_len = strlen(iter);
					next = iter + entry_len;
				} else {
					entry_len = next - iter;
					++next;
				}
				if (url_len != entry_len)
					continue;
				if (!strncmp(pv->advisory[i], iter, entry_len))
					break;
			}
			if (*iter != '\0')
				continue;
		}
		if (limit_vul_types != NULL &&
		    strcmp(limit_vul_types, pv->classification[i]))
			continue;
		if (!pkg_match(pv->vulnerability[i], pkg))
			continue;
		if (strcmp("eol", pv->classification[i]) == 0) {
			if (!check_eol)
				continue;
			if (quiet)
				puts(pkg);
			else
				printf("Package %s has reached end-of-life (eol), "
				    "see %s/eol-packages\n", pkg,
				    tnf_vulnerability_base);
			continue;
		}
		if (quiet)
			puts(pkg);
		else
			printf("Package %s has a %s vulnerability, see %s\n",
			    pkg, pv->classification[i], pv->advisory[i]);
		ret = 1;
	}
	return ret;
}

static int
check_batch_exact_pkgs(const char *fname)
{
	FILE *f;
	char buf[4096], *line, *eol;
	int ret;

	ret = 0;
	if (strcmp(fname, "-") == 0)
		f = stdin;
	else {
		f = fopen(fname, "r");
		if (f == NULL)
			err(EXIT_FAILURE, "Failed to open input file %s",
			    fname);
	}
	while ((line = fgets(buf, sizeof(buf), f)) != NULL) {
		eol = line + strlen(line);
		if (eol == line)
			continue;
		--eol;
		if (*eol == '\n') {
			if (eol == line)
				continue;
			*eol = '\0';
		}
		ret |= check_exact_pkg(line);
	}
	if (f != stdin)
		fclose(f);

	return ret;
}

static int
check_one_installed_pkg(const char *pkg, void *cookie)
{
	int *ret = cookie;

	*ret |= check_exact_pkg(pkg);
	return 0;
}

static int
check_installed_pattern(const char *pattern)
{
	int ret = 0;

	match_installed_pkgs(pattern, check_one_installed_pkg, &ret);

	return ret;
}

static void
check_and_read_pkg_vulnerabilities(void)
{
	struct stat st;
	time_t now;

	if (pkg_vulnerabilities_file == NULL)
		errx(EXIT_FAILURE, "PKG_VULNERABILITIES is not set");

	if (verbose >= 1) {
		if (stat(pkg_vulnerabilities_file, &st) == -1) {
			if (errno == ENOENT)
				errx(EXIT_FAILURE,
				    "pkg-vulnerabilities not found, run %s -d",
				    getprogname());
			errx(EXIT_FAILURE, "pkg-vulnerabilities not readable");
		}
		now = time(NULL);
		now -= st.st_mtime;
		if (now < 0)
			warnx("pkg-vulnerabilities is from the future");
		else if (now > 86400 * 7)
			warnx("pkg-vulnerabilities is out of day (%d days old)",
			    now / 86400);
		else if (verbose >= 2)
			warnx("pkg-vulnerabilities is %d day%s old",
			    now / 86400, now / 86400 == 1 ? "" : "s");
	}

	pv = read_pkg_vulnerabilities(pkg_vulnerabilities_file, 0, check_signature);
}

void
audit_pkgdb(int argc, char **argv)
{
	int rv;

	parse_options(argc, argv);
	argv += optind;

	check_and_read_pkg_vulnerabilities();

	rv = 0;
	if (*argv == NULL)
		rv |= check_installed_pattern("*");
	else {
		for (; *argv != NULL; ++argv)
			rv |= check_installed_pattern(*argv);
	}
	free_pkg_vulnerabilities(pv);

	if (rv == 0 && verbose >= 1)
		fputs("No vulnerabilities found\n", stderr);
	exit(rv ? EXIT_FAILURE : EXIT_SUCCESS);
}

void
audit_pkg(int argc, char **argv)
{
	int rv;

	parse_options(argc, argv);
	argv += optind;

	check_and_read_pkg_vulnerabilities();
	rv = 0;
	for (; *argv != NULL; ++argv)
		rv |= check_exact_pkg(*argv);

	free_pkg_vulnerabilities(pv);

	if (rv == 0 && verbose >= 1)
		fputs("No vulnerabilities found\n", stderr);
	exit(rv ? EXIT_FAILURE : EXIT_SUCCESS);
}

void
audit_batch(int argc, char **argv)
{
	int rv;

	parse_options(argc, argv);
	argv += optind;

	check_and_read_pkg_vulnerabilities();
	rv = 0;
	for (; *argv != NULL; ++argv)
		rv |= check_batch_exact_pkgs(*argv);
	free_pkg_vulnerabilities(pv);

	if (rv == 0 && verbose >= 1)
		fputs("No vulnerabilities found\n", stderr);
	exit(rv ? EXIT_FAILURE : EXIT_SUCCESS);
}

void
check_pkg_vulnerabilities(int argc, char **argv)
{
	parse_options(argc, argv);
	if (argc != optind + 1)
		usage();

	pv = read_pkg_vulnerabilities(argv[optind], 0, check_signature);
	free_pkg_vulnerabilities(pv);
}

void
fetch_pkg_vulnerabilities(int argc, char **argv)
{
	struct pkg_vulnerabilities *pv_check;
	const char *error;
	pid_t child;
	char *buf, *decompressed_input;
	size_t buf_len, cur_len, decompressed_len;
	ssize_t bytes_read;
	int fd[2], status;

	parse_options(argc, argv);
	if (argc != optind)
		usage();

	if (verbose >= 2)
		fprintf(stderr, "ftp -o - %s\n", pkg_vulnerabilities_url);

	if (pipe(fd) == -1)
		err(EXIT_FAILURE, "cannot create FTP data pipe");

	child = vfork();
	if (child == -1)
		err(EXIT_FAILURE, "cannot fork FTP process");
	if (child == 0) {
		close(fd[0]);
		close(STDOUT_FILENO);
		if (dup2(fd[1], STDOUT_FILENO) == -1) {
			static const char err_msg[] =
			    "cannot redirect stdout of FTP process\n";
			write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
			_exit(255);
		}
		close(fd[1]);
		execlp(fetch_cmd, fetch_cmd, "-o", "-",
		    pkg_vulnerabilities_url, (char *)NULL);
		_exit(255);
	}
	close(fd[1]);

	cur_len = 0;
	buf_len = 32768;
	if ((buf = malloc(buf_len + 1)) == NULL) {
		error = "malloc failed";
		goto ftp_error;
	}

	while ((bytes_read = read(fd[0], buf + cur_len, buf_len - cur_len)) > 0) {
		cur_len += bytes_read;
		if (cur_len * 2 < buf_len)
			continue;
		if (cur_len >= SSIZE_MAX / 2) {
			error = "pkg-vulnerabilies too large";
			goto ftp_error;
		}
		buf_len *= 2;
		if ((buf = realloc(buf, buf_len + 1)) == NULL) {
			error = "realloc failed";
			goto ftp_error;
		}
	}

	if (bytes_read == -1) {
		error = "read from FTP process failed";
		goto ftp_error;
	}

	waitpid(child, &status, 0);
	close(fd[0]);

	if (status)
		errx(EXIT_FAILURE,
		    "Download of pkg-vulnerabilities from %s failed",
		    pkg_vulnerabilities_url);

	buf[cur_len] = '\0';

	if (decompress_buffer(buf, cur_len, &decompressed_input,
	    &decompressed_len)) {
		pv_check = parse_pkg_vulnerabilities(decompressed_input,
		    decompressed_len, check_signature);
		free(decompressed_input);
	} else {
		pv_check = parse_pkg_vulnerabilities(buf, cur_len,
		    check_signature);
	}
	free_pkg_vulnerabilities(pv_check);

	fd[0] = open(pkg_vulnerabilities_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0] == -1)
		err(EXIT_FAILURE, "Cannot create pkg-vulnerability file %s",
		    pkg_vulnerabilities_file);

	if (write(fd[0], buf, cur_len) != cur_len)
		err(EXIT_FAILURE, "Cannot write pkg-vulnerability file");
	if (close(fd[0]) == -1)
		err(EXIT_FAILURE, "Cannot close pkg-vulnerability file after write");

	free(buf);

	exit(EXIT_SUCCESS);

 ftp_error:
	(void)kill(child, SIGTERM);
	(void)close(fd[0]);
	(void)waitpid(child, &status, 0);
	err(EXIT_FAILURE, error);
}
