/* $NetBSD: check-portability.c,v 1.12 2020/03/21 15:02:20 rillig Exp $ */

/*
 Copyright (c) 2020 Roland Illig
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr ((void *) 0)
static const size_t npos = -1;

static bool
is_alnum(char c)
{
	return isalnum((unsigned char) c) != 0;
}

static bool
is_hspace(char c)
{
	return c == ' ' || c == '\t';
}

// cstr is a constant string view.
typedef struct {
	const char *data; // never nullptr
	size_t len;
} cstr;

#define CSTR(str) ((cstr) { str, strlen(str) })

static const char *
cstr_charptr(cstr s)
{
	assert(memchr(s.data, 0, s.len) == nullptr);
	assert(s.data[s.len] == '\0');
	return s.data;
}

#if 0 /* unused */
static bool
cstr_ends_with(cstr s, cstr suffix)
{
	if (suffix.len > s.len)
		return false;
	const char *start = s.data + s.len - suffix.len;
	return memcmp(start, suffix.data, suffix.len) == 0;
}
#endif

static bool
cstr_starts_with(cstr s, cstr prefix)
{
	if (prefix.len > s.len)
		return false;
	return memcmp(s.data, prefix.data, prefix.len) == 0;
}

static cstr
cstr_substr(cstr s, size_t start, size_t end)
{
	assert(start <= s.len);
	assert(end <= s.len);
	assert(end - start <= s.len);
	return (cstr) { s.data + start, end - start };
}

static size_t
cstr_index(cstr haystack, cstr needle)
{
	if (needle.len > haystack.len)
		return npos;
	size_t limit = haystack.len - needle.len;
	for (size_t i = 0; i <= limit; i++)
		if (memcmp(haystack.data + i, needle.data, needle.len) == 0)
			return i;
	return npos;
}

static bool
cstr_contains_char(cstr haystack, char needle)
{
	return memchr(haystack.data, needle, haystack.len);
}

static bool
cstr_contains(cstr haystack, cstr needle)
{
	return cstr_index(haystack, needle) != npos;
}

static size_t
cstr_rindex(cstr haystack, cstr needle)
{
	if (needle.len > haystack.len)
		return npos;
	size_t limit = haystack.len - needle.len;
	for (size_t i = limit + 1; i-- > 0; )
		if (memcmp(haystack.data + i, needle.data, needle.len) == 0)
			return i;
	return npos;
}

static bool
cstr_eq(cstr s1, cstr s2)
{
	return s1.len == s2.len
	    && memcmp(s1.data, s2.data, s1.len) == 0;
}

static cstr
cstr_next_field(cstr line, size_t *pidx)
{
	size_t idx = *pidx;
	while (idx < line.len && is_hspace(line.data[idx]))
		idx++;
	size_t start = idx;
	while (idx < line.len && !is_hspace(line.data[idx]))
		idx++;
	*pidx = idx;
	return cstr_substr(line, start, idx);
}

static cstr
cstr_right_of_last(cstr s, cstr delimiter)
{
	size_t i = cstr_rindex(s, delimiter);
	if (i == npos)
		return s;
	return cstr_substr(s, i + delimiter.len, s.len);
}

static bool
cstr_has_word_boundary(cstr s, size_t idx)
{
	assert(idx <= s.len);
	if (idx == 0 || idx == s.len)
		return true;
	return is_alnum(s.data[idx - 1]) != is_alnum(s.data[idx]);
}

// str is a modifiable string buffer.
typedef struct {
	char *data;
	size_t len;
	size_t cap;
} str;

#define STR_EMPTY { nullptr, 0, 0 }

static cstr
str_c(str *s)
{
	return (cstr) { s->data == nullptr ? "" : s->data, s->len };
}

static void
str_free(str *s)
{
	free(s->data);
}

static void
str_reserve(str *s, size_t n)
{
	size_t req_len = s->len + n;
	assert(req_len >= s->len);
	if (req_len <= s->cap)
		return;

	size_t new_cap = s->cap == 0 ? 64 : 2 * s->cap;
	if (new_cap == 0)
		new_cap = -1;

	char *new_data = realloc(s->data, new_cap);
	if (new_data == nullptr) {
		perror(nullptr);
		exit(EXIT_FAILURE);
	}

	s->data = new_data;
	s->cap = new_cap;
}

static void
str_append_char(str *s, char c)
{
	str_reserve(s, 1);
	s->data[s->len++] = c;
}

static const char *
str_charptr(str *s)
{
	str_reserve(s, 1);
	s->data[s->len] = '\0';
	assert(memchr(s->data, '\0', s->len) == nullptr);
	return s->data;
}

static bool
str_read_line(str *s, FILE *f)
{
	int c;

	s->len = 0;
	while ((c = fgetc(f)) != EOF && c != '\n' && c != '\r') {
		str_append_char(s, (char) c);
	}
	return c != EOF;
}

static bool
str_read_text_line(str *s, FILE *f)
{
	int c;

	s->len = 0;
	while ((c = fgetc(f)) > '\0' && c != '\n' && c != '\r') {
		str_append_char(s, (char) c);
	}
	assert(c != '\0');
	return c != EOF;
}

typedef enum {
	W_how_to_fix,
	W_dollar_random,
	W_test_eqeq,
	W_double_bracket
} warning_kind;

static unsigned long explained = 0;

static void
explain(warning_kind warning, ...)
{
	unsigned long mask = 1UL << warning;
	if ((explained & mask) != 0)
		return;
	explained |= mask;

	va_list args;
	va_start(args, warning);
	printf("\n");
	const char *line;
	while ((line = va_arg(args, const char *)) != nullptr)
		printf("%s%s\n", line[0] == '\0' ? "" : "\t", line);
	printf("\n");
	va_end(args);
}

static void
explain_how_to_fix(void)
{
	explain(
	    W_how_to_fix,
	    "To fix this message, decide whether this file is necessary",
	    "for the package to build. Then choose any of these variants:",
	    "",
	    "1.  Add a patch for the file",
	    "    (see https://www.netbsd.org/docs/pkgsrc/pkgsrc.html#components.patches)",
	    "2.  Add a SUBST block for the file to the package Makefile",
	    "    (see mk/subst.mk)",
	    "3.  Add CHECK_PORTABILITY_SKIP+= shell/glob to the package Makefile",
	    "    (see mk/check/check-portability.mk)",
	    nullptr);
}

static size_t
index_opening_brackets(cstr s)
{
	size_t index = cstr_index(s, CSTR("[["));
	if (index == npos)
		return npos;
	if (index > 0 && !is_hspace(s.data[index - 1]))
		return npos;
	if (index + 2 < s.len && !is_hspace(s.data[index + 2]))
		return npos;
	return index;
}

static size_t
index_closing_brackets(cstr s)
{
	size_t index = cstr_index(s, CSTR("]]"));
	if (index == npos)
		return npos;
	if (index > 0 && !is_hspace(s.data[index - 1]))
		return npos;
	if (index + 2 < s.len && !is_hspace(s.data[index + 2]) && s.data[index + 2] != ';')
		return npos;
	return index;
}

static size_t nerrors = 0;

static bool
is_shell_comment(cstr line)
{
	size_t i = 0;
	cstr f1 = cstr_next_field(line, &i);
	return cstr_starts_with(f1, CSTR("#"));
}

static void
checkline_sh_double_brackets(cstr filename, size_t lineno, cstr line)
{
	if (is_shell_comment(line))
		return;

	size_t opening_index = index_opening_brackets(line);
	if (opening_index == npos)
		return;

	cstr suffix = cstr_substr(line, opening_index, line.len);
	size_t closing_index = index_closing_brackets(suffix);
	if (closing_index == npos)
		return;

	printf("%s:%zu:%zu: double brackets: %s\n",
	    cstr_charptr(filename), lineno, opening_index + 1,
	    cstr_charptr(line));
	nerrors++;
	explain(
	    W_double_bracket,
	    "The keyword [[ is only available in bash, not in other shells.",
	    "Since it is typically used inside an if statement, if that",
	    "command is missing, it is interpreted as a \"no\".",
	    "",
	    "An error message of the form \"[[: command not found\"",
	    "is logged, but that is easy to overlook in the large",
	    "output of the build process.",
	    nullptr);
	explain_how_to_fix();
}

// Check for $RANDOM, which is specific to ksh and bash.
static void
checkline_sh_dollar_random(cstr filename, size_t lineno, cstr line)
{
	// Note: This code does not find _all_ instances of
	// unportable code. If a single line contains an unsafe and
	// a safe usage of $RANDOM, it will pass the test.
	if (is_shell_comment(line))
		return;
	size_t idx = cstr_index(line, CSTR("$RANDOM"));

	// Variable names that only start with RANDOM are not special.
	if (idx == npos || !cstr_has_word_boundary(line, idx + 7))
		return;

	// $RANDOM together with the PID is often found in GNU-style
	// configure scripts and is considered acceptable.
	if (cstr_contains(line, CSTR("$$-$RANDOM")))
		return;
	if (cstr_contains(line, CSTR("$RANDOM-$$")))
		return;

	printf("%s:%zu:%zu: $RANDOM: %s\n",
	    cstr_charptr(filename), lineno, idx + 1,
	    cstr_charptr(line));
	explain(
	    W_dollar_random,
	    "The variable $RANDOM is not required for a POSIX-conforming shell, and",
	    "many implementations of /bin/sh do not support it. It should therefore",
	    "not be used in shell programs that are meant to be portable across a",
	    "large number of POSIX-like systems.",
	    nullptr);
	explain_how_to_fix();
}

typedef void (*foreach_3_fields_cb)(cstr f1, cstr f2, cstr f3, void *actiondata);

static void
foreach_3_fields_in_line(cstr line, foreach_3_fields_cb action, void *actiondata)
{
	size_t idx = 0;
	cstr f1 = cstr_next_field(line, &idx);
	cstr f2 = cstr_next_field(line, &idx);
	cstr f3 = cstr_next_field(line, &idx);

	while (f3.len > 0) {
		action(f1, f2, f3, actiondata);
		f1 = f2;
		f2 = f3;
		f3 = cstr_next_field(line, &idx);
	}
}

struct checkline_sh_test_eqeq_actiondata {
	cstr filename;
	size_t lineno;
	cstr line;
};

static void
checkline_sh_test_eqeq_action(cstr f1, cstr f2, cstr f3, void *actiondata)
{
	if (!cstr_eq(f3, CSTR("==")))
		return;
	if (!cstr_eq(f1, CSTR("test")) && !cstr_eq(f1, CSTR("[")))
		return;

	struct checkline_sh_test_eqeq_actiondata *ad = actiondata;
	printf(
	    "%s:%zu:%zu: found test ... == ...: %s\n",
	    cstr_charptr(ad->filename), ad->lineno,
	    (size_t) (f3.data - ad->line.data),
	    cstr_charptr(ad->line));
	explain(
	    W_test_eqeq,
	    "The \"test\" command, as well as the \"[\" command, are not required to know",
	    "the \"==\" operator. Only a few implementations like bash and some",
	    "versions of ksh support it.",
	    "",
	    "When you run \"test foo == foo\" on a platform that does not support the",
	    "\"==\" operator, the result will be \"false\" instead of \"true\". This can",
	    "lead to unexpected behavior.",
	    nullptr);
	explain_how_to_fix();
}

static void
checkline_sh_test_eqeq(cstr filename, size_t lineno, cstr line)
{
	if (is_shell_comment(line))
		return;

	struct checkline_sh_test_eqeq_actiondata ad = { filename, lineno, line };
	foreach_3_fields_in_line(line, checkline_sh_test_eqeq_action, &ad);
}

static bool
is_shell_shebang(cstr line)
{
	if (!cstr_starts_with(line, CSTR("#!")))
		return false;

	size_t i = 2;
	cstr full_interp = cstr_next_field(line, &i);
	cstr arg = cstr_next_field(line, &i);

	cstr interp = cstr_right_of_last(full_interp, CSTR("/"));
	if (cstr_eq(interp, CSTR("env")) && arg.len > 0) {
		interp = arg;
	}

	return cstr_eq(interp, CSTR("sh"))
	    || cstr_eq(interp, CSTR("ksh"))
	    || cstr_eq(interp, CSTR("@SH@"))
	    || cstr_eq(interp, CSTR("@SHELL@"));
}

static bool
is_irrelevant_extension(cstr ext)
{
	return cstr_eq(ext, CSTR("bz2"))
	    || cstr_eq(ext, CSTR("c"))
	    || cstr_eq(ext, CSTR("cc"))
	    || cstr_eq(ext, CSTR("cpp"))
	    || cstr_eq(ext, CSTR("gz"))
	    || cstr_eq(ext, CSTR("m4"))
	    || cstr_eq(ext, CSTR("pdf"))
	    || cstr_eq(ext, CSTR("ps"))
	    || cstr_eq(ext, CSTR("xz"))
	    || cstr_eq(ext, CSTR("zip"));
}

static bool
skip_shebang(cstr basename)
{
	return cstr_eq(basename, CSTR("Makefile.am"))
	    || cstr_eq(basename, CSTR("Makefile.in"))
	    || cstr_eq(basename, CSTR("Makefile"));
}

static void
check_file(cstr filename)
{
	cstr basename = cstr_right_of_last(filename, CSTR("/"));
	cstr ext = cstr_right_of_last(basename, CSTR("."));
	if (is_irrelevant_extension(ext))
		return;

	FILE *f = fopen(cstr_charptr(filename), "rb");
	if (f == nullptr) {
		perror(cstr_charptr(filename));
		nerrors++;
		return;
	}

	str line = STR_EMPTY;

	size_t lineno = 0;
	if (!skip_shebang(basename)) {
		if (!str_read_line(&line, f))
			goto cleanup;
		lineno++;
		if (!is_shell_shebang(str_c(&line)))
			goto cleanup;
	}

	while (str_read_line(&line, f)) {
		cstr cline = str_c(&line);
		if (cstr_contains_char(cline, '\0'))
			break;
		lineno++;
		str_charptr(&line);

		checkline_sh_double_brackets(filename, lineno, cline);
		checkline_sh_dollar_random(filename, lineno, cline);
		checkline_sh_test_eqeq(filename, lineno, cline);
	}

cleanup:
	str_free(&line);

	(void) fclose(f);
}

static void
check_files_from_stdin(void)
{
	str line = STR_EMPTY;

	while (str_read_text_line(&line, stdin)) {
		str_charptr(&line);
		check_file(str_c(&line));
	}
}

static int
usage(const char *progname)
{
	fprintf(stderr,
	    "usage: %s < file-list\n"
	    "       %s file...\n",
	    progname, progname);
	return EXIT_FAILURE;
}

int
main(int argc, char **argv)
{
	if (argc > 1 && argv[1][0] == '-')
		return usage(argv[0]);
	if (argc == 1)
		check_files_from_stdin();
	for (int i = 1; i < argc; i++)
		check_file(CSTR(argv[i]));
	return nerrors > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
