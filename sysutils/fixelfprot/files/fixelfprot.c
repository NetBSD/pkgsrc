/*
 * Fix up the permission bits for the program load section containing the
 * .got section of a PPC ELF binary.
 */

#include <stdio.h>
#include <err.h>
#define ELFSIZE 32
#include <sys/exec_elf.h>
#include <sys/endian.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void xlseek(int, off_t, int);
void xread(int, void *, size_t);
void xwrite(int, void *, size_t);
void *xmalloc(size_t);

void
xlseek(int fd, off_t off, int whence)
{
	int rv;

	rv = lseek(fd, off, whence);
	if (rv < 0) {
		err(1, "lseek");
	}
}

void
xread(int fd, void *buf, size_t size)
{
	int rv;

	rv = read(fd, buf, size);
	if (rv < 0) {
		err(1, "read");
	}
	if (rv != size) {
		errx(1, "short read %d vs. %d", rv, size);
	}
}

void
xwrite(int fd, void *buf, size_t size)
{
	int rv;

	rv = write(fd, buf, size);
	if (rv < 0) {
		err(1, "write");
	}
	if (rv != size) {
		errx(1, "short write %d vs. %d", rv, size);
	}
}


void *
xmalloc(size_t size)
{
	void *buf;

	buf = malloc(size);
	if (buf == NULL) {
		err(1, "malloc");
	}
	return buf;
}

int
main(int argc, char **argv)
{
	Elf32_Ehdr eh;
	Elf32_Phdr *ph;
	Elf32_Shdr *sh;
	Elf32_Addr gotaddr;
	size_t phsize, shsize, strsize;
	char *strbuf;
	int fd, i, idx;

	/*
	 * Check arguments and open the file.
	 */

	if (argc != 2) {
		errx(1, "usage: %s <file>", getprogname());
	}
	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		err(1, "open %s", argv[1]);
	}

	/*
	 * Read and validate the ELF header.
	 */

	xread(fd, &eh, sizeof (eh));
	if (memcmp(eh.e_ident, ELFMAG, SELFMAG) != 0 ||
	    eh.e_ident[EI_CLASS] != ELFCLASS) {
		errx(1, "not an ELF file");
	}
	if (be16toh(eh.e_machine) != EM_PPC) {
		errx(1, "ELF file is wrong architecture");
	}
	if (be16toh(eh.e_type) != ET_EXEC) {
		errx(1, "ELF file is not an executable");
	}
	if (be16toh(eh.e_shnum) > 512 || be16toh(eh.e_phnum) > 128) {
		errx(1, "ELF file has too many sections");
	}
	if (be16toh(eh.e_shstrndx) >= be16toh(eh.e_shnum)) {
		errx(1, "string table index out of range");
	}

	/*
	 * Read the program headers, section headers and string table.
	 */

	phsize = be16toh(eh.e_phnum) * sizeof(Elf_Phdr);
	ph = xmalloc(phsize);
	xlseek(fd, (off_t)be32toh(eh.e_phoff), SEEK_SET);
	xread(fd, ph, phsize);

	shsize = be16toh(eh.e_shnum) * sizeof(Elf_Shdr);
	sh = xmalloc(shsize);
	xlseek(fd, (off_t)be32toh(eh.e_shoff), SEEK_SET);
	xread(fd, sh, shsize);

	idx = be16toh(eh.e_shstrndx);
	strsize = be32toh(sh[idx].sh_size);
	strbuf = xmalloc(strsize);
	xlseek(fd, (off_t)be32toh(sh[idx].sh_offset), SEEK_SET);
	xread(fd, strbuf, strsize);

	/*
	 * Find the .got section.
	 */

	gotaddr = 0;
	for (i = 0; i < be16toh(eh.e_shnum); i++) {
		if (strcmp(&strbuf[be32toh(sh[i].sh_name)], ".got") == 0) {
			gotaddr = be32toh(sh[i].sh_addr);
			break;
		}
	}
	if (gotaddr == 0) {
		errx(1, "couldn't find the .got section");
	}

	/*
	 * Find the program header load section containing the .got section.
	 */

	idx = -1;
	for (i = 0; i < be16toh(eh.e_phnum); i++) {
		if (be32toh(ph[i].p_type) == PT_LOAD &&
		    gotaddr >= be32toh(ph[i].p_vaddr) &&
		    gotaddr < be32toh(ph[i].p_vaddr) + be32toh(ph[i].p_memsz)) {
			idx = i;
		}
	}
	if (idx == -1) {
		errx(1, "couldn't find program header for .got");
	}
	if (be32toh(ph[idx].p_flags) & PF_X) {
		errx(1, "permission bits already include execute");
	}

	/*
	 * Add execute permission and write back the entry.
	 */

	ph[idx].p_flags |= be32toh(PF_X);
	xlseek(fd, (off_t)be32toh(eh.e_phoff), SEEK_SET);
	xwrite(fd, ph, phsize);

	errx(0, "execute permission added");
	exit(0);
}
