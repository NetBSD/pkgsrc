/*	$OpenBSD: c_ksh.c,v 1.37 2015/09/10 22:48:58 nicm Exp $	*/
/*	$OpenBSD: c_sh.c,v 1.46 2015/07/20 20:46:24 guenther Exp $	*/
/*	$OpenBSD: c_test.c,v 1.18 2009/03/01 20:11:06 otto Exp $	*/
/*	$OpenBSD: c_ulimit.c,v 1.19 2013/11/28 10:33:37 sobrado Exp $	*/

/*-
 * Copyright (c) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009,
 *		 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017,
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

#include "sh.h"

#if HAVE_SELECT
#if HAVE_SYS_BSDTYPES_H
#include <sys/bsdtypes.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#if HAVE_BSTRING_H
#include <bstring.h>
#endif
#endif

__RCSID("$MirOS: src/bin/mksh/funcs.c,v 1.373 2020/05/16 22:38:21 tg Exp $");

#if HAVE_KILLPG
/*
 * use killpg if < -1 since -1 does special things
 * for some non-killpg-endowed kills
 */
#define mksh_kill(p,s)	((p) < -1 ? killpg(-(p), (s)) : kill((p), (s)))
#else
/* cross fingers and hope kill is killpg-endowed */
#define mksh_kill	kill
#endif

/* XXX conditions correct? */
#if !defined(RLIM_INFINITY) && !defined(MKSH_NO_LIMITS)
#define MKSH_NO_LIMITS	1
#endif

#ifdef MKSH_NO_LIMITS
#define c_ulimit	c_true
#endif

#if !defined(MKSH_UNEMPLOYED) && HAVE_GETSID
static int c_suspend(const char **);
#endif

static int do_whence(const char **, int, bool, bool);

/* getn() that prints error */
static int
bi_getn(const char *as, int *ai)
{
	int rv;

	if (!(rv = getn(as, ai)))
		bi_errorf(Tf_sD_s, Tbadnum, as);
	return (rv);
}

static int
c_true(const char **wp MKSH_A_UNUSED)
{
	return (0);
}

static int
c_false(const char **wp MKSH_A_UNUSED)
{
	return (1);
}

/*
 * A leading = means assignments before command are kept.
 * A leading * means a POSIX special builtin.
 * A leading ^ means declaration utility, - forwarder.
 */
const struct builtin mkshbuiltins[] = {
	{Tsgdot, c_dot},
	{"*=:", c_true},
	{Tbracket, c_test},
	/* no =: AT&T manual wrong */
	{Talias, c_alias},
	{Tsgbreak, c_brkcont},
	{T__builtin, c_builtin},
	{Tbuiltin, c_builtin},
	{Tbcat, c_cat},
	{Tcd, c_cd},
	/* dash compatibility hack */
	{"chdir", c_cd},
	{T_command, c_command},
	{Tsgcontinue, c_brkcont},
	{"echo", c_print},
	{"*=eval", c_eval},
	{"*=exec", c_exec},
	{"*=exit", c_exitreturn},
	{Tdsgexport, c_typeset},
	{Tfalse, c_false},
	{"fc", c_fc},
	{Tgetopts, c_getopts},
	{Tjobs, c_jobs},
	{"kill", c_kill},
	{"let", c_let},
	{"print", c_print},
	{"pwd", c_pwd},
	{Tread, c_read},
	{Tdsgreadonly, c_typeset},
	{"!realpath", c_realpath},
	{"~rename", c_rename},
	{"*=return", c_exitreturn},
	{Tsghset, c_set},
	{"*=#shift", c_shift},
	{Tgsource, c_dot},
#if !defined(MKSH_UNEMPLOYED) && HAVE_GETSID
	{Tsuspend, c_suspend},
#endif
	{"test", c_test},
	{"*=times", c_times},
	{"*=trap", c_trap},
	{Ttrue, c_true},
	{Tdgtypeset, c_typeset},
	{"ulimit", c_ulimit},
	{"umask", c_umask},
	{Tunalias, c_unalias},
	{"*=unset", c_unset},
	{"wait", c_wait},
	{"whence", c_whence},
#ifndef MKSH_UNEMPLOYED
	{Tbg, c_fgbg},
	{Tfg, c_fgbg},
#endif
#ifndef MKSH_NO_CMDLINE_EDITING
	{"bind", c_bind},
#endif
#if HAVE_MKNOD
	{"mknod", c_mknod},
#endif
#ifdef MKSH_PRINTF_BUILTIN
	{"~printf", c_printf},
#endif
#if HAVE_SELECT
	{"sleep", c_sleep},
#endif
#ifdef __MirBSD__
	/* alias to "true" for historical reasons */
	{"domainname", c_true},
#endif
#ifdef __OS2__
	{Textproc, c_true},
#endif
	{NULL, (int (*)(const char **))NULL}
};

struct kill_info {
	int num_width;
	int name_width;
};

const struct t_op u_ops[] = {
/* 0*/	{"-a",	TO_FILAXST },
	{"-b",	TO_FILBDEV },
	{"-c",	TO_FILCDEV },
	{"-d",	TO_FILID },
	{"-e",	TO_FILEXST },
	{"-f",	TO_FILREG },
	{"-G",	TO_FILGID },
	{"-g",	TO_FILSETG },
	{"-H",	TO_FILCDF },
	{"-h",	TO_FILSYM },
	{"-k",	TO_FILSTCK },
	{"-L",	TO_FILSYM },
/*12*/	{"-n",	TO_STNZE },
	{"-O",	TO_FILUID },
/*14*/	{"-o",	TO_OPTION },
	{"-p",	TO_FILFIFO },
/*16*/	{"-r",	TO_FILRD },
	{"-S",	TO_FILSOCK },
	{"-s",	TO_FILGZ },
	{"-t",	TO_FILTT },
/*20*/	{"-u",	TO_FILSETU },
	{"-v",	TO_ISSET },
	{"-w",	TO_FILWR },
/*23*/	{"-x",	TO_FILEX },
	{"-z",	TO_STZER },
	{"",	TO_NONOP }
};
cta(u_ops_size, NELEM(u_ops) == 26);
const struct t_op b_ops[] = {
	{"=",	TO_STEQL },
	{"==",	TO_STEQL },
	{"!=",	TO_STNEQ },
	{"<",	TO_STLT },
	{">",	TO_STGT },
	{"-eq",	TO_INTEQ },
	{"-ne",	TO_INTNE },
	{"-gt",	TO_INTGT },
	{"-ge",	TO_INTGE },
	{"-lt",	TO_INTLT },
	{"-le",	TO_INTLE },
	{"-ef",	TO_FILEQ },
	{"-nt",	TO_FILNT },
	{"-ot",	TO_FILOT },
	{"",	TO_NONOP }
};

static int test_oexpr(Test_env *, bool);
static int test_aexpr(Test_env *, bool);
static int test_nexpr(Test_env *, bool);
static int test_primary(Test_env *, bool);
static Test_op ptest_isa(Test_env *, Test_meta);
static const char *ptest_getopnd(Test_env *, Test_op, bool);
static void ptest_error(Test_env *, int, const char *);
static void kill_fmt_entry(char *, size_t, unsigned int, const void *);
static void p_time(struct shf *, bool, long, int, int,
    const char *, const char *);

int
c_pwd(const char **wp)
{
	int optc;
	bool physical = tobool(Flag(FPHYSICAL));
	char *p, *allocd = NULL;

	while ((optc = ksh_getopt(wp, &builtin_opt, "LP")) != -1)
		switch (optc) {
		case 'L':
			physical = false;
			break;
		case 'P':
			physical = true;
			break;
		case '?':
			return (1);
		}
	wp += builtin_opt.optind;

	if (wp[0]) {
		bi_errorf(Ttoo_many_args);
		return (1);
	}
	p = current_wd[0] ? (physical ? allocd = do_realpath(current_wd) :
	    current_wd) : NULL;
	/* LINTED use of access */
	if (p && access(p, R_OK) < 0)
		p = NULL;
	if (!p && !(p = allocd = ksh_get_wd())) {
		bi_errorf(Tf_sD_s, "can't determine current directory",
		    cstrerror(errno));
		return (1);
	}
	shprintf(Tf_sN, p);
	afree(allocd, ATEMP);
	return (0);
}

static const char *s_ptr;
static int s_get(void);
static void s_put(int);

int
c_print(const char **wp)
{
	int c;
	const char *s;
	char *xp;
	XString xs;
	struct {
		/* storage for columnisation */
		XPtrV words;
		/* temporary storage for a wide character */
		mksh_ari_t wc;
		/* output file descriptor (if any) */
		int fd;
		/* temporary storage for a multibyte character */
		char ts[4];
		/* output word separator */
		char ws;
		/* output line separator */
		char ls;
		/* output a trailing line separator? */
		bool nl;
		/* expand backslash sequences? */
		bool exp;
		/* columnise output? */
		bool col;
		/* print to history instead of file descriptor / stdout? */
		bool hist;
		/* print words as wide characters? */
		bool chars;
		/* writing to a coprocess (SIGPIPE blocked)? */
		bool coproc;
		bool copipe;
	} po;

	memset(&po, 0, sizeof(po));
	po.fd = 1;
	po.ws = ' ';
	po.ls = '\n';
	po.nl = true;

	if (wp[0][0] == 'e') {
		/* "echo" builtin */
		if (Flag(FPOSIX) ||
#ifndef MKSH_MIDNIGHTBSD01ASH_COMPAT
		    Flag(FSH) ||
#endif
		    as_builtin) {
			/* BSD "echo" cmd, Debian Policy 10.4 compliant */
			++wp;
 bsd_echo:
			if (*wp && !strcmp(*wp, Tdn)) {
				po.nl = false;
				++wp;
			}
			po.exp = false;
		} else {
			bool new_exp, new_nl = true;

			/*-
			 * compromise between various historic echos: only
			 * recognise -Een if they appear in arguments with
			 * no illegal options; e.g. echo -nq outputs '-nq'
			 */
#ifdef MKSH_MIDNIGHTBSD01ASH_COMPAT
			/* MidnightBSD /bin/sh needs -e supported but off */
			if (Flag(FSH))
				new_exp = false;
			else
#endif
			/* otherwise compromise on -e enabled by default */
			  new_exp = true;
			goto print_tradparse_beg;

 print_tradparse_arg:
			if ((s = *wp) && *s++ == '-' && *s) {
 print_tradparse_ch:
				switch ((c = *s++)) {
				case 'E':
					new_exp = false;
					goto print_tradparse_ch;
				case 'e':
					new_exp = true;
					goto print_tradparse_ch;
				case 'n':
					new_nl = false;
					goto print_tradparse_ch;
				case '\0':
 print_tradparse_beg:
					po.exp = new_exp;
					po.nl = new_nl;
					++wp;
					goto print_tradparse_arg;
				}
			}
		}
	} else {
		/* "print" builtin */
		const char *opts = "AcelNnpRrsu,";
		const char *emsg;

		po.exp = true;

		while ((c = ksh_getopt(wp, &builtin_opt, opts)) != -1)
			switch (c) {
			case 'A':
				po.chars = true;
				break;
			case 'c':
				po.col = true;
				break;
			case 'e':
				po.exp = true;
				break;
			case 'l':
				po.ws = '\n';
				break;
			case 'N':
				po.ws = '\0';
				po.ls = '\0';
				break;
			case 'n':
				po.nl = false;
				break;
			case 'p':
				if ((po.fd = coproc_getfd(W_OK, &emsg)) < 0) {
					bi_errorf(Tf_coproc, emsg);
					return (1);
				}
				break;
			case 'R':
				/* fake BSD echo but don't reset other flags */
				wp += builtin_opt.optind;
				goto bsd_echo;
			case 'r':
				po.exp = false;
				break;
			case 's':
				po.hist = true;
				break;
			case 'u':
				if (!*(s = builtin_opt.optarg))
					po.fd = 0;
				else if ((po.fd = check_fd(s, W_OK, &emsg)) < 0) {
					bi_errorf("-u%s: %s", s, emsg);
					return (1);
				}
				break;
			case '?':
				return (1);
			}

		if (!(builtin_opt.info & GI_MINUSMINUS)) {
			/* treat a lone "-" like "--" */
			if (wp[builtin_opt.optind] &&
			    ksh_isdash(wp[builtin_opt.optind]))
				builtin_opt.optind++;
		}
		wp += builtin_opt.optind;
	}

	if (po.col) {
		if (*wp == NULL)
			return (0);

		XPinit(po.words, 16);
	}

	Xinit(xs, xp, 128, ATEMP);

	if (*wp == NULL)
		goto print_no_arg;
 print_read_arg:
	if (po.chars) {
		while (*wp != NULL) {
			s = *wp++;
			if (*s == '\0')
				break;
			if (!evaluate(s, &po.wc, KSH_RETURN_ERROR, true))
				return (1);
			Xcheck(xs, xp);
			if (UTFMODE) {
				po.ts[utf_wctomb(po.ts, po.wc)] = 0;
				c = 0;
				do {
					Xput(xs, xp, po.ts[c]);
				} while (po.ts[++c]);
			} else
				Xput(xs, xp, po.wc & 0xFF);
		}
	} else {
		s = *wp++;
		while ((c = *s++) != '\0') {
			Xcheck(xs, xp);
			if (po.exp && c == '\\') {
				s_ptr = s;
				c = unbksl(false, s_get, s_put);
				s = s_ptr;
				if (c == -1) {
					/* rejected by generic function */
					switch ((c = *s++)) {
					case 'c':
						po.nl = false;
						/* AT&T brain damage */
						continue;
					case '\0':
						--s;
						c = '\\';
						break;
					default:
						Xput(xs, xp, '\\');
					}
				} else if ((unsigned int)c > 0xFF) {
					/* generic function returned UCS */
					po.ts[utf_wctomb(po.ts, c - 0x100)] = 0;
					c = 0;
					do {
						Xput(xs, xp, po.ts[c]);
					} while (po.ts[++c]);
					continue;
				}
			}
			Xput(xs, xp, c);
		}
	}
	if (po.col) {
		Xput(xs, xp, '\0');
		XPput(po.words, Xclose(xs, xp));
		Xinit(xs, xp, 128, ATEMP);
	}
	if (*wp != NULL) {
		if (!po.col)
			Xput(xs, xp, po.ws);
		goto print_read_arg;
	}
	if (po.col) {
		size_t w = XPsize(po.words);
		struct columnise_opts co;

		XPput(po.words, NULL);
		co.shf = shf_sopen(NULL, 128, SHF_WR | SHF_DYNAMIC, NULL);
		co.linesep = po.ls;
		co.prefcol = co.do_last = false;
		pr_list(&co, (char **)XPptrv(po.words));
		while (w--)
			afree(XPptrv(po.words)[w], ATEMP);
		XPfree(po.words);
		w = co.shf->wp - co.shf->buf;
		XcheckN(xs, xp, w);
		memcpy(xp, co.shf->buf, w);
		xp += w;
		shf_sclose(co.shf);
	}
 print_no_arg:
	if (po.nl)
		Xput(xs, xp, po.ls);

	c = 0;
	if (po.hist) {
		Xput(xs, xp, '\0');
		histsave(&source->line, Xstring(xs, xp), HIST_STORE, false);
	} else {
		size_t len = Xlength(xs, xp);

		/*
		 * Ensure we aren't killed by a SIGPIPE while writing to
		 * a coprocess. AT&T ksh doesn't seem to do this (seems
		 * to just check that the co-process is alive which is
		 * not enough).
		 */
		if (coproc.write >= 0 && coproc.write == po.fd) {
			po.coproc = true;
			po.copipe = block_pipe();
		} else
			po.coproc = po.copipe = false;

		s = Xstring(xs, xp);
		while (len > 0) {
			ssize_t nwritten;

			if ((nwritten = write(po.fd, s, len)) < 0) {
				if (errno == EINTR) {
					if (po.copipe)
						restore_pipe();
					/* give the user a chance to ^C out */
					intrcheck();
					/* interrupted, try again */
					if (po.coproc)
						po.copipe = block_pipe();
					continue;
				}
				c = 1;
				break;
			}
			s += nwritten;
			len -= nwritten;
		}
		if (po.copipe)
			restore_pipe();
	}
	Xfree(xs, xp);

	return (c);
}

static int
s_get(void)
{
	return (ord(*s_ptr++));
}

static void
s_put(int c MKSH_A_UNUSED)
{
	--s_ptr;
}

int
c_whence(const char **wp)
{
	int optc;
	bool pflag = false, vflag = false;

	while ((optc = ksh_getopt(wp, &builtin_opt, Tpv)) != -1)
		switch (optc) {
		case 'p':
			pflag = true;
			break;
		case 'v':
			vflag = true;
			break;
		case '?':
			return (1);
		}
	wp += builtin_opt.optind;

	return (do_whence(wp, pflag ? FC_PATH :
	    FC_BI | FC_FUNC | FC_PATH | FC_WHENCE, vflag, false));
}

/* note: command without -vV is dealt with in comexec() */
int
c_command(const char **wp)
{
	int optc, fcflags = FC_BI | FC_FUNC | FC_PATH | FC_WHENCE;
	bool vflag = false;

	while ((optc = ksh_getopt(wp, &builtin_opt, TpVv)) != -1)
		switch (optc) {
		case 'p':
			fcflags |= FC_DEFPATH;
			break;
		case 'V':
			vflag = true;
			break;
		case 'v':
			vflag = false;
			break;
		case '?':
			return (1);
		}
	wp += builtin_opt.optind;

	return (do_whence(wp, fcflags, vflag, true));
}

static int
do_whence(const char **wp, int fcflags, bool vflag, bool iscommand)
{
	uint32_t h;
	int rv = 0;
	struct tbl *tp;
	const char *id;

	while ((vflag || rv == 0) && (id = *wp++) != NULL) {
		h = hash(id);
		tp = NULL;

		if (fcflags & FC_WHENCE)
			tp = ktsearch(&keywords, id, h);
		if (!tp && (fcflags & FC_WHENCE)) {
			tp = ktsearch(&aliases, id, h);
			if (tp && !(tp->flag & ISSET))
				tp = NULL;
		}
		if (!tp)
			tp = findcom(id, fcflags);

		switch (tp->type) {
		case CSHELL:
		case CFUNC:
		case CKEYWD:
			shf_puts(id, shl_stdout);
			break;
		}

		switch (tp->type) {
		case CSHELL:
			if (vflag)
				shprintf(" is a %sshell %s",
				    (tp->flag & SPEC_BI) ? "special " : "",
				    Tbuiltin);
			break;
		case CFUNC:
			if (vflag) {
				shf_puts(" is a", shl_stdout);
				if (tp->flag & EXPORT)
					shf_puts("n exported", shl_stdout);
				if (tp->flag & TRACE)
					shf_puts(" traced", shl_stdout);
				if (!(tp->flag & ISSET)) {
					shf_puts(" undefined", shl_stdout);
					if (tp->u.fpath)
						shprintf(" (autoload from %s)",
						    tp->u.fpath);
				}
				shf_puts(T_function, shl_stdout);
			}
			break;
		case CEXEC:
		case CTALIAS:
			if (tp->flag & ISSET) {
				if (vflag) {
					shprintf("%s is ", id);
					if (tp->type == CTALIAS)
						shprintf("a tracked %s%s for ",
						    (tp->flag & EXPORT) ?
						    "exported " : "",
						    Talias);
				}
				shf_puts(tp->val.s, shl_stdout);
			} else {
				if (vflag)
					shprintf(Tnot_found_s, id);
				rv = 1;
			}
			break;
		case CALIAS:
			if (!vflag && iscommand)
				shprintf(Tf_s_, Talias);
			if (vflag || iscommand)
				print_value_quoted(shl_stdout, id);
			if (vflag)
				shprintf(" is an %s%s for ",
				    (tp->flag & EXPORT) ? "exported " : "",
				    Talias);
			else if (iscommand)
				shf_putc('=', shl_stdout);
			print_value_quoted(shl_stdout, tp->val.s);
			break;
		case CKEYWD:
			if (vflag)
				shf_puts(" is a reserved word", shl_stdout);
			break;
#ifndef MKSH_SMALL
		default:
			bi_errorf(Tunexpected_type, id, Tcommand, tp->type);
			return (1);
#endif
		}
		if (vflag || !rv)
			shf_putc('\n', shl_stdout);
	}
	return (rv);
}

bool
valid_alias_name(const char *cp)
{
	switch (ord(*cp)) {
	case ORD('+'):
	case ORD('-'):
		return (false);
	case ORD('['):
		if (ord(cp[1]) == ORD('[') && !cp[2])
			return (false);
		break;
	}
	while (*cp)
		if (ctype(*cp, C_ALIAS))
			++cp;
		else
			return (false);
	return (true);
}

int
c_alias(const char **wp)
{
	struct table *t = &aliases;
	int rv = 0, prefix = 0;
	bool rflag = false, tflag, Uflag = false, pflag = false, chkalias;
	uint32_t xflag = 0;
	int optc;

	builtin_opt.flags |= GF_PLUSOPT;
	while ((optc = ksh_getopt(wp, &builtin_opt, "dprtUx")) != -1) {
		prefix = builtin_opt.info & GI_PLUS ? '+' : '-';
		switch (optc) {
		case 'd':
#ifdef MKSH_NOPWNAM
			t = NULL;	/* fix "alias -dt" */
#else
			t = &homedirs;
#endif
			break;
		case 'p':
			pflag = true;
			break;
		case 'r':
			rflag = true;
			break;
		case 't':
			t = &taliases;
			break;
		case 'U':
			/*
			 * kludge for tracked alias initialization
			 * (don't do a path search, just make an entry)
			 */
			Uflag = true;
			break;
		case 'x':
			xflag = EXPORT;
			break;
		case '?':
			return (1);
		}
	}
#ifdef MKSH_NOPWNAM
	if (t == NULL)
		return (0);
#endif
	wp += builtin_opt.optind;

	if (!(builtin_opt.info & GI_MINUSMINUS) && *wp &&
	    ctype(wp[0][0], C_MINUS | C_PLUS) && wp[0][1] == '\0') {
		prefix = wp[0][0];
		wp++;
	}

	tflag = t == &taliases;
	chkalias = t == &aliases;

	/* "hash -r" means reset all the tracked aliases.. */
	if (rflag) {
		static const char *args[] = {
			Tunalias, "-ta", NULL
		};

		if (!tflag || *wp) {
			shprintf("%s: -r flag can only be used with -t"
			    " and without arguments\n", Talias);
			return (1);
		}
		ksh_getopt_reset(&builtin_opt, GF_ERROR);
		return (c_unalias(args));
	}

	if (*wp == NULL) {
		struct tbl *ap, **p;

		for (p = ktsort(t); (ap = *p++) != NULL; )
			if ((ap->flag & (ISSET|xflag)) == (ISSET|xflag)) {
				if (pflag)
					shprintf(Tf_s_, Talias);
				print_value_quoted(shl_stdout, ap->name);
				if (prefix != '+') {
					shf_putc('=', shl_stdout);
					print_value_quoted(shl_stdout, ap->val.s);
				}
				shf_putc('\n', shl_stdout);
			}
	}

	for (; *wp != NULL; wp++) {
		const char *alias = *wp, *val, *newval;
		char *xalias = NULL;
		struct tbl *ap;
		uint32_t h;

		if ((val = cstrchr(alias, '='))) {
			strndupx(xalias, alias, val++ - alias, ATEMP);
			alias = xalias;
		}
		if (chkalias && !valid_alias_name(alias)) {
			bi_errorf(Tinvname, alias, Talias);
			afree(xalias, ATEMP);
			return (1);
		}
		h = hash(alias);
		if (val == NULL && !tflag && !xflag) {
			ap = ktsearch(t, alias, h);
			if (ap != NULL && (ap->flag&ISSET)) {
				if (pflag)
					shprintf(Tf_s_, Talias);
				print_value_quoted(shl_stdout, ap->name);
				if (prefix != '+') {
					shf_putc('=', shl_stdout);
					print_value_quoted(shl_stdout, ap->val.s);
				}
				shf_putc('\n', shl_stdout);
			} else {
				shprintf(Tf_s_s_sN, alias, Talias, Tnot_found);
				rv = 1;
			}
			continue;
		}
		ap = ktenter(t, alias, h);
		ap->type = tflag ? CTALIAS : CALIAS;
		/* Are we setting the value or just some flags? */
		if ((val && !tflag) || (!val && tflag && !Uflag)) {
			if (ap->flag&ALLOC) {
				ap->flag &= ~(ALLOC|ISSET);
				afree(ap->val.s, APERM);
			}
			/* ignore values for -t (AT&T ksh does this) */
			newval = tflag ?
			    search_path(alias, path, X_OK, NULL) :
			    val;
			if (newval) {
				strdupx(ap->val.s, newval, APERM);
				ap->flag |= ALLOC|ISSET;
			} else
				ap->flag &= ~ISSET;
		}
		ap->flag |= DEFINED;
		if (prefix == '+')
			ap->flag &= ~xflag;
		else
			ap->flag |= xflag;
		afree(xalias, ATEMP);
	}

	return (rv);
}

int
c_unalias(const char **wp)
{
	struct table *t = &aliases;
	struct tbl *ap;
	int optc, rv = 0;
	bool all = false;

	while ((optc = ksh_getopt(wp, &builtin_opt, "adt")) != -1)
		switch (optc) {
		case 'a':
			all = true;
			break;
		case 'd':
#ifdef MKSH_NOPWNAM
			/* fix "unalias -dt" */
			t = NULL;
#else
			t = &homedirs;
#endif
			break;
		case 't':
			t = &taliases;
			break;
		case '?':
			return (1);
		}
#ifdef MKSH_NOPWNAM
	if (t == NULL)
		return (0);
#endif
	wp += builtin_opt.optind;

	for (; *wp != NULL; wp++) {
		ap = ktsearch(t, *wp, hash(*wp));
		if (ap == NULL) {
			/* POSIX */
			rv = 1;
			continue;
		}
		if (ap->flag&ALLOC) {
			ap->flag &= ~(ALLOC|ISSET);
			afree(ap->val.s, APERM);
		}
		ap->flag &= ~(DEFINED|ISSET|EXPORT);
	}

	if (all) {
		struct tstate ts;

		for (ktwalk(&ts, t); (ap = ktnext(&ts)); ) {
			if (ap->flag&ALLOC) {
				ap->flag &= ~(ALLOC|ISSET);
				afree(ap->val.s, APERM);
			}
			ap->flag &= ~(DEFINED|ISSET|EXPORT);
		}
	}

	return (rv);
}

int
c_let(const char **wp)
{
	int rv = 1;
	mksh_ari_t val;

	if (wp[1] == NULL)
		/* AT&T ksh does this */
		bi_errorf(Tno_args);
	else
		for (wp++; *wp; wp++)
			if (!evaluate(*wp, &val, KSH_RETURN_ERROR, true)) {
				/* distinguish error from zero result */
				rv = 2;
				break;
			} else
				rv = val == 0;
	return (rv);
}

int
c_jobs(const char **wp)
{
	int optc, flag = 0, nflag = 0, rv = 0;

	while ((optc = ksh_getopt(wp, &builtin_opt, "lpnz")) != -1)
		switch (optc) {
		case 'l':
			flag = 1;
			break;
		case 'p':
			flag = 2;
			break;
		case 'n':
			nflag = 1;
			break;
		case 'z':
			/* debugging: print zombies */
			nflag = -1;
			break;
		case '?':
			return (1);
		}
	wp += builtin_opt.optind;
	if (!*wp) {
		if (j_jobs(NULL, flag, nflag))
			rv = 1;
	} else {
		for (; *wp; wp++)
			if (j_jobs(*wp, flag, nflag))
				rv = 1;
	}
	return (rv);
}

#ifndef MKSH_UNEMPLOYED
int
c_fgbg(const char **wp)
{
	bool bg = strcmp(*wp, Tbg) == 0;
	int rv = 0;

	if (!Flag(FMONITOR)) {
		bi_errorf("job control not enabled");
		return (1);
	}
	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	wp += builtin_opt.optind;
	if (*wp)
		for (; *wp; wp++)
			rv = j_resume(*wp, bg);
	else
		rv = j_resume("%%", bg);
	/* fg returns $? of the job unless POSIX */
	return ((bg | Flag(FPOSIX)) ? 0 : rv);
}
#endif

/* format a single kill item */
static void
kill_fmt_entry(char *buf, size_t buflen, unsigned int i, const void *arg)
{
	const struct kill_info *ki = (const struct kill_info *)arg;

	i++;
	shf_snprintf(buf, buflen, "%*u %*s %s",
	    ki->num_width, i,
	    ki->name_width, sigtraps[i].name,
	    sigtraps[i].mess);
}

int
c_kill(const char **wp)
{
	Trap *t = NULL;
	const char *p;
	bool lflag = false;
	int i, n, rv, sig;

	/* assume old style options if -digits or -UPPERCASE */
	if ((p = wp[1]) && *p == '-' && ctype(p[1], C_DIGIT | C_UPPER)) {
		if (!(t = gettrap(p + 1, false, false))) {
			bi_errorf(Tbad_sig_s, p + 1);
			return (1);
		}
		i = (wp[2] && strcmp(wp[2], "--") == 0) ? 3 : 2;
	} else {
		int optc;

		while ((optc = ksh_getopt(wp, &builtin_opt, "ls:")) != -1)
			switch (optc) {
			case 'l':
				lflag = true;
				break;
			case 's':
				if (!(t = gettrap(builtin_opt.optarg,
				    true, false))) {
					bi_errorf(Tbad_sig_s,
					    builtin_opt.optarg);
					return (1);
				}
				break;
			case '?':
				return (1);
			}
		i = builtin_opt.optind;
	}
	if ((lflag && t) || (!wp[i] && !lflag)) {
#ifndef MKSH_SMALL
		shf_puts("usage:\tkill [-s signame | -signum | -signame]"
		    " { job | pid | pgrp } ...\n"
		    "\tkill -l [exit_status ...]\n", shl_out);
#endif
		bi_errorfz();
		return (1);
	}

	if (lflag) {
		if (wp[i]) {
			for (; wp[i]; i++) {
				if (!bi_getn(wp[i], &n))
					return (1);
#if (ksh_NSIG <= 128)
				if (n > 128 && n < 128 + ksh_NSIG)
					n -= 128;
#endif
				if (n > 0 && n < ksh_NSIG)
					shprintf(Tf_sN, sigtraps[n].name);
				else
					shprintf(Tf_dN, n);
			}
		} else if (Flag(FPOSIX)) {
			n = 1;
			while (n < ksh_NSIG) {
				shf_puts(sigtraps[n].name, shl_stdout);
				shf_putc(++n == ksh_NSIG ? '\n' : ' ',
				    shl_stdout);
			}
		} else {
			ssize_t w, mess_cols = 0, mess_octs = 0;
			int j = ksh_NSIG - 1;
			struct kill_info ki = { 0, 0 };
			struct columnise_opts co;

			do {
				ki.num_width++;
			} while ((j /= 10));

			for (j = 1; j < ksh_NSIG; j++) {
				w = strlen(sigtraps[j].name);
				if (w > ki.name_width)
					ki.name_width = w;
				w = strlen(sigtraps[j].mess);
				if (w > mess_octs)
					mess_octs = w;
				w = utf_mbswidth(sigtraps[j].mess);
				if (w > mess_cols)
					mess_cols = w;
			}

			co.shf = shl_stdout;
			co.linesep = '\n';
			co.prefcol = co.do_last = true;

			print_columns(&co, (unsigned int)(ksh_NSIG - 1),
			    kill_fmt_entry, (void *)&ki,
			    ki.num_width + 1 + ki.name_width + 1 + mess_octs,
			    ki.num_width + 1 + ki.name_width + 1 + mess_cols);
		}
		return (0);
	}
	rv = 0;
	sig = t ? t->signal : SIGTERM;
	for (; (p = wp[i]); i++) {
		if (*p == '%') {
			if (j_kill(p, sig))
				rv = 1;
		} else if (!getn(p, &n)) {
			bi_errorf(Tf_sD_s, p,
			    "arguments must be jobs or process IDs");
			rv = 1;
		} else {
			if (mksh_kill(n, sig) < 0) {
				bi_errorf(Tf_sD_s, p, cstrerror(errno));
				rv = 1;
			}
		}
	}
	return (rv);
}

void
getopts_reset(int val)
{
	if (val >= 1) {
		ksh_getopt_reset(&user_opt, GF_NONAME |
		    (Flag(FPOSIX) ? 0 : GF_PLUSOPT));
		user_opt.optind = user_opt.uoptind = val;
	}
}

int
c_getopts(const char **wp)
{
	int argc, optc, rv;
	const char *opts, *var;
	char buf[3];
	struct tbl *vq, *voptarg;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	wp += builtin_opt.optind;

	opts = *wp++;
	if (!opts) {
		bi_errorf(Tf_sD_s, "options", Tno_args);
		return (1);
	}

	var = *wp++;
	if (!var) {
		bi_errorf(Tf_sD_s, Tname, Tno_args);
		return (1);
	}
	if (!*var || *skip_varname(var, true)) {
		bi_errorf(Tf_sD_s, var, Tnot_ident);
		return (1);
	}

	if (e->loc->next == NULL) {
		internal_warningf(Tf_sD_s, Tgetopts, Tno_args);
		return (1);
	}
	/* Which arguments are we parsing... */
	if (*wp == NULL)
		wp = e->loc->next->argv;
	else
		*--wp = e->loc->next->argv[0];

	/* Check that our saved state won't cause a core dump... */
	for (argc = 0; wp[argc]; argc++)
		;
	if (user_opt.optind > argc ||
	    (user_opt.p != 0 &&
	    user_opt.p > strlen(wp[user_opt.optind - 1]))) {
		bi_errorf("arguments changed since last call");
		return (1);
	}

	user_opt.optarg = NULL;
	optc = ksh_getopt(wp, &user_opt, opts);

	if (optc >= 0 && optc != '?' && (user_opt.info & GI_PLUS)) {
		buf[0] = '+';
		buf[1] = optc;
		buf[2] = '\0';
	} else {
		/*
		 * POSIX says var is set to ? at end-of-options, AT&T ksh
		 * sets it to null - we go with POSIX...
		 */
		buf[0] = optc < 0 ? '?' : optc;
		buf[1] = '\0';
	}

	/* AT&T ksh93 in fact does change OPTIND for unknown options too */
	user_opt.uoptind = user_opt.optind;

	voptarg = global("OPTARG");
	/* AT&T ksh clears ro and int */
	voptarg->flag &= ~RDONLY;
	/* Paranoia: ensure no bizarre results. */
	if (voptarg->flag & INTEGER)
	    typeset("OPTARG", 0, INTEGER, 0, 0);
	if (user_opt.optarg == NULL)
		unset(voptarg, 1);
	else
		/* this can't fail (haing cleared readonly/integer) */
		setstr(voptarg, user_opt.optarg, KSH_RETURN_ERROR);

	rv = 0;

	vq = global(var);
	/* Error message already printed (integer, readonly) */
	if (!setstr(vq, buf, KSH_RETURN_ERROR))
		rv = 2;
	if (Flag(FEXPORT))
		typeset(var, EXPORT, 0, 0, 0);

	return (optc < 0 ? 1 : rv);
}

#ifndef MKSH_NO_CMDLINE_EDITING
int
c_bind(const char **wp)
{
	int optc, rv = 0;
#ifndef MKSH_SMALL
	bool macro = false;
#endif

	if (x_bind_check()) {
		bi_errorf("can't bind, not a tty");
		return (1);
	}

	while ((optc = ksh_getopt(wp, &builtin_opt, "lm")) != -1)
		switch (optc) {
		case 'l':
			return (x_bind_list());
#ifndef MKSH_SMALL
		case 'm':
			macro = true;
			break;
#endif
		default:
			return (1);
		}
	wp += builtin_opt.optind;

	if (*wp == NULL)
		return (x_bind_showall());

	do {
		rv |= x_bind(*wp SMALLP(macro));
	} while (*++wp);

	return (rv);
}
#endif

int
c_shift(const char **wp)
{
	int n;
	mksh_ari_t val;
	const char *arg;
	struct block *l = e->loc;

	if ((l->flags & BF_RESETSPEC)) {
		/* prevent pollution */
		l->flags &= ~BF_RESETSPEC;
		/* operate on parent environment */
		l = l->next;
	}

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	arg = wp[builtin_opt.optind];

	if (!arg)
		n = 1;
	else if (!evaluate(arg, &val, KSH_RETURN_ERROR, false)) {
		/* error already printed */
		bi_errorfz();
		return (1);
	} else if (!(n = val)) {
		/* nothing to do */
		return (0);
	} else if (n < 0) {
		bi_errorf(Tf_sD_s, Tbadnum, arg);
		return (1);
	}

	if (l->argc < n) {
		bi_errorf("nothing to shift");
		return (1);
	}
	l->argv[n] = l->argv[0];
	l->argv += n;
	l->argc -= n;
	return (0);
}

int
c_umask(const char **wp)
{
	int i, optc;
	const char *cp;
	bool symbolic = false;
	mode_t old_umask;

	while ((optc = ksh_getopt(wp, &builtin_opt, "S")) != -1)
		switch (optc) {
		case 'S':
			symbolic = true;
			break;
		case '?':
			return (1);
		}
	cp = wp[builtin_opt.optind];
	if (cp == NULL) {
		old_umask = umask((mode_t)0);
		umask(old_umask);
		if (symbolic) {
			char buf[18], *p;
			int j;

			old_umask = ~old_umask;
			p = buf;
			for (i = 0; i < 3; i++) {
				*p++ = Tugo[i];
				*p++ = '=';
				for (j = 0; j < 3; j++)
					if (old_umask & (1 << (8 - (3*i + j))))
						*p++ = "rwx"[j];
				*p++ = ',';
			}
			p[-1] = '\0';
			shprintf(Tf_sN, buf);
		} else
			shprintf("%#3.3o\n", (unsigned int)old_umask);
	} else {
		mode_t new_umask;

		if (ctype(*cp, C_DIGIT)) {
			new_umask = 0;
			while (ctype(*cp, C_OCTAL)) {
				new_umask = new_umask * 8 + ksh_numdig(*cp);
				++cp;
			}
			if (*cp) {
				bi_errorf(Tbadnum);
				return (1);
			}
		} else {
			/* symbolic format */
			int positions, new_val;
			char op;

			old_umask = umask((mode_t)0);
			/* in case of error */
			umask(old_umask);
			old_umask = ~old_umask;
			new_umask = old_umask;
			positions = 0;
			while (*cp) {
				while (*cp && vstrchr(Taugo, *cp))
					switch (*cp++) {
					case 'a':
						positions |= 0111;
						break;
					case 'u':
						positions |= 0100;
						break;
					case 'g':
						positions |= 0010;
						break;
					case 'o':
						positions |= 0001;
						break;
					}
				if (!positions)
					/* default is a */
					positions = 0111;
				if (!ctype((op = *cp), C_EQUAL | C_MINUS | C_PLUS))
					break;
				cp++;
				new_val = 0;
				while (*cp && vstrchr("rwxugoXs", *cp))
					switch (*cp++) {
					case 'r': new_val |= 04; break;
					case 'w': new_val |= 02; break;
					case 'x': new_val |= 01; break;
					case 'u':
						new_val |= old_umask >> 6;
						break;
					case 'g':
						new_val |= old_umask >> 3;
						break;
					case 'o':
						new_val |= old_umask >> 0;
						break;
					case 'X':
						if (old_umask & 0111)
							new_val |= 01;
						break;
					case 's':
						/* ignored */
						break;
					}
				new_val = (new_val & 07) * positions;
				switch (op) {
				case '-':
					new_umask &= ~new_val;
					break;
				case '=':
					new_umask = new_val |
					    (new_umask & ~(positions * 07));
					break;
				case '+':
					new_umask |= new_val;
				}
				if (*cp == ',') {
					positions = 0;
					cp++;
				} else if (!ctype(*cp, C_EQUAL | C_MINUS | C_PLUS))
					break;
			}
			if (*cp) {
				bi_errorf("bad mask");
				return (1);
			}
			new_umask = ~new_umask;
		}
		umask(new_umask);
	}
	return (0);
}

int
c_dot(const char **wp)
{
	const char *file, *cp, **argv;
	int argc, rv, errcode;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);

	if ((cp = wp[builtin_opt.optind]) == NULL) {
		bi_errorf(Tno_args);
		return (1);
	}
	file = search_path(cp, path, R_OK, &errcode);
	if (!file && errcode == ENOENT && wp[0][0] == 's' &&
	    search_access(cp, R_OK) == 0)
		file = cp;
	if (!file) {
		bi_errorf(Tf_sD_s, cp, cstrerror(errcode));
		return (1);
	}

	/* Set positional parameters? */
	if (wp[builtin_opt.optind + 1]) {
		argv = wp + builtin_opt.optind;
		/* preserve $0 */
		argv[0] = e->loc->argv[0];
		for (argc = 0; argv[argc + 1]; argc++)
			;
	} else {
		argc = 0;
		argv = NULL;
	}
	/* SUSv4: OR with a high value never written otherwise */
	exstat |= 0x4000;
	if ((rv = include(file, argc, argv, false)) < 0) {
		/* should not happen */
		bi_errorf(Tf_sD_s, cp, cstrerror(errno));
		return (1);
	}
	if (exstat & 0x4000)
		/* detect old exstat, use 0 in that case */
		rv = 0;
	return (rv);
}

int
c_wait(const char **wp)
{
	int rv = 0, sig;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	wp += builtin_opt.optind;
	if (*wp == NULL) {
		while (waitfor(NULL, &sig) >= 0)
			;
		rv = sig;
	} else {
		for (; *wp; wp++)
			rv = waitfor(*wp, &sig);
		if (rv < 0)
			/* magic exit code: bad job-id */
			rv = sig ? sig : 127;
	}
	return (rv);
}

int
c_read(const char **wp)
{
#define is_ifsws(c) (ctype((c), C_IFS) && ctype((c), C_IFSWS))
	int c, fd = 0, rv = 0;
	bool savehist = false, intoarray = false, aschars = false;
	bool rawmode = false, expanding = false;
	bool lastparmmode = false, lastparmused = false;
	enum { LINES, BYTES, UPTO, READALL } readmode = LINES;
	char delim = '\n';
	size_t bytesleft = 128, bytesread;
	struct tbl *vp /* FU gcc */ = NULL, *vq = NULL;
	char *cp, *allocd = NULL, *xp;
	const char *ccp;
	XString xs;
	size_t xsave = 0;
	mksh_ttyst tios;
	bool restore_tios = false;
	/* to catch read -aN2 foo[i] */
	bool subarray = false;
#if HAVE_SELECT
	bool hastimeout = false;
	struct timeval tv, tvlim;
#define c_read_opts "Aad:N:n:prst:u,"
#else
#define c_read_opts "Aad:N:n:prsu,"
#endif
#if defined(__OS2__) && defined(MKSH_WITH_TEXTMODE)
	int saved_mode;
	int saved_errno;
#endif

	while ((c = ksh_getopt(wp, &builtin_opt, c_read_opts)) != -1)
	switch (c) {
	case 'a':
		aschars = true;
		/* FALLTHROUGH */
	case 'A':
		intoarray = true;
		break;
	case 'd':
		delim = builtin_opt.optarg[0];
		break;
	case 'N':
	case 'n':
		readmode = c == 'N' ? BYTES : UPTO;
		if (!bi_getn(builtin_opt.optarg, &c))
			return (2);
		if (c == -1) {
			readmode = readmode == BYTES ? READALL : UPTO;
			bytesleft = 1024;
		} else
			bytesleft = (unsigned int)c;
		break;
	case 'p':
		if ((fd = coproc_getfd(R_OK, &ccp)) < 0) {
			bi_errorf(Tf_coproc, ccp);
			return (2);
		}
		break;
	case 'r':
		rawmode = true;
		break;
	case 's':
		savehist = true;
		break;
#if HAVE_SELECT
	case 't':
		if (parse_usec(builtin_opt.optarg, &tv)) {
			bi_errorf(Tf_sD_s_qs, Tsynerr, cstrerror(errno),
			    builtin_opt.optarg);
			return (2);
		}
		hastimeout = true;
		break;
#endif
	case 'u':
		if (!builtin_opt.optarg[0])
			fd = 0;
		else if ((fd = check_fd(builtin_opt.optarg, R_OK, &ccp)) < 0) {
			bi_errorf(Tf_sD_sD_s, Tdu, builtin_opt.optarg, ccp);
			return (2);
		}
		break;
	case '?':
		return (2);
	}
	wp += builtin_opt.optind;
	if (*wp == NULL)
		*--wp = TREPLY;

	if (intoarray && wp[1] != NULL) {
		bi_errorf(Ttoo_many_args);
		return (2);
	}

	if ((ccp = cstrchr(*wp, '?')) != NULL) {
		strdupx(allocd, *wp, ATEMP);
		allocd[ccp - *wp] = '\0';
		*wp = allocd;
		if (isatty(fd)) {
			/*
			 * AT&T ksh says it prints prompt on fd if it's open
			 * for writing and is a tty, but it doesn't do it
			 * (it also doesn't check the interactive flag,
			 * as is indicated in the Korn Shell book).
			 */
			shf_puts(ccp + 1, shl_out);
			shf_flush(shl_out);
		}
	}

	Xinit(xs, xp, bytesleft, ATEMP);

	if (readmode == LINES)
		bytesleft = 1;
	else if (isatty(fd)) {
		x_mkraw(fd, &tios, true);
		restore_tios = true;
	}

#if HAVE_SELECT
	if (hastimeout) {
		mksh_TIME(tvlim);
		timeradd(&tvlim, &tv, &tvlim);
	}
#endif

 c_read_readloop:
#if HAVE_SELECT
	if (hastimeout) {
		fd_set fdset;

		FD_ZERO(&fdset);
		FD_SET((unsigned int)fd, &fdset);
		mksh_TIME(tv);
		timersub(&tvlim, &tv, &tv);
		if (tv.tv_sec < 0) {
			/* timeout expired globally */
			rv = 3;
			goto c_read_out;
		}

		switch (select(fd + 1, &fdset, NULL, NULL, &tv)) {
		case 1:
			break;
		case 0:
			/* timeout expired for this call */
			bytesread = 0;
			rv = 3;
			goto c_read_readdone;
		default:
			bi_errorf(Tf_sD_s, Tselect, cstrerror(errno));
			rv = 2;
			goto c_read_out;
		}
	}
#endif

#if defined(__OS2__) && defined(MKSH_WITH_TEXTMODE)
	saved_mode = setmode(fd, O_TEXT);
#endif
	if ((bytesread = blocking_read(fd, xp, bytesleft)) == (size_t)-1) {
#if defined(__OS2__) && defined(MKSH_WITH_TEXTMODE)
		saved_errno = errno;
		setmode(fd, saved_mode);
		errno = saved_errno;
#endif
		if (errno == EINTR) {
			/* check whether the signal would normally kill */
			if (!fatal_trap_check()) {
				/* no, just ignore the signal */
				goto c_read_readloop;
			}
			/* pretend the read was killed */
		} else {
			/* unexpected error */
			bi_errorf(Tf_s, cstrerror(errno));
		}
		rv = 2;
		goto c_read_out;
	}
#if defined(__OS2__) && defined(MKSH_WITH_TEXTMODE)
	setmode(fd, saved_mode);
#endif

	switch (readmode) {
	case READALL:
		if (bytesread == 0) {
			/* end of file reached */
			rv = 1;
			goto c_read_readdone;
		}
		xp += bytesread;
		XcheckN(xs, xp, bytesleft);
		break;

	case UPTO:
		if (bytesread == 0)
			/* end of file reached */
			rv = 1;
		xp += bytesread;
		goto c_read_readdone;

	case BYTES:
		if (bytesread == 0) {
			/* end of file reached */
			rv = 1;
			/* may be partial read: $? = 1, but content */
			goto c_read_readdone;
		}
		xp += bytesread;
		if ((bytesleft -= bytesread) == 0)
			goto c_read_readdone;
		break;
	case LINES:
		if (bytesread == 0) {
			/* end of file reached */
			rv = 1;
			goto c_read_readdone;
		}
		if ((c = *xp) == '\0' && !aschars && delim != '\0') {
			/* skip any read NULs unless delimiter */
			break;
		}
		if (expanding) {
			expanding = false;
			if (c == delim) {
				if (Flag(FTALKING_I) && isatty(fd)) {
					/*
					 * set prompt in case this is
					 * called from .profile or $ENV
					 */
					set_prompt(PS2, NULL);
					pprompt(prompt, 0);
				}
				/* drop the backslash */
				--xp;
				/* and the delimiter */
				break;
			}
		} else if (c == delim) {
			goto c_read_readdone;
		} else if (!rawmode && c == '\\') {
			expanding = true;
		}
		Xcheck(xs, xp);
		++xp;
		break;
	}
	goto c_read_readloop;

 c_read_readdone:
	bytesread = Xlength(xs, xp);
	Xput(xs, xp, '\0');

	/*-
	 * state: we finished reading the input and NUL terminated it
	 * Xstring(xs, xp) -> xp-1 = input string without trailing delim
	 * rv = 3 if timeout, 1 if EOF, 0 otherwise (errors handled already)
	 */

	if (rv) {
		/* clean up coprocess if needed, on EOF/error/timeout */
		coproc_read_close(fd);
		if (readmode == READALL && (rv == 1 || (rv == 3 && bytesread)))
			/* EOF is no error here */
			rv = 0;
	}

	if (savehist)
		histsave(&source->line, Xstring(xs, xp), HIST_STORE, false);

	ccp = cp = Xclose(xs, xp);
	expanding = false;
	XinitN(xs, 128, ATEMP);
	if (intoarray) {
		vp = global(*wp);
		subarray = last_lookup_was_array;
		if (vp->flag & RDONLY) {
 c_read_splitro:
			bi_errorf(Tf_ro, *wp);
 c_read_spliterr:
			rv = 2;
			afree(cp, ATEMP);
			goto c_read_out;
		}
		/* counter for array index */
		c = subarray ? arrayindex(vp) : 0;
		/* exporting an array is currently pointless */
		unset(vp, subarray ? 0 : 1);
	}
	if (!aschars) {
		/* skip initial IFS whitespace */
		while (bytesread && is_ifsws(*ccp)) {
			++ccp;
			--bytesread;
		}
		/* trim trailing IFS whitespace */
		while (bytesread && is_ifsws(ccp[bytesread - 1])) {
			--bytesread;
		}
	}
 c_read_splitloop:
	xp = Xstring(xs, xp);
	/* generate next word */
	if (!bytesread) {
		/* no more input */
		if (intoarray)
			goto c_read_splitdone;
		/* zero out next parameters */
		goto c_read_gotword;
	}
	if (aschars) {
		Xput(xs, xp, '1');
		Xput(xs, xp, '#');
		bytesleft = utf_ptradj(ccp);
		while (bytesleft && bytesread) {
			*xp++ = *ccp++;
			--bytesleft;
			--bytesread;
		}
		if (xp[-1] == '\0') {
			xp[-1] = '0';
			xp[-3] = '2';
		}
		goto c_read_gotword;
	}

	if (!intoarray && wp[1] == NULL)
		lastparmmode = true;

 c_read_splitlast:
	/* copy until IFS character */
	while (bytesread) {
		char ch;

		ch = *ccp;
		if (expanding) {
			expanding = false;
			goto c_read_splitcopy;
		} else if (ctype(ch, C_IFS)) {
			break;
		} else if (!rawmode && ch == '\\') {
			expanding = true;
		} else {
 c_read_splitcopy:
			Xcheck(xs, xp);
			Xput(xs, xp, ch);
		}
		++ccp;
		--bytesread;
	}
	xsave = Xsavepos(xs, xp);
	/* copy word delimiter: IFSWS+IFS,IFSWS */
	expanding = false;
	while (bytesread) {
		char ch;

		ch = *ccp;
		if (!ctype(ch, C_IFS))
			break;
		if (lastparmmode && !expanding && !rawmode && ch == '\\') {
			expanding = true;
		} else {
			Xcheck(xs, xp);
			Xput(xs, xp, ch);
		}
		++ccp;
		--bytesread;
		if (expanding)
			continue;
		if (!ctype(ch, C_IFSWS))
			break;
	}
	while (bytesread && is_ifsws(*ccp)) {
		Xcheck(xs, xp);
		Xput(xs, xp, *ccp);
		++ccp;
		--bytesread;
	}
	/* if no more parameters, rinse and repeat */
	if (lastparmmode && bytesread) {
		lastparmused = true;
		goto c_read_splitlast;
	}
	/* get rid of the delimiter unless we pack the rest */
	if (!lastparmused)
		xp = Xrestpos(xs, xp, xsave);
 c_read_gotword:
	Xput(xs, xp, '\0');
	if (intoarray) {
		if (subarray) {
			/* array element passed, accept first read */
			if (vq) {
				bi_errorf("nested arrays not yet supported");
				goto c_read_spliterr;
			}
			vq = vp;
			if (c)
				/* [0] doesn't */
				vq->flag |= AINDEX;
		} else
			vq = arraysearch(vp, c++);
	} else {
		vq = global(*wp);
		/* must be checked before exporting */
		if (vq->flag & RDONLY)
			goto c_read_splitro;
		if (Flag(FEXPORT))
			typeset(*wp, EXPORT, 0, 0, 0);
	}
	if (!setstr(vq, Xstring(xs, xp), KSH_RETURN_ERROR))
		goto c_read_spliterr;
	if (aschars) {
		setint_v(vq, vq, false);
		/* protect from UTFMODE changes */
		vq->type = 0;
	}
	if (intoarray || *++wp != NULL)
		goto c_read_splitloop;

 c_read_splitdone:
	/* free up */
	afree(cp, ATEMP);

 c_read_out:
	afree(allocd, ATEMP);
	Xfree(xs, xp);
	if (restore_tios)
		mksh_tcset(fd, &tios);
	return (rv == 3 ? ksh_sigmask(SIGALRM) : rv);
#undef is_ifsws
}

int
c_eval(const char **wp)
{
	struct source *s, *saves = source;
	int rv;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	s = pushs(SWORDS, ATEMP);
	s->u.strv = wp + builtin_opt.optind;
	s->line = current_lineno;

	/*-
	 * The following code handles the case where the command is
	 * empty due to failed command substitution, for example by
	 *	eval "$(false)"
	 * This has historically returned 1 by AT&T ksh88. In this
	 * case, shell() will not set or change exstat because the
	 * compiled tree is empty, so it will use the value we pass
	 * from subst_exstat, which is cleared in execute(), so it
	 * should have been 0 if there were no substitutions.
	 *
	 * POSIX however says we don't do this, even though it is
	 * traditionally done. AT&T ksh93 agrees with POSIX, so we
	 * do. The following is an excerpt from SUSv4 [1003.2-2008]:
	 *
	 * 2.9.1: Simple Commands
	 *	... If there is a command name, execution shall
	 *	continue as described in 2.9.1.1 [Command Search
	 *	and Execution]. If there is no command name, but
	 *	the command contained a command substitution, the
	 *	command shall complete with the exit status of the
	 *	last command substitution performed.
	 * 2.9.1.1: Command Search and Execution
	 *	(1) a. If the command name matches the name of a
	 *	special built-in utility, that special built-in
	 *	utility shall be invoked.
	 * 2.14.5: eval
	 *	If there are no arguments, or only null arguments,
	 *	eval shall return a zero exit status; ...
	 */
	/* AT&T ksh88: use subst_exstat */
	/* exstat = subst_exstat; */
	/* SUSv4: OR with a high value never written otherwise */
	exstat |= 0x4000;

	rv = shell(s, 2);
	source = saves;
	afree(s, ATEMP);
	if (exstat & 0x4000)
		/* detect old exstat, use 0 in that case */
		rv = 0;
	return (rv);
}

int
c_trap(const char **wp)
{
	Trap *p = sigtraps;
	int i = ksh_NSIG;
	const char *s;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		return (1);
	wp += builtin_opt.optind;

	if (*wp == NULL) {
		do {
			if (p->trap) {
				shf_puts("trap -- ", shl_stdout);
				print_value_quoted(shl_stdout, p->trap);
				shprintf(Tf__sN, p->name);
			}
			++p;
		} while (i--);
		return (0);
	}

	if (getn(*wp, &i)) {
		/* first argument is a signal number, reset them all */
		s = NULL;
	} else {
		/* first argument must be a command, then */
		s = *wp++;
		/* reset traps? */
		if (ksh_isdash(s))
			s = NULL;
	}

	/* set/clear the traps */
	i = 0;
	while (*wp)
		if (!(p = gettrap(*wp++, true, true))) {
			warningf(true, Tbad_sig_ss, builtin_argv0, wp[-1]);
			i = 1;
		} else
			settrap(p, s);
	return (i);
}

int
c_exitreturn(const char **wp)
{
	int n, how = LEXIT;

	if (wp[1]) {
		if (wp[2])
			goto c_exitreturn_err;
		exstat = bi_getn(wp[1], &n) ? (n & 0xFF) : 1;
	} else if (trap_exstat != -1)
		exstat = trap_exstat;

	if (wp[0][0] == 'r') {
		/* return */
		struct env *ep;

		/*
		 * need to tell if this is exit or return so trap exit will
		 * work right (POSIX)
		 */
		for (ep = e; ep; ep = ep->oenv)
			if (STOP_RETURN(ep->type)) {
				how = LRETURN;
				break;
			}
	}

	if (how == LEXIT && !really_exit && j_stopped_running()) {
		really_exit = true;
		how = LSHELL;
	}

	/* get rid of any I/O redirections */
	quitenv(NULL);
	unwind(how);
	/* NOTREACHED */

 c_exitreturn_err:
	bi_errorf(Ttoo_many_args);
	return (1);
}

int
c_brkcont(const char **wp)
{
	unsigned int quit;
	int n;
	struct env *ep, *last_ep = NULL;
	const char *arg;

	if (ksh_getopt(wp, &builtin_opt, null) == '?')
		goto c_brkcont_err;
	arg = wp[builtin_opt.optind];

	if (!arg)
		n = 1;
	else if (!bi_getn(arg, &n))
		goto c_brkcont_err;
	if (n <= 0) {
		/* AT&T ksh does this for non-interactive shells only - weird */
		bi_errorf("%s: bad value", arg);
		goto c_brkcont_err;
	}
	quit = (unsigned int)n;

	/* Stop at E_NONE, E_PARSE, E_FUNC, or E_INCL */
	for (ep = e; ep && !STOP_BRKCONT(ep->type); ep = ep->oenv)
		if (ep->type == E_LOOP) {
			if (--quit == 0)
				break;
			ep->flags |= EF_BRKCONT_PASS;
			last_ep = ep;
		}

	if (quit) {
		/*
		 * AT&T ksh doesn't print a message - just does what it
		 * can. We print a message 'cause it helps in debugging
		 * scripts, but don't generate an error (ie, keep going).
		 */
		if ((unsigned int)n == quit) {
			warningf(true, Tf_cant_s, wp[0], wp[0]);
			return (0);
		}
		/*
		 * POSIX says if n is too big, the last enclosing loop
		 * shall be used. Doesn't say to print an error but we
		 * do anyway 'cause the user messed up.
		 */
		if (last_ep)
			last_ep->flags &= ~EF_BRKCONT_PASS;
		warningf(true, "%s: can only %s %u level(s)",
		    wp[0], wp[0], (unsigned int)n - quit);
	}

	unwind(*wp[0] == 'b' ? LBREAK : LCONTIN);
	/* NOTREACHED */

 c_brkcont_err:
	return (1);
}

int
c_set(const char **wp)
{
	int argi;
	bool setargs;
	struct block *l = e->loc;

	if ((l->flags & BF_RESETSPEC)) {
		/* prevent pollution */
		l->flags &= ~BF_RESETSPEC;
		/* operate on parent environment */
		l = l->next;
	}

	if (wp[1] == NULL) {
		static const char *args[] = { Tset, "-", NULL };
		return (c_typeset(args));
	}

	if ((argi = parse_args(wp, OF_SET, &setargs)) < 0)
		return (2);
	/* set $# and $* */
	if (setargs) {
		const char **owp;

		wp += argi - 1;
		owp = wp;
		/* save $0 */
		wp[0] = l->argv[0];
		while (*++wp != NULL)
			strdupx(*wp, *wp, &l->area);
		l->argc = wp - owp - 1;
		l->argv = alloc2(l->argc + 2, sizeof(char *), &l->area);
		for (wp = l->argv; (*wp++ = *owp++) != NULL; )
			;
	}
	/*-
	 * POSIX says set exit status is 0, but old scripts that use
	 * getopt(1) use the construct
	 *	set -- $(getopt ab:c "$@")
	 * which assumes the exit value set will be that of the $()
	 * (subst_exstat is cleared in execute() so that it will be 0
	 * if there are no command substitutions).
	 */
#ifdef MKSH_LEGACY_MODE
	/* traditional behaviour, unless set -o posix */
	return (Flag(FPOSIX) ? 0 : subst_exstat);
#else
	/* conformant behaviour, unless set -o sh +o posix */
	return (Flag(FSH) && !Flag(FPOSIX) ? subst_exstat : 0);
#endif
}

int
c_unset(const char **wp)
{
	const char *id;
	int optc, rv = 0;
	bool unset_var = true;

	while ((optc = ksh_getopt(wp, &builtin_opt, "fv")) != -1)
		switch (optc) {
		case 'f':
			unset_var = false;
			break;
		case 'v':
			unset_var = true;
			break;
		case '?':
			/*XXX not reached due to GF_ERROR */
			return (2);
		}
	wp += builtin_opt.optind;
	for (; (id = *wp) != NULL; wp++)
		if (unset_var) {
			/* unset variable */
			struct tbl *vp;
			char *cp = NULL;
			size_t n;

			n = strlen(id);
			if (n > 3 && ord(id[n - 3]) == ORD('[') &&
			    ord(id[n - 2]) == ORD('*') &&
			    ord(id[n - 1]) == ORD(']')) {
				strndupx(cp, id, n - 3, ATEMP);
				id = cp;
				optc = 3;
			} else
				optc = vstrchr(id, '[') ? 0 : 1;

			vp = global(id);
			afree(cp, ATEMP);

			if ((vp->flag&RDONLY)) {
				warningf(true, Tf_ro, vp->name);
				rv = 1;
			} else
				unset(vp, optc);
		} else
			/* unset function */
			define(id, NULL);
	return (rv);
}

static void
p_time(struct shf *shf, bool posix, long tv_sec, int tv_usec, int width,
    const char *prefix, const char *suffix)
{
	tv_usec /= 10000;
	if (posix)
		shf_fprintf(shf, "%s%*ld.%02d%s", prefix, width,
		    tv_sec, tv_usec, suffix);
	else
		shf_fprintf(shf, "%s%*ldm%02d.%02ds%s", prefix, width,
		    tv_sec / 60, (int)(tv_sec % 60), tv_usec, suffix);
}

int
c_times(const char **wp MKSH_A_UNUSED)
{
	struct rusage usage;

	getrusage(RUSAGE_SELF, &usage);
	p_time(shl_stdout, false, usage.ru_utime.tv_sec,
	    usage.ru_utime.tv_usec, 0, null, T1space);
	p_time(shl_stdout, false, usage.ru_stime.tv_sec,
	    usage.ru_stime.tv_usec, 0, null, "\n");

	getrusage(RUSAGE_CHILDREN, &usage);
	p_time(shl_stdout, false, usage.ru_utime.tv_sec,
	    usage.ru_utime.tv_usec, 0, null, T1space);
	p_time(shl_stdout, false, usage.ru_stime.tv_sec,
	    usage.ru_stime.tv_usec, 0, null, "\n");

	return (0);
}

/*
 * time pipeline (really a statement, not a built-in command)
 */
int
timex(struct op *t, int f, volatile int *xerrok)
{
#define TF_NOARGS	BIT(0)
#define TF_NOREAL	BIT(1)		/* don't report real time */
#define TF_POSIX	BIT(2)		/* report in POSIX format */
	int rv = 0, tf = 0;
	struct rusage ru0, ru1, cru0, cru1;
	struct timeval usrtime, systime, tv0, tv1;

	mksh_TIME(tv0);
	getrusage(RUSAGE_SELF, &ru0);
	getrusage(RUSAGE_CHILDREN, &cru0);
	if (t->left) {
		/*
		 * Two ways of getting cpu usage of a command: just use t0
		 * and t1 (which will get cpu usage from other jobs that
		 * finish while we are executing t->left), or get the
		 * cpu usage of t->left. AT&T ksh does the former, while
		 * pdksh tries to do the later (the j_usrtime hack doesn't
		 * really work as it only counts the last job).
		 */
		timerclear(&j_usrtime);
		timerclear(&j_systime);
		rv = execute(t->left, f | XTIME, xerrok);
		if (t->left->type == TCOM)
			tf |= t->left->str[0];
		mksh_TIME(tv1);
		getrusage(RUSAGE_SELF, &ru1);
		getrusage(RUSAGE_CHILDREN, &cru1);
	} else
		tf = TF_NOARGS;

	if (tf & TF_NOARGS) {
		/* ksh93 - report shell times (shell+kids) */
		tf |= TF_NOREAL;
		timeradd(&ru0.ru_utime, &cru0.ru_utime, &usrtime);
		timeradd(&ru0.ru_stime, &cru0.ru_stime, &systime);
	} else {
		timersub(&ru1.ru_utime, &ru0.ru_utime, &usrtime);
		timeradd(&usrtime, &j_usrtime, &usrtime);
		timersub(&ru1.ru_stime, &ru0.ru_stime, &systime);
		timeradd(&systime, &j_systime, &systime);
	}

	if (!(tf & TF_NOREAL)) {
		timersub(&tv1, &tv0, &tv1);
		if (tf & TF_POSIX)
			p_time(shl_out, true, tv1.tv_sec, tv1.tv_usec,
			    5, Treal_sp1, "\n");
		else
			p_time(shl_out, false, tv1.tv_sec, tv1.tv_usec,
			    5, null, Treal_sp2);
	}
	if (tf & TF_POSIX)
		p_time(shl_out, true, usrtime.tv_sec, usrtime.tv_usec,
		    5, Tuser_sp1, "\n");
	else
		p_time(shl_out, false, usrtime.tv_sec, usrtime.tv_usec,
		    5, null, Tuser_sp2);
	if (tf & TF_POSIX)
		p_time(shl_out, true, systime.tv_sec, systime.tv_usec,
		    5, "sys  ", "\n");
	else
		p_time(shl_out, false, systime.tv_sec, systime.tv_usec,
		    5, null, " system\n");
	shf_flush(shl_out);

	return (rv);
}

void
timex_hook(struct op *t, char **volatile *app)
{
	char **wp = *app;
	int optc, i, j;
	Getopt opt;

	ksh_getopt_reset(&opt, 0);
	/* start at the start */
	opt.optind = 0;
	while ((optc = ksh_getopt((const char **)wp, &opt, ":p")) != -1)
		switch (optc) {
		case 'p':
			t->str[0] |= TF_POSIX;
			break;
		case '?':
			errorf(Tf_optfoo, Ttime, Tcolsp,
			    opt.optarg[0], Tunknown_option);
		case ':':
			errorf(Tf_optfoo, Ttime, Tcolsp,
			    opt.optarg[0], Treq_arg);
		}
	/* Copy command words down over options. */
	if (opt.optind != 0) {
		for (i = 0; i < opt.optind; i++)
			afree(wp[i], ATEMP);
		for (i = 0, j = opt.optind; (wp[i] = wp[j]); i++, j++)
			;
	}
	if (!wp[0])
		t->str[0] |= TF_NOARGS;
	*app = wp;
}

/* exec with no args - args case is taken care of in comexec() */
int
c_exec(const char **wp MKSH_A_UNUSED)
{
	int i;

	/* make sure redirects stay in place */
	if (e->savefd != NULL) {
		for (i = 0; i < NUFILE; i++) {
			if (e->savefd[i] > 0)
				close(e->savefd[i]);
			/*
			 * keep all file descriptors > 2 private for ksh,
			 * but not for POSIX or legacy/kludge sh
			 */
			if (!Flag(FPOSIX) && !Flag(FSH) && i > 2 &&
			    e->savefd[i])
				fcntl(i, F_SETFD, FD_CLOEXEC);
		}
		e->savefd = NULL;
	}
	return (0);
}

#if HAVE_MKNOD && !defined(__OS2__)
int
c_mknod(const char **wp)
{
	int argc, optc, rv = 0;
	bool ismkfifo = false;
	const char **argv;
	void *set = NULL;
	mode_t mode = 0, oldmode = 0;

	while ((optc = ksh_getopt(wp, &builtin_opt, "m:")) != -1) {
		switch (optc) {
		case 'm':
			set = setmode(builtin_opt.optarg);
			if (set == NULL) {
				bi_errorf("invalid file mode");
				return (1);
			}
			mode = getmode(set, (mode_t)(DEFFILEMODE));
			free_ossetmode(set);
			break;
		default:
			goto c_mknod_usage;
		}
	}
	argv = &wp[builtin_opt.optind];
	if (argv[0] == NULL)
		goto c_mknod_usage;
	for (argc = 0; argv[argc]; argc++)
		;
	if (argc == 2 && argv[1][0] == 'p')
		ismkfifo = true;
	else if (argc != 4 || (argv[1][0] != 'b' && argv[1][0] != 'c'))
		goto c_mknod_usage;

	if (set != NULL)
		oldmode = umask((mode_t)0);
	else
		mode = DEFFILEMODE;

	mode |= (argv[1][0] == 'b') ? S_IFBLK :
	    (argv[1][0] == 'c') ? S_IFCHR : 0;

	if (!ismkfifo) {
		unsigned long majnum, minnum;
		dev_t dv;
		char *c;

		majnum = strtoul(argv[2], &c, 0);
		if ((c == argv[2]) || (*c != '\0')) {
			bi_errorf(Tf_nonnum, "device", "major", argv[2]);
			goto c_mknod_err;
		}
		minnum = strtoul(argv[3], &c, 0);
		if ((c == argv[3]) || (*c != '\0')) {
			bi_errorf(Tf_nonnum, "device", "minor", argv[3]);
			goto c_mknod_err;
		}
		dv = makedev(majnum, minnum);
		if ((unsigned long)(major(dv)) != majnum) {
			bi_errorf(Tf_toolarge, "device", "major", majnum);
			goto c_mknod_err;
		}
		if ((unsigned long)(minor(dv)) != minnum) {
			bi_errorf(Tf_toolarge, "device", "minor", minnum);
			goto c_mknod_err;
		}
		if (mknod(argv[0], mode, dv))
			goto c_mknod_failed;
	} else if (mkfifo(argv[0], mode)) {
 c_mknod_failed:
		bi_errorf(Tf_sD_s, argv[0], cstrerror(errno));
 c_mknod_err:
		rv = 1;
	}

	if (set)
		umask(oldmode);
	return (rv);
 c_mknod_usage:
	bi_errorf("usage: mknod [-m mode] name %s", "b|c major minor");
	bi_errorf("usage: mknod [-m mode] name %s", "p");
	return (1);
}
#endif

/*-
 * test(1) roughly accepts the following grammar:
 *	oexpr	::= aexpr | aexpr "-o" oexpr ;
 *	aexpr	::= nexpr | nexpr "-a" aexpr ;
 *	nexpr	::= primary | "!" nexpr ;
 *	primary	::= unary-operator operand
 *		| operand binary-operator operand
 *		| operand
 *		| "(" oexpr ")"
 *		;
 *
 *	unary-operator ::= "-a"|"-b"|"-c"|"-d"|"-e"|"-f"|"-G"|"-g"|"-H"|"-h"|
 *			   "-k"|"-L"|"-n"|"-O"|"-o"|"-p"|"-r"|"-S"|"-s"|"-t"|
 *			   "-u"|"-v"|"-w"|"-x"|"-z";
 *
 *	binary-operator ::= "="|"=="|"!="|"<"|">"|"-eq"|"-ne"|"-gt"|"-ge"|
 *			    "-lt"|"-le"|"-ef"|"-nt"|"-ot";
 *
 *	operand ::= <anything>
 */

/* POSIX says > 1 for errors */
#define T_ERR_EXIT 2

int
c_test(const char **wp)
{
	int argc, rv, invert = 0;
	Test_env te;
	Test_op op;
	Test_meta tm;
	const char *lhs, **swp;

	te.flags = 0;
	te.isa = ptest_isa;
	te.getopnd = ptest_getopnd;
	te.eval = test_eval;
	te.error = ptest_error;

	for (argc = 0; wp[argc]; argc++)
		;

	if (strcmp(wp[0], Tbracket) == 0) {
		if (strcmp(wp[--argc], "]") != 0) {
			bi_errorf("missing ]");
			return (T_ERR_EXIT);
		}
	}

	te.pos.wp = wp + 1;
	te.wp_end = wp + argc;

	/*
	 * Attempt to conform to POSIX special cases. This is pretty
	 * dumb code straight-forward from the 2008 spec, but unlike
	 * the old pdksh code doesn't live from so many assumptions.
	 * It does, though, inline some calls to '(*te.funcname)()'.
	 */
	switch (argc - 1) {
	case 0:
		return (1);
	case 1:
 ptest_one:
		op = TO_STNZE;
		goto ptest_unary;
	case 2:
 ptest_two:
		if (ptest_isa(&te, TM_NOT)) {
			++invert;
			goto ptest_one;
		}
		if ((op = ptest_isa(&te, TM_UNOP))) {
 ptest_unary:
			rv = test_eval(&te, op, *te.pos.wp++, NULL, true);
 ptest_out:
			if (te.flags & TEF_ERROR)
				return (T_ERR_EXIT);
			return ((invert & 1) ? rv : !rv);
		}
		/* let the parser deal with anything else */
		break;
	case 3:
 ptest_three:
		swp = te.pos.wp;
		/* use inside knowledge of ptest_getopnd inlined below */
		lhs = *te.pos.wp++;
		if ((op = ptest_isa(&te, TM_BINOP))) {
			/* test lhs op rhs */
			rv = test_eval(&te, op, lhs, *te.pos.wp++, true);
			goto ptest_out;
		}
		if (ptest_isa(&te, tm = TM_AND) || ptest_isa(&te, tm = TM_OR)) {
			/* XSI */
			argc = test_eval(&te, TO_STNZE, lhs, NULL, true);
			rv = test_eval(&te, TO_STNZE, *te.pos.wp++, NULL, true);
			if (tm == TM_AND)
				rv = argc && rv;
			else
				rv = argc || rv;
			goto ptest_out;
		}
		/* back up to lhs */
		te.pos.wp = swp;
		if (ptest_isa(&te, TM_NOT)) {
			++invert;
			goto ptest_two;
		}
		if (ptest_isa(&te, TM_OPAREN)) {
			swp = te.pos.wp;
			/* skip operand, without evaluation */
			te.pos.wp++;
			/* check for closing parenthesis */
			op = ptest_isa(&te, TM_CPAREN);
			/* back up to operand */
			te.pos.wp = swp;
			/* if there was a closing paren, handle it */
			if (op)
				goto ptest_one;
			/* backing up is done before calling the parser */
		}
		/* let the parser deal with it */
		break;
	case 4:
		if (ptest_isa(&te, TM_NOT)) {
			++invert;
			goto ptest_three;
		}
		if (ptest_isa(&te, TM_OPAREN)) {
			swp = te.pos.wp;
			/* skip two operands, without evaluation */
			te.pos.wp++;
			te.pos.wp++;
			/* check for closing parenthesis */
			op = ptest_isa(&te, TM_CPAREN);
			/* back up to first operand */
			te.pos.wp = swp;
			/* if there was a closing paren, handle it */
			if (op)
				goto ptest_two;
			/* backing up is done before calling the parser */
		}
		/* defer this to the parser */
		break;
	}

	/* "The results are unspecified." */
	te.pos.wp = wp + 1;
	return (test_parse(&te));
}

/*
 * Generic test routines.
 */

Test_op
test_isop(Test_meta meta, const char *s)
{
	char sc1;
	const struct t_op *tbl;

	tbl = meta == TM_UNOP ? u_ops : b_ops;
	if (*s) {
		sc1 = s[1];
		for (; tbl->op_text[0]; tbl++)
			if (sc1 == tbl->op_text[1] && !strcmp(s, tbl->op_text))
				return (tbl->op_num);
	}
	return (TO_NONOP);
}

#ifdef __OS2__
#define test_access(name,mode)	access_ex(access, (name), (mode))
#define test_stat(name,buffer)	stat_ex(stat, (name), (buffer))
#define test_lstat(name,buffer)	stat_ex(lstat, (name), (buffer))
#else
#define test_access(name,mode)	access((name), (mode))
#define test_stat(name,buffer)	stat((name), (buffer))
#define test_lstat(name,buffer)	lstat((name), (buffer))
#endif

#if HAVE_ST_MTIM
#undef st_mtimensec
#define st_mtimensec st_mtim.tv_nsec
#endif

static int
mtimecmp(const struct stat *sb1, const struct stat *sb2)
{
	if (sb1->st_mtime < sb2->st_mtime)
		return (-1);
	if (sb1->st_mtime > sb2->st_mtime)
		return (1);
#if (HAVE_ST_MTIMENSEC || HAVE_ST_MTIM)
	if (sb1->st_mtimensec < sb2->st_mtimensec)
		return (-1);
	if (sb1->st_mtimensec > sb2->st_mtimensec)
		return (1);
#endif
	return (0);
}

int
test_eval(Test_env *te, Test_op op, const char *opnd1, const char *opnd2,
    bool do_eval)
{
	int i, s;
	size_t k;
	struct stat b1, b2;
	mksh_ari_t v1, v2;
	struct tbl *vp;

	if (!do_eval)
		return (0);

#ifdef DEBUG
	switch (op) {
	/* Binary operators */
	case TO_STEQL:
	case TO_STNEQ:
	case TO_STLT:
	case TO_STGT:
	case TO_INTEQ:
	case TO_INTNE:
	case TO_INTGT:
	case TO_INTGE:
	case TO_INTLT:
	case TO_INTLE:
	case TO_FILEQ:
	case TO_FILNT:
	case TO_FILOT:
		/* consistency check, but does not happen in practice */
		if (!opnd2) {
			te->flags |= TEF_ERROR;
			return (1);
		}
		break;
	default:
		/* for completeness of switch */
		break;
	}
#endif

	switch (op) {

	/*
	 * Unary Operators
	 */

	/* -n */
	case TO_STNZE:
		return (*opnd1 != '\0');

	/* -z */
	case TO_STZER:
		return (*opnd1 == '\0');

	/* -v */
	case TO_ISSET:
		return ((vp = isglobal(opnd1, false)) && (vp->flag & ISSET));

	/* -o */
	case TO_OPTION:
		if ((i = *opnd1) == '!' || i == '?')
			opnd1++;
		if ((k = option(opnd1)) == (size_t)-1)
			return (0);
		return (i == '?' ? 1 : i == '!' ? !Flag(k) : Flag(k));

	/* -r */
	case TO_FILRD:
		/* LINTED use of access */
		return (test_access(opnd1, R_OK) == 0);

	/* -w */
	case TO_FILWR:
		/* LINTED use of access */
		return (test_access(opnd1, W_OK) == 0);

	/* -x */
	case TO_FILEX:
		return (ksh_access(opnd1, X_OK) == 0);

	/* -a */
	case TO_FILAXST:
	/* -e */
	case TO_FILEXST:
		return (test_stat(opnd1, &b1) == 0);

	/* -f */
	case TO_FILREG:
		return (test_stat(opnd1, &b1) == 0 && S_ISREG(b1.st_mode));

	/* -d */
	case TO_FILID:
		return (test_stat(opnd1, &b1) == 0 && S_ISDIR(b1.st_mode));

	/* -c */
	case TO_FILCDEV:
		return (test_stat(opnd1, &b1) == 0 && S_ISCHR(b1.st_mode));

	/* -b */
	case TO_FILBDEV:
		return (test_stat(opnd1, &b1) == 0 && S_ISBLK(b1.st_mode));

	/* -p */
	case TO_FILFIFO:
		return (test_stat(opnd1, &b1) == 0 && S_ISFIFO(b1.st_mode));

	/* -h or -L */
	case TO_FILSYM:
#ifdef MKSH__NO_SYMLINK
		return (0);
#else
		return (test_lstat(opnd1, &b1) == 0 && S_ISLNK(b1.st_mode));
#endif

	/* -S */
	case TO_FILSOCK:
		return (test_stat(opnd1, &b1) == 0 && S_ISSOCK(b1.st_mode));

	/* -H => HP context dependent files (directories) */
	case TO_FILCDF:
#ifdef S_ISCDF
	{
		char *nv;

		/*
		 * Append a + to filename and check to see if result is
		 * a setuid directory. CDF stuff in general is hookey,
		 * since it breaks for, e.g., the following sequence:
		 * echo hi >foo+; mkdir foo; echo bye >foo/default;
		 * chmod u+s foo (foo+ refers to the file with hi in it,
		 * there is no way to get at the file with bye in it;
		 * please correct me if I'm wrong about this).
		 */

		nv = shf_smprintf("%s+", opnd1);
		i = (test_stat(nv, &b1) == 0 && S_ISCDF(b1.st_mode));
		afree(nv, ATEMP);
		return (i);
	}
#else
		return (0);
#endif

	/* -u */
	case TO_FILSETU:
		return (test_stat(opnd1, &b1) == 0 &&
		    (b1.st_mode & S_ISUID) == S_ISUID);

	/* -g */
	case TO_FILSETG:
		return (test_stat(opnd1, &b1) == 0 &&
		    (b1.st_mode & S_ISGID) == S_ISGID);

	/* -k */
	case TO_FILSTCK:
#ifdef S_ISVTX
		return (test_stat(opnd1, &b1) == 0 &&
		    (b1.st_mode & S_ISVTX) == S_ISVTX);
#else
		return (0);
#endif

	/* -s */
	case TO_FILGZ:
		return (test_stat(opnd1, &b1) == 0 &&
		    (off_t)b1.st_size > (off_t)0);

	/* -t */
	case TO_FILTT:
		if (opnd1 && !bi_getn(opnd1, &i)) {
			te->flags |= TEF_ERROR;
			i = 0;
		} else
			i = isatty(opnd1 ? i : 0);
		return (i);

	/* -O */
	case TO_FILUID:
		return (test_stat(opnd1, &b1) == 0 &&
		    (uid_t)b1.st_uid == ksheuid);

	/* -G */
	case TO_FILGID:
		return (test_stat(opnd1, &b1) == 0 &&
		    (gid_t)b1.st_gid == kshegid);

	/*
	 * Binary Operators
	 */

	/* =, == */
	case TO_STEQL:
		if (te->flags & TEF_DBRACKET) {
			if ((i = gmatchx(opnd1, opnd2, false)))
				record_match(opnd1);
			return (i);
		}
		return (strcmp(opnd1, opnd2) == 0);

	/* != */
	case TO_STNEQ:
		if (te->flags & TEF_DBRACKET) {
			if ((i = gmatchx(opnd1, opnd2, false)))
				record_match(opnd1);
			return (!i);
		}
		return (strcmp(opnd1, opnd2) != 0);

	/* < */
	case TO_STLT:
		return (strcmp(opnd1, opnd2) < 0);

	/* > */
	case TO_STGT:
		return (strcmp(opnd1, opnd2) > 0);

	/* -nt */
	case TO_FILNT:
		/*
		 * ksh88/ksh93 succeed if file2 can't be stated
		 * (subtly different from 'does not exist').
		 */
		return (test_stat(opnd1, &b1) == 0 &&
		    (((s = test_stat(opnd2, &b2)) == 0 &&
		    mtimecmp(&b1, &b2) > 0) || s < 0));

	/* -ot */
	case TO_FILOT:
		/*
		 * ksh88/ksh93 succeed if file1 can't be stated
		 * (subtly different from 'does not exist').
		 */
		return (test_stat(opnd2, &b2) == 0 &&
		    (((s = test_stat(opnd1, &b1)) == 0 &&
		    mtimecmp(&b1, &b2) < 0) || s < 0));

	/* -ef */
	case TO_FILEQ:
		return (test_stat(opnd1, &b1) == 0 &&
		    test_stat(opnd2, &b2) == 0 &&
		    b1.st_dev == b2.st_dev && b1.st_ino == b2.st_ino);

	/* all other cases */
	case TO_NONOP:
	case TO_NONNULL:
		/* throw the error */
		break;

	/* -eq */
	case TO_INTEQ:
	/* -ne */
	case TO_INTNE:
	/* -ge */
	case TO_INTGE:
	/* -gt */
	case TO_INTGT:
	/* -le */
	case TO_INTLE:
	/* -lt */
	case TO_INTLT:
		if (!evaluate(opnd1, &v1, KSH_RETURN_ERROR, false) ||
		    !evaluate(opnd2, &v2, KSH_RETURN_ERROR, false)) {
			/* error already printed.. */
			te->flags |= TEF_ERROR;
			return (1);
		}
		switch (op) {
		case TO_INTEQ:
			return (v1 == v2);
		case TO_INTNE:
			return (v1 != v2);
		case TO_INTGE:
			return (v1 >= v2);
		case TO_INTGT:
			return (v1 > v2);
		case TO_INTLE:
			return (v1 <= v2);
		case TO_INTLT:
			return (v1 < v2);
		default:
			/* NOTREACHED */
			break;
		}
		/* NOTREACHED */
	}
	(*te->error)(te, 0, "internal error: unknown op");
	return (1);
}

int
test_parse(Test_env *te)
{
	int rv;

	rv = test_oexpr(te, 1);

	if (!(te->flags & TEF_ERROR) && !(*te->isa)(te, TM_END))
		(*te->error)(te, 0, "unexpected operator/operand");

	return ((te->flags & TEF_ERROR) ? T_ERR_EXIT : !rv);
}

static int
test_oexpr(Test_env *te, bool do_eval)
{
	int rv;

	if ((rv = test_aexpr(te, do_eval)))
		do_eval = false;
	if (!(te->flags & TEF_ERROR) && (*te->isa)(te, TM_OR))
		return (test_oexpr(te, do_eval) || rv);
	return (rv);
}

static int
test_aexpr(Test_env *te, bool do_eval)
{
	int rv;

	if (!(rv = test_nexpr(te, do_eval)))
		do_eval = false;
	if (!(te->flags & TEF_ERROR) && (*te->isa)(te, TM_AND))
		return (test_aexpr(te, do_eval) && rv);
	return (rv);
}

static int
test_nexpr(Test_env *te, bool do_eval)
{
	if (!(te->flags & TEF_ERROR) && (*te->isa)(te, TM_NOT))
		return (!test_nexpr(te, do_eval));
	return (test_primary(te, do_eval));
}

static int
test_primary(Test_env *te, bool do_eval)
{
	const char *opnd1, *opnd2;
	int rv;
	Test_op op;

	if (te->flags & TEF_ERROR)
		return (0);
	if ((*te->isa)(te, TM_OPAREN)) {
		rv = test_oexpr(te, do_eval);
		if (te->flags & TEF_ERROR)
			return (0);
		if (!(*te->isa)(te, TM_CPAREN)) {
			(*te->error)(te, 0, "missing )");
			return (0);
		}
		return (rv);
	}
	/*
	 * Binary should have precedence over unary in this case
	 * so that something like test \( -f = -f \) is accepted
	 */
	if ((te->flags & TEF_DBRACKET) || (&te->pos.wp[1] < te->wp_end &&
	    !test_isop(TM_BINOP, te->pos.wp[1]))) {
		if ((op = (*te->isa)(te, TM_UNOP))) {
			/* unary expression */
			opnd1 = (*te->getopnd)(te, op, do_eval);
			if (!opnd1) {
				(*te->error)(te, -1, Tno_args);
				return (0);
			}

			return ((*te->eval)(te, op, opnd1, NULL, do_eval));
		}
	}
	opnd1 = (*te->getopnd)(te, TO_NONOP, do_eval);
	if (!opnd1) {
		(*te->error)(te, 0, "expression expected");
		return (0);
	}
	if ((op = (*te->isa)(te, TM_BINOP))) {
		/* binary expression */
		opnd2 = (*te->getopnd)(te, op, do_eval);
		if (!opnd2) {
			(*te->error)(te, -1, "missing second argument");
			return (0);
		}

		return ((*te->eval)(te, op, opnd1, opnd2, do_eval));
	}
	return ((*te->eval)(te, TO_STNZE, opnd1, NULL, do_eval));
}

/*
 * Plain test (test and [ .. ]) specific routines.
 */

/*
 * Test if the current token is a whatever. Accepts the current token if
 * it is. Returns 0 if it is not, non-zero if it is (in the case of
 * TM_UNOP and TM_BINOP, the returned value is a Test_op).
 */
static Test_op
ptest_isa(Test_env *te, Test_meta meta)
{
	/* Order important - indexed by Test_meta values */
	static const char * const tokens[] = {
		Tdo, Tda, "!", "(", ")"
	};
	Test_op rv;

	if (te->pos.wp >= te->wp_end)
		return (meta == TM_END ? TO_NONNULL : TO_NONOP);

	if (meta == TM_UNOP || meta == TM_BINOP)
		rv = test_isop(meta, *te->pos.wp);
	else if (meta == TM_END)
		rv = TO_NONOP;
	else
		rv = !strcmp(*te->pos.wp, tokens[(int)meta]) ?
		    TO_NONNULL : TO_NONOP;

	/* Accept the token? */
	if (rv != TO_NONOP)
		te->pos.wp++;

	return (rv);
}

static const char *
ptest_getopnd(Test_env *te, Test_op op, bool do_eval MKSH_A_UNUSED)
{
	if (te->pos.wp >= te->wp_end)
		return (op == TO_FILTT ? "1" : NULL);
	return (*te->pos.wp++);
}

static void
ptest_error(Test_env *te, int ofs, const char *msg)
{
	const char *op;

	te->flags |= TEF_ERROR;
	if ((op = te->pos.wp + ofs >= te->wp_end ? NULL : te->pos.wp[ofs]))
		bi_errorf(Tf_sD_s, op, msg);
	else
		bi_errorf(Tf_s, msg);
}

#ifndef MKSH_NO_LIMITS
#define SOFT	0x1
#define HARD	0x2

/* Magic to divine the 'm' and 'v' limits */

#ifdef RLIMIT_AS
#if !defined(RLIMIT_VMEM) || (RLIMIT_VMEM == RLIMIT_AS) || \
    !defined(RLIMIT_RSS) || (RLIMIT_VMEM == RLIMIT_RSS)
#define ULIMIT_V_IS_AS
#elif defined(RLIMIT_VMEM)
#if !defined(RLIMIT_RSS) || (RLIMIT_RSS == RLIMIT_AS)
#define ULIMIT_V_IS_AS
#else
#define ULIMIT_V_IS_VMEM
#endif
#endif
#endif

#ifdef RLIMIT_RSS
#ifdef ULIMIT_V_IS_VMEM
#define ULIMIT_M_IS_RSS
#elif defined(RLIMIT_VMEM) && (RLIMIT_VMEM == RLIMIT_RSS)
#define ULIMIT_M_IS_VMEM
#else
#define ULIMIT_M_IS_RSS
#endif
#if defined(ULIMIT_M_IS_RSS) && defined(RLIMIT_AS) && (RLIMIT_RSS == RLIMIT_AS) && !defined(__APPLE__)
#undef ULIMIT_M_IS_RSS
#endif
#endif

#if !defined(RLIMIT_AS) && !defined(ULIMIT_M_IS_VMEM) && defined(RLIMIT_VMEM)
#define ULIMIT_V_IS_VMEM
#endif

#if !defined(ULIMIT_V_IS_VMEM) && defined(RLIMIT_VMEM) && \
    (!defined(RLIMIT_RSS) || (defined(RLIMIT_AS) && (RLIMIT_RSS == RLIMIT_AS)))
#define ULIMIT_M_IS_VMEM
#endif

#if defined(ULIMIT_M_IS_VMEM) && defined(RLIMIT_AS) && \
    (RLIMIT_VMEM == RLIMIT_AS)
#undef ULIMIT_M_IS_VMEM
#endif

#if defined(ULIMIT_M_IS_RSS) && defined(ULIMIT_M_IS_VMEM)
# error nonsensical m ulimit
#endif

#if defined(ULIMIT_V_IS_VMEM) && defined(ULIMIT_V_IS_AS)
# error nonsensical v ulimit
#endif

struct limits {
	/* limit resource */
	int resource;
	/* multiply by to get rlim_{cur,max} values */
	unsigned int factor;
	/* getopts char */
	char optchar;
	/* limit name */
	char name[1];
};

#define RLIMITS_DEFNS
#define FN(lname,lid,lfac,lopt)				\
	static const struct {				\
		int resource;				\
		unsigned int factor;			\
		char optchar;				\
		char name[sizeof(lname)];		\
	} rlimits_ ## lid = {				\
		lid, lfac, lopt, lname			\
	};
#include "rlimits.gen"

static void print_ulimit(const struct limits *, int);
static int set_ulimit(const struct limits *, const char *, int);

static const struct limits * const rlimits[] = {
#define RLIMITS_ITEMS
#include "rlimits.gen"
};

static const char rlimits_opts[] =
#define RLIMITS_OPTCS
#include "rlimits.gen"
    ;

int
c_ulimit(const char **wp)
{
	size_t i = 0;
	int how = SOFT | HARD, optc, what = 'f';
	bool all = false;

	while ((optc = ksh_getopt(wp, &builtin_opt, rlimits_opts)) != -1)
		switch (optc) {
		case 'H':
			how = HARD;
			break;
		case 'S':
			how = SOFT;
			break;
		case 'a':
			all = true;
			break;
		case '?':
			bi_errorf("usage: ulimit [-%s] [value]", rlimits_opts);
			return (1);
		default:
			what = optc;
		}

	while (i < NELEM(rlimits)) {
		if (rlimits[i]->optchar == what)
			goto found;
		++i;
	}
	internal_warningf("ulimit: %c", what);
	return (1);
 found:
	if (wp[builtin_opt.optind]) {
		if (all || wp[builtin_opt.optind + 1]) {
			bi_errorf(Ttoo_many_args);
			return (1);
		}
		return (set_ulimit(rlimits[i], wp[builtin_opt.optind], how));
	}
	if (!all)
		print_ulimit(rlimits[i], how);
	else for (i = 0; i < NELEM(rlimits); ++i) {
		shprintf("-%c: %-20s  ", rlimits[i]->optchar, rlimits[i]->name);
		print_ulimit(rlimits[i], how);
	}
	return (0);
}

static int
set_ulimit(const struct limits *l, const char *v, int how)
{
	rlim_t val = (rlim_t)0;
	struct rlimit limit;

	if (strcmp(v, "unlimited") == 0)
		val = (rlim_t)RLIM_INFINITY;
	else {
		mksh_uari_t rval;

		if (!evaluate(v, (mksh_ari_t *)&rval, KSH_RETURN_ERROR, false))
			return (1);
		/*
		 * Avoid problems caused by typos that evaluate misses due
		 * to evaluating unset parameters to 0...
		 * If this causes problems, will have to add parameter to
		 * evaluate() to control if unset params are 0 or an error.
		 */
		if (!rval && !ctype(v[0], C_DIGIT)) {
			bi_errorf("invalid %s limit: %s", l->name, v);
			return (1);
		}
		val = (rlim_t)((rlim_t)rval * l->factor);
	}

	if (getrlimit(l->resource, &limit) < 0) {
#ifndef MKSH_SMALL
		bi_errorf("limit %s could not be read, contact the mksh developers: %s",
		    l->name, cstrerror(errno));
#endif
		/* some can't be read */
		limit.rlim_cur = RLIM_INFINITY;
		limit.rlim_max = RLIM_INFINITY;
	}
	if (how & SOFT)
		limit.rlim_cur = val;
	if (how & HARD)
		limit.rlim_max = val;
	if (!setrlimit(l->resource, &limit))
		return (0);
	if (errno == EPERM)
		bi_errorf("%s exceeds allowable %s limit", v, l->name);
	else
		bi_errorf("bad %s limit: %s", l->name, cstrerror(errno));
	return (1);
}

static void
print_ulimit(const struct limits *l, int how)
{
	rlim_t val = (rlim_t)0;
	struct rlimit limit;

	if (getrlimit(l->resource, &limit)) {
		shf_puts("unknown\n", shl_stdout);
		return;
	}
	if (how & SOFT)
		val = limit.rlim_cur;
	else if (how & HARD)
		val = limit.rlim_max;
	if (val == (rlim_t)RLIM_INFINITY)
		shf_puts("unlimited\n", shl_stdout);
	else
		shprintf("%lu\n", (unsigned long)(val / l->factor));
}
#endif

int
c_rename(const char **wp)
{
	int rv = 1;

	/* skip argv[0] */
	++wp;
	if (wp[0] && !strcmp(wp[0], "--"))
		/* skip "--" (options separator) */
		++wp;

	/* check for exactly two arguments */
	if (wp[0] == NULL	/* first argument */ ||
	    wp[1] == NULL	/* second argument */ ||
	    wp[2] != NULL	/* no further args please */)
		bi_errorf(Tsynerr);
	else if ((rv = rename(wp[0], wp[1])) != 0) {
		rv = errno;
		bi_errorf(Tf_sD_s, "failed", cstrerror(rv));
	}

	return (rv);
}

int
c_realpath(const char **wp)
{
	int rv = 1;
	char *buf;

	/* skip argv[0] */
	++wp;
	if (wp[0] && !strcmp(wp[0], "--"))
		/* skip "--" (options separator) */
		++wp;

	/* check for exactly one argument */
	if (wp[0] == NULL || wp[1] != NULL)
		bi_errorf(Tsynerr);
	else if ((buf = do_realpath(wp[0])) == NULL) {
		rv = errno;
		bi_errorf(Tf_sD_s, wp[0], cstrerror(rv));
		if ((unsigned int)rv > 255)
			rv = 255;
	} else {
		shprintf(Tf_sN, buf);
		afree(buf, ATEMP);
		rv = 0;
	}

	return (rv);
}

int
c_cat(const char **wp)
{
	int fd = STDIN_FILENO, rv;
	ssize_t n, w;
	const char *fn = "<stdin>";
	char *buf, *cp;
	bool opipe;
#define MKSH_CAT_BUFSIZ 4096

	/* parse options: POSIX demands we support "-u" as no-op */
	while ((rv = ksh_getopt(wp, &builtin_opt, Tu)) != -1) {
		switch (rv) {
		case 'u':
			/* we already operate unbuffered */
			break;
		default:
			bi_errorf(Tsynerr);
			return (1);
		}
	}
	wp += builtin_opt.optind;
	rv = 0;

	if ((buf = malloc_osfunc(MKSH_CAT_BUFSIZ)) == NULL) {
		bi_errorf(Toomem, (size_t)MKSH_CAT_BUFSIZ);
		return (1);
	}

	/* catch SIGPIPE */
	opipe = block_pipe();

	do {
		if (*wp) {
			fn = *wp++;
			if (ksh_isdash(fn))
				fd = STDIN_FILENO;
			else if ((fd = binopen2(fn, O_RDONLY)) < 0) {
				bi_errorf(Tf_sD_s, fn, cstrerror(errno));
				rv = 1;
				continue;
			}
		}
		while (/* CONSTCOND */ 1) {
			if ((n = blocking_read(fd, (cp = buf),
			    MKSH_CAT_BUFSIZ)) == -1) {
				if (errno == EINTR) {
					if (opipe)
						restore_pipe();
					/* give the user a chance to ^C out */
					intrcheck();
					/* interrupted, try again */
					opipe = block_pipe();
					continue;
				}
				/* an error occured during reading */
				bi_errorf(Tf_sD_s, fn, cstrerror(errno));
				rv = 1;
				break;
			} else if (n == 0)
				/* end of file reached */
				break;
			while (n) {
				if (intrsig)
					goto has_intrsig;
				if ((w = write(STDOUT_FILENO, cp, n)) != -1) {
					n -= w;
					cp += w;
					continue;
				}
				if (errno == EINTR) {
 has_intrsig:
					if (opipe)
						restore_pipe();
					/* give the user a chance to ^C out */
					intrcheck();
					/* interrupted, try again */
					opipe = block_pipe();
					continue;
				}
				if (errno == EPIPE) {
					/* fake receiving signal */
					rv = ksh_sigmask(SIGPIPE);
				} else {
					/* an error occured during writing */
					bi_errorf(Tf_sD_s, "<stdout>",
					    cstrerror(errno));
					rv = 1;
				}
				if (fd != STDIN_FILENO)
					close(fd);
				goto out;
			}
		}
		if (fd != STDIN_FILENO)
			close(fd);
	} while (*wp);

 out:
	if (opipe)
		restore_pipe();
	free_osfunc(buf);
	return (rv);
}

#if HAVE_SELECT
int
c_sleep(const char **wp)
{
	struct timeval tv;
	int rv = 1;

	/* skip argv[0] */
	++wp;
	if (wp[0] && !strcmp(wp[0], "--"))
		/* skip "--" (options separator) */
		++wp;

	if (!wp[0] || wp[1])
		bi_errorf(Tsynerr);
	else if (parse_usec(wp[0], &tv))
		bi_errorf(Tf_sD_s_qs, Tsynerr, cstrerror(errno), wp[0]);
	else {
#ifndef MKSH_NOPROSPECTOFWORK
		sigset_t omask, bmask;

		/* block a number of signals from interrupting us, though */
		(void)sigemptyset(&bmask);
		(void)sigaddset(&bmask, SIGPIPE);
		(void)sigaddset(&bmask, SIGCHLD);
#ifdef SIGWINCH
		(void)sigaddset(&bmask, SIGWINCH);
#endif
#ifdef SIGINFO
		(void)sigaddset(&bmask, SIGINFO);
#endif
#ifdef SIGUSR1
		(void)sigaddset(&bmask, SIGUSR1);
#endif
#ifdef SIGUSR2
		(void)sigaddset(&bmask, SIGUSR2);
#endif
		sigprocmask(SIG_BLOCK, &bmask, &omask);
#endif
		if (select(1, NULL, NULL, NULL, &tv) == 0 || errno == EINTR)
			/*
			 * strictly speaking only for SIGALRM, but the
			 * execution may be interrupted by other signals
			 */
			rv = 0;
		else
			bi_errorf(Tf_sD_s, Tselect, cstrerror(errno));
#ifndef MKSH_NOPROSPECTOFWORK
		/* this will re-schedule signal delivery */
		sigprocmask(SIG_SETMASK, &omask, NULL);
#endif
	}
	return (rv);
}
#endif

#if !defined(MKSH_UNEMPLOYED) && HAVE_GETSID
static int
c_suspend(const char **wp)
{
	if (wp[1] != NULL) {
		bi_errorf(Ttoo_many_args);
		return (1);
	}
	if (Flag(FLOGIN)) {
		/* Can't suspend an orphaned process group. */
		if (getpgid(kshppid) == getpgid(0) ||
		    getsid(kshppid) != getsid(0)) {
			bi_errorf("can't suspend a login shell");
			return (1);
		}
	}
	j_suspend();
	return (0);
}
#endif
