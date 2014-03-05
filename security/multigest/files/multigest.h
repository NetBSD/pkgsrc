/*-
 * Copyright (c) 2014 Alistair Crooks <agc@NetBSD.org>
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
#ifndef MULTIGEST_H_
#define MULTIGEST_H_	20140304

#include <sys/types.h>

#include <inttypes.h>

typedef void	(*mg_initfunc_t)(void *);
typedef void	(*mg_updatefunc_t)(void *, const char *, unsigned);
typedef void	(*mg_finalfunc_t)(uint8_t *, void *);

#define MG_MAX_DIG	32

/* a single digest struct */
typedef struct multigest_dig_t {
	char		*alg;		/* digest name */
	size_t		 ctxoff;	/* offset in context */
	size_t		 rawsize;	/* length of raw output */
	mg_updatefunc_t	 update;	/* digest update function */
	mg_finalfunc_t	 final;		/* final update function */
} multigest_dig_t;

/* a multiple digest struct */
typedef struct multigest_t {
	void		*r;		/* regular expression for matching */
	char		*pat;		/* pattern we match */
	char		*repl;		/* replacement text */
	unsigned	 repllen;	/* cached length of replacement */
	char		*type;		/* digest type */
	size_t		 rawsize;	/* raw size of output digest */
	size_t		 ctxsize;	/* allocated size of contexts */
	uint8_t		*ctx;		/* digest contexts */
	uint32_t	 digc;		/* # of digests */
	multigest_dig_t	 digs[MG_MAX_DIG];	/* digest algorithms being used */
} multigest_t;

#ifndef __BEGIN_DECLS
#  if defined(__cplusplus)
#  define __BEGIN_DECLS           extern "C" {
#  define __END_DECLS             }
#  else
#  define __BEGIN_DECLS
#  define __END_DECLS
#  endif
#endif

__BEGIN_DECLS

/* new and free */
multigest_t *multigest_new(void);
void multigest_free(multigest_t */*s*/);

/* low-level interface */
int multigest_init(multigest_t */*multigest*/, const char */*alg*/);
int multigest_add_subst(multigest_t */*multigest*/, const char */*from*/, const char */*to*/);
void multigest_update(multigest_t */*multigest*/, const char */*data*/, size_t /*len*/);
void multigest_final(multigest_t */*multigest*/, uint8_t */*raw*/);
uint32_t multigest_get_rawsize(multigest_t */*multigest*/);

/* high-level interface */
uint8_t *multigest_data(const char */*alg*/, const char */*data*/, size_t /*size*/, uint8_t */*raw*/, const char */*pat*/, const char */*repl*/);
uint8_t *multigest_file(const char */*alg*/, const char */*f*/, uint8_t */*raw*/, const char */*pat*/, const char */*repl*/);
uint32_t multigest_algs_rawsize(const char */*algs*/);

/* output */
void multigest_unpcstring(const char */*in*/, size_t /*isize*/, char */*out*/, size_t /*osize*/);
int multigest_format_hex(uint8_t */*raw*/, const char */*algname*/, char */*out*/, size_t /*size*/);
int multigest_print_hex(uint8_t */*raw*/, const char */*algname*/, const char */*outname*/, const char */*f*/, const char */*sub*/, const char */*sep*/, const char */*format*/);
char *multigest_format_raw(const uint8_t */*in*/, size_t /*insize*/, char */*out*/, size_t /*outsize*/);

__END_DECLS

#endif
