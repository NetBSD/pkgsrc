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
#include <sys/param.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "multigest.h"
#include "merkletree.h"

#define MERKLETREE_MAX_ROWS	16

#ifndef __UNCONST
#define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))
#endif

/* a row of digests in a merkle tree */
typedef struct merkletree_row_t {
	uint64_t	 outc;		/* # of output bytes */
	uint64_t	 blocks;	/* # of blocks in this row */
	char		*out;		/* sums for this row */
} merkletree_row_t;

/* a tree of rows */
typedef struct Rows {
	uint64_t		 height;	/* # of row in tree */
	merkletree_row_t	 row[MERKLETREE_MAX_ROWS];	/* rows of digests in tree */
} Rows;


/* round up to correct number of blocks */
static inline uint64_t
numblocks(uint64_t size, uint64_t blocksize)
{
	return (size + (blocksize - 1)) / blocksize;
}

/* dynamically allocate the tree */
static int
allocate_tree(merkletree_t *tree, uint64_t size, size_t h)
{
	Rows	*rows = (Rows *)tree->rows;

	if (h == 0) {
		rows->row[h].outc = size;
	}
	rows->row[h].blocks = numblocks(size, tree->blocksize);
	rows->row[h].out = calloc(1, rows->row[h].blocks * tree->rawoutsize);
	if (size > 0 && rows->row[h].blocks > 1) {
		return allocate_tree(tree, size / (tree->blocksize * tree->rawoutsize), ++rows->height);
	}
	return (int)++rows->height;
}

/* calculate a row in a tree */
static int
calc_row(merkletree_t *tree, FILE *fp, char *v, size_t size, size_t h)
{
	uint8_t	 tmp[8192];
	size_t	 xfer;
	size_t	 cc;
	size_t	 b;
	Rows	*rows = (Rows *)tree->rows;

	rows->row[h].outc = 0;
	for (b = cc = 0 ; cc < size; b++, cc += xfer) {
		if (fp) {
			xfer = fread(v, 1, tree->blocksize, fp);
			multigest_data(tree->algname, (const char *)v, xfer, tmp, NULL, NULL);
			multigest_format_raw(tmp, tree->rawoutsize / 2,
				&rows->row[h].out[rows->row[h].outc], tree->rawoutsize);
		} else {
			xfer = MIN(size - cc, tree->blocksize);
			multigest_data(tree->algname, (const char *)&v[cc], xfer,
				tmp, NULL, NULL);
			multigest_format_raw(tmp, tree->rawoutsize / 2,
				&rows->row[h].out[rows->row[h].outc], tree->rawoutsize);
		}
		rows->row[h].outc += tree->rawoutsize;
	}
	if (h < rows->height - 1) {
		return calc_row(tree, NULL, rows->row[h].out, rows->row[h].outc, h + 1);
	}
	return 1;
}

/* skip over initial stuff */
static inline char *
skip_to_sum(char *s)
{
	char	*ret;
	char	*eq;

	if ((eq = strchr(s, '=')) == NULL) {
		ret = s;
	} else {
		for (ret = eq + 1; *ret == ' ' ; ret++) {
		}
	}
	return ret;
}

/* get the col'th column */
static inline char *
get_column(char *s, size_t col)
{
	size_t	 i;
	char	*space;
	char	*p;

	for (space = s, i = 0 ; i < col ; i++, space = p + 1) {
		if ((p = strchr(space + 1, ' ')) == NULL) {
			return NULL;
		}
	}
	return space;
}

/* set up the tree */
static inline int
setup_tree(merkletree_t *tree, size_t size, const char *alg, size_t blocksize)
{
	if (tree == NULL || alg == NULL || blocksize == 0) {
		fprintf(stderr, "bad arg\n");
		return 0;
	}
	memset(tree, 0x0, sizeof(*tree));
	if ((tree->rawoutsize = multigest_algs_rawsize(alg) * 2) == 0) {
		fprintf(stderr, "unrecognised algorithm '%s'\n", alg);
		return 0;
	}
	snprintf(tree->algname, sizeof(tree->algname), "%s", alg);
	tree->size = size;
	tree->blocksize = blocksize;
	tree->rows = calloc(1, sizeof(Rows));
	allocate_tree(tree, tree->size, 0);
	return 1;
}

/************************************************************************/

/* calculate a merkle tree on data */
int
merkletree_data(merkletree_t *tree, const void *v, size_t size, const char *alg, size_t blocksize)
{
	if (!setup_tree(tree, size, alg, blocksize)) {
		return 0;
	}
	return calc_row(tree, NULL, __UNCONST(v), tree->size, 0);
}

/* calculate a merkle tree on a file */
int
merkletree_file(merkletree_t *tree, const char *f, const char *alg, size_t blocksize)
{
	struct stat	 st;
	size_t		 size;
	char		*mapped;
	char		*alloc;
	FILE		*fp;
	int		 ret;

	if (tree == NULL || f == NULL || alg == NULL || blocksize == 0) {
		return 0;
	}
	if ((fp = fopen(f, "r")) == NULL) {
		fprintf(stderr, "can't open file '%s'\n", f);
		return 0;
	}
	ret = 0;
	fstat(fileno(fp), &st);
	size = st.st_size;
	alloc = NULL;
	if ((mapped = mmap(NULL, size, PROT_READ, MAP_SHARED, fileno(fp), 0)) == MAP_FAILED) {
		if ((alloc = calloc(1, blocksize)) == NULL) {
			goto done;
		}
		if (!setup_tree(tree, size, alg, blocksize)) {
			goto done;
		}
		ret = calc_row(tree, fp, alloc, tree->size, 0);
	} else {
		ret = merkletree_data(tree, mapped, size, alg, blocksize);
	}
done:
	if (mapped != MAP_FAILED) {
		munmap(mapped, tree->size);
	}
	if (alloc) {
		free(alloc);
	}
	fclose(fp);
	return ret;
}

/* format a merkle tree */
int
merkletree_snprintf(merkletree_t *tree, const char *f, char *buf, size_t size)
{
	size_t	 cc;
	size_t	 h;
	Rows	*rows;

	if (tree != NULL && buf != NULL && size > 0) {
		rows = (Rows *)tree->rows;
		cc = 0;
		if (f == NULL) {
			f = "[stdin]";
		}
		cc = snprintf(buf, size,
			"merkle %s %" PRIu64 " %" PRIu64 " %" PRIu64 " (%s) = ",
			tree->algname, rows->height, tree->size, tree->blocksize, f);
		for (h = 0 ; h < rows->height ; h++) {
			cc += snprintf(&buf[cc], size - cc, "%s", rows->row[h].out);
		}
		return (int)cc;
	}
	return 0;
}

/* format a merkle tree */
int
merkletree_asprintf(merkletree_t *tree, const char *f, char **buf)
{
	size_t	 size;
	size_t	 cc;
	size_t	 h;
	Rows	*rows = (Rows *)tree->rows;

	if (tree != NULL) {
		if (f == NULL) {
			f = "[stdin]";
		}
		for (size = 0, h = 0 ; h < rows->height ; h++) {
			size += strlen((char *)rows->row[h].out);
		}
		size += strlen(f) + 100;
		if ((*buf = calloc(1, size)) == NULL) {
			return 0;
		}
		cc = snprintf(*buf, size,
			"merkle %s %" PRIu64 " %" PRIu64 " %" PRIu64 " (%s) = ",
			tree->algname, rows->height, tree->size, tree->blocksize, f);
		for (h = 0 ; h < rows->height ; h++) {
			cc += snprintf(&(*buf)[cc], size - cc, "%s", rows->row[h].out);
		}
		return (int)cc;
	}
	return 0;
}

/* free resources */
void
merkletree_free(merkletree_t *tree)
{
	uint64_t	 i;
	Rows		*rows;

	if (tree != NULL) {
		rows = (Rows *)tree->rows;
		for (i = 0 ; i < rows->height ; i++) {
			free(rows->row[i].out);
		}
		free(tree->rows);
	}
}

/* higher level */

/* retrieve sum information from a sum file */
int
merkletree_sum_info(merkletree_t *tree, const char *f, char **buf)
{
	struct stat	 st;
	FILE		*fp;
	char		*alg;
	char		*p;
	int		 ret;

	if (tree == NULL || f == NULL || buf == NULL || *buf == NULL) {
		return 0;
	}
	memset(tree, 0x0, sizeof(*tree));
	if ((fp = fopen(f, "r")) == NULL) {
		fprintf(stderr, "can't open '%s'\n", f);
		return 0;
	}
	fstat(fileno(fp), &st);
	*buf = calloc(1, (size_t)(st.st_size + 1));
	ret = (int)fread(*buf, 1, (size_t)(st.st_size - 1), fp);
	fclose(fp);
	(*buf)[ret] = 0x0;
	if ((alg = get_column(*buf, 1)) == NULL) {
		return 0;
	}
	if ((p = get_column(*buf, 2)) == NULL) {
		return 0;
	}
	snprintf(tree->algname, sizeof(tree->algname), "%.*s", (int)(p - alg) - 1, alg);
	if ((tree->rawoutsize = multigest_algs_rawsize(tree->algname) * 2) == 0) {
		fprintf(stderr, "bad alg name '%s'\n", tree->algname);
		return 0;
	}
	if ((p = get_column(*buf, 3)) == NULL) {
		return 0;
	}
	tree->size = (uint64_t)strtoull(p, NULL, 0);
	if ((p = get_column(*buf, 4)) == NULL) {
		return 0;
	}
	tree->blocksize = (uint64_t)strtoull(p, NULL, 0);
	return ret;
}

/* verify a merkletree sum output against a file in the file system */
int
merkletree_verify(const char *sumfile, const char *f)
{
	merkletree_t	 store;
	merkletree_t	 calc;
	size_t		 off;
	size_t		 len;
	size_t		 i;
	char		*calcsum;
	char		*stored;
	char		*sum[2];

	if (sumfile == NULL || f == NULL) {
		return 1;
	}
	memset(&calc, 0x0, sizeof(calc));
	memset(&store, 0x0, sizeof(store));
	if (!merkletree_sum_info(&store, sumfile, &stored)) {
		return 0;
	}
	merkletree_file(&calc, f, store.algname, store.blocksize);
	merkletree_asprintf(&calc, f, &calcsum);
	sum[0] = skip_to_sum(calcsum);
	sum[1] = skip_to_sum(stored);
	if ((len = strlen(sum[0])) == strlen(sum[1]) && memcmp(sum[0], sum[1], len) == 0) {
		return 1;
	}
	for (off = 0, i = 0 ; off < store.size ; i += store.rawoutsize, off += store.blocksize) {
		if (memcmp(&sum[0][i], &sum[1][i], store.rawoutsize) != 0) {
			printf("[%" PRIu64 "] %" PRIu64 ", %" PRIu64 "\n",
				off / store.blocksize, off, off + store.blocksize - 1);
		}
	}
	return 0;
}
