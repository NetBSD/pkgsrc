/*
 * $NetBSD: netbsd.c,v 1.1.1.1 2001/07/21 02:51:35 gmcgarry Exp $
 *
 * i386 netbsd (GNU as, GNU ld)
 */

#include <string.h>

#define LCC_LIBPATH	"@PREFIX@/libexec/"
#define LCC_INCPATH	"@PREFIX@/share/lcc/include"

char *suffixes[] = { ".c", ".i", ".s", ".o", ".out", 0 };

char inputs[256] = "";

char *cpp[] = {
	LCC_LIBPATH "cpp",
	"-D__STDC__=1",
#ifdef __ELF__
	"-D__ELF__",
#else
	"",
#endif
	"-Di386",
	"-D__NetBSD__",
	"-D__KPRINTF_ATTRIBUTE__",
	"-D__STRICT_ANSI__",
	"", /* _POSIX_SOURCE */
	"$1",
	"$2",
	"$3",
	0
};
char *include[] = {
	"-I" LCC_INCPATH,
	"-I/usr/include",
	0
};
char *com[] = {
	LCC_LIBPATH "rcc",
#ifdef __ELF__
	"-target=x86/netbsdelf",
#else
	"-target=x86/netbsd",
#endif
	"$1",
	"$2",
	"$3",
	0
};
char *as[] = {
	"/usr/bin/as",
	"-o",
	"$3",
	"$1",
	"$2",
	0
};
char *ld[] = {
	"/usr/bin/ld",
	"-m",
#ifdef __ELF__
	"elf_i386",
#else
	"i386nbsd",
#endif
	"-dynamic-linker",
#ifdef __ELF__
	"/usr/libexec/ld.elf_so",
#else
	"/usr/libexec/ld.aout_so",
#endif
	"-o",
	"$3",
	"$1",
	"/usr/lib/crt0.o",
	"/usr/lib/crtbegin.o",
	"$2",
	"", /* -b */
	"-lc",
	"/usr/lib/crtend.o",
	0
};
static char *bbexit = LCC_LIBPATH "bbexit.o";

extern char *concat(char *, char *);
extern int access(const char *, int);

int option(char *arg) {
	if (strncmp(arg, "-lccdir=", 8) == 0) {
		cpp[0] = concat(&arg[8], "/cpp");
		include[0] = concat("-I", concat(&arg[8], "/include"));
		com[0] = concat(&arg[8], "/rcc");
		bbexit = concat(&arg[8], "/bbexit.o");
	} else if (strncmp(arg, "-posix",6) == 0) {
		cpp[7] = "-D_POSIX_SOURCE";
	} else if (strcmp(arg, "-g") == 0)
		;
	else if (strcmp(arg, "-b") == 0 && access(bbexit, 4) == 0)
		ld[11] = bbexit;
	else if (strcmp(arg, "-p") == 0) {
		ld[8] = "/usr/lib/gcrt0.o";
		ld[14] = "-lc_p";
	}
	else if (strcmp(arg, "-static") == 0) {
		ld[3] = "-static";
		ld[4] = "";
	}
	else
		return 0;
	return 1;
}
