/* $NetBSD: extract.c,v 1.3 2014/02/19 19:31:08 drochner Exp $ */

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

static int
getbin(void *buf, int len)
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

	return (-1);
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

	sprintf(name, "%08x.%08x", uh->uh_signature, uh->uh_rev);
	fd = open(name, O_WRONLY|O_CREAT|O_TRUNC|O_EXCL, 0644);
	if (fd < 0)
		err(2, "open %s", name);
	write(fd, uh, len);
	close(fd);

	used = 0;
	for (i = 0; i < 8; i++) {
		if (!(uh->uh_proc_flags & (1 << i)))
			continue;
		sprintf(alias, "%08x-%d", uh->uh_signature, i);
		used += link_unless_newer_exists(name, alias, uh->uh_rev);
	}
	if (eh) {
		/* extension headers are unused in rev. 20140122 */
		for (j = 0; j < eh->uet_count; j++) {
			eps = &eh->uet_proc_sig[j];
			for (i = 0; i < 8; i++) {
				if (!(eps->ups_proc_flags & (1 << i)))
					continue;
				sprintf(alias, "%08x-%d",
					eps->ups_signature, i);
				used += link_unless_newer_exists(name, alias,
								 uh->uh_rev);
			}
		}
	}

	unlink(name);
	printf("%s: %d links\n", name, used);
}

int
main(int argc, char **argv)
{
	struct intel1_ucode_header uh;
	int datasize, totalsize;
	void *theupdate;
	struct intel1_ucode_ext_table *eh;

	if (argc < 2)
		errx(1, "need filename");

	in = fopen(argv[1], "r");
	if (!in)
		err(2, "could not open \"%s\"", argv[1]);

	for (;;) {
		if (getbin(&uh, sizeof(uh)) < 0)
			break;
		if (uh.uh_header_ver != 1)
			errx(3, "wrong file format, last line %d", lc);
		if (uh.uh_data_size)
			datasize = uh.uh_data_size;
		else
			datasize = 2000;
		if (uh.uh_total_size)
			totalsize = uh.uh_total_size;
		else
			totalsize = datasize + 48;

		theupdate = malloc(totalsize);
		memcpy(theupdate, &uh, 48);
		if (getbin((char *)theupdate + 48, totalsize - 48) < 0)
			errx(3, "data format");

		if (totalsize != datasize + 48)
			eh = (void *)((char *)theupdate + 48 + datasize);
		else
			eh = NULL;

		writeout(theupdate, totalsize, eh);
		free(theupdate);

	}

	fclose(in);
	exit(0);
}
