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
#include <sys/mman.h>

#ifdef _KERNEL
#include <inttypes.h>
#include <string.h>
#else
#include <ctype.h>
#include <inttypes.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#endif

/* digests */
#include "md5.h"
#include "rmd160.h"
#include "sha1.h"
#include "sha2.h"
#include "crc32c.h"
#include "tiger.h"
#include "blake2.h"
#include "whirlpool.h"
#include "keccak.h"

#include "multigest.h"

#ifndef __arraycount
#define	__arraycount(__x)	(sizeof(__x) / sizeof(__x[0]))
#endif

#ifndef USE_ARG
#define	USE_ARG(x)		/*LINTED*/(void)&(x)
#endif

#define MB(x)	((x) * 1024 * 1024)

/*
 * If you'd like to add a digest to this library and/or utility, then
 * you need to write:
 *
 * 1. a wrapper function for the digest init function
 * 2. a wrapper function for the digest update function
 * 3. a wrapper function for the digest final function
 *
 * and then add the entry to the algs table below.
 *
 * The table-driven nature of this is not strictly necessary, but makes
 * it easier to add digest functions.
 *
 * The table is searched once at initialisation time, and so there is
 * only one table scan to find the correct digest algorithm.
 * Algorithms are searched in a case-insensitive manner.
 * The text for the algorithm name in the algs table is printed as the
 * name of the algorithm in the output. Convention has this as upper
 * case.
 */

/*****/

static void
wrap_sha1_init(void *v)
{
	SHA1Init(v);
}

static void
wrap_md5_init(void *v)
{
	MD5Init(v);
}

static void
wrap_sha256_init(void *v)
{
	SHA256_Init(v);
}

static void
wrap_sha512_init(void *v)
{
	SHA512_Init(v);
}

static void
wrap_rmd160_init(void *v)
{
	RMD160Init(v);
}

static void
wrap_crc32c_init(void *v)
{
	crc32c_init(v);
}

static void
wrap_tiger_init(void *v)
{
	TIGER_Init(v);
}

static void
wrap_tiger2_init(void *v)
{
	TIGER2_Init(v);
}

static void
wrap_blake2_init(void *v)
{
	blake2b_init(v, 64);
}

static void
wrap_whirlpool_init(void *v)
{
	whirlpool_init(v);
}

static void
wrap_keccak224_init(void *v)
{
	KECCAK_Init(v, 224);
}

static void
wrap_keccak256_init(void *v)
{
	KECCAK_Init(v, 256);
}

static void
wrap_keccak384_init(void *v)
{
	KECCAK_Init(v, 384);
}

static void
wrap_keccak512_init(void *v)
{
	KECCAK_Init(v, 512);
}

static void
wrap_size_init(void *v)
{
	memset(v, 0x0, sizeof(uint64_t));
}

/*****/

static void
wrap_md5_update(void *v, const char *data, unsigned len)
{
	MD5Update(v, (const uint8_t *)data, len);
}

static void
wrap_sha1_update(void *v, const char *data, unsigned len)
{
	SHA1Update(v, (const uint8_t *)data, len);
}

static void
wrap_sha256_update(void *v, const char *data, unsigned len)
{
	SHA256_Update(v, (const uint8_t *)data, len);
}

static void
wrap_sha512_update(void *v, const char *data, unsigned len)
{
	SHA512_Update(v, (const uint8_t *)data, len);
}

static void
wrap_rmd160_update(void *v, const char *data, unsigned len)
{
	RMD160Update(v, (const uint8_t *)data, len);
}

static void
wrap_crc32c_update(void *v, const char *data, unsigned len)
{
	crc32c_update(v, (const uint8_t *)data, len);
}

static void
wrap_tiger_update(void *v, const char *data, unsigned len)
{
	TIGER_Update(v, (const uint8_t *)data, len);
}

static void
wrap_blake2_update(void *v, const char *data, unsigned len)
{
	blake2b_update(v, (const uint8_t *)data, (uint64_t)len);
}

static void
wrap_whirlpool_update(void *v, const char *data, unsigned len)
{
	whirlpool_update(v, (const uint8_t *)data, len);
}

static void
wrap_keccak_update(void *v, const char *data, unsigned len)
{
	/* number of bits for keccak */
	KECCAK_Update(v, (const uint8_t *)data, (uint64_t)(len * 8));
}

static void
wrap_size_update(void *v, const char *data, unsigned len)
{
	uint64_t	n;

	USE_ARG(data);
	memcpy(&n, v, sizeof(n));
	n += len;
	memcpy(v, &n, sizeof(n));
}

/*****/

static void
wrap_sha1_final(uint8_t *raw, void *v)
{
	SHA1Final(raw, v);
}

static void
wrap_sha256_final(uint8_t *raw, void *v)
{
	SHA256_Final(raw, v);
}

static void
wrap_sha512_final(uint8_t *raw, void *v)
{
	SHA512_Final(raw, v);
}

static void
wrap_rmd160_final(uint8_t *raw, void *v)
{
	RMD160Final(raw, v);
}

static void
wrap_md5_final(uint8_t *raw, void *v)
{
	MD5Final(raw, v);
}

static void
wrap_crc32c_final(uint8_t *raw, void *v)
{
	crc32c_final((ctx32_t *)(void *)raw, v);
}

static void
wrap_tiger_final(uint8_t *raw, void *v)
{
	TIGER_Final(raw, v);
}

static void
wrap_blake2_final(uint8_t *raw, void *v)
{
	blake2b_final(v, raw, 64);
}

static void
wrap_whirlpool_final(uint8_t *raw, void *v)
{
	whirlpool_finalize((char *)raw, v);
}

static void
wrap_keccak_final(uint8_t *raw, void *v)
{
	KECCAK_Final(v, raw);
}

static void
wrap_size_final(uint8_t *raw, void *v)
{
	const int	indian = 1;
	uint64_t	tmp;
	uint64_t	w;

	memcpy(&w, v, sizeof(w));
	if (*(const char *)(const void *)&indian) {
		/* little endian */
		tmp = (w >> 32) | (w << 32); \
		tmp = ((tmp & (uint64_t)0xff00ff00ff00ff00ULL) >> 8) |
		      ((tmp & (uint64_t)0x00ff00ff00ff00ffULL) << 8);
		w = ((tmp & (uint64_t)0xffff0000ffff0000ULL) >> 16) |
		      ((tmp & (uint64_t)0x0000ffff0000ffffULL) << 16);
	}
	memcpy(raw, &w, sizeof(w));
}

/*****/

/* digest algorithm struct */
typedef struct Alg {
	const char	*name;		/* digest name */
	size_t		 namelen;	/* length of name */
	size_t		 ctxsize;	/* context size */
	size_t		 rawsize;	/* rawsize of output */
	mg_initfunc_t	 init;		/* digest init function */
	mg_updatefunc_t	 update;	/* digest update function */
	mg_finalfunc_t	 final;		/* digest final function */
} Alg;

static const Alg	algs[] = {
	{ "MD5",	3, sizeof(MD5_CTX), 	16, wrap_md5_init, wrap_md5_update, wrap_md5_final },
	{ "SHA1",	4, sizeof(SHA1_CTX), 	20, wrap_sha1_init, wrap_sha1_update, wrap_sha1_final },
	{ "SHA256",	6, sizeof(SHA256_CTX), 	32, wrap_sha256_init, wrap_sha256_update, wrap_sha256_final },
	{ "SHA512",	6, sizeof(SHA512_CTX), 	64, wrap_sha512_init, wrap_sha512_update, wrap_sha512_final },
	{ "BLAKE2",	6, sizeof(BLAKE2_CTX),	64, wrap_blake2_init, wrap_blake2_update, wrap_blake2_final },
	{ "RMD160",	6, sizeof(RMD160_CTX), 	20, wrap_rmd160_init, wrap_rmd160_update, wrap_rmd160_final },
	{ "RIPEMD160",	9, sizeof(RMD160_CTX), 	20, wrap_rmd160_init, wrap_rmd160_update, wrap_rmd160_final },
	{ "CRC32C",	6, sizeof(ctx32_t), 	4,  wrap_crc32c_init, wrap_crc32c_update, wrap_crc32c_final },
	{ "TIGER2",	6, sizeof(TIGER_CTX), 	24, wrap_tiger2_init, wrap_tiger_update, wrap_tiger_final },
	{ "TIGER",	5, sizeof(TIGER_CTX), 	24, wrap_tiger_init, wrap_tiger_update, wrap_tiger_final },
	{ "WHIRLPOOL",	9, sizeof(whirlpool_context_t), 64, wrap_whirlpool_init, wrap_whirlpool_update, wrap_whirlpool_final },
	{ "SHA3-224",	8, sizeof(KECCAK_CTX),	28, wrap_keccak224_init, wrap_keccak_update, wrap_keccak_final },
	{ "SHA3-256",	8, sizeof(KECCAK_CTX),	32, wrap_keccak256_init, wrap_keccak_update, wrap_keccak_final },
	{ "SHA3-384",	8, sizeof(KECCAK_CTX),	48, wrap_keccak384_init, wrap_keccak_update, wrap_keccak_final },
	{ "SHA3-512",	8, sizeof(KECCAK_CTX),	64, wrap_keccak512_init, wrap_keccak_update, wrap_keccak_final },
	{ "KECCAK-224",	10, sizeof(KECCAK_CTX),	28, wrap_keccak224_init, wrap_keccak_update, wrap_keccak_final },
	{ "KECCAK-256",	10, sizeof(KECCAK_CTX),	32, wrap_keccak256_init, wrap_keccak_update, wrap_keccak_final },
	{ "KECCAK-384",	10, sizeof(KECCAK_CTX),	48, wrap_keccak384_init, wrap_keccak_update, wrap_keccak_final },
	{ "KECCAK-512",	10, sizeof(KECCAK_CTX),	64, wrap_keccak512_init, wrap_keccak_update, wrap_keccak_final },
	{ "SIZE",	4, sizeof(uint64_t),	8, wrap_size_init, wrap_size_update, wrap_size_final },
	{ NULL, 0, 0, 0, NULL, NULL, NULL}
};

/* find an algorithm in the table above */
static const Alg *
findalg(const char *algname)
{
	const Alg	*alg;

	for (alg = algs ; algname && alg->name ; alg++) {
		if (strncasecmp(algname, alg->name, alg->namelen) == 0) {
			return alg;
		}
	}
	return NULL;
}

/* normalise through regexp substitution */
static int
normalise(multigest_t *multigest, const char *data, size_t len, int64_t *from)
{
#ifndef _KERNEL
	multigest_dig_t	*d;
	regmatch_t	 match[2];
	uint32_t	 i;

	*from = 0;
	while (multigest->r && len > 0) {
		match[0].rm_so = *from;
		match[0].rm_eo = len;
		if (regexec(multigest->r, data, 2, match, REG_STARTEND) != 0) {
			break;
		}
		for (d = multigest->digs, i = 0 ; i < multigest->digc ; i++, d++) {
			(*d->update)(&multigest->ctx[d->ctxoff], &data[*from],
				(unsigned)(match[0].rm_so - *from));
			if (multigest->repllen) {
				(*d->update)(&multigest->ctx[d->ctxoff], multigest->repl,
					multigest->repllen);
			}
		}
		*from = match[0].rm_eo;
	}
#else
	*from = 0;
#endif
	return 1;
}

/***************************************************************************/

/* create a new struct and return it */
multigest_t *
multigest_new(void)
{
	return calloc(1, sizeof(multigest_t));
}

/* initialise a struct */
int
multigest_init(multigest_t *multigest, const char *algname)
{
	multigest_dig_t	*d;
	const Alg	*alg;
	uint32_t	 ctxoff;
	uint32_t	 i;
	uint8_t		*newv;

	if (multigest && algname) {
		memset(multigest, 0x0, sizeof(*multigest));
		multigest->type = strdup(algname);
		for (i = 0, d = multigest->digs, ctxoff = 0 ;  *algname ; d++, i++) {
			if (i >= __arraycount(multigest->digs)) {
				fprintf(stderr, "too many digest types %u\n", i);
				break;
			}
			if ((alg = findalg(algname)) == NULL) {
				fprintf(stderr, "no such algorithm '%.10s'\n", algname);
				break;
			}
			if (ctxoff + alg->ctxsize >= multigest->ctxsize) {
				if ((newv = realloc(multigest->ctx, multigest->ctxsize + 4096)) == NULL) {
					fprintf(stderr, "multigest_init: allocation issues\n");
					return 0;
				}
				multigest->ctx = newv;
				multigest->ctxsize += 4096;
			}
			d->alg = strdup(alg->name);
			(*alg->init)(&multigest->ctx[ctxoff]);
			d->rawsize = alg->rawsize;
			multigest->rawsize += alg->rawsize;
			d->ctxoff = ctxoff;
			d->update = alg->update;
			d->final = alg->final;
			ctxoff += (uint32_t)alg->ctxsize;
			algname += alg->namelen;
			if (*algname == ',') {
				algname += 1;
			}
			multigest->digc += 1;
		}
		return 1;
	}
	fprintf(stderr, "!multigest || !algname\n");
	return 0;
}

/* add a substitution pattern */
int
multigest_add_subst(multigest_t *multigest, const char *from, const char *to)
{
	if (multigest && from && from[0]) {
		if ((multigest->r = calloc(1, sizeof(regex_t))) == NULL ||
		    regcomp(multigest->r, from, REG_EXTENDED) != 0) {
			return 0;
		}
		multigest->pat = strdup(from);
		if (to) {
			multigest->repl = strdup(to);
			multigest->repllen = (uint32_t)strlen(to);
		}
		return 1;
	}
	return 0;
}

/* update the digest with the input */
void
multigest_update(multigest_t *multigest, const char *data, size_t len)
{
	multigest_dig_t	*d;
	uint32_t	 i;
	int64_t	 	 from;

	if (multigest && data) {
		normalise(multigest, data, len, &from);
		for (d = multigest->digs, i = 0 ; i < multigest->digc ; i++, d++) {
			(*d->update)(&multigest->ctx[d->ctxoff], &data[from], (unsigned)(len - from));
		}
	}
}

/* finalise the digest */
void
multigest_final(multigest_t *multigest, uint8_t *raw)
{
	multigest_dig_t	*d;
	uint32_t	 rawoff;
	uint32_t	 i;

	if (multigest && raw) {
		rawoff = 0;
		for (d = multigest->digs, i = 0 ; i < multigest->digc ; i++, d++) {
			(*d->final)(&raw[rawoff], &multigest->ctx[d->ctxoff]);
			rawoff += (uint32_t)d->rawsize;
		}
	}
}

/* run sed on data and then digest it */
uint8_t *
multigest_data(const char *alg, const char *data, size_t size, uint8_t *raw, const char *pat, const char *repl)
{
	multigest_t	s;

	if (data && alg && raw) {
		memset(&s, 0x0, sizeof(s));
		multigest_init(&s, alg);
		multigest_add_subst(&s, pat, repl);
		multigest_update(&s, data, size);
		multigest_final(&s, raw);
		multigest_free(&s);
		return raw;
	}
	return NULL;
}

/* percent decode (pseudo-RFC1738) a string */
void
multigest_unpcstring(const char *in, size_t isize, char *out, size_t osize)
{
	static const char	*hexes = "0123456789abcdef";
	const char		*p[2];
	const char		*i;
	char			*o;

	for (i = in, o = out ; (size_t)(o - out) < osize - 1 && (size_t)(i - in) < isize && *i ; o++) {
		if (*i == '%') {
			if ((p[0] = strchr(hexes, i[1])) == NULL ||
			    (p[1] = strchr(hexes, i[2])) == NULL) {
				break;
			}
			*o = ((char)(p[0] - hexes) * 16) + (p[1] - hexes);
			i += 3;
		} else {
			*o = *i++;
		}
	}
	*o = 0x0;
}

/* print as hex string */
int
multigest_format_hex(uint8_t *raw, const char *algname, char *out, size_t size)
{
	const Alg	*alg;
	size_t		 rawsize;
	size_t		 i;

	for (rawsize = 0 ; *algname ; rawsize += alg->rawsize) {
		if ((alg = findalg(algname)) == NULL) {
			break;
		}
		for (i = 0 ; i < alg->rawsize && (rawsize + i) * 2 < size; i++) {
			snprintf(&out[(rawsize + i) * 2], 3, "%02hhx", raw[rawsize + i]);
		}
		algname += alg->namelen;
		if (*algname == ',') {
			algname += 1;
		}
	}
	return (int)(rawsize + rawsize + 1);
}

/* return the size of output array we'll need */
uint32_t
multigest_get_rawsize(multigest_t *multigest)
{
	return (multigest) ? (uint32_t)multigest->rawsize : 0;
}

/* return the size of output array we'll need for the alg names */
uint32_t
multigest_algs_rawsize(const char *alg)
{
	multigest_t	m;
	uint32_t	size;

	memset(&m, 0x0, sizeof(m));
	if (!multigest_init(&m, alg)) {
		fprintf(stderr, "multigest_init: failed\n");
		return 0;
	}
	size = multigest_get_rawsize(&m);
	multigest_free(&m);
	return size;
}

/*****************************************************************/

#ifndef _KERNEL
/* percent encode (pseudo-RFC1738) a string */
static void
pcstring(FILE *fp, const char *s)
{
	static const char	*pcencodes = "%$\r\n\t ";

	for ( ; *s ; s++) {
		if (strchr(pcencodes, *s) == NULL) {
			fprintf(fp, "%c", *s);
		} else {
			fprintf(fp, "%%%02hhx", *s);
		}
	}
}

/* print as hex string */
int
multigest_print_hex(uint8_t *raw, const char *algname, const char *outname,
	const char *f, const char *sub, const char *sep, const char *format)
{
	const Alg	*alg;
	size_t		 rawsize;
	size_t		 i;
	FILE		*fp;

	if (outname == NULL) {
		fp = stdout;
	} else {
		if ((fp = fopen(outname, "w")) == NULL) {
			fprintf(stderr, "can't write to '%s'\n", outname);
			return 0;
		}
	}
	if (f != NULL) {
		for (i = 0 ; algname[i] ; i++) {
			fprintf(fp, "%c", toupper((uint8_t)algname[i]));
		}
		if (format && strcasecmp(format, "openssl") == 0) {
			fprintf(fp, "(%s)= ", f);
		} else if (format && strcasecmp(format, "digest") == 0) {
			fprintf(fp, " (%s) = ", f);
		} else {
			fprintf(fp, " (%s) (", f);
			if (sub) {
				pcstring(fp, sub);
			}
			fprintf(fp, ") = ");
		}
	}
	for (rawsize = 0 ; *algname ; rawsize += alg->rawsize) {
		if ((alg = findalg(algname)) == NULL) {
			break;
		}
		for (i = 0 ; i < alg->rawsize ; i++) {
			fprintf(fp, "%02hhx", raw[rawsize + i]);
		}
		if (sep) {
			fprintf(fp, "%s", sep);
		}
		algname += alg->namelen;
		if (*algname == ',') {
			algname += 1;
		}
	}
	fprintf(fp, "\n");
	if (outname != NULL) {
		fclose(fp);
	}
	return 1;
}

/* run sed, then digest on a file */
uint8_t *
multigest_file(const char *alg, const char *f, uint8_t *raw, const char *pat, const char *repl)
{
	struct stat	 st;
	multigest_t	 m;
	ssize_t		 rc;
	size_t		 size;
	size_t		 cc;
	char		*mapped;
	FILE		*fp;

	if (f && alg && raw) {
                memset(&m, 0x0, sizeof(m));
                multigest_init(&m, alg);
                multigest_add_subst(&m, pat, repl);
		if ((fp = fopen(f, "r")) == NULL) {
			fprintf(stderr, "can't open '%s'\n", f);
			return 0;
		}
		fstat(fileno(fp), &st);
		size = st.st_size;
		mapped = mmap(NULL, size, PROT_READ, MAP_SHARED, fileno(fp), 0);
		if (mapped == MAP_FAILED) {
			mapped = calloc(1, MB(1));
			for (cc = 0 ; cc < size ; cc += rc) {
				if ((rc = read(fileno(fp), mapped, MB(1))) <= 0) {
					break;
				}
				multigest_update(&m, mapped, (size_t)rc);
			}
			free(mapped);
		} else {
			multigest_update(&m, mapped, (size_t)size);
			munmap(mapped, size);
		}
		fclose(fp);
                multigest_final(&m, raw);
                multigest_free(&m);
		return raw;
	}
	return NULL;
}

/* free resources used in a sedded digest */
void
multigest_free(multigest_t *s)
{
	uint32_t	i;

	if (s) {
		if (s->ctx) {
			free(s->ctx);
		}
		if (s->pat) {
			free(s->pat);
			regfree(s->r);
		}
		if (s->repl) {
			free(s->repl);
		}
		for (i = 0 ; i < s->digc ; i++) {
			free(s->digs[i].alg);
		}
	}
}

/* turn a raw digest into an ascii string */
char *
multigest_format_raw(const uint8_t *in, size_t insize, char *out, size_t outsize)
{
	const uint8_t	*i;
	char		*o;

	for (o = out, i = in ; (size_t)(i - in) < insize && (size_t)(o - out) < outsize ; i++, o += 2) {
		snprintf(o, 3, "%02hhx", *i);
	}
	*o = 0x0;
	return out;
}

#endif

