/* $NetBSD: common.c,v 1.7 2017/06/11 19:34:43 joerg Exp $ */

/*-
 * Copyright (c) 2009, 2017 Joerg Sonnenberger <joerg@NetBSD.org>.
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
#include "config.h"
#include <sys/wait.h>
#include <nbcompat/err.h>
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <string.h>
#include <unistd.h>
#if defined(HAVE_POSIX_SPAWNP) && defined(HAVE_SPAWN_H)
#include <spawn.h>
#endif

#include "common.h"

static char *worklog_path;
static char *real_path;
char *exec_path;
char *exec_name;
char *wrksrc;
int debug;
enum operation_mode current_operation_mode = mode_unknown;

static struct arglist prepend_args = TAILQ_HEAD_INITIALIZER(prepend_args);
static struct arglist append_args = TAILQ_HEAD_INITIALIZER(append_args);
static struct arglist prepend_executable_args =
   TAILQ_HEAD_INITIALIZER(prepend_executable_args);
static struct arglist append_executable_args =
   TAILQ_HEAD_INITIALIZER(append_executable_args);
static struct arglist prepend_shared_args =
   TAILQ_HEAD_INITIALIZER(prepend_shared_args);
static struct arglist append_shared_args =
   TAILQ_HEAD_INITIALIZER(append_shared_args);
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

static void
arglist_prepend_list(struct arglist *args, struct arglist *prepends)
{
	struct argument *arg, *arg2;

	if (prepend_after) {
		TAILQ_FOREACH(arg, prepends, link) {
			arg2 = argument_copy(arg->val);
			TAILQ_INSERT_AFTER(args, prepend_after, arg2, link);
		}
	} else {
		TAILQ_FOREACH_REVERSE(arg, prepends, arglist, link) {
			arg2 = argument_copy(arg->val);
			TAILQ_INSERT_HEAD(args, arg2, link);
		}
	}
}

static void
arglist_append_list(struct arglist *args, struct arglist *appends)
{
	struct argument *arg, *arg2;

	TAILQ_FOREACH(arg, appends, link) {
		arg2 = argument_copy(arg->val);
		TAILQ_INSERT_TAIL(args, arg2, link);
	}
}

void
arglist_apply_config(struct arglist *args)
{
	arglist_prepend_list(args, &prepend_args);
	arglist_append_list(args, &append_args);

	switch (current_operation_mode) {
	default:
		break;
	case mode_link_executable:
		arglist_prepend_list(args, &prepend_executable_args);
		arglist_append_list(args, &append_executable_args);
		break;
	case mode_link_shared:
		arglist_prepend_list(args, &prepend_shared_args);
		arglist_append_list(args, &prepend_shared_args);
		break;
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
		if (strncmp(line, "prepend_executable=", 19) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 19);
			TAILQ_INSERT_TAIL(&prepend_executable_args, arg, link);
		}
		if (strncmp(line, "append_executable=", 18) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 18);
			TAILQ_INSERT_TAIL(&append_executable_args, arg, link);
		}
		if (strncmp(line, "prepend_shared=", 15) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 15);
			TAILQ_INSERT_TAIL(&prepend_shared_args, arg, link);
		}
		if (strncmp(line, "append_shared=", 14) == 0) {
			struct argument *arg;
			arg = argument_copy(line + 14);
			TAILQ_INSERT_TAIL(&append_shared_args, arg, link);
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

#if __GNUC__ + 0 >= 3
__attribute__((__noreturn__))
#endif
static void
command_child_exec(char **argv)
{
	static const char failed_exec_msg[] = "exec failed\n";
	int status;

	execvp(exec_name, argv);
	status = write(STDERR_FILENO, failed_exec_msg,
	    sizeof(failed_exec_msg) - 1);
	_exit(255 | status);
}

int
command_exec(struct arglist *args, int do_fork, char **environment)
{
	struct argument *arg;
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

	if (!do_fork)
		command_child_exec(argv2);

#if defined(HAVE_POSIX_SPAWNP) && defined(HAVE_SPAWN_H)
	status = posix_spawnp(&child, exec_name, NULL, NULL, argv2,
	    environment);
	if (status) {
		errno = status;
		err(255, "posix_spawn failed");
	}
#else
	child = vfork();

	if (child == -1)
		err(255, "fork failed");
	if (child == 0)
		command_child_exec(argv2);
#endif
	waitpid(child, &status, 0);
	return WEXITSTATUS(status);
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
