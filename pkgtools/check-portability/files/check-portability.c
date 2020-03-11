/* $NetBSD: check-portability.c,v 1.1 2020/03/11 19:15:03 rillig Exp $ */

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
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr ((void *)0)
static const size_t npos = -1;

typedef struct {
	const char *data; // never nullptr
	size_t len;
} cstr;

#define CSTR(str) ((cstr) { str, strlen(str) })

typedef struct {
	char *data;
	size_t len;
	size_t cap;
} str;

#define STR_EMPTY { nullptr, 0, 0 }

static const char *
cstr_charptr(cstr s)
{
	assert(memchr(s.data, 0, s.len) == nullptr);
	assert(s.data[s.len] == '\0');
	return s.data;
}

static bool
cstr_ends_with(cstr s, cstr suffix)
{
	if (suffix.len > s.len)
		return false;
	const char *start = s.data + s.len - suffix.len;
	return memcmp(start, suffix.data, suffix.len) == 0;
}

static void
str_free(str *s)
{
	free(s->data);
}

static void
str_prepare_append(str *s, size_t n)
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

static const char *
str_charptr(str *s)
{
	str_prepare_append(s, 1);
	s->data[s->len] = '\0';
	assert(memchr(s->data, 0, s->len) == nullptr);
	return s->data;
}

static bool
cstr_starts_with(cstr s, cstr prefix)
{
	return prefix.len <= s.len && memcmp(s.data, prefix.data, prefix.len) == 0;
}

static void
str_append_char(str *s, char c)
{
	str_prepare_append(s, 1);
	s->data[s->len++] = c;
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

static cstr
str_c(str *s)
{
	return (cstr) { s->data, s->len };
}

static cstr
cstr_substr(cstr s, size_t start, size_t end)
{
	return (cstr) { s.data + start, end - start };
}

static bool
is_hspace(char c)
{
	return c == ' ' || c == '\t';
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

static size_t
cstr_rindex(cstr haystack, cstr needle)
{
	size_t i = cstr_index(haystack, needle);
	if (i == npos)
		return npos;

	while (true) {
		cstr rest = cstr_substr(haystack, i + 1, haystack.len);
		size_t next = cstr_index(rest, needle);
		if (next == npos)
			return i;
		i = i + 1 + next;
	}
}

static bool
cstr_eq(cstr s1, cstr s2)
{
	return s1.len == s2.len && memcmp(s1.data, s2.data, s1.len) == 0;
}

typedef enum {
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

static size_t
index_opening_bracket(cstr s)
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
index_closing_bracket(cstr s)
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

static void
checkline_sh_brackets(cstr filename, size_t lineno, cstr line)
{
	if (line.len > 0 && line.data[0] == '#')
		return;

	size_t opening_index = index_opening_bracket(line);
	if (opening_index == npos)
		return;

	cstr suffix = cstr_substr(line, opening_index, line.len);
	size_t closing_index = index_closing_bracket(suffix);
	if (closing_index == npos)
		return;

	printf("%s:%zu:%zu: double brackets: %s\n",
	    cstr_charptr(filename), lineno, opening_index + 1,
	    cstr_charptr(line));
	nerrors++;
	explain(
	    W_double_bracket,
	    "The command [[ is not available on all platforms.",
	    "Since it is typically used inside an if statement,",
	    "the missing command is interpreted as a \"no\".",
	    "",
	    "An error message of the form \"[[: command not found\"",
	    "is logged, but that is easy to overlook in the large",
	    "output of the build process.",
	    nullptr);
}

static bool
is_relevant(cstr line)
{
	if (!cstr_starts_with(line, CSTR("#!")))
		return false;

	size_t last_slash = cstr_rindex(line, CSTR("/"));
	if (last_slash == npos)
		return false;

	cstr basename = cstr_substr(line, last_slash + 1, line.len);
	if (cstr_starts_with(basename, CSTR("env")) && basename.len > 3 && is_hspace(basename.data[3])) {
		basename = cstr_substr(basename, 3, basename.len);
		while (basename.len > 0 && is_hspace(basename.data[0]))
			basename = cstr_substr(basename, 1, basename.len);
	}

	if (cstr_starts_with(basename, CSTR("bash")))
		return false;
	if (cstr_eq(basename, CSTR("false")))
		return false;
	if (cstr_starts_with(basename, CSTR("perl")))
		return false;
	if (cstr_starts_with(basename, CSTR("python")))
		return false;
	return true;
}

static void
check_sh_brackets(cstr filename)
{

#define SKIP_EXT(ext) \
	if (cstr_ends_with(filename, CSTR(ext))) \
		return;

	SKIP_EXT(".bz2");
	SKIP_EXT(".c");
	SKIP_EXT(".cc");
	SKIP_EXT(".cpp");
	SKIP_EXT(".gz");
	SKIP_EXT(".m4");
	SKIP_EXT(".pdf");
	SKIP_EXT(".ps");
	SKIP_EXT(".xz");
	SKIP_EXT(".zip");
#undef SKIP_EXT

	FILE *f = fopen(cstr_charptr(filename), "rb");
	if (f == nullptr) {
		perror(cstr_charptr(filename));
		nerrors++;
		return;
	}

	str line = STR_EMPTY;

	if (str_read_line(&line, f) && is_relevant(str_c(&line))) {
		size_t lineno = 1;
		while (str_read_line(&line, f)) {
			lineno++;
			str_charptr(&line);
			checkline_sh_brackets(filename, lineno, str_c(&line));
		}
	}

	str_free(&line);

	(void) fclose(f);
}

static void
check_files_from_stdin(void)
{
	str line = STR_EMPTY;

	while (str_read_text_line(&line, stdin)) {
		str_charptr(&line);
		check_sh_brackets(str_c(&line));
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
		check_sh_brackets(CSTR(argv[i]));
	return nerrors > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
