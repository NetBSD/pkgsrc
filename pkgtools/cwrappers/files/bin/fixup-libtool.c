/* $NetBSD: fixup-libtool.c,v 1.6 2015/04/19 13:30:35 tnn Exp $ */

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
#include <nbcompat/stdio.h>
#include <sys/stat.h>
#include <err.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "common.h"

#define	LIBPATH_HASH	256

struct unwrap_rule {
	TAILQ_ENTRY(unwrap_rule) link;
	char *src;
	char *dst;
	size_t src_len;
};

TAILQ_HEAD(unwrap_ruleset, unwrap_rule);

static struct unwrap_ruleset unwrap_rules =
    TAILQ_HEAD_INITIALIZER(unwrap_rules);

void
register_unwrap(const char *rule)
{
	const char *sep;
	struct unwrap_rule *r;

	sep = strchr(rule, ':');
	if (sep == NULL)
		goto failure;
	if (strchr(sep + 1, ':') != NULL)
		goto failure;

	r = xmalloc(sizeof(*r));
	r->src = xstrndup(rule, sep - rule);
	if (sep[1])
		r->dst = xstrdup(sep + 1);
	else
		r->dst = NULL;
	r->src_len = sep - rule;

	TAILQ_INSERT_TAIL(&unwrap_rules, r, link);

	return;

failure:
	errx(255, "Invalid transform rule: %s", rule);
}

struct processing_option {
	FILE *output;
	const char *lafile;
	struct arglist hashtab[LIBPATH_HASH];
	int first;
	int in_lai;
	int in_relink;
	const char *last_opt;
	size_t last_len;
};

static void
process_option(struct processing_option *opt, const char *line, size_t len,
    int in_relink)
{
	struct unwrap_rule *r;
	struct argument *arg;
	char *tmp;
	const char *eol;
	size_t i, wlen;

	if (opt->in_lai && opt->last_opt && opt->last_len == len &&
	    strncmp(opt->last_opt, line, len) == 0)
		return;
	if (len >= 11 && strncmp(line, "-Wl,-rpath,", 11) == 0) {
		if (in_relink)
			goto print_option;
		return;
	}
	if (len >= 15 && strncmp(line, "-Wl,-rpath-link,", 15) == 0) {
		if (in_relink)
			goto print_option;
		return;
	}
	if (len > 2 && strncmp(line, "-D", 2) == 0)
		return; /* No preprocessor options */
	if (len > 2 && strncmp(line, "-I", 2) == 0)
		return; /* No preprocessor options */

	if (len >= 2 && strncmp(line, "-L", 2) == 0) {
		if (opt->in_lai) {
			TAILQ_FOREACH(r, &unwrap_rules, link) {
				if (len - 2 < r->src_len)
					continue;
				if (strncmp(line + 2, r->src, r->src_len))
					continue;
				if (line[r->src_len + 2] != '/' &&
				    len != r->src_len + 2)
					continue;
				line += r->src_len + 2;
				len -= r->src_len + 2;
				tmp = xasprintf("-L%s%*.*s", r->dst,
				    (int)len, (int)len, line);
				process_option(opt, tmp, strlen(tmp),
				    in_relink);
				free(tmp);
				return;
			}
			if (wrksrc) {
				wlen = strlen(wrksrc);

				if (wlen <= len - 2 &&
				    strncmp(line + 2, wrksrc, wlen) == 0 &&
				    (line[wlen + 2] == '/' || wlen + 2 == len))
					return;
			}
		}
		i = wrapper_hash2(line, len) & (LIBPATH_HASH - 1);
		TAILQ_FOREACH(arg, opt->hashtab + i, link) {
			if (strncmp(arg->val, line, len) == 0 &&
			    arg->val[len] == '\0')
				break;
		}
		if (arg != NULL)
			return;

		arg = argument_new(xstrndup(line, len));
		TAILQ_INSERT_TAIL(opt->hashtab + i, arg, link);

		goto print_option;
	}

	opt->last_opt = line;
	opt->last_len = len;

	if (len < 3 || strncmp(line + len - 3, ".la", 3))
		goto print_option;

	for (eol = line + len - 3; eol > line; --eol) {
		if (*eol == '/')
			break;
	}

	if (opt->in_lai && *eol == '/') {
		TAILQ_FOREACH(r, &unwrap_rules, link) {
			if (eol < line + r->src_len)
				continue;
			if (strncmp(line, r->src, r->src_len))
				continue;
			if (line[r->src_len] != '/')
				continue;
			line += r->src_len;
			len -= r->src_len;
			if (strncmp(eol + 1, "lib", 3) == 0) {
				tmp = xasprintf("-L%s%*.*s", r->dst,
				    (int)(eol - line), (int)(eol - line), line);
				process_option(opt, tmp, strlen(tmp),
				    in_relink);
				free(tmp);
				eol += 4;
				len = line + len - eol - 3;
				fprintf(opt->output, " -l%*.*s", (int)len,
				    (int)len, eol);
			} else {
				tmp = xasprintf("%s%*.*s", r->dst,
				    (int)len, (int)len, line);
				process_option(opt, tmp, strlen(tmp),
				    in_relink);
				free(tmp);
			}
			return;
		}
	}

	if (!opt->in_relink)
		goto print_option;

	if (opt->lafile && strncmp(opt->lafile, line, len) == 0 &&
	    len == strlen(opt->lafile))
		goto print_option;

	if (*line != '/' && line == eol) {
		process_option(opt, "-L./.libs", 9, in_relink);
		goto print_option;
	}

	if (*line != '/') {
		tmp = xasprintf("-L%*.*s/.libs", (int)(eol - line),
		    (int)(eol - line), line);
		process_option(opt, tmp, strlen(tmp), in_relink);
		free(tmp);
		goto print_option;
	}

	if (wrksrc == NULL)
		goto print_option;

	wlen = strlen(wrksrc);
	if (wlen > len ||
	    (wlen != len && line[wlen] != '/') ||
	    strncmp(wrksrc, line, wlen))
		goto print_option;

	tmp = xasprintf("-L%*.*s/.libs", (int)(eol - line),
	    (int)(eol - line), line);
	process_option(opt, tmp, strlen(tmp), in_relink);
	free(tmp);

print_option:
	if (opt->first)
		opt->first = 0;
	else
		putc(' ', opt->output);
	fwrite(line, len, 1, opt->output);
}

static void
process_variable(FILE *output, const char *lafile, const char *line,
    int in_lai, int in_relink)
{
	struct processing_option opt;
	size_t len, len2;
	struct argument *arg;
	size_t i;
	const char *command;

	for (i = 0; i < LIBPATH_HASH; ++i)
		TAILQ_INIT(opt.hashtab + i);

	opt.output = output;
	opt.lafile = lafile;
	opt.in_lai = in_lai;
	opt.in_relink = in_relink;
	opt.last_opt = NULL;
	opt.last_len = 0;

	if (in_relink) {
		command = strchr(line, ';');
		if (command == NULL)
			errx(255, "Unrecognizable relink format");
		++command;
		fwrite(line, command - line, 1, output);
		fprintf(output, " %s", exec_path);

		/* XXX document this logic */
		line = command + 1;
		len = strspn(line, " \t");
		line += len;
		len2 = len = strcspn(line, " \t");
		command = line;
		if (len == 0)
			errx(255, "Unrecognizable relink format");
		line += len;
		len = strspn(line, " \t");
		line += len;
		if (len2 != 7 || strncmp(command, "libtool", 7)) {
			len = strcspn(line, " \t");
			if (len == 0)
				errx(255, "Unrecognizable relink format");
			line += len;
			len = strspn(line, " \t");
			line += len;
		}
	}

	for (opt.first = !in_relink; *line ; line += len) {
		len = strspn(line, " \t");
		line += len;
		len = strcspn(line, " \t");
		if (len == 0)
			break;
		process_option(&opt, line, len, in_relink);
	}

	for (i = 0; i < LIBPATH_HASH; ++i) {
		while ((arg = TAILQ_FIRST(opt.hashtab + i)) != NULL)
			argument_unlink(opt.hashtab + i, &arg);
	}
}

static void
fixup_libtool_la(const char *lafile, int in_lai)
{
	static const char dep_lib[] = "dependency_libs='";
	static const char relink_cmd[] = "relink_command=\"";
	static const char relink_marker_cmd[] = "# buildlink modification\n";
	struct stat st;
	FILE *fp, *output;
	char *line, *opt_start, *tmp_name;
	const char *pass_lafile, *cur_option;
	int in_relink, ignore_relink = 0;
	char delimiter;
	size_t len;
	ssize_t cur;

	fp = fopen(lafile, "r");
	if (fp == NULL)
		return;
	if (fstat(fileno(fp), &st))
		err(255, "fstat('%s') failed", lafile);
	if ((st.st_mode & S_IFMT) != S_IFREG) {
		fclose(fp);
		return;
	}

	tmp_name = concat(lafile, ".tmp");
	output = fopen(tmp_name, "w");
	if (output == NULL)
		err(255, "fopen('%s') failed", tmp_name);

	line = NULL;
	len = 0;
	while ((cur = getline(&line, &len, fp)) > 0) {
		if (strcmp(line, relink_marker_cmd) == 0) {
			fwrite(line, 1, cur, output);
			ignore_relink = 1;
			continue;
		}
		if (strncmp(line, relink_cmd, sizeof(relink_cmd) - 1) == 0) {
			if (ignore_relink) {
				fwrite(line, 1, cur, output);
				ignore_relink = 0;
				continue;
			}
			cur_option = relink_cmd;
			opt_start = line + sizeof(relink_cmd) - 1;
			pass_lafile = lafile;
			delimiter='\"';
			in_relink = 1;
			ignore_relink = 0;
		} else if (strncmp(line, dep_lib, sizeof(dep_lib) - 1) == 0) {
			cur_option = dep_lib;
			opt_start = line + sizeof(dep_lib) - 1;
			pass_lafile = NULL;
			delimiter='\'';
			in_relink = 0;
			ignore_relink = 0;
		} else {
			fwrite(line, 1, cur, output);
			ignore_relink = 0;
			continue;
		}

		if (line[cur - 2] != delimiter || line[cur - 1] != '\n')
			errx(255, "corrupted libtool archive '%s'", lafile);
		if (debug) {
			fputs("# buildlink modification, original:\n# ",
			    output);
			fwrite(line, 1, cur, output);
		} else {
			fputs(relink_marker_cmd, output);
		}
		fputs(cur_option, output);
		line[cur - 2] = '\0';
		process_variable(output, pass_lafile, opt_start, in_lai,
		    in_relink);
		fprintf(output, "%c\n", delimiter);
	}
	free(line);

	if (ferror(fp) || fclose(fp) ||
	    ferror(output) || fclose(output) ||
	    rename(tmp_name, lafile)) {
		unlink(tmp_name);
		err(255, "output processing failed");
	}		
}

void
fixup_libtool(struct arglist *args)
{
	struct argument *arg, *arg2;
	const char *slash;
	char *laifile;
	size_t len;

	TAILQ_FOREACH(arg, args, link) {
		if (strcmp(arg->val, "-o"))
			continue;
		arg2 = TAILQ_NEXT(arg, link);
		if (arg2 == NULL || arg2->val[0] == '-')
			errx(255, "Missing argument for option -o");
		arg = arg2;
		len = strlen(arg->val);
		if (len < 3)
			continue;
		if (strcmp(arg->val + len - 3, ".la") == 0)
			break;
	}
	if (arg == NULL)
		return;

	fixup_libtool_la(arg->val, 0);
	slash = strrchr(arg->val, '/');
	if (slash == NULL)
		laifile = xasprintf("./.libs/%si", arg->val);
	else
		laifile = xasprintf("%*.*s/.libs/%si",
		    (int)(slash - arg->val), (int)(slash - arg->val),
		    arg->val, slash + 1);
	fixup_libtool_la(laifile, 1);
	free(laifile);
}
