/*	$OpenBSD: main.c,v 1.57 2015/09/10 22:48:58 nicm Exp $	*/
/*	$OpenBSD: tty.c,v 1.10 2014/08/10 02:44:26 guenther Exp $	*/
/*	$OpenBSD: io.c,v 1.26 2015/09/11 08:00:27 guenther Exp $	*/
/*	$OpenBSD: table.c,v 1.16 2015/09/01 13:12:31 tedu Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *		 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018,
 *		 2019, 2020
 *	mirabilos <m@mirbsd.org>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un-
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person's immediate fault when using the work as intended.
 */

#define EXTERN
#include "sh.h"

#if HAVE_LANGINFO_CODESET
#include <langinfo.h>
#endif
#if HAVE_SETLOCALE_CTYPE
#include <locale.h>
#endif

__RCSID("$MirOS: src/bin/mksh/main.c,v 1.372 2020/05/16 22:51:24 tg Exp $");

#ifndef MKSHRC_PATH
#define MKSHRC_PATH	"~/.mkshrc"
#endif

#ifndef MKSH_DEFAULT_TMPDIR
#define MKSH_DEFAULT_TMPDIR	MKSH_UNIXROOT "/tmp"
#endif

static uint8_t isuc(const char *);
static int main_init(int, const char *[], Source **, struct block **);
void chvt_reinit(void);
static void reclaim(void);
static void remove_temps(struct temp *);
static mksh_uari_t rndsetup(void);
static void init_environ(void);
#ifdef SIGWINCH
static void x_sigwinch(int);
#endif

static const char initsubs[] =
    "${PS2=> }"
    "${PS3=#? }"
    "${PS4=+ }"
    "${SECONDS=0}"
    "${TMOUT=0}"
    "${EPOCHREALTIME=}";

static const char *initcoms[] = {
	Ttypeset, Tdr, initvsn, NULL,
	Ttypeset, Tdx, "HOME", TPATH, TSHELL, NULL,
	Ttypeset, "-i10", "COLUMNS", "LINES", "SECONDS", "TMOUT", NULL,
	Talias,
	"integer=\\\\builtin typeset -i",
	"local=\\\\builtin typeset",
	/* not "alias -t --": hash -r needs to work */
	"hash=\\\\builtin alias -t",
	"type=\\\\builtin whence -v",
	"autoload=\\\\builtin typeset -fu",
	"functions=\\\\builtin typeset -f",
	"history=\\\\builtin fc -l",
	"nameref=\\\\builtin typeset -n",
	"nohup=nohup ",
	"r=\\\\builtin fc -e -",
	"login=\\\\builtin exec login",
	NULL,
	 /* this is what AT&T ksh seems to track, with the addition of emacs */
	Talias, "-tU",
	Tcat, "cc", "chmod", "cp", "date", "ed", "emacs", "grep", "ls",
	"make", "mv", "pr", "rm", "sed", Tsh, "vi", "who", NULL,
	NULL
};

static const char *restr_com[] = {
	Ttypeset, Tdr, TPATH, TENV, TSHELL, NULL
};

static bool initio_done;

/* top-level parsing and execution environment */
static struct env env;
struct env *e = &env;

/* compile-time assertions */

/* this one should be defined by the standard */
cta(char_is_1_char, (sizeof(char) == 1) && (sizeof(signed char) == 1) &&
    (sizeof(unsigned char) == 1));
cta(char_is_8_bits, ((CHAR_BIT) == 8) && ((int)(unsigned char)0xFF == 0xFF) &&
    ((int)(unsigned char)0x100 == 0) && ((int)(unsigned char)(int)-1 == 0xFF));
/* the next assertion is probably not really needed */
cta(short_is_2_char, sizeof(short) == 2);
cta(short_size_no_matter_of_signedness, sizeof(short) == sizeof(unsigned short));
/* the next assertion is probably not really needed */
cta(int_is_4_char, sizeof(int) == 4);
cta(int_size_no_matter_of_signedness, sizeof(int) == sizeof(unsigned int));

cta(long_ge_int, sizeof(long) >= sizeof(int));
cta(long_size_no_matter_of_signedness, sizeof(long) == sizeof(unsigned long));

#ifndef MKSH_LEGACY_MODE
/* the next assertion is probably not really needed */
cta(ari_is_4_char, sizeof(mksh_ari_t) == 4);
/* but this is */
cta(ari_has_31_bit, 0 < (mksh_ari_t)(((((mksh_ari_t)1 << 15) << 15) - 1) * 2 + 1));
/* the next assertion is probably not really needed */
cta(uari_is_4_char, sizeof(mksh_uari_t) == 4);
/* but the next three are; we REQUIRE unsigned integer wraparound */
cta(uari_has_31_bit, 0 < (mksh_uari_t)(((((mksh_uari_t)1 << 15) << 15) - 1) * 2 + 1));
cta(uari_has_32_bit, 0 < (mksh_uari_t)(((((mksh_uari_t)1 << 15) << 15) - 1) * 4 + 3));
cta(uari_wrap_32_bit,
    (mksh_uari_t)(((((mksh_uari_t)1 << 15) << 15) - 1) * 4 + 3) >
    (mksh_uari_t)(((((mksh_uari_t)1 << 15) << 15) - 1) * 4 + 4));
#endif
/* these are always required */
cta(ari_is_signed, (mksh_ari_t)-1 < (mksh_ari_t)0);
cta(uari_is_unsigned, (mksh_uari_t)-1 > (mksh_uari_t)0);
/* we require these to have the precisely same size and assume 2s complement */
cta(ari_size_no_matter_of_signedness, sizeof(mksh_ari_t) == sizeof(mksh_uari_t));

cta(sizet_size_no_matter_of_signedness, sizeof(ssize_t) == sizeof(size_t));
cta(sizet_voidptr_same_size, sizeof(size_t) == sizeof(void *));
cta(sizet_funcptr_same_size, sizeof(size_t) == sizeof(void (*)(void)));
/* our formatting routines assume this */
cta(ptr_fits_in_long, sizeof(size_t) <= sizeof(long));
cta(ari_fits_in_long, sizeof(mksh_ari_t) <= sizeof(long));

static mksh_uari_t
rndsetup(void)
{
	register uint32_t h;
	struct {
		ALLOC_ITEM alloc_INT;
		void *dataptr, *stkptr, *mallocptr;
#if defined(__GLIBC__) && (__GLIBC__ >= 2)
		sigjmp_buf jbuf;
#endif
		struct timeval tv;
	} *bufptr;
	char *cp;

	cp = alloc(sizeof(*bufptr) - sizeof(ALLOC_ITEM), APERM);
	/* clear the allocated space, for valgrind and to avoid UB */
	memset(cp, 0, sizeof(*bufptr) - sizeof(ALLOC_ITEM));
	/* undo what alloc() did to the malloc result address */
	bufptr = (void *)(cp - sizeof(ALLOC_ITEM));
	/* PIE or something similar provides us with deltas here */
	bufptr->dataptr = &rndsetupstate;
	/* ASLR in at least Windows, Linux, some BSDs */
	bufptr->stkptr = &bufptr;
	/* randomised malloc in BSD (and possibly others) */
	bufptr->mallocptr = bufptr;
#if defined(__GLIBC__) && (__GLIBC__ >= 2)
	/* glibc pointer guard */
	sigsetjmp(bufptr->jbuf, 1);
#endif
	/* introduce variation (and yes, second arg MBZ for portability) */
	mksh_TIME(bufptr->tv);

#ifdef MKSH_ALLOC_CATCH_UNDERRUNS
	mprotect(((char *)bufptr) + 4096, 4096, PROT_READ | PROT_WRITE);
#endif
	h = chvt_rndsetup(bufptr, sizeof(*bufptr));

	afree(cp, APERM);
	return ((mksh_uari_t)h);
}

void
chvt_reinit(void)
{
	kshpid = procpid = getpid();
	ksheuid = geteuid();
	kshpgrp = getpgrp();
	kshppid = getppid();
}

static const char *empty_argv[] = {
	Tmksh, NULL
};

static uint8_t
isuc(const char *cx) {
	char *cp, *x;
	uint8_t rv = 0;

	if (!cx || !*cx)
		return (0);

	/* uppercase a string duplicate */
	strdupx(x, cx, ATEMP);
	cp = x;
	while ((*cp = ksh_toupper(*cp)))
		++cp;

	/* check for UTF-8 */
	if (strstr(x, "UTF-8") || strstr(x, "UTF8"))
		rv = 1;

	/* free copy and out */
	afree(x, ATEMP);
	return (rv);
}

static int
main_init(int argc, const char *argv[], Source **sp, struct block **lp)
{
	int argi, i;
	Source *s = NULL;
	struct block *l;
	unsigned char restricted_shell = 0, errexit, utf_flag;
	char *cp;
	const char *ccp, **wp;
	struct tbl *vp;
	struct stat s_stdin;
#if !defined(_PATH_DEFPATH) && defined(_CS_PATH)
	ssize_t k;
#endif

#if defined(MKSH_EBCDIC) || defined(MKSH_FAUX_EBCDIC)
	ebcdic_init();
#endif
	set_ifs(TC_IFSWS);

#ifdef __OS2__
	os2_init(&argc, &argv);
#define builtin_name_cmp stricmp
#else
#define builtin_name_cmp strcmp
#endif

	/* do things like getpgrp() et al. */
	chvt_reinit();

	/* make sure argv[] is sane, for weird OSes */
	if (!*argv) {
		argv = empty_argv;
		argc = 1;
	}
	kshname = argv[0];

	/* initialise permanent Area */
	ainit(&aperm);
	/* max. name length: -2147483648 = 11 (+ NUL) */
	vtemp = alloc(offsetof(struct tbl, name[0]) + 12, APERM);

	/* set up base environment */
	env.type = E_NONE;
	ainit(&env.area);
	/* set up global l->vars and l->funs */
	newblock();

	/* Do this first so output routines (eg, errorf, shellf) can work */
	initio();

	/* determine the basename (without '-' or path) of the executable */
	ccp = kshname;
	goto begin_parsing_kshname;
	while ((i = ccp[argi++])) {
		if (mksh_cdirsep(i)) {
			ccp += argi;
 begin_parsing_kshname:
			argi = 0;
		}
	}
	Flag(FLOGIN) = (ord(*ccp) == ORD('-')) || (ord(*kshname) == ORD('-'));
	if (ord(*ccp) == ORD('-'))
		++ccp;
	if (!*ccp)
		ccp = empty_argv[0];

	/*
	 * Turn on nohup by default. (AT&T ksh does not have a nohup
	 * option - it always sends the hup).
	 */
	Flag(FNOHUP) = 1;

	/*
	 * Turn on brace expansion by default. AT&T kshs that have
	 * alternation always have it on.
	 */
	Flag(FBRACEEXPAND) = 1;

	/*
	 * Turn on "set -x" inheritance by default.
	 */
	Flag(FXTRACEREC) = 1;

	/* define built-in commands and see if we were called as one */
	ktinit(APERM, &builtins,
	    /* currently up to 52 builtins: 75% of 128 = 2^7 */
	    7);
	for (i = 0; mkshbuiltins[i].name != NULL; ++i) {
		const char *builtin_name;

		builtin_name = builtin(mkshbuiltins[i].name,
		    mkshbuiltins[i].func);
		if (!builtin_name_cmp(ccp, builtin_name)) {
			/* canonicalise argv[0] */
			ccp = builtin_name;
			as_builtin = true;
		}
	}

	if (!as_builtin) {
		/* check for -T option early */
		argi = parse_args(argv, OF_FIRSTTIME, NULL);
		if (argi < 0)
			return (1);
		/* called as rsh, rmksh, -rsh, RKSH.EXE, etc.? */
		if (ksh_eq(*ccp, 'R', 'r')) {
			++ccp;
			++restricted_shell;
		}
#if defined(MKSH_BINSHPOSIX) || defined(MKSH_BINSHREDUCED)
		/* are we called as -rsh or /bin/sh or SH.EXE or so? */
		if (ksh_eq(ccp[0], 'S', 's') &&
		    ksh_eq(ccp[1], 'H', 'h')) {
			/* either also turns off braceexpand */
#ifdef MKSH_BINSHPOSIX
			/* enable better POSIX conformance */
			change_flag(FPOSIX, OF_FIRSTTIME, true);
#endif
#ifdef MKSH_BINSHREDUCED
			/* enable kludge/compat mode */
			change_flag(FSH, OF_FIRSTTIME, true);
#endif
		}
#endif
	}

	initvar();

	inittraps();

	coproc_init();

	/* set up variable and command dictionaries */
	ktinit(APERM, &taliases, 0);
	ktinit(APERM, &aliases, 0);
#ifndef MKSH_NOPWNAM
	ktinit(APERM, &homedirs, 0);
#endif

	/* define shell keywords */
	initkeywords();

	init_histvec();

	/* initialise tty size before importing environment */
	change_winsz();

#ifdef _PATH_DEFPATH
	def_path = _PATH_DEFPATH;
#else
#ifdef _CS_PATH
	if ((k = confstr(_CS_PATH, NULL, 0)) > 0 &&
	    confstr(_CS_PATH, cp = alloc(k + 1, APERM), k + 1) == k + 1)
		def_path = cp;
	else
#endif
		/*
		 * this is uniform across all OSes unless it
		 * breaks somewhere hard; don't try to optimise,
		 * e.g. add stuff for Interix or remove /usr
		 * for HURD, because e.g. Debian GNU/HURD is
		 * "keeping a regular /usr"; this is supposed
		 * to be a sane 'basic' default PATH
		 */
		def_path = MKSH_UNIXROOT "/bin" MKSH_PATHSEPS
		    MKSH_UNIXROOT "/usr/bin" MKSH_PATHSEPS
		    MKSH_UNIXROOT "/sbin" MKSH_PATHSEPS
		    MKSH_UNIXROOT "/usr/sbin";
#endif

	/*
	 * Set PATH to def_path (will set the path global variable).
	 * (import of environment below will probably change this setting).
	 */
	vp = global(TPATH);
	/* setstr can't fail here */
	setstr(vp, def_path, KSH_RETURN_ERROR);

#ifndef MKSH_NO_CMDLINE_EDITING
	/*
	 * Set edit mode to emacs by default, may be overridden
	 * by the environment or the user. Also, we want tab completion
	 * on in vi by default.
	 */
	change_flag(FEMACS, OF_SPECIAL, true);
#if !MKSH_S_NOVI
	Flag(FVITABCOMPLETE) = 1;
#endif
#endif

	/* import environment */
	init_environ();

	/* for security */
	typeset(TinitIFS, 0, 0, 0, 0);

	/* assign default shell variable values */
	typeset("PATHSEP=" MKSH_PATHSEPS, 0, 0, 0, 0);
	substitute(initsubs, 0);

	/* Figure out the current working directory and set $PWD */
	vp = global(TPWD);
	cp = str_val(vp);
	/* Try to use existing $PWD if it is valid */
	set_current_wd((mksh_abspath(cp) && test_eval(NULL, TO_FILEQ, cp,
	    Tdot, true)) ? cp : NULL);
	if (current_wd[0])
		simplify_path(current_wd);
	/* Only set pwd if we know where we are or if it had a bogus value */
	if (current_wd[0] || *cp)
		/* setstr can't fail here */
		setstr(vp, current_wd, KSH_RETURN_ERROR);

	for (wp = initcoms; *wp != NULL; wp++) {
		c_builtin(wp);
		while (*wp != NULL)
			wp++;
	}
	setint_n(global("OPTIND"), 1, 10);

	kshuid = getuid();
	kshgid = getgid();
	kshegid = getegid();

	safe_prompt = ksheuid ? "$ " : "# ";
	vp = global("PS1");
	/* Set PS1 if unset or we are root and prompt doesn't contain a # */
	if (!(vp->flag & ISSET) ||
	    (!ksheuid && !strchr(str_val(vp), '#')))
		/* setstr can't fail here */
		setstr(vp, safe_prompt, KSH_RETURN_ERROR);
	setint_n((vp = global("BASHPID")), 0, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("PGRP")), (mksh_uari_t)kshpgrp, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("PPID")), (mksh_uari_t)kshppid, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("USER_ID")), (mksh_uari_t)ksheuid, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("KSHUID")), (mksh_uari_t)kshuid, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("KSHEGID")), (mksh_uari_t)kshegid, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("KSHGID")), (mksh_uari_t)kshgid, 10);
	vp->flag |= INT_U;
	setint_n((vp = global("RANDOM")), rndsetup(), 10);
	vp->flag |= INT_U;
	setint_n((vp_pipest = global("PIPESTATUS")), 0, 10);

	/* Set this before parsing arguments */
	Flag(FPRIVILEGED) = (kshuid != ksheuid || kshgid != kshegid) ? 2 : 0;

	/* record if monitor is set on command line (see j_init() in jobs.c) */
#ifndef MKSH_UNEMPLOYED
	Flag(FMONITOR) = 127;
#endif
	/* this to note if utf-8 mode is set on command line (see below) */
	UTFMODE = 2;

	if (!as_builtin) {
		argi = parse_args(argv, OF_CMDLINE, NULL);
		if (argi < 0)
			return (1);
	}

	/* process this later only, default to off (hysterical raisins) */
	utf_flag = UTFMODE;
	UTFMODE = 0;

	if (as_builtin) {
		/* auto-detect from environment variables, always */
		utf_flag = 3;
	} else if (Flag(FCOMMAND)) {
		s = pushs(SSTRINGCMDLINE, ATEMP);
		if (!(s->start = s->str = argv[argi++]))
			errorf(Tf_optfoo, "", "", 'c', Treq_arg);
		while (*s->str) {
			if (ctype(*s->str, C_QUOTE))
				break;
			s->str++;
		}
		if (!*s->str)
			s->flags |= SF_MAYEXEC;
		s->str = s->start;
#ifdef MKSH_MIDNIGHTBSD01ASH_COMPAT
		/* compatibility to MidnightBSD 0.1 /bin/sh (kludge) */
		if (Flag(FSH) && argv[argi] && !strcmp(argv[argi], "--"))
			++argi;
#endif
		if (argv[argi])
			kshname = argv[argi++];
	} else if (argi < argc && !Flag(FSTDIN)) {
		s = pushs(SFILE, ATEMP);
#ifdef __OS2__
		/*
		 * A bug in OS/2 extproc (like shebang) handling makes
		 * it not pass the full pathname of a script, so we need
		 * to search for it. This changes the behaviour of a
		 * simple "mksh foo", but can't be helped.
		 */
		s->file = argv[argi++];
		if (search_access(s->file, X_OK) != 0)
			s->file = search_path(s->file, path, X_OK, NULL);
		if (!s->file || !*s->file)
			s->file = argv[argi - 1];
#else
		s->file = argv[argi++];
#endif
		s->u.shf = shf_open(s->file, O_RDONLY | O_MAYEXEC, 0,
		    SHF_MAPHI | SHF_CLEXEC);
		if (s->u.shf == NULL) {
			shl_stdout_ok = false;
			warningf(true, Tf_sD_s, s->file, cstrerror(errno));
			/* mandated by SUSv4 */
			exstat = 127;
			unwind(LERROR);
		}
		kshname = s->file;
	} else {
		Flag(FSTDIN) = 1;
		s = pushs(SSTDIN, ATEMP);
		s->file = "<stdin>";
		s->u.shf = shf_fdopen(0, SHF_RD | can_seek(0),
		    NULL);
		if (isatty(0) && isatty(2)) {
			Flag(FTALKING) = Flag(FTALKING_I) = 1;
			/* The following only if isatty(0) */
			s->flags |= SF_TTY;
			s->u.shf->flags |= SHF_INTERRUPT;
			s->file = NULL;
		}
	}

	/* this bizarreness is mandated by POSIX */
	if (Flag(FTALKING) && fstat(0, &s_stdin) >= 0 &&
	    S_ISCHR(s_stdin.st_mode))
		reset_nonblock(0);

	/* initialise job control */
	j_init();
	/* do this after j_init() which calls tty_init_state() */
	if (Flag(FTALKING)) {
		if (utf_flag == 2) {
#ifndef MKSH_ASSUME_UTF8
			/* auto-detect from locale or environment */
			utf_flag = 4;
#else /* this may not be an #elif */
#if MKSH_ASSUME_UTF8
			utf_flag = 1;
#else
			/* always disable UTF-8 (for interactive) */
			utf_flag = 0;
#endif
#endif
		}
#ifndef MKSH_NO_CMDLINE_EDITING
		x_init();
#endif
	}

#ifdef SIGWINCH
	sigtraps[SIGWINCH].flags |= TF_SHELL_USES;
	setsig(&sigtraps[SIGWINCH], x_sigwinch,
	    SS_RESTORE_ORIG|SS_FORCE|SS_SHTRAP);
#endif

	l = e->loc;
	if (as_builtin) {
		l->argc = argc;
		l->argv = argv;
		l->argv[0] = ccp;
	} else {
		l->argc = argc - argi;
		/*
		 * allocate a new array because otherwise, when we modify
		 * it in-place, ps(1) output changes; the meaning of argc
		 * here is slightly different as it excludes kshname, and
		 * we add a trailing NULL sentinel as well
		 */
		l->argv = alloc2(l->argc + 2, sizeof(void *), APERM);
		l->argv[0] = kshname;
		memcpy(&l->argv[1], &argv[argi], l->argc * sizeof(void *));
		l->argv[l->argc + 1] = NULL;
		getopts_reset(1);
	}

	/* divine the initial state of the utf8-mode Flag */
	ccp = null;
	switch (utf_flag) {

	/* auto-detect from locale or environment */
	case 4:
#if HAVE_SETLOCALE_CTYPE
		ccp = setlocale(LC_CTYPE, "");
#if HAVE_LANGINFO_CODESET
		if (!isuc(ccp))
			ccp = nl_langinfo(CODESET);
#endif
		if (!isuc(ccp))
			ccp = null;
#endif
		/* FALLTHROUGH */

	/* auto-detect from environment */
	case 3:
		/* these were imported from environ earlier */
		if (ccp == null)
			ccp = str_val(global("LC_ALL"));
		if (ccp == null)
			ccp = str_val(global("LC_CTYPE"));
		if (ccp == null)
			ccp = str_val(global("LANG"));
		UTFMODE = isuc(ccp);
		break;

	/* not set on command line, not FTALKING */
	case 2:
	/* unknown values */
	default:
		utf_flag = 0;
		/* FALLTHROUGH */

	/* known values */
	case 1:
	case 0:
		UTFMODE = utf_flag;
		break;
	}

	/* Disable during .profile/ENV reading */
	restricted_shell |= Flag(FRESTRICTED);
	Flag(FRESTRICTED) = 0;
	errexit = Flag(FERREXIT);
	Flag(FERREXIT) = 0;

	/* save flags for "set +o" handling */
	memcpy(baseline_flags, shell_flags, sizeof(shell_flags));
	/* disable these because they have special handling */
	baseline_flags[(int)FPOSIX] = 0;
	baseline_flags[(int)FSH] = 0;
	/* ensure these always show up setting, for FPOSIX/FSH */
	baseline_flags[(int)FBRACEEXPAND] = 0;
	baseline_flags[(int)FUNNYCODE] = 0;
#if !defined(MKSH_SMALL) || defined(DEBUG)
	/* mark as initialised */
	baseline_flags[(int)FNFLAGS] = 1;
#endif
	if (as_builtin)
		goto skip_startup_files;

	/*
	 * Do this before profile/$ENV so that if it causes problems in them,
	 * user will know why things broke.
	 */
	if (!current_wd[0] && Flag(FTALKING))
		warningf(false, "can't determine current directory");

	if (Flag(FLOGIN))
		include(MKSH_SYSTEM_PROFILE, 0, NULL, true);
	if (Flag(FPRIVILEGED)) {
		include(MKSH_SUID_PROFILE, 0, NULL, true);
		/* note whether -p was enabled during startup */
		if (Flag(FPRIVILEGED) == 1)
			/* allow set -p to setuid() later */
			Flag(FPRIVILEGED) = 3;
		else
			/* turn off -p if not set explicitly */
			change_flag(FPRIVILEGED, OF_INTERNAL, false);
		/* track shell-imposed changes */
		baseline_flags[(int)FPRIVILEGED] = Flag(FPRIVILEGED);
	} else {
		if (Flag(FLOGIN))
			include(substitute("$HOME/.profile", 0), 0, NULL, true);
		if (Flag(FTALKING)) {
			cp = substitute("${ENV:-" MKSHRC_PATH "}", DOTILDE);
			if (cp[0] != '\0')
				include(cp, 0, NULL, true);
		}
	}
	if (restricted_shell) {
		c_builtin(restr_com);
		/* After typeset command... */
		Flag(FRESTRICTED) = 1;
		/* track shell-imposed changes */
		baseline_flags[(int)FRESTRICTED] = 1;
	}
	Flag(FERREXIT) = errexit;

	if (Flag(FTALKING) && s)
		hist_init(s);
	else {
		/* set after ENV */
 skip_startup_files:
		Flag(FTRACKALL) = 1;
		/* track shell-imposed change (might lower surprise) */
		baseline_flags[(int)FTRACKALL] = 1;
	}

	alarm_init();

	*sp = s;
	*lp = l;
	return (0);
}

/* this indirection barrier reduces stack usage during normal operation */

int
main(int argc, const char *argv[])
{
	int rv;
	Source *s;
	struct block *l;

	if ((rv = main_init(argc, argv, &s, &l)) == 0) {
		if (as_builtin) {
			rv = c_builtin(l->argv);
		} else {
			shell(s, 0);
			/* NOTREACHED */
		}
	}
	return (rv);
}

int
include(const char *name, int argc, const char **argv, bool intr_ok)
{
	Source *volatile s = NULL;
	struct shf *shf;
	const char **volatile old_argv;
	volatile int old_argc;
	int i;

	shf = shf_open(name, O_RDONLY | O_MAYEXEC, 0, SHF_MAPHI | SHF_CLEXEC);
	if (shf == NULL)
		return (-1);

	if (argv) {
		old_argv = e->loc->argv;
		old_argc = e->loc->argc;
	} else {
		old_argv = NULL;
		old_argc = 0;
	}
	newenv(E_INCL);
	if ((i = kshsetjmp(e->jbuf))) {
		quitenv(s ? s->u.shf : NULL);
		if (old_argv) {
			e->loc->argv = old_argv;
			e->loc->argc = old_argc;
		}
		switch (i) {
		case LRETURN:
		case LERROR:
		case LERREXT:
			/* see below */
			return (exstat & 0xFF);
		case LINTR:
			/*
			 * intr_ok is set if we are including .profile or $ENV.
			 * If user ^Cs out, we don't want to kill the shell...
			 */
			if (intr_ok && ((exstat & 0xFF) - 128) != SIGTERM)
				return (1);
			/* FALLTHROUGH */
		case LEXIT:
		case LLEAVE:
		case LSHELL:
			unwind(i);
			/* NOTREACHED */
		default:
			internal_errorf(Tunexpected_type, Tunwind, Tsource, i);
			/* NOTREACHED */
		}
	}
	if (argv) {
		e->loc->argv = argv;
		e->loc->argc = argc;
	}
	s = pushs(SFILE, ATEMP);
	s->u.shf = shf;
	strdupx(s->file, name, ATEMP);
	i = shell(s, 1);
	quitenv(s->u.shf);
	if (old_argv) {
		e->loc->argv = old_argv;
		e->loc->argc = old_argc;
	}
	/* & 0xff to ensure value not -1 */
	return (i & 0xFF);
}

/* spawn a command into a shell optionally keeping track of the line number */
int
command(const char *comm, int line)
{
	Source *s, *sold = source;
	int rv;

	s = pushs(SSTRING, ATEMP);
	s->start = s->str = comm;
	s->line = line;
	rv = shell(s, 1);
	source = sold;
	return (rv);
}

/*
 * run the commands from the input source, returning status.
 */
int
shell(Source * volatile s, volatile int level)
{
	struct op *t;
	volatile bool wastty = tobool(s->flags & SF_TTY);
	volatile uint8_t attempts = 13;
	volatile bool interactive = (level == 0) && Flag(FTALKING);
	volatile bool sfirst = true;
	Source *volatile old_source = source;
	int i;

	newenv(level == 2 ? E_EVAL : E_PARSE);
	if (level == 2)
		e->flags |= EF_IN_EVAL;
	if (interactive)
		really_exit = false;
	switch ((i = kshsetjmp(e->jbuf))) {
	case 0:
		break;
	case LBREAK:
	case LCONTIN:
		/* assert: interactive == false */
		source = old_source;
		quitenv(NULL);
		if (level == 2) {
			/* keep on going */
			unwind(i);
			/* NOTREACHED */
		}
		internal_errorf(Tf_cant_s, Tshell,
		    i == LBREAK ? Tbreak : Tcontinue);
		/* NOTREACHED */
	case LINTR:
		/* we get here if SIGINT not caught or ignored */
	case LERROR:
	case LERREXT:
	case LSHELL:
		if (interactive) {
			if (i == LINTR)
				shellf("\n");
			/*
			 * Reset any eof that was read as part of a
			 * multiline command.
			 */
			if (Flag(FIGNOREEOF) && s->type == SEOF && wastty)
				s->type = SSTDIN;
			/*
			 * Used by exit command to get back to
			 * top level shell. Kind of strange since
			 * interactive is set if we are reading from
			 * a tty, but to have stopped jobs, one only
			 * needs FMONITOR set (not FTALKING/SF_TTY)...
			 */
			/* toss any input we have so far */
			yyrecursive_pop(true);
			s->start = s->str = null;
			retrace_info = NULL;
			herep = heres;
			break;
		}
		/* FALLTHROUGH */
	case LEXIT:
	case LLEAVE:
	case LRETURN:
		source = old_source;
		quitenv(NULL);
		if (i == LERREXT && level == 2)
			return (exstat & 0xFF);
		/* keep on going */
		unwind(i);
		/* NOTREACHED */
	default:
		source = old_source;
		quitenv(NULL);
		internal_errorf(Tunexpected_type, Tunwind, Tshell, i);
		/* NOTREACHED */
	}
	while (/* CONSTCOND */ 1) {
		if (trap)
			runtraps(0);

		if (s->next == NULL) {
			if (Flag(FVERBOSE))
				s->flags |= SF_ECHO;
			else
				s->flags &= ~SF_ECHO;
		}
		if (interactive) {
			j_notify();
			set_prompt(PS1, s);
		}
		t = compile(s, sfirst, true);
		if (interactive)
			histsave(&s->line, NULL, HIST_FLUSH, true);
		sfirst = false;
		if (!t)
			goto source_no_tree;
		if (t->type == TEOF) {
			if (wastty && Flag(FIGNOREEOF) && --attempts > 0) {
				shellf("Use 'exit' to leave mksh\n");
				s->type = SSTDIN;
			} else if (wastty && !really_exit &&
			    j_stopped_running()) {
				really_exit = true;
				s->type = SSTDIN;
			} else {
				/*
				 * this for POSIX which says EXIT traps
				 * shall be taken in the environment
				 * immediately after the last command
				 * executed.
				 */
				if (level == 0)
					unwind(LEXIT);
				break;
			}
		} else if ((s->flags & SF_MAYEXEC) && t->type == TCOM)
			t->u.evalflags |= DOTCOMEXEC;
		if (!Flag(FNOEXEC) || (s->flags & SF_TTY))
			exstat = execute(t, 0, NULL) & 0xFF;

		if (t->type != TEOF && interactive && really_exit)
			really_exit = false;

 source_no_tree:
		reclaim();
	}
	source = old_source;
	quitenv(NULL);
	return (exstat & 0xFF);
}

/* return to closest error handler or shell(), exit if none found */
/* note: i MUST NOT be 0 */
void
unwind(int i)
{
	/* during eval, skip FERREXIT trap */
	if (i == LERREXT && (e->flags & EF_IN_EVAL))
		goto defer_traps;

	/* ordering for EXIT vs ERR is a bit odd (this is what AT&T ksh does) */
	if (i == LEXIT || ((i == LERROR || i == LERREXT || i == LINTR) &&
	    sigtraps[ksh_SIGEXIT].trap &&
	    (!Flag(FTALKING) || Flag(FERREXIT)))) {
		++trap_nested;
		runtrap(&sigtraps[ksh_SIGEXIT], trap_nested == 1);
		--trap_nested;
		i = LLEAVE;
	} else if (Flag(FERREXIT) && (i == LERROR || i == LERREXT || i == LINTR)) {
		++trap_nested;
		runtrap(&sigtraps[ksh_SIGERR], trap_nested == 1);
		--trap_nested;
		i = LLEAVE;
	}
 defer_traps:

	while (/* CONSTCOND */ 1) {
		switch (e->type) {
		case E_PARSE:
		case E_FUNC:
		case E_INCL:
		case E_LOOP:
		case E_ERRH:
		case E_EVAL:
			kshlongjmp(e->jbuf, i);
			/* NOTREACHED */
		case E_NONE:
			if (i == LINTR)
				e->flags |= EF_FAKE_SIGDIE;
			/* FALLTHROUGH */
		default:
			quitenv(NULL);
		}
	}
}

void
newenv(int type)
{
	struct env *ep;
	char *cp;

	/*
	 * struct env includes ALLOC_ITEM for alignment constraints
	 * so first get the actually used memory, then assign it
	 */
	cp = alloc(sizeof(struct env) - sizeof(ALLOC_ITEM), ATEMP);
	/* undo what alloc() did to the malloc result address */
	ep = (void *)(cp - sizeof(ALLOC_ITEM));
	/* initialise public members of struct env (not the ALLOC_ITEM) */
	ainit(&ep->area);
	ep->oenv = e;
	ep->loc = e->loc;
	ep->savefd = NULL;
	ep->temps = NULL;
	ep->yyrecursive_statep = NULL;
	ep->type = type;
	ep->flags = e->flags & EF_IN_EVAL;
	e = ep;
}

void
quitenv(struct shf *shf)
{
	struct env *ep = e;
	char *cp;
	int fd;

	yyrecursive_pop(true);
	while (ep->oenv && ep->oenv->loc != ep->loc)
		popblock();
	if (ep->savefd != NULL) {
		for (fd = 0; fd < NUFILE; fd++)
			/* if ep->savefd[fd] < 0, means fd was closed */
			if (ep->savefd[fd])
				restfd(fd, ep->savefd[fd]);
		if (ep->savefd[2])
			/* Clear any write errors */
			shf_reopen(2, SHF_WR, shl_out);
	}
	/*
	 * Bottom of the stack.
	 * Either main shell is exiting or cleanup_parents_env() was called.
	 */
	if (ep->oenv == NULL) {
#ifdef DEBUG_LEAKS
		int i;
#endif

		if (ep->type == E_NONE) {
			/* Main shell exiting? */
#if HAVE_PERSISTENT_HISTORY
			if (Flag(FTALKING))
				hist_finish();
#endif
			j_exit();
			if (ep->flags & EF_FAKE_SIGDIE) {
				int sig = (exstat & 0xFF) - 128;

				/*
				 * ham up our death a bit (AT&T ksh
				 * only seems to do this for SIGTERM)
				 * Don't do it for SIGQUIT, since we'd
				 * dump a core..
				 */
				if ((sig == SIGINT || sig == SIGTERM) &&
				    (kshpgrp == kshpid)) {
					setsig(&sigtraps[sig], SIG_DFL,
					    SS_RESTORE_CURR | SS_FORCE);
					kill(0, sig);
				}
			}
		}
		if (shf)
			shf_close(shf);
		reclaim();
#ifdef DEBUG_LEAKS
#ifndef MKSH_NO_CMDLINE_EDITING
		x_done();
#endif
#ifndef MKSH_NOPROSPECTOFWORK
		/* block at least SIGCHLD during/after afreeall */
		sigprocmask(SIG_BLOCK, &sm_sigchld, NULL);
#endif
		afreeall(APERM);
		for (fd = 3; fd < NUFILE; fd++)
			if ((i = fcntl(fd, F_GETFD, 0)) != -1 &&
			    (i & FD_CLOEXEC))
				close(fd);
		close(2);
		close(1);
		close(0);
#endif
		exit(exstat & 0xFF);
	}
	if (shf)
		shf_close(shf);
	reclaim();

	e = e->oenv;

	/* free the struct env - tricky due to the ALLOC_ITEM inside */
	cp = (void *)ep;
	afree(cp + sizeof(ALLOC_ITEM), ATEMP);
}

/* Called after a fork to cleanup stuff left over from parents environment */
void
cleanup_parents_env(void)
{
	struct env *ep;
	int fd;

	/*
	 * Don't clean up temporary files - parent will probably need them.
	 * Also, can't easily reclaim memory since variables, etc. could be
	 * anywhere.
	 */

	/* close all file descriptors hiding in savefd */
	for (ep = e; ep; ep = ep->oenv) {
		if (ep->savefd) {
			for (fd = 0; fd < NUFILE; fd++)
				if (ep->savefd[fd] > 0)
					close(ep->savefd[fd]);
			afree(ep->savefd, &ep->area);
			ep->savefd = NULL;
		}
#ifdef DEBUG_LEAKS
		if (ep->type != E_NONE)
			ep->type = E_GONE;
#endif
	}
#ifndef DEBUG_LEAKS
	e->oenv = NULL;
#endif
}

/* Called just before an execve cleanup stuff temporary files */
void
cleanup_proc_env(void)
{
	struct env *ep;

	for (ep = e; ep; ep = ep->oenv)
		remove_temps(ep->temps);
}

/* remove temp files and free ATEMP Area */
static void
reclaim(void)
{
	struct block *l;

	while ((l = e->loc) && (!e->oenv || e->oenv->loc != l)) {
		e->loc = l->next;
		afreeall(&l->area);
	}

	remove_temps(e->temps);
	e->temps = NULL;

	/*
	 * if the memory backing source is reclaimed, things
	 * will end up badly when a function expecting it to
	 * be valid is run; a NULL pointer is easily debugged
	 */
	if (source && source->areap == &e->area)
		source = NULL;
	afreeall(&e->area);
}

static void
remove_temps(struct temp *tp)
{
	while (tp) {
		if (tp->pid == procpid)
			unlink(tp->tffn);
		tp = tp->next;
	}
}

/*
 * Initialise tty_fd. Used for tracking the size of the terminal,
 * saving/resetting tty modes upon forground job completion, and
 * for setting up the tty process group. Return values:
 *	0 = got controlling tty
 *	1 = got terminal but no controlling tty
 *	2 = cannot find a terminal
 *	3 = cannot dup fd
 *	4 = cannot make fd close-on-exec
 * An existing tty_fd is cached if no "better" one could be found,
 * i.e. if tty_devtty was already set or the new would not set it.
 */
int
tty_init_fd(void)
{
	int fd, rv, eno = 0;
	bool do_close = false, is_devtty = true;

	if (tty_devtty) {
		/* already got a tty which is /dev/tty */
		return (0);
	}

#ifdef _UWIN
	/*XXX imake style */
	if (isatty(3)) {
		/* fd 3 on UWIN _is_ /dev/tty (or our controlling tty) */
		fd = 3;
		goto got_fd;
	}
#endif
	if ((fd = open(T_devtty, O_RDWR, 0)) >= 0) {
		do_close = true;
		goto got_fd;
	}
	eno = errno;

	if (tty_fd >= 0) {
		/* already got a non-devtty one */
		rv = 1;
		goto out;
	}
	is_devtty = false;

	if (isatty((fd = 0)) || isatty((fd = 2)))
		goto got_fd;
	/* cannot find one */
	rv = 2;
	/* assert: do_close == false */
	goto out;

 got_fd:
	if ((rv = fcntl(fd, F_DUPFD, FDBASE)) < 0) {
		eno = errno;
		rv = 3;
		goto out;
	}
	if (fcntl(rv, F_SETFD, FD_CLOEXEC) < 0) {
		eno = errno;
		close(rv);
		rv = 4;
		goto out;
	}
	tty_fd = rv;
	tty_devtty = is_devtty;
	rv = eno = 0;
 out:
	if (do_close)
		close(fd);
	errno = eno;
	return (rv);
}

/* A shell error occurred (eg, syntax error, etc.) */

#define VWARNINGF_ERRORPREFIX	1
#define VWARNINGF_FILELINE	2
#define VWARNINGF_BUILTIN	4
#define VWARNINGF_INTERNAL	8

static void vwarningf(unsigned int, const char *, va_list)
    MKSH_A_FORMAT(__printf__, 2, 0);

static void
vwarningf(unsigned int flags, const char *fmt, va_list ap)
{
	if (fmt) {
		if (flags & VWARNINGF_INTERNAL)
			shf_fprintf(shl_out, Tf_sD_, "internal error");
		if (flags & VWARNINGF_ERRORPREFIX)
			error_prefix(tobool(flags & VWARNINGF_FILELINE));
		if ((flags & VWARNINGF_BUILTIN) &&
		    /* not set when main() calls parse_args() */
		    builtin_argv0 && builtin_argv0 != kshname)
			shf_fprintf(shl_out, Tf_sD_, builtin_argv0);
		shf_vfprintf(shl_out, fmt, ap);
		shf_putchar('\n', shl_out);
	}
	shf_flush(shl_out);
}

void
errorfx(int rc, const char *fmt, ...)
{
	va_list va;

	exstat = rc;

	/* debugging: note that stdout not valid */
	shl_stdout_ok = false;

	va_start(va, fmt);
	vwarningf(VWARNINGF_ERRORPREFIX | VWARNINGF_FILELINE, fmt, va);
	va_end(va);
	unwind(LERROR);
}

void
errorf(const char *fmt, ...)
{
	va_list va;

	exstat = 1;

	/* debugging: note that stdout not valid */
	shl_stdout_ok = false;

	va_start(va, fmt);
	vwarningf(VWARNINGF_ERRORPREFIX | VWARNINGF_FILELINE, fmt, va);
	va_end(va);
	unwind(LERROR);
}

/* like errorf(), but no unwind is done */
void
warningf(bool fileline, const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	vwarningf(VWARNINGF_ERRORPREFIX | (fileline ? VWARNINGF_FILELINE : 0),
	    fmt, va);
	va_end(va);
}

/*
 * Used by built-in utilities to prefix shell and utility name to message
 * (also unwinds environments for special builtins).
 */
void
bi_errorf(const char *fmt, ...)
{
	va_list va;

	/* debugging: note that stdout not valid */
	shl_stdout_ok = false;

	exstat = 1;

	va_start(va, fmt);
	vwarningf(VWARNINGF_ERRORPREFIX | VWARNINGF_FILELINE |
	    VWARNINGF_BUILTIN, fmt, va);
	va_end(va);

	/* POSIX special builtins cause non-interactive shells to exit */
	if (builtin_spec) {
		builtin_argv0 = NULL;
		/* may not want to use LERROR here */
		unwind(LERROR);
	}
}

/*
 * Used by functions called by builtins and not:
 * identical to errorfx if first argument is nil,
 * like bi_errorf storing the errorlevel into it otherwise
 */
void
maybe_errorf(int *ep, int rc, const char *fmt, ...)
{
	va_list va;

	/* debugging: note that stdout not valid */
	shl_stdout_ok = false;

	exstat = rc;

	va_start(va, fmt);
	vwarningf(VWARNINGF_ERRORPREFIX | VWARNINGF_FILELINE |
	    (ep ? VWARNINGF_BUILTIN : 0), fmt, va);
	va_end(va);

	if (!ep)
		goto and_out;
	*ep = rc;

	/* POSIX special builtins cause non-interactive shells to exit */
	if (builtin_spec) {
		builtin_argv0 = NULL;
		/* may not want to use LERROR here */
 and_out:
		unwind(LERROR);
	}
}

/* Called when something that shouldn't happen does */
void
internal_errorf(const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	vwarningf(VWARNINGF_INTERNAL, fmt, va);
	va_end(va);
	unwind(LERROR);
}

void
internal_warningf(const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	vwarningf(VWARNINGF_INTERNAL, fmt, va);
	va_end(va);
}

/* used by error reporting functions to print "ksh: .kshrc[25]: " */
void
error_prefix(bool fileline)
{
	/* Avoid foo: foo[2]: ... */
	if (!fileline || !source || !source->file ||
	    strcmp(source->file, kshname) != 0)
		shf_fprintf(shl_out, Tf_sD_, kshname + (*kshname == '-'));
	if (fileline && source && source->file != NULL) {
		shf_fprintf(shl_out, "%s[%lu]: ", source->file,
		    (unsigned long)(source->errline ?
		    source->errline : source->line));
		source->errline = 0;
	}
}

/* printf to shl_out (stderr) with flush */
void
shellf(const char *fmt, ...)
{
	va_list va;

	if (!initio_done)
		/* shl_out may not be set up yet... */
		return;
	va_start(va, fmt);
	shf_vfprintf(shl_out, fmt, va);
	va_end(va);
	shf_flush(shl_out);
}

/* printf to shl_stdout (stdout) */
void
shprintf(const char *fmt, ...)
{
	va_list va;

	if (!shl_stdout_ok)
		internal_errorf("shl_stdout not valid");
	va_start(va, fmt);
	shf_vfprintf(shl_stdout, fmt, va);
	va_end(va);
}

/* test if we can seek backwards fd (returns 0 or SHF_UNBUF) */
int
can_seek(int fd)
{
	struct stat statb;

	return (fstat(fd, &statb) == 0 && !S_ISREG(statb.st_mode) ?
	    SHF_UNBUF : 0);
}

#ifdef DF
int shl_dbg_fd;
#define NSHF_IOB 4
#else
#define NSHF_IOB 3
#endif
struct shf shf_iob[NSHF_IOB];

void
initio(void)
{
#ifdef DF
	const char *lfp;
#endif

	/* force buffer allocation */
	shf_fdopen(1, SHF_WR, shl_stdout);
	shf_fdopen(2, SHF_WR, shl_out);
	shf_fdopen(2, SHF_WR, shl_xtrace);
#ifdef DF
	if ((lfp = getenv("SDMKSH_PATH")) == NULL) {
		if ((lfp = getenv("HOME")) == NULL || !mksh_abspath(lfp))
			errorf("can't get home directory");
		strpathx(lfp, lfp, "mksh-dbg.txt", 1);
	}

	if ((shl_dbg_fd = open(lfp, O_WRONLY | O_APPEND | O_CREAT, 0600)) < 0)
		errorf("can't open debug output file %s", lfp);
	if (shl_dbg_fd < FDBASE) {
		int nfd;

		nfd = fcntl(shl_dbg_fd, F_DUPFD, FDBASE);
		close(shl_dbg_fd);
		if ((shl_dbg_fd = nfd) == -1)
			errorf("can't dup debug output file");
	}
	fcntl(shl_dbg_fd, F_SETFD, FD_CLOEXEC);
	shf_fdopen(shl_dbg_fd, SHF_WR, shl_dbg);
	DF("=== open ===");
#endif
	initio_done = true;
}

/* A dup2() with error checking */
int
ksh_dup2(int ofd, int nfd, bool errok)
{
	int rv;

	if (((rv = dup2(ofd, nfd)) < 0) && !errok && (errno != EBADF))
		errorf(Ttoo_many_files);

#ifdef __ultrix
	/*XXX imake style */
	if (rv >= 0)
		fcntl(nfd, F_SETFD, 0);
#endif

	return (rv);
}

/*
 * Move fd from user space (0 <= fd < 10) to shell space (fd >= 10),
 * set close-on-exec flag. See FDBASE in sh.h, maybe 24 not 10 here.
 */
short
savefd(int fd)
{
	int nfd = fd;

	if (fd < FDBASE && (nfd = fcntl(fd, F_DUPFD, FDBASE)) < 0 &&
	    (errno == EBADF || errno == EPERM))
		return (-1);
	if (nfd < 0 || nfd > SHRT_MAX)
		errorf(Ttoo_many_files);
	fcntl(nfd, F_SETFD, FD_CLOEXEC);
	return ((short)nfd);
}

void
restfd(int fd, int ofd)
{
	if (fd == 2)
		shf_flush(&shf_iob[/* fd */ 2]);
	if (ofd < 0)
		/* original fd closed */
		close(fd);
	else if (fd != ofd) {
		/*XXX: what to do if this dup fails? */
		ksh_dup2(ofd, fd, true);
		close(ofd);
	}
}

void
openpipe(int *pv)
{
	int lpv[2];

	if (pipe(lpv) < 0)
		errorf("can't create pipe - try again");
	pv[0] = savefd(lpv[0]);
	if (pv[0] != lpv[0])
		close(lpv[0]);
	pv[1] = savefd(lpv[1]);
	if (pv[1] != lpv[1])
		close(lpv[1]);
#ifdef __OS2__
	setmode(pv[0], O_BINARY);
	setmode(pv[1], O_BINARY);
#endif
}

void
closepipe(int *pv)
{
	close(pv[0]);
	close(pv[1]);
}

/*
 * Called by iosetup() (deals with 2>&4, etc.), c_read, c_print to turn
 * a string (the X in 2>&X, read -uX, print -uX) into a file descriptor.
 */
int
check_fd(const char *name, int mode, const char **emsgp)
{
	int fd, fl;

	if (!name[0] || name[1])
		goto illegal_fd_name;
	if (name[0] == 'p')
		return (coproc_getfd(mode, emsgp));
	if (!ctype(name[0], C_DIGIT)) {
 illegal_fd_name:
		if (emsgp)
			*emsgp = "illegal file descriptor name";
		return (-1);
	}

	if ((fl = fcntl((fd = ksh_numdig(name[0])), F_GETFL, 0)) < 0) {
		if (emsgp)
			*emsgp = "bad file descriptor";
		return (-1);
	}
	fl &= O_ACCMODE;
	/*
	 * X_OK is a kludge to disable this check for dups (x<&1):
	 * historical shells never did this check (XXX don't know what
	 * POSIX has to say).
	 */
	if (!(mode & X_OK) && fl != O_RDWR && (
	    ((mode & R_OK) && fl != O_RDONLY) ||
	    ((mode & W_OK) && fl != O_WRONLY))) {
		if (emsgp)
			*emsgp = (fl == O_WRONLY) ?
			    "fd not open for reading" :
			    "fd not open for writing";
		return (-1);
	}
	return (fd);
}

/* Called once from main */
void
coproc_init(void)
{
	coproc.read = coproc.readw = coproc.write = -1;
	coproc.njobs = 0;
	coproc.id = 0;
}

/* Called by c_read() when eof is read - close fd if it is the co-process fd */
void
coproc_read_close(int fd)
{
	if (coproc.read >= 0 && fd == coproc.read) {
		coproc_readw_close(fd);
		close(coproc.read);
		coproc.read = -1;
	}
}

/*
 * Called by c_read() and by iosetup() to close the other side of the
 * read pipe, so reads will actually terminate.
 */
void
coproc_readw_close(int fd)
{
	if (coproc.readw >= 0 && coproc.read >= 0 && fd == coproc.read) {
		close(coproc.readw);
		coproc.readw = -1;
	}
}

/*
 * Called by c_print when a write to a fd fails with EPIPE and by iosetup
 * when co-process input is dup'd
 */
void
coproc_write_close(int fd)
{
	if (coproc.write >= 0 && fd == coproc.write) {
		close(coproc.write);
		coproc.write = -1;
	}
}

/*
 * Called to check for existence of/value of the co-process file descriptor.
 * (Used by check_fd() and by c_read/c_print to deal with -p option).
 */
int
coproc_getfd(int mode, const char **emsgp)
{
	int fd = (mode & R_OK) ? coproc.read : coproc.write;

	if (fd >= 0)
		return (fd);
	if (emsgp)
		*emsgp = "no coprocess";
	return (-1);
}

/*
 * called to close file descriptors related to the coprocess (if any)
 * Should be called with SIGCHLD blocked.
 */
void
coproc_cleanup(int reuse)
{
	/* This to allow co-processes to share output pipe */
	if (!reuse || coproc.readw < 0 || coproc.read < 0) {
		if (coproc.read >= 0) {
			close(coproc.read);
			coproc.read = -1;
		}
		if (coproc.readw >= 0) {
			close(coproc.readw);
			coproc.readw = -1;
		}
	}
	if (coproc.write >= 0) {
		close(coproc.write);
		coproc.write = -1;
	}
}

struct temp *
maketemp(Area *ap, Temp_type type, struct temp **tlist)
{
	char *cp;
	size_t len;
	int i, j;
	struct temp *tp;
	const char *dir;
	struct stat sb;

	dir = tmpdir ? tmpdir : MKSH_DEFAULT_TMPDIR;
	/* add "/shXXXXXX.tmp" plus NUL */
	len = strlen(dir);
	checkoktoadd(len, offsetof(struct temp, tffn[0]) + 14);
	tp = alloc(offsetof(struct temp, tffn[0]) + 14 + len, ap);

	tp->shf = NULL;
	tp->pid = procpid;
	tp->type = type;

	if (stat(dir, &sb) || !S_ISDIR(sb.st_mode)) {
		tp->tffn[0] = '\0';
		goto maketemp_out;
	}

	cp = (void *)tp;
	cp += offsetof(struct temp, tffn[0]);
	memcpy(cp, dir, len);
	cp += len;
	memcpy(cp, "/shXXXXXX.tmp", 14);
	/* point to the first of six Xes */
	cp += 3;

	/* cyclically attempt to open a temporary file */
	do {
		/* generate random part of filename */
		len = 0;
		do {
			cp[len++] = digits_lc[rndget() % 36];
		} while (len < 6);

		/* check if this one works */
		if ((i = binopen3(tp->tffn, O_CREAT | O_EXCL | O_RDWR,
		    0600)) < 0 && errno != EEXIST)
			goto maketemp_out;
	} while (i < 0);

	if (type == TT_FUNSUB) {
		/* map us high and mark as close-on-exec */
		if ((j = savefd(i)) != i) {
			close(i);
			i = j;
		}

		/* operation mode for the shf */
		j = SHF_RD;
	} else
		j = SHF_WR;

	/* shf_fdopen cannot fail, so no fd leak */
	tp->shf = shf_fdopen(i, j, NULL);

 maketemp_out:
	tp->next = *tlist;
	*tlist = tp;
	return (tp);
}

/*
 * We use a similar collision resolution algorithm as Python 2.5.4
 * but with a slightly tweaked implementation written from scratch.
 */

#define	INIT_TBLSHIFT	3	/* initial table shift (2^3 = 8) */
#define PERTURB_SHIFT	5	/* see Python 2.5.4 Objects/dictobject.c */

static void tgrow(struct table *);
static int tnamecmp(const void *, const void *);

static void
tgrow(struct table *tp)
{
	size_t i, j, osize, mask, perturb;
	struct tbl *tblp, **pp;
	struct tbl **ntblp, **otblp = tp->tbls;

	if (tp->tshift > 29)
		internal_errorf("hash table size limit reached");

	/* calculate old size, new shift and new size */
	osize = (size_t)1 << (tp->tshift++);
	i = osize << 1;

	ntblp = alloc2(i, sizeof(struct tbl *), tp->areap);
	/* multiplication cannot overflow: alloc2 checked that */
	memset(ntblp, 0, i * sizeof(struct tbl *));

	/* table can get very full when reaching its size limit */
	tp->nfree = (tp->tshift == 30) ? 0x3FFF0000UL :
	    /* but otherwise, only 75% */
	    ((i * 3) / 4);
	tp->tbls = ntblp;
	if (otblp == NULL)
		return;

	mask = i - 1;
	for (i = 0; i < osize; i++)
		if ((tblp = otblp[i]) != NULL) {
			if ((tblp->flag & DEFINED)) {
				/* search for free hash table slot */
				j = perturb = tblp->ua.hval;
				goto find_first_empty_slot;
 find_next_empty_slot:
				j = (j << 2) + j + perturb + 1;
				perturb >>= PERTURB_SHIFT;
 find_first_empty_slot:
				pp = &ntblp[j & mask];
				if (*pp != NULL)
					goto find_next_empty_slot;
				/* found an empty hash table slot */
				*pp = tblp;
				tp->nfree--;
			} else if (!(tblp->flag & FINUSE)) {
				afree(tblp, tp->areap);
			}
		}
	afree(otblp, tp->areap);
}

void
ktinit(Area *ap, struct table *tp, uint8_t initshift)
{
	tp->areap = ap;
	tp->tbls = NULL;
	tp->tshift = ((initshift > INIT_TBLSHIFT) ?
	    initshift : INIT_TBLSHIFT) - 1;
	tgrow(tp);
}

/* table, name (key) to search for, hash(name), rv pointer to tbl ptr */
struct tbl *
ktscan(struct table *tp, const char *name, uint32_t h, struct tbl ***ppp)
{
	size_t j, perturb, mask;
	struct tbl **pp, *p;

	mask = ((size_t)1 << (tp->tshift)) - 1;
	/* search for hash table slot matching name */
	j = perturb = h;
	goto find_first_slot;
 find_next_slot:
	j = (j << 2) + j + perturb + 1;
	perturb >>= PERTURB_SHIFT;
 find_first_slot:
	pp = &tp->tbls[j & mask];
	if ((p = *pp) != NULL && (p->ua.hval != h || !(p->flag & DEFINED) ||
	    strcmp(p->name, name)))
		goto find_next_slot;
	/* p == NULL if not found, correct found entry otherwise */
	if (ppp)
		*ppp = pp;
	return (p);
}

/* table, name (key) to enter, hash(n) */
struct tbl *
ktenter(struct table *tp, const char *n, uint32_t h)
{
	struct tbl **pp, *p;
	size_t len;

 Search:
	if ((p = ktscan(tp, n, h, &pp)))
		return (p);

	if (tp->nfree == 0) {
		/* too full */
		tgrow(tp);
		goto Search;
	}

	/* create new tbl entry */
	len = strlen(n);
	checkoktoadd(len, offsetof(struct tbl, name[0]) + 1);
	p = alloc(offsetof(struct tbl, name[0]) + ++len, tp->areap);
	p->flag = 0;
	p->type = 0;
	p->areap = tp->areap;
	p->ua.hval = h;
	p->u2.field = 0;
	p->u.array = NULL;
	memcpy(p->name, n, len);

	/* enter in tp->tbls */
	tp->nfree--;
	*pp = p;
	return (p);
}

void
ktwalk(struct tstate *ts, struct table *tp)
{
	ts->left = (size_t)1 << (tp->tshift);
	ts->next = tp->tbls;
}

struct tbl *
ktnext(struct tstate *ts)
{
	while (--ts->left >= 0) {
		struct tbl *p = *ts->next++;
		if (p != NULL && (p->flag & DEFINED))
			return (p);
	}
	return (NULL);
}

static int
tnamecmp(const void *p1, const void *p2)
{
	const struct tbl *a = *((const struct tbl * const *)p1);
	const struct tbl *b = *((const struct tbl * const *)p2);

	return (ascstrcmp(a->name, b->name));
}

struct tbl **
ktsort(struct table *tp)
{
	size_t i;
	struct tbl **p, **sp, **dp;

	/*
	 * since the table is never entirely full, no need to reserve
	 * additional space for the trailing NULL appended below
	 */
	i = (size_t)1 << (tp->tshift);
	p = alloc2(i, sizeof(struct tbl *), ATEMP);
	sp = tp->tbls;		/* source */
	dp = p;			/* dest */
	while (i--)
		if ((*dp = *sp++) != NULL && (((*dp)->flag & DEFINED) ||
		    ((*dp)->flag & ARRAY)))
			dp++;
	qsort(p, (i = dp - p), sizeof(struct tbl *), tnamecmp);
	p[i] = NULL;
	return (p);
}

#ifdef SIGWINCH
static void
x_sigwinch(int sig MKSH_A_UNUSED)
{
	/* this runs inside interrupt context, with errno saved */

	got_winch = 1;
}
#endif

#ifdef DF
void
DF(const char *fmt, ...)
{
	va_list args;
	struct timeval tv;
	mirtime_mjd mjd;

	mksh_lockfd(shl_dbg_fd);
	mksh_TIME(tv);
	timet2mjd(&mjd, tv.tv_sec);
	shf_fprintf(shl_dbg, "[%02u:%02u:%02u (%u) %u.%06u] ",
	    (unsigned)mjd.sec / 3600, ((unsigned)mjd.sec / 60) % 60,
	    (unsigned)mjd.sec % 60, (unsigned)getpid(),
	    (unsigned)tv.tv_sec, (unsigned)tv.tv_usec);
	va_start(args, fmt);
	shf_vfprintf(shl_dbg, fmt, args);
	va_end(args);
	shf_putc('\n', shl_dbg);
	shf_flush(shl_dbg);
	mksh_unlkfd(shl_dbg_fd);
}
#endif

void
x_mkraw(int fd, mksh_ttyst *ocb, bool forread)
{
	mksh_ttyst cb;

	if (ocb)
		mksh_tcget(fd, ocb);
	else
		ocb = &tty_state;

	cb = *ocb;
	if (forread) {
		cb.c_iflag &= ~(ISTRIP);
		cb.c_lflag &= ~(ICANON) | ECHO;
	} else {
		cb.c_iflag &= ~(INLCR | ICRNL | ISTRIP);
		cb.c_lflag &= ~(ISIG | ICANON | ECHO);
	}
#if defined(VLNEXT) && defined(_POSIX_VDISABLE)
	/* OSF/1 processes lnext when ~icanon */
	cb.c_cc[VLNEXT] = _POSIX_VDISABLE;
#endif
	/* SunOS 4.1.x and OSF/1 process discard(flush) when ~icanon */
#if defined(VDISCARD) && defined(_POSIX_VDISABLE)
	cb.c_cc[VDISCARD] = _POSIX_VDISABLE;
#endif
	cb.c_cc[VTIME] = 0;
	cb.c_cc[VMIN] = 1;

	mksh_tcset(fd, &cb);
}

#ifdef MKSH_ENVDIR
static void
init_environ(void)
{
	char *xp;
	ssize_t n;
	XString xs;
	struct shf *shf;
	DIR *dirp;
	struct dirent *dent;

	if ((dirp = opendir(MKSH_ENVDIR)) == NULL) {
		warningf(false, "cannot read environment from %s: %s",
		    MKSH_ENVDIR, cstrerror(errno));
		return;
	}
	XinitN(xs, 256, ATEMP);
 read_envfile:
	errno = 0;
	if ((dent = readdir(dirp)) != NULL) {
		if (skip_varname(dent->d_name, true)[0] == '\0') {
			strpathx(xp, MKSH_ENVDIR, dent->d_name, 1);
			if (!(shf = shf_open(xp, O_RDONLY, 0, 0))) {
				warningf(false,
				    "cannot read environment %s from %s: %s",
				    dent->d_name, MKSH_ENVDIR,
				    cstrerror(errno));
				goto read_envfile;
			}
			afree(xp, ATEMP);
			n = strlen(dent->d_name);
			xp = Xstring(xs, xp);
			XcheckN(xs, xp, n + 32);
			memcpy(xp, dent->d_name, n);
			xp += n;
			*xp++ = '=';
			while ((n = shf_read(xp, Xnleft(xs, xp), shf)) > 0) {
				xp += n;
				if (Xnleft(xs, xp) <= 0)
					XcheckN(xs, xp, Xlength(xs, xp));
			}
			if (n < 0) {
				warningf(false,
				    "cannot read environment %s from %s: %s",
				    dent->d_name, MKSH_ENVDIR,
				    cstrerror(shf_errno(shf)));
			} else {
				*xp = '\0';
				xp = Xstring(xs, xp);
				rndpush(xp);
				typeset(xp, IMPORT | EXPORT, 0, 0, 0);
			}
			shf_close(shf);
		}
		goto read_envfile;
	} else if (errno)
		warningf(false, "cannot read environment from %s: %s",
		    MKSH_ENVDIR, cstrerror(errno));
	closedir(dirp);
	Xfree(xs, xp);
}
#else
extern char **environ;

static void
init_environ(void)
{
	const char **wp;

	if (environ == NULL)
		return;

	wp = (const char **)environ;
	while (*wp != NULL) {
		rndpush(*wp);
		typeset(*wp, IMPORT | EXPORT, 0, 0, 0);
		++wp;
	}
}
#endif

#ifdef MKSH_EARLY_LOCALE_TRACKING
void
recheck_ctype(void)
{
	const char *ccp;
	uint8_t old_utfmode = UTFMODE;

	ccp = str_val(global("LC_ALL"));
	if (ccp == null)
		ccp = str_val(global("LC_CTYPE"));
	if (ccp == null)
		ccp = str_val(global("LANG"));
	UTFMODE = isuc(ccp);
#if HAVE_SETLOCALE_CTYPE
	ccp = setlocale(LC_CTYPE, ccp);
#if HAVE_LANGINFO_CODESET
	if (!isuc(ccp))
		ccp = nl_langinfo(CODESET);
#endif
	if (isuc(ccp))
		UTFMODE = 1;
#endif

	if (Flag(FPOSIX) && UTFMODE && !old_utfmode)
		warningf(true, "early locale tracking enabled UTF-8 mode while in POSIX mode, you are now noncompliant");
}
#endif
