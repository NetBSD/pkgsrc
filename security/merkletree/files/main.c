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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "merkletree.h"

#define MERKLE_VERSION_STRING	"20130723"

#define KB(x)	(1024 * (x))
#define MB(x)	(1024 * 1024 * (x))

/* read from stdin (up to a max size) */
static ssize_t
dostdin(merkletree_t *tree, const char *alg, uint64_t blocksize, uint64_t maxsz)
{
	uint8_t	*buf;
	ssize_t	 cc;
	int	 ret;
	int	 i;

	if ((buf = calloc(1, (unsigned)maxsz)) == NULL) {
		(void) fprintf(stderr, "can't allocate %" PRIu64 " bytes\n", maxsz);
		return 0;
	}
	for (cc = 0 ; (i = read(STDIN_FILENO, &buf[cc], (size_t)(maxsz - cc))) > 0 && cc < (ssize_t)maxsz ; cc += i) {
	}
	ret = merkletree_data(tree, buf, cc, alg, blocksize);
	free(buf);
	return ret;
}

/* write to output file, or stdout if none specified */
static int
dooutput(const char *outname, char *output)
{
	FILE	*fp;

	if (outname) {
		if ((fp = fopen(outname, "w")) == NULL) {
			fprintf(stderr, "can't write to output file '%s'\n", outname);
			return 0;
		}
	} else {
		fp = stdout;
	}
	fprintf(fp, "%s\n", output);
	if (fp != stdout) {
		fclose(fp);
	}
	return 1;
}

int
main(int argc, char **argv)
{
	merkletree_t	 m;
	const char	*alg;
	const char	*sumfile;
	const char	*outname;
	uint64_t	 blocksize;
	uint64_t	 maxsz;
	char		 out[KB(10)];
	int		 ok;
	int		 cc;
	int		 i;

	blocksize = 512;
	maxsz = MB(10);
	alg = "sha1";
	outname = sumfile = NULL;
	while ((i = getopt(argc, argv, "Va:b:m:o:v:")) != -1) {
		switch(i) {
		case 'V':
			printf("merkle version %s\n", MERKLE_VERSION_STRING);
			exit(EXIT_SUCCESS);
		case 'a':
			alg = optarg;
			break;
		case 'b':
			blocksize = strtoul(optarg, NULL, 0);
			break;
		case 'm':
			maxsz = strtoul(optarg, NULL, 0);
			break;
		case 'o':
			outname = optarg;
			break;
		case 'v':
			sumfile = optarg;
			break;
		default:
			break;
		}
	}
	ok = 1;
	if (sumfile != NULL) {
		ok = merkletree_verify(sumfile, argv[optind]);
	} else if (optind == argc) {
		if (dostdin(&m, alg, blocksize, maxsz)) {
			cc = merkletree_snprintf(&m, NULL, out, sizeof(out));
			dooutput(outname, out);
		} else {
			ok = 0;
		}
	} else {
		for (i = optind ; i < argc ; i++) {
			memset(&m, 0x0, sizeof(m));
			if (merkletree_file(&m, argv[i], alg, blocksize)) {
				cc = merkletree_snprintf(&m, argv[i], out, sizeof(out));
				dooutput(outname, out);
			} else {
				ok = 0;
			}
		}
	}
	exit((ok) ? EXIT_SUCCESS : EXIT_FAILURE);
}
