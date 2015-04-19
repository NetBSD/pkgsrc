/* $NetBSD: common.c,v 1.4 2015/04/19 13:30:35 tnn Exp $ */

/*-
 * Copyright (c) 2009 Joerg Sonnenberger <joerg@NetBSD.org>.
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

#include <nbcompat.h>
#include <sys/wait.h>
#include <nbcompat/err.h>
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common.h"

static char *worklog_path;
static char *real_path;
char *exec_path;
char *exec_name;
char *wrksrc;
int debug;

static struct arglist prepend_args = TAILQ_HEAD_INITIALIZER(prepend_args);
static struct arglist append_args = TAILQ_HEAD_INITIALIZER(append_args);
struct argument *prepend_after;

const char library_name_chars[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "01234567890-_";

char *
concat(const char *s1, const char *s2)
{
	size_t len1, len2;
	char *output;

	len1 = strlen(s1);
	len2 = strlen(s2);

	output = xmalloc(len1 + len2 + 1);
	memcpy(output, s1, len1);
	memcpy(output + len1, s2, len2);
	output[len1 + len2] = '\0';

	return output;
}

char *
concat2(const char *s1, const char *s2, size_t len2)
{
	size_t len1;
	char *output;

	len1 = strlen(s1);

	output = xmalloc(len1 + len2 + 1);
	memcpy(output, s1, len1);
	memcpy(output + len1, s2, len2);
	output[len1 + len2] = '\0';

	return output;
}

struct argument *
argument_new(char *str)
{
	struct argument *arg;

	arg = xmalloc(sizeof(*arg));
	arg->val = str;

	return arg;
}

struct argument *
argument_copy(const char *str)
{
	struct argument *arg;

	arg = xmalloc(sizeof(*arg));
	arg->val = xstrdup(str);

	return arg;
}

void
argument_update(struct argument *arg, char *str)
{
	free(arg->val);
	arg->val = str;
}

void
arglist_from_argc(struct arglist *args, int argc, char **argv)
{
	struct argument *arg;

	TAILQ_INIT(args);

	for (--argc, ++argv; argc; --argc, ++argv) {
		if (**argv == '\0')
			continue;
		arg = argument_copy(*argv);
		TAILQ_INSERT_TAIL(args, arg, link);		
	}
}

void
arglist_apply_config(struct arglist *args)
{
	struct argument *arg, *arg2;

	if (prepend_after) {
		TAILQ_FOREACH(arg, &prepend_args, link) {
			arg2 = argument_copy(arg->val);
			TAILQ_INSERT_AFTER(args, prepend_after, arg2, link);
		}
	} else {
		TAILQ_FOREACH_REVERSE(arg, &prepend_args, arglist, link) {
			arg2 = argument_copy(arg->val);
			TAILQ_INSERT_HEAD(args, arg2, link);
		}
	}
	TAILQ_FOREACH(arg, &append_args, link) {
		arg2 = argument_copy(arg->val);
		TAILQ_INSERT_TAIL(args, arg2, link);
	}
}

void
argument_unlink(struct arglist *args, struct argument **argp)
{
	struct argument *arg;

	arg = *argp;
	*argp = TAILQ_NEXT(arg, link);

	TAILQ_REMOVE(args, arg, link);
	free(arg->val);
	free(arg);
}

void
parse_config(const char *wrapper)
{
	const char *config_dir;
	char *config_file, *line;
	size_t len;
	ssize_t llen;
	FILE *fp;

	config_dir = getenv("CWRAPPERS_CONFIG_DIR");
	if (config_dir == NULL)
		errx(255, "CWRAPPERS_CONFIG_DIR is missing from environment");

	config_file = xasprintf("%s/%s", config_dir, wrapper);
	fp = fopen(config_file, "r");
	if (fp == NULL)
		errx(255, "Failed to open wrapper config file `%s'",
		    config_file);

	for (len = 0, line = NULL; (llen = getline(&line, &len, fp)) > 0;
	     free(line), line = NULL, len = 0) {
		if (line[llen - 1] == '\n') {
			line[llen - 1] = '\0';
			--llen;
		}
		if (strncmp(line, "worklog=", 8) == 0) {
			free(worklog_path);
			worklog_path = xstrdup(line + 8);
			continue;
		}
		if (strncmp(line, "path=", 5) == 0) {
			free(real_path);
			real_path = xstrdup(line + 5);
			continue;
		}
		if (strncmp(line, "exec_path=", 10) == 0) {
			free(exec_path);
			exec_path = xstrdup(line + 10);
			continue;
		}
		if (strncmp(line, "exec=", 5) == 0) {
			free(exec_name);
			exec_name = xstrdup(line + 5);
			continue;
		}
		if (strncmp(line, "reorder=", 8) == 0) {
			register_reorder(line + 8);
			continue;
		}
		if (strncmp(line, "transform=", 10) == 0) {
			register_generic_transform(line + 10);
			continue;
		}
		if (strncmp(line, "prepend=", 8) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 8);
			TAILQ_INSERT_TAIL(&prepend_args, arg, link);
		}
		if (strncmp(line, "append=", 7) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 7);
			TAILQ_INSERT_TAIL(&append_args, arg, link);
		}
		if (strncmp(line, "wrksrc=", 7) == 0) {
			free(wrksrc);
			wrksrc = xstrdup(line + 7);
			continue;
		}
		if (strncmp(line, "unwrap=", 7) == 0) {
			register_unwrap(line + 7);
			continue;
		}
		if (strncmp(line, "debug=", 6) == 0) {
			debug = atoi(line + 6);
			continue;
		}
	}

	fclose(fp);

	if (worklog_path == NULL)
		errx(255, "worklog path has not been set");
	if (exec_name == NULL)
		errx(255, "executable name has not been set");
	if (exec_path == NULL)
		errx(255, "executable path has not been set");
}

FILE *
worklog_open(void)
{
	FILE *fp;

	fp = fopen(worklog_path, "a");
	if (fp == NULL)
		err(255, "Could not open %s", worklog_path);

	return fp;
}

void
worklog_cmd(FILE *worklog, const char *prefix, const char *cmd,
    struct arglist *args)
{
	static const char safe_chars[] =
	    "abcdefghijklmnopqrstuvwxyz"
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "01234567890-_/:.,+=";
	struct argument *arg;
	size_t len, buflen;
	char *buf;

	fprintf(worklog, "%s %s", prefix, cmd);	

	buf = NULL;
	buflen = 0;
	TAILQ_FOREACH(arg, args, link) {
		len = strlen(arg->val);
		if (len == 0) {
			fputs(" ''", worklog);
			continue;
		}
		if (strspn(arg->val, safe_chars) == len) {
			fputc(' ', worklog);
			fputs(arg->val, worklog);
			continue;
		}
		len = shquote(arg->val, buf, buflen);
		if (len >= buflen) {
			buflen = len + 1;
			free(buf);
			buf = xmalloc(buflen);
			shquote(arg->val, buf, buflen);
		}
		fputc(' ', worklog);
		fputs(buf, worklog);
	}

	fputc('\n', worklog);

	if (buf)
		free(buf);
}

int
command_exec(struct arglist *args, int do_fork)
{
	struct argument *arg;
	static const char failed_exec_msg[] = "exec failed\n";
	char **argv, **argv2;
	int argc, status;
	pid_t child;

	argc = 2;
	TAILQ_FOREACH(arg, args, link)
		++argc;

	argv2 = xmalloc(sizeof(void *) * argc);
	argv2[0] = exec_name;
	argv = argv2 + 1;
	TAILQ_FOREACH(arg, args, link)
		*argv++ = arg->val;
	*argv = NULL;

	if (real_path)
		setenv("PATH", real_path, 1);

	if (do_fork)
		child = vfork();
	else
		child = 0;

	switch (child) {
	case 0:
		execvp(exec_name, argv2);
		status = write(STDERR_FILENO, failed_exec_msg,
		    sizeof(failed_exec_msg) - 1);
		_exit(255 | status);
	case -1:
		err(255, "fork failed");
	default:
		waitpid(child, &status, 0);
		return WEXITSTATUS(status);
	}
}

size_t
wrapper_hash(const char *str)
{
	return wrapper_hash2(str, strlen(str));
}

size_t
wrapper_hash2(const char *str, size_t len)
{
	uint32_t hashes[3];

	mi_vector_hash(str, len, 0xdeadbeef, hashes);
	return hashes[0];
}
