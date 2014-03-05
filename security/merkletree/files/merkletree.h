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
#ifndef MERKLETREE_H_
#define MERKLETREE_H_	20140303

#include <sys/types.h>

#include <inttypes.h>

#define MERKLE_MAX_ALGNAME	128

/* a merkle hash tree */
typedef struct merkletree_t {
	uint64_t	 size;		/* # of bytes to calculate sum over */
	uint64_t	 blocksize;	/* blocksize for calculation */
	char		 algname[MERKLE_MAX_ALGNAME];	/* name of digest algorithm */
	void		*alg;		/* digest algorithm we're using */
	void		*rows;		/* the digest rows in the tree */
	uint32_t	 rawoutsize;	/* raw output size */
} merkletree_t;

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

int merkletree_file(merkletree_t */*tree*/, const char */*f*/, const char */*alg*/, size_t /*blocksize*/);
int merkletree_data(merkletree_t */*tree*/, const void */*v*/, size_t /*sz*/, const char */*alg*/, size_t /*blksize*/);
void merkletree_free(merkletree_t */*tree*/);
int merkletree_snprintf(merkletree_t */*tree*/, const char */*f*/, char */*buf*/, size_t /*size*/);
int merkletree_asprintf(merkletree_t */*tree*/, const char */*f*/, char **/*buf*/);

int merkletree_sum_info(merkletree_t */*tree*/, const char */*f*/, char **/*buf*/);
int merkletree_verify(const char */*sumfile*/, const char */*f*/);

__END_DECLS

#endif
