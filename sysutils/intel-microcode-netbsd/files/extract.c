/* $NetBSD: extract.c,v 1.5 2019/05/10 18:26:46 maxv Exp $ */

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <err.h>

#include <x86/cpu_ucode.h>

FILE *in;
int lc;

/*
 * Read .dat data, and convert to binary format.
 */
static int
get_bin(void *buf, int len)
{
	char lbuf[100], *l;
	uint32_t b[4];
	int n;

	while ((l = fgets(lbuf, sizeof(lbuf), in))) {
		lc++;
		if (l[0] == '/')
			continue;
		n = sscanf(l, "0x%x, 0x%x, 0x%x, 0x%x,",
		    &b[0], &b[1], &b[2], &b[3]);
		if (n != 4)
			errx(3, "can't digest line %d", lc);

		if (len < 16)
			errx(3, "wrong size assumption");
		memcpy(buf, b, 16);
		len -= 16;
		if (len == 0)
			return 0;
		buf = (char *)buf + 16;
	}

	return -1;
}

static int
isnewer(const char *fn, int rev)
{
	int fd;
	struct intel1_ucode_header uh;

	fd = open(fn, O_RDONLY, 0);
	if (fd < 0)
		err(2, "open %s", fn);
	read(fd, &uh, sizeof(uh));
	close(fd);

	return (uh.uh_rev > rev);
}

static int
link_unless_newer_exists(const char *name, const char *alias, int rev)
{
again:
	if (link(name, alias) == 0) {
		printf("link %s->%s\n", alias, name);
		return 1;
	}
	if (errno != EEXIST)
		err(2, "link %s->%s", alias, name);
	if (isnewer(alias, rev))
		return 0;
	printf("replacing %s\n", alias);
	if (unlink(alias))
		err(2, "unlink %s", alias);
	goto again;
}

static void
writeout(struct intel1_ucode_header *uh, int len,
    struct intel1_ucode_ext_table *eh)
{
	char name[18], alias[11];
	int fd, used, i, j;
	struct intel1_ucode_proc_signature *eps;
	int rv;

	/* Write the microcode to a file. */
	snprintf(name, sizeof(name), "%08x.%08x", uh->uh_signature, uh->uh_rev);
	fd = open(name, O_WRONLY|O_CREAT|O_TRUNC|O_EXCL, 0644);
	if (fd < 0)
		err(2, "open %s", name);
	rv = write(fd, uh, len);
	if (rv == -1)
		err(EXIT_FAILURE, "failed to write %s\n", name);
	close(fd);

	used = 0;
	for (i = 0; i < 8; i++) {
		if (!(uh->uh_proc_flags & (1 << i)))
			continue;
		snprintf(alias, sizeof(alias), "%08x-%d", uh->uh_signature, i);
		used += link_unless_newer_exists(name, alias, uh->uh_rev);
	}
	if (eh) {
		printf("%s: Check the extended header.\n", __func__);
		for (j = 0; j < eh->uet_count; j++) {
			eps = &eh->uet_proc_sig[j];
			for (i = 0; i < 8; i++) {
				if (!(eps->ups_proc_flags & (1 << i)))
					continue;
				snprintf(alias, sizeof(alias), "%08x-%d",
				    eps->ups_signature, i);
				used += link_unless_newer_exists(name, alias,
				    uh->uh_rev);
			}
		}
	}

	unlink(name);
	printf("%s: %d links\n", name, used);
}

static void
get_sizes(struct intel1_ucode_header *uh, uint32_t *datasize,
    uint32_t *totalsize)
{
	if (uh->uh_data_size)
		*datasize = uh->uh_data_size;
	else
		*datasize = 2000;
	if (uh->uh_total_size)
		*totalsize = uh->uh_total_size;
	else
		*totalsize = *datasize + 48;
}

/*
 * Extract .dat (or .inc) file. Usually for "microcode.dat".
 */
static int
extract_dat(const char *fname)
{
	struct intel1_ucode_ext_table *eh;
	struct intel1_ucode_header uh;
	uint32_t datasize, totalsize;
	void *theupdate;

	in = fopen(fname, "r");
	if (!in)
		err(2, "could not open \"%s\"", fname);

	for (;;) {
		/* Get the ucode header. */
		if (get_bin(&uh, sizeof(uh)) < 0)
			break;
		if (uh.uh_header_ver != 1)
			errx(3, "wrong file format, last line %d", lc);

		/* Compute the total size, and fetch everything. */
		get_sizes(&uh, &datasize, &totalsize);
		theupdate = malloc(totalsize);
		memcpy(theupdate, &uh, 48);
		if (get_bin((char *)theupdate + 48, totalsize - 48) < 0)
			errx(3, "data format");

		/* Maybe an extended header. */
		if (totalsize != datasize + 48)
			eh = (void *)((char *)theupdate + 48 + datasize);
		else
			eh = NULL;

		/* Write out the ucode. */
		writeout(theupdate, totalsize, eh);
		free(theupdate);
	}

	fclose(in);

	return 0;
}

/*
 * Extract binary files (UV-WX-YZ style filename).
 */
static int
extract_bin(int argc, char **argv)
{
	struct intel1_ucode_header *uh;
	uint32_t datasize, totalsize;
	void *theupdate, *buf;
	struct intel1_ucode_ext_table *eh;
	struct stat sb;
	size_t left;
	int i, rv;

	argv++; /* Skip argc[0] (command name). */

	for (i = 1; i < argc; i++, argv++) {
		rv = stat(*argv, &sb);
		if (rv != 0)
			err(EXIT_FAILURE, "failed to stat \"%s\"", *argv);

		theupdate = buf = malloc(sb.st_size);
		if (theupdate == NULL)
			err(EXIT_FAILURE,
			    "failed to alloc buf for \"%s\" (size = %zu)",
			    *argv, sb.st_size);

		in = fopen(*argv, "r");
		if (!in)
			err(EXIT_FAILURE, "could not open \"%s\"", *argv);

		rv = fread(theupdate, sizeof(char), sb.st_size, in);
		if (rv != sb.st_size)
			err(EXIT_FAILURE,
			    "failed to read \"%s\" (size = %zu)",
			    *argv, sb.st_size);
		left = sb.st_size;

next:
		uh = (struct intel1_ucode_header *)theupdate;

#if 0 /* Dump header */
		for (int j = 0; j < sizeof(struct intel1_ucode_header) / 4;
		     j++) {
			uint32_t *q = (uint32_t *)uh;

			if ((j % 4) == 0)
				printf("%08x:", j);
			printf(" %08x", q[j]);
			if ((j % 4) == 3)
				printf("\n");
		}
		printf("\n");
#endif

		if (uh->uh_header_ver != 1)
			errx(EXIT_FAILURE,
			    "wrong file format, last line %d", lc);

		get_sizes(uh, &datasize, &totalsize);

		if (totalsize != datasize + 48)
			eh = (void *)((char *)theupdate + 48 + datasize);
		else
			eh = NULL;

		writeout(theupdate, totalsize, eh);

		if ((eh == NULL) && (totalsize != left)) {
			printf("file = %s. size in headers (%u) != file size "
			    "left (%zu). This file has multiple entries "
			    "without the extended signature stucture.\n",
			    *argv, totalsize, left);
			theupdate += totalsize;
			left -= totalsize;
			goto next;
		}

		free(buf);
		fclose(in);
	}

	return 0;
}

int
main(int argc, char **argv)
{
	const char *p;
	int rv;

	if (argc < 2)
		errx(1, "need filename");

	p = strchr(argv[1], '.');
	if ((p != NULL) && (strcmp(p + 1, "dat") == 0)) {
		/* Extract microcode.dat file */
		rv = extract_dat(argv[1]);
	} else {
		/* Extract UV-WX-YZ files */
		rv = extract_bin(argc, argv);
	}

	return rv;
}
