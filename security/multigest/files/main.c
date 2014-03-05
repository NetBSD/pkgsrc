/*-
 * Copyright (c) 2013 Alistair Crooks <agc@NetBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "multigest.h"


#define MB(x)	((x) * 1024 * 1024)

/* read input into memory, and then multigest that */
static int
do_input(const char *alg, uint8_t *raw, const char *pat, const char *repl)
{
	size_t	 cc;
	size_t	 rc;
	char	*data;

	if ((data = calloc(1, MB(4))) != NULL) {
		for (cc = 0 ; cc < MB(4) ; cc += rc) {
			if ((rc = read(fileno(stdin), &data[cc], MB(4) - cc)) <= 0) {
				break;
			}
		}
		multigest_data(alg, data, cc, raw, pat, repl);
		free(data);
		return 1;
	}
	return 0;
}

/* get the substitution pattern from the arg */
static int
getsubst(const char *arg, char *from, size_t fromsize, char *to, size_t tosize)
{
	const char	*sep;
	const char	*sub;
	size_t		 len;

	for (sep = arg + 1 ; *sep && *sep != *arg ; sep++) {
		if (*sep == '\\') {
			sep += 1;
		}
	}
	len = (size_t)(sep - arg) - 1;
	len = MIN(fromsize - 1, len);
	multigest_unpcstring(arg + 1, len, from, fromsize);
	for (sub = ++sep ; *sep && *sep != *arg ; sep++) {
		if (*sep == '\\') {
			sep += 1;
		}
	}
	len = (size_t)(sep - sub);
	len = MIN(tosize - 1, len);
	multigest_unpcstring(sub, len, to, tosize);
	return 1;
}

/* verify contents of an existing dynamic digest file */
static int
read_check(const char *check)
{
	struct stat	 st;
	regmatch_t	 match[10];
	regex_t		 r;
	uint8_t		 raw[8192];
	FILE		*fp;
	char		*provided;
	char		 calc[8192];
	char		 from[128];
	char		 to[128];
	char		*file;
	char		*subs;
	char		*alg;
	char		*in;
	int		 ret;

	regcomp(&r, "([^ ]+) \\(([^)]+)\\) \\((.*)\\) = ([0-9a-zA-Z]+)", REG_EXTENDED);
	if ((fp = fopen(check, "r")) == NULL) {
		fprintf(stderr, "can't check existing file '%s'\n", check);
		return 0;
	}
	fstat(fileno(fp), &st);
	if ((in = calloc(1, st.st_size + 1)) == NULL) {
		fclose(fp);
		return 0;
	}
	read(fileno(fp), in, st.st_size);
	in[st.st_size] = 0x0;
	fclose(fp);
	if (regexec(&r, in, 10, match, 0) != 0) {
		free(in);
		return 0;
	}
	alg = &in[match[1].rm_so];
	file = &in[match[2].rm_so];
	subs = &in[match[3].rm_so];
	provided = &in[match[4].rm_so];
	in[match[1].rm_eo] = in[match[2].rm_eo] = in[match[3].rm_eo] = in[match[4].rm_eo] = 0x0;
	getsubst(subs, from, sizeof(from), to, sizeof(to));
	multigest_file(alg, file, raw, from, to);
	multigest_format_hex(raw, alg, calc, sizeof(calc));
	if ((ret = memcmp(calc, provided, match[4].rm_eo - match[4].rm_so)) != 0) {
		fprintf(stderr, "multigest: provided digest:   '%s', calculated digest: '%s'\n", provided, calc);
	}
	regfree(&r);
	free(in);
	return ret == 0;
}

int
main(int argc, char **argv)
{
	const char	*outname;
	const char	*format;
	const char	*check;
	const char	*alg;
	const char	*sub;
	const char	*sep;
	uint8_t		 raw[8192];
	char	 	 from[128];
	char	 	 to[128];
	int		 ok;
	int		 i;

	alg = "sha1";
	format = "multigest";
	sep = sub = outname = check = NULL;
	from[0] = to[0] = 0x0;
	while ((i = getopt(argc, argv, "F:S:a:c:o:rs:")) != -1) {
		switch(i) {
		case 'F':
			format = optarg;
			break;
		case 'S':
			sep = optarg;
			break;
		case 'a':
			alg = optarg;
			break;
		case 'c':
			check = optarg;
			break;
		case 'o':
			outname = optarg;
			break;
		case 'r':
			getsubst(sub = ",\\$(Id|NetBSD)[^\n]*\\$,\044NetBSD\044", from, sizeof(from), to, sizeof(to));
			break;
		case 's':
			getsubst(sub = optarg, from, sizeof(from), to, sizeof(to));
			break;
		default:
			break;
		}
	}
	ok = 1;
	if (check) {
		if (!read_check(check)) {
			ok = 0;
		}
	} else if (optind == argc) {
		if (do_input(alg, raw, from, to)) {
			multigest_print_hex(raw, alg, outname, NULL, sub, sep, format);
		} else {
			ok = 0;
		}
	} else {
		for (i = optind ; i < argc ; i++) {
			if (multigest_file(alg, argv[i], raw, from, to) == NULL) {
				ok = 0;
			} else {
				multigest_print_hex(raw, alg, outname, argv[i], sub, sep, format);
			}
		}
	}
	exit((ok) ? EXIT_SUCCESS : EXIT_FAILURE);
}
