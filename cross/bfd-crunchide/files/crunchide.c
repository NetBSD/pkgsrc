/* $NetBSD: crunchide.c,v 1.1.1.1 1999/12/20 05:57:40 sakamoto Exp $ */
/* NetBSD: crunchide.c,v 1.9 1999/01/11 22:40:00 kleink Exp 	 */

/*
 * Copyright (c) 1997 Christopher G. Demetriou.  All rights reserved.
 * Copyright (c) 1994 University of Maryland
 * All Rights Reserved.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of U.M. not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  U.M. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * U.M. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL U.M.
 * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author: James da Silva, Systems Design and Analysis Group
 *			   Computer Science Department
 *			   University of Maryland at College Park
 */
/*
 * crunchide.c - tiptoes through an a.out symbol table, hiding all defined
 *	global symbols.  Allows the user to supply a "keep list" of symbols
 *	that are not to be hidden.  This program relies on the use of the
 * 	linker's -dc flag to actually put global bss data into the file's
 * 	bss segment (rather than leaving it as undefined "common" data).
 *
 * 	The point of all this is to allow multiple programs to be linked
 *	together without getting multiple-defined errors.
 *
 *	For example, consider a program "foo.c".  It can be linked with a
 *	small stub routine, called "foostub.c", eg:
 *	    int foo_main(int argc, char **argv){ return main(argc, argv); }
 *      like so:
 *	    cc -c foo.c foostub.c
 *	    ld -dc -r foo.o foostub.o -o foo.combined.o
 *	    crunchide -k _foo_main foo.combined.o
 *	at this point, foo.combined.o can be linked with another program
 * 	and invoked with "foo_main(argc, argv)".  foo's main() and any
 * 	other globals are hidden and will not conflict with other symbols.
 *
 * TODO:
 *	- resolve the theoretical hanging reloc problem (see check_reloc()
 *	  below). I have yet to see this problem actually occur in any real
 *	  program. In what cases will gcc/gas generate code that needs a
 *	  relative reloc from a global symbol, other than PIC?  The
 *	  solution is to not hide the symbol from the linker in this case,
 *	  but to generate some random name for it so that it doesn't link
 *	  with anything but holds the place for the reloc.
 *      - arrange that all the BSS segments start at the same address, so
 *	  that the final crunched binary BSS size is the max of all the
 *	  component programs' BSS sizes, rather than their sum.
 */

#include <sys/cdefs.h>
#ifndef lint
__RCSID("$NetBSD: crunchide.c,v 1.1.1.1 1999/12/20 05:57:40 sakamoto Exp $");
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <a.out.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bfd.h>

extern const char *__progname;

void usage      __P((void));
void add_to_keep_list __P((char *));
void add_file_to_keep_list __P((char *));
int hide_syms   __P((const char *, char *));
static void setup_section __P((bfd *, sec_ptr, PTR));
static void copy_section __P((bfd *, sec_ptr, PTR));

int verbose;

struct keep {
	struct keep *next;
	char *sym;
} *keep_list;

struct bfd_cookie {
	bfd *bfd;
	asymbol **symtable;
};

int
main(argc, argv)
	int argc;
	char **argv;
{
	int ch, errors;
	char *bfdname = NULL;

	while ((ch = getopt(argc, argv, "b:k:f:v")) != -1)
		switch (ch) {
		case 'b':
			bfdname = optarg;
			break;
		case 'k':
			add_to_keep_list(optarg);
			break;
		case 'f':
			add_file_to_keep_list(optarg);
			break;
		case 'v':
			verbose = 1;
			break;
		default:
			usage();
		}

	argc -= optind;
	argv += optind;

	if (argc == 0)
		usage();

	errors = 0;
	while (argc) {
		if (hide_syms(*argv, bfdname))
			errors = 1;
		argc--, argv++;
	}

	return errors;
}

void 
usage()
{
	const char **list;

	fprintf(stderr,
"Usage: %s [-b bfdname] [-k <symbol-name>] [-f <keep-list-file>] <files> ...\n",
		__progname);
	fprintf(stderr, "supported targets:");
	for (list = bfd_target_list(); *list != NULL; list++)
		fprintf(stderr, " %s", *list);
	fprintf(stderr, "\n");
	exit(1);
}

void 
add_to_keep_list(symbol)
	char *symbol;
{
	struct keep *newp, *prevp, *curp;
	int cmp;

	cmp = 0;

	for (curp = keep_list, prevp = NULL; curp;
	    prevp = curp, curp = curp->next)
		if ((cmp = strcmp(symbol, curp->sym)) <= 0)
			break;

	if (curp && cmp == 0)
		return;		/* already in table */

	newp = (struct keep *)malloc(sizeof (struct keep));
	if (newp)
		newp->sym = strdup(symbol);
	if (newp == NULL || newp->sym == NULL) {
		fprintf(stderr,
			"%s: out of memory for keep list\n", __progname);
		exit(1);
	}
	newp->next = curp;
	if (prevp)
		prevp->next = newp;
	else
		keep_list = newp;
}

int 
in_keep_list(symbol)
	const char *symbol;
{
	struct keep *curp;
	int cmp;

	cmp = 0;

	for (curp = keep_list; curp; curp = curp->next)
		if ((cmp = strcmp(symbol, curp->sym)) <= 0)
			break;

	return curp && cmp == 0;
}

void 
add_file_to_keep_list(filename)
	char *filename;
{
	FILE *keepf;
	char symbol[1024];
	int len;

	if ((keepf = fopen(filename, "r")) == NULL) {
		perror(filename);
		usage();
	}
	while (fgets(symbol, 1024, keepf)) {
		len = strlen(symbol);
		if (len && symbol[len - 1] == '\n')
			symbol[len - 1] = '\0';

		add_to_keep_list(symbol);
	}
	fclose(keepf);
}

int 
hide_syms(filename, bfdname)
	const char *filename;
	char *bfdname;
{
	int i, n, rv = 0;
	bfd *org_bfd = NULL, *new_bfd = NULL;
	char *tempname;
	char **name;
	long storage_needed, number_of_symbols;
	size_t fn_size;
	asymbol **org_symtable, **new_symtable;

	fn_size = strlen(filename);

	bfd_init();
	if ((org_bfd = bfd_openr(filename, bfdname)) == NULL) {
		bfd_perror(filename);
		return 1;
	}
	if (!bfd_check_format(org_bfd, bfd_object)) {
		bfd_perror(filename);
		goto err;
	}

	bfdname = bfd_get_target(org_bfd);
	tempname = tempnam(".", NULL);
	if ((new_bfd = bfd_openw(tempname, bfdname)) == NULL) {
		bfd_perror(tempname);
		goto err;
	}

	if (!bfd_set_format(new_bfd, bfd_get_format(org_bfd)) ||
	    !bfd_set_start_address(new_bfd, bfd_get_start_address(org_bfd)) ||
	    !bfd_set_file_flags(new_bfd, (bfd_get_file_flags(org_bfd) &
	      bfd_applicable_file_flags(new_bfd))) ||
	    !bfd_set_arch_mach (new_bfd, bfd_get_arch (org_bfd),
	      bfd_get_mach (org_bfd))) {
		bfd_perror(tempname);
		goto err;
	}
	bfd_map_over_sections(org_bfd, setup_section, (void *)new_bfd);

	storage_needed = bfd_get_symtab_upper_bound(org_bfd);
	if (storage_needed < 0)
		goto err;
	if (storage_needed == 0)
		goto out;

	org_symtable = (asymbol **)malloc(storage_needed);
	number_of_symbols = bfd_canonicalize_symtab(org_bfd, org_symtable);
	if (number_of_symbols < 0)
		goto err;

	new_symtable = (asymbol **)malloc(storage_needed);
	if (new_symtable == NULL)
		goto err;
	name = (char **)calloc(sizeof (char *), number_of_symbols);
	if (name == NULL)
		goto err;

	n = 0;
	for (i = 0; i < number_of_symbols; i++) {
		const char *symname;

		new_symtable[i] = org_symtable[i];
		if (!(new_symtable[i]->flags & BSF_GLOBAL))
			continue;

		symname = bfd_asymbol_name(new_symtable[i]);
		if (symname[0] == '_')
			symname++;
		if (in_keep_list(symname))
			continue;

		n++;

		/*
		 * make sure there's size for the next entry, even if it's
		 * as large as it can be.
		 *
		 * "_$$hide$$ <filename> <symname><NUL>" ->
		 *    9 + 3 + sizes of fn and sym name 
		 */
		name[i] = (char *)malloc(12 + fn_size + strlen(symname));
		sprintf(name[i], "_$$hide$$ %s %s", filename, symname);
		new_symtable[i]->name = name[i];
	}

	if (n > 0) {
		struct bfd_cookie cookie;

		new_symtable[number_of_symbols] = NULL;
		bfd_set_symtab(new_bfd, new_symtable, number_of_symbols);

		cookie.bfd = new_bfd;
		cookie.symtable = org_symtable;
		bfd_map_over_sections(org_bfd, copy_section, (void *)&cookie);

		if (!bfd_copy_private_bfd_data(org_bfd, new_bfd)) {
			bfd_perror("bfd_copy_private_bfd_data");
			goto err;
		}
	}

	bfd_close(new_bfd);
	bfd_close(org_bfd);

	if (rename(tempname, filename) < 0)
		perror("rename");
	unlink(tempname);

	for (i = 0; i < number_of_symbols; i++)
		if (name[i])
			free(name[i]);
	free(new_symtable);
	free(name);

out:
	return (rv);

err:
	rv = 1;
	if (org_bfd)
		bfd_close(org_bfd);
	if (new_bfd) {
		unlink(tempname);
		bfd_close(new_bfd);
	}
	goto out;
}

static void
setup_section(ibfd, isection, arg)
	bfd *ibfd;
	sec_ptr isection;
	PTR arg;
{
	sec_ptr osection;
	bfd *obfd = (bfd *)arg;

	if ((osection = bfd_make_section_anyway(obfd,
	      bfd_section_name(ibfd, isection))) == NULL ||
	    !bfd_set_section_size(obfd, osection,
	      bfd_section_size(ibfd, isection)) ||
	    !bfd_set_section_vma(obfd, osection,
	      bfd_section_vma(ibfd, isection)) ||
	    !bfd_set_section_alignment(obfd, osection,
	      bfd_section_alignment(ibfd, isection)) ||
	    !bfd_set_section_flags(obfd, osection,
	      bfd_get_section_flags(ibfd, isection))) {
		bfd_perror("setup_section");
		return;
	}

	isection->output_section = osection;
	isection->output_offset = 0;
	if (!bfd_copy_private_section_data(ibfd, isection, obfd, osection)) {
		bfd_perror("setup_section");
		return;
	}
}

static void
copy_section(ibfd, isection, arg)
	bfd *ibfd;
	sec_ptr isection;
	PTR arg;
{
	struct bfd_cookie *bc = (struct bfd_cookie *)arg;
	bfd *obfd = bc->bfd;
	asymbol **isym = bc->symtable;
	arelent **relpp;
	sec_ptr osection;
	PTR memhunk;
	bfd_size_type size;
	long relcount, relsize;

	osection = isection->output_section;
	size = bfd_get_section_size_before_reloc(isection);
	if (size == 0 || osection == 0)
		return;

	relsize = bfd_get_reloc_upper_bound(ibfd, isection);
	if (relsize < 0) {
		bfd_perror(bfd_get_filename(ibfd));
	}
	if (relsize == 0) {
		bfd_set_reloc(obfd, osection, NULL, 0);
	} else {
		relpp = (arelent **)malloc(relsize);
		relcount = bfd_canonicalize_reloc(ibfd, isection, relpp, isym);
		if (relcount < 0)
			bfd_perror(bfd_get_filename(ibfd));
		bfd_set_reloc(obfd, osection, relpp, relcount);
	}

	isection->_cooked_size = isection->_raw_size;
	isection->reloc_done = true;

	if (bfd_get_section_flags(ibfd, isection) & SEC_HAS_CONTENTS) {
		memhunk = (PTR)malloc((unsigned int)size);
		if (!bfd_get_section_contents(ibfd, isection, memhunk, 0, size))
			bfd_perror(bfd_get_filename(ibfd));
		if (!bfd_set_section_contents(obfd, osection, memhunk, 0, size))
			bfd_perror(bfd_get_filename(obfd));
		free(memhunk);
	} else if (bfd_get_section_flags(ibfd, isection) & SEC_LOAD) {
		memhunk = (PTR)malloc((unsigned int)size);
		memset(memhunk, 0, size);
		if (!bfd_set_section_contents(obfd, osection, memhunk, 0, size))
			bfd_perror(bfd_get_filename(obfd));
		free(memhunk);
	}
}
