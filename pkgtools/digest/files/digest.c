/*	$NetBSD: digest.c,v 1.16 2016/03/03 22:11:07 agc Exp $ */

/*-
 * Copyright (c) 2001-2016 Alistair Crooks <agc@NetBSD.org>
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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif
#include <md5.h>
#include <rmd160.h>
#include <sha1.h>
#include <sha2.h>
#include <sha3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tiger.h>
#include <whirlpool.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

typedef void (*HASH_init)(void *);
typedef void (*HASH_update)(void *, const uint8_t *, size_t);
typedef char *(*HASH_end)(void *, char *);
typedef char *(*HASH_file)(char *, char *);
  
/* this struct defines a message digest algorithm */
typedef struct alg_t {
	const char     *name;
	int		hash_len;
	HASH_init	hash_init;
	HASH_update	hash_update;
	HASH_end	hash_end;
	HASH_file	hash_file;
	union {
		MD5_CTX			m;
		SHA1_CTX		sha;
		RMD160_CTX		rmd;
		SHA256_CTX		sha256;
		SHA384_CTX		sha384;
		SHA3_224_CTX		sha3_224;
		SHA3_256_CTX		sha3_256;
		SHA3_384_CTX		sha3_384;
		SHA3_512_CTX		sha3_512;
		SHA512_CTX		sha512;
		tiger_context_t		tiger;
		whirlpool_context_t	whirlpool;
	} hash_ctx, hash_ctx2;
} alg_t;

/* list of supported message digest algorithms */
static alg_t algorithms[] = {
	{ "MD5",	16,
	  (HASH_init) MD5Init,		(HASH_update) MD5Update,
	  (HASH_end) MD5End,		(HASH_file) MD5File },
	{ "RMD160",	20,
	  (HASH_init) RMD160Init,	(HASH_update) RMD160Update,
	  (HASH_end) RMD160End,		(HASH_file) RMD160File },
	{ "SHA1",	20,
	  (HASH_init) SHA1Init,		(HASH_update) SHA1Update,
	  (HASH_end) SHA1End,		(HASH_file) SHA1File },
	{ "SHA256",	SHA256_DIGEST_LENGTH,
	  (HASH_init) SHA256_Init,	(HASH_update) SHA256_Update,
	  (HASH_end) SHA256_End,	(HASH_file) SHA256_File },
	{ "SHA3_224",	SHA3_224_DIGEST_LENGTH,
	  (HASH_init) SHA3_224_Init,	(HASH_update) SHA3_224_Update,
	  (HASH_end) SHA3_224_End,	(HASH_file) SHA3_224_File },
	{ "SHA3_256",	SHA3_256_DIGEST_LENGTH,
	  (HASH_init) SHA3_256_Init,	(HASH_update) SHA3_256_Update,
	  (HASH_end) SHA3_256_End,	(HASH_file) SHA3_256_File },
	{ "SHA3_384",	SHA3_384_DIGEST_LENGTH,
	  (HASH_init) SHA3_384_Init,	(HASH_update) SHA3_384_Update,
	  (HASH_end) SHA3_384_End,	(HASH_file) SHA3_384_File },
	{ "SHA3_512",	SHA3_512_DIGEST_LENGTH,
	  (HASH_init) SHA3_512_Init,	(HASH_update) SHA3_512_Update,
	  (HASH_end) SHA3_512_End,	(HASH_file) SHA3_512_File },
	{ "SHA384",	SHA384_DIGEST_LENGTH,
	  (HASH_init) SHA384_Init,	(HASH_update) SHA384_Update,
	  (HASH_end) SHA384_End,	(HASH_file) SHA384_File },
	{ "SHA512",	SHA512_DIGEST_LENGTH,
	  (HASH_init) SHA512_Init,	(HASH_update) SHA512_Update,
	  (HASH_end) SHA512_End,	(HASH_file) SHA512_File },
	{ "TIGER",	24,
	  (HASH_init) TIGERInit,	(HASH_update) TIGERUpdate,
	  (HASH_end) TIGEREnd,		(HASH_file) TIGERFile },
	{ "WHIRLPOOL",	WHIRLPOOL_DIGEST_BYTES,
	  (HASH_init) whirlpool_init,	(HASH_update) whirlpool_update,
	  (HASH_end) whirlpool_end,	(HASH_file) whirlpool_file },
	{ NULL }
};

/* find an algorithm, given a name */
static alg_t *
find_algorithm(const char *a)
{
	alg_t	*alg;

	for (alg = algorithms ; alg->name && strcasecmp(alg->name, a) != 0 ; alg++) {
	}
	return (alg->name) ? alg : NULL;
}

/* compute a digest, and print the results if successful */
static int
digest_file(char *fn, alg_t *alg)
{
	char	in[BUFSIZ * 20];
	char   *digest;
	int	cc, rc;

	digest = malloc(alg->hash_len * 2 + 1);

        if (fn == NULL) {
		(*alg->hash_init)(&alg->hash_ctx);
                while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			(*alg->hash_update)(&alg->hash_ctx, (uint8_t *)in,
					    (unsigned) cc);
		}
		(void) printf("%s\n", (*alg->hash_end)(&alg->hash_ctx, digest));
		rc = 1;
	} else {
		if ((*alg->hash_file)(fn, digest) == NULL) {
			rc = 0;
		} else {
			(void) printf("%s (%s) = %s\n", alg->name, fn, digest);
			rc = 1;
		}
	}

	free(digest);

	return (rc);
}

int
main(int argc, char **argv)
{
	alg_t  *alg;
	int	test;
	int	ok;
	int	i;

#ifdef HAVE_SETLOCALE
	(void) setlocale(LC_ALL, "");
#endif
	test = 0;
	while ((i = getopt(argc, argv, "Vt")) != -1) {
		switch(i) {
		case 'V':
			printf("%s\n", VERSION);
			return EXIT_SUCCESS;
		case 't':
			test = 1;
			break;
		}
	}
	if (test) {
		/* there's room for other tests here -- agc */
		printf("self test mode starting\n");
		ok = 1;
		if (SHA3_Selftest() != 0) {
			ok = 0;
		}
		printf("self test mode completed\n");
		return (ok) ? EXIT_SUCCESS : EXIT_FAILURE;
	}
	/* check for correct usage */
	if (argc == optind) {
		(void) fprintf(stderr, "Usage: %s algorithm [file...]\n",
		    argv[0]);
		return EXIT_FAILURE;
	}
	/* check we know the digest algorithm */
	if ((alg = find_algorithm(argv[optind])) == NULL) {
		(void) fprintf(stderr, "No such algorithm `%s'\n", argv[optind]);
		exit(EXIT_FAILURE);
	}
	ok = 1;
	if (argc == optind + 1) {
		if (!digest_file(NULL, alg)) {
			fprintf(stderr, "stdin\n");
			ok = 0;
		}
	} else {
		for (i = optind + 1 ; i < argc ; i++) {
			if (!digest_file(argv[i], alg)) {
				fprintf(stderr, "%s\n", argv[i]);
				ok = 0;
			}
		}
	}
	return (ok) ? EXIT_SUCCESS : EXIT_FAILURE;
}
