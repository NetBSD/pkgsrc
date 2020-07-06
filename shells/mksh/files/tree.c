/*	$OpenBSD: tree.c,v 1.21 2015/09/01 13:12:31 tedu Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *		 2011, 2012, 2013, 2015, 2016, 2017
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

__RCSID("$MirOS: src/bin/mksh/tree.c,v 1.97 2018/10/20 18:46:00 tg Exp $");

#define INDENT	8

static void ptree(struct op *, int, struct shf *);
static void pioact(struct shf *, struct ioword *);
static const char *wdvarput(struct shf *, const char *, int, int);
static void vfptreef(struct shf *, int, const char *, va_list);
static struct ioword **iocopy(struct ioword **, Area *);
static void iofree(struct ioword **, Area *);

/* "foo& ; bar" and "foo |& ; bar" are invalid */
static bool prevent_semicolon;

static const char Telif_pT[] = "elif %T";

/*
 * print a command tree
 */
static void
ptree(struct op *t, int indent, struct shf *shf)
{
	const char **w;
	struct ioword **ioact;
	struct op *t1;
	int i;
	const char *ccp;

 Chain:
	if (t == NULL)
		return;
	switch (t->type) {
	case TCOM:
		prevent_semicolon = false;
		/* special-case 'var=<<EOF' (cf. exec.c:execute) */
		if (t->args &&
		    /* we have zero arguments, i.e. no program to run */
		    t->args[0] == NULL &&
		    /* we have exactly one variable assignment */
		    t->vars[0] != NULL && t->vars[1] == NULL &&
		    /* we have exactly one I/O redirection */
		    t->ioact != NULL && t->ioact[0] != NULL &&
		    t->ioact[1] == NULL &&
		    /* of type "here document" (or "here string") */
		    (t->ioact[0]->ioflag & IOTYPE) == IOHERE &&
		    /* the variable assignment begins with a valid varname */
		    (ccp = skip_wdvarname(t->vars[0], true)) != t->vars[0] &&
		    /* and has no right-hand side (i.e. "varname=") */
		    ccp[0] == CHAR && ((ccp[1] == '=' && ccp[2] == EOS) ||
		    /* or "varname+=" */ (ccp[1] == '+' && ccp[2] == CHAR &&
		    ccp[3] == '=' && ccp[4] == EOS))) {
			fptreef(shf, indent, Tf_S, t->vars[0]);
			break;
		}

		if (t->vars) {
			w = (const char **)t->vars;
			while (*w)
				fptreef(shf, indent, Tf_S_, *w++);
		} else
			shf_puts("#no-vars# ", shf);
		if (t->args) {
			w = t->args;
			if (*w && **w == CHAR) {
				char *cp = wdstrip(*w++, WDS_TPUTS);

				if (valid_alias_name(cp))
					shf_putc('\\', shf);
				shf_puts(cp, shf);
				shf_putc(' ', shf);
				afree(cp, ATEMP);
			}
			while (*w)
				fptreef(shf, indent, Tf_S_, *w++);
		} else
			shf_puts("#no-args# ", shf);
		break;
	case TEXEC:
		t = t->left;
		goto Chain;
	case TPAREN:
		fptreef(shf, indent + 2, "( %T) ", t->left);
		break;
	case TPIPE:
		fptreef(shf, indent, "%T| ", t->left);
		t = t->right;
		goto Chain;
	case TLIST:
		fptreef(shf, indent, "%T%;", t->left);
		t = t->right;
		goto Chain;
	case TOR:
	case TAND:
		fptreef(shf, indent, "%T%s %T",
		    t->left, (t->type == TOR) ? "||" : "&&", t->right);
		break;
	case TBANG:
		shf_puts("! ", shf);
		prevent_semicolon = false;
		t = t->right;
		goto Chain;
	case TDBRACKET:
		w = t->args;
		shf_puts("[[", shf);
		while (*w)
			fptreef(shf, indent, Tf__S, *w++);
		shf_puts(" ]] ", shf);
		break;
	case TSELECT:
	case TFOR:
		fptreef(shf, indent, "%s %s ",
		    (t->type == TFOR) ? "for" : Tselect, t->str);
		if (t->vars != NULL) {
			shf_puts("in ", shf);
			w = (const char **)t->vars;
			while (*w)
				fptreef(shf, indent, Tf_S_, *w++);
			fptreef(shf, indent, Tft_end);
		}
		fptreef(shf, indent + INDENT, "do%N%T", t->left);
		fptreef(shf, indent, "%;done ");
		break;
	case TCASE:
		fptreef(shf, indent, "case %S in", t->str);
		for (t1 = t->left; t1 != NULL; t1 = t1->right) {
			fptreef(shf, indent, "%N(");
			w = (const char **)t1->vars;
			while (*w) {
				fptreef(shf, indent, "%S%c", *w,
				    (w[1] != NULL) ? '|' : ')');
				++w;
			}
			fptreef(shf, indent + INDENT, "%N%T%N;%c", t1->left,
			    t1->u.charflag);
		}
		fptreef(shf, indent, "%Nesac ");
		break;
	case TELIF:
		internal_errorf(TELIF_unexpected);
		/* FALLTHROUGH */
	case TIF:
		i = 2;
		t1 = t;
		goto process_TIF;
		do {
			t1 = t1->right;
			i = 0;
			fptreef(shf, indent, Tft_end);
 process_TIF:
			/* 5 == strlen("elif ") */
			fptreef(shf, indent + 5 - i, Telif_pT + i, t1->left);
			t1 = t1->right;
			if (t1->left != NULL) {
				fptreef(shf, indent, Tft_end);
				fptreef(shf, indent + INDENT, "%s%N%T",
				    "then", t1->left);
			}
		} while (t1->right && t1->right->type == TELIF);
		if (t1->right != NULL) {
			fptreef(shf, indent, Tft_end);
			fptreef(shf, indent + INDENT, "%s%N%T",
			    "else", t1->right);
		}
		fptreef(shf, indent, "%;fi ");
		break;
	case TWHILE:
	case TUNTIL:
		/* 6 == strlen("while "/"until ") */
		fptreef(shf, indent + 6, Tf_s_T,
		    (t->type == TWHILE) ? "while" : "until",
		    t->left);
		fptreef(shf, indent, Tft_end);
		fptreef(shf, indent + INDENT, "do%N%T", t->right);
		fptreef(shf, indent, "%;done ");
		break;
	case TBRACE:
		fptreef(shf, indent + INDENT, "{%N%T", t->left);
		fptreef(shf, indent, "%;} ");
		break;
	case TCOPROC:
		fptreef(shf, indent, "%T|& ", t->left);
		prevent_semicolon = true;
		break;
	case TASYNC:
		fptreef(shf, indent, "%T& ", t->left);
		prevent_semicolon = true;
		break;
	case TFUNCT:
		fpFUNCTf(shf, indent, tobool(t->u.ksh_func), t->str, t->left);
		break;
	case TTIME:
		fptreef(shf, indent, Tf_s_T, Ttime, t->left);
		break;
	default:
		shf_puts("<botch>", shf);
		prevent_semicolon = false;
		break;
	}
	if ((ioact = t->ioact) != NULL) {
		bool need_nl = false;

		while (*ioact != NULL)
			pioact(shf, *ioact++);
		/* Print here documents after everything else... */
		ioact = t->ioact;
		while (*ioact != NULL) {
			struct ioword *iop = *ioact++;

			/* heredoc is NULL when tracing (set -x) */
			if ((iop->ioflag & (IOTYPE | IOHERESTR)) == IOHERE &&
			    iop->heredoc) {
				shf_putc('\n', shf);
				shf_puts(iop->heredoc, shf);
				fptreef(shf, indent, Tf_s,
				    evalstr(iop->delim, 0));
				need_nl = true;
			}
		}
		/*
		 * Last delimiter must be followed by a newline (this
		 * often leads to an extra blank line, but it's not
		 * worth worrying about)
		 */
		if (need_nl) {
			shf_putc('\n', shf);
			prevent_semicolon = true;
		}
	}
}

static void
pioact(struct shf *shf, struct ioword *iop)
{
	unsigned short flag = iop->ioflag;
	unsigned short type = flag & IOTYPE;
	short expected;

	expected = (type == IOREAD || type == IORDWR || type == IOHERE) ? 0 :
	    (type == IOCAT || type == IOWRITE) ? 1 :
	    (type == IODUP && (iop->unit == !(flag & IORDUP))) ? iop->unit :
	    iop->unit + 1;
	if (iop->unit != expected)
		shf_fprintf(shf, Tf_d, (int)iop->unit);

	switch (type) {
	case IOREAD:
		shf_putc('<', shf);
		break;
	case IOHERE:
		shf_puts("<<", shf);
		if (flag & IOSKIP)
			shf_putc('-', shf);
		else if (flag & IOHERESTR)
			shf_putc('<', shf);
		break;
	case IOCAT:
		shf_puts(">>", shf);
		break;
	case IOWRITE:
		shf_putc('>', shf);
		if (flag & IOCLOB)
			shf_putc('|', shf);
		break;
	case IORDWR:
		shf_puts("<>", shf);
		break;
	case IODUP:
		shf_puts(flag & IORDUP ? "<&" : ">&", shf);
		break;
	}
	/* name/delim are NULL when printing syntax errors */
	if (type == IOHERE) {
		if (iop->delim && !(iop->ioflag & IONDELIM))
			wdvarput(shf, iop->delim, 0, WDS_TPUTS);
	} else if (iop->ioname) {
		if (flag & IONAMEXP)
			print_value_quoted(shf, iop->ioname);
		else
			wdvarput(shf, iop->ioname, 0, WDS_TPUTS);
	}
	shf_putc(' ', shf);
	prevent_semicolon = false;
}

/* variant of fputs for ptreef and wdstrip */
static const char *
wdvarput(struct shf *shf, const char *wp, int quotelevel, int opmode)
{
	int c;
	const char *cs;

	/*-
	 * problems:
	 *	`...` -> $(...)
	 *	'foo' -> "foo"
	 *	x${foo:-"hi"} -> x${foo:-hi} unless WDS_TPUTS
	 *	x${foo:-'hi'} -> x${foo:-hi}
	 * could change encoding to:
	 *	OQUOTE ["'] ... CQUOTE ["']
	 *	COMSUB [(`] ...\0	(handle $ ` \ and maybe " in `...` case)
	 */
	while (/* CONSTCOND */ 1)
		switch (*wp++) {
		case EOS:
			return (--wp);
		case ADELIM:
			if (ord(*wp) == ORD(/*{*/ '}')) {
				++wp;
				goto wdvarput_csubst;
			}
			/* FALLTHROUGH */
		case CHAR:
			c = ord(*wp++);
			shf_putc(c, shf);
			break;
		case QCHAR:
			c = ord(*wp++);
			if (opmode & WDS_TPUTS)
				switch (c) {
				case ORD('\n'):
					if (quotelevel == 0) {
						c = ORD('\'');
						shf_putc(c, shf);
						shf_putc(ORD('\n'), shf);
					}
					break;
				default:
					if (quotelevel == 0)
						/* FALLTHROUGH */
				case ORD('"'):
				case ORD('`'):
				case ORD('$'):
				case ORD('\\'):
					  shf_putc(ORD('\\'), shf);
					break;
				}
			shf_putc(c, shf);
			break;
		case COMASUB:
		case COMSUB:
			shf_puts("$(", shf);
			cs = ")";
			if (ord(*wp) == ORD('(' /*)*/))
				shf_putc(' ', shf);
 pSUB:
			while ((c = *wp++) != 0)
				shf_putc(c, shf);
			shf_puts(cs, shf);
			break;
		case FUNASUB:
		case FUNSUB:
			c = ORD(' ');
			if (0)
				/* FALLTHROUGH */
		case VALSUB:
			  c = ORD('|');
			shf_putc('$', shf);
			shf_putc('{', shf);
			shf_putc(c, shf);
			cs = ";}";
			goto pSUB;
		case EXPRSUB:
			shf_puts("$((", shf);
			cs = "))";
			goto pSUB;
		case OQUOTE:
			if (opmode & WDS_TPUTS) {
				quotelevel++;
				shf_putc('"', shf);
			}
			break;
		case CQUOTE:
			if (opmode & WDS_TPUTS) {
				if (quotelevel)
					quotelevel--;
				shf_putc('"', shf);
			}
			break;
		case OSUBST:
			shf_putc('$', shf);
			if (ord(*wp++) == ORD('{'))
				shf_putc('{', shf);
			while ((c = *wp++) != 0)
				shf_putc(c, shf);
			wp = wdvarput(shf, wp, 0, opmode);
			break;
		case CSUBST:
			if (ord(*wp++) == ORD('}')) {
 wdvarput_csubst:
				shf_putc('}', shf);
			}
			return (wp);
		case OPAT:
			shf_putchar(*wp++, shf);
			shf_putc('(', shf);
			break;
		case SPAT:
			c = ORD('|');
			if (0)
				/* FALLTHROUGH */
		case CPAT:
			  c = ORD(/*(*/ ')');
			shf_putc(c, shf);
			break;
		}
}

/*
 * this is the _only_ way to reliably handle
 * variable args with an ANSI compiler
 */
/* VARARGS */
void
fptreef(struct shf *shf, int indent, const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	vfptreef(shf, indent, fmt, va);
	va_end(va);
}

/* VARARGS */
char *
snptreef(char *s, ssize_t n, const char *fmt, ...)
{
	va_list va;
	struct shf shf;

	shf_sopen(s, n, SHF_WR | (s ? 0 : SHF_DYNAMIC), &shf);

	va_start(va, fmt);
	vfptreef(&shf, 0, fmt, va);
	va_end(va);

	/* shf_sclose NUL terminates */
	return (shf_sclose(&shf));
}

static void
vfptreef(struct shf *shf, int indent, const char *fmt, va_list va)
{
	int c;

	while ((c = ord(*fmt++))) {
		if (c == '%') {
			switch ((c = ord(*fmt++))) {
			case ORD('c'):
				/* character (octet, probably) */
				shf_putchar(va_arg(va, int), shf);
				break;
			case ORD('s'):
				/* string */
				shf_puts(va_arg(va, char *), shf);
				break;
			case ORD('S'):
				/* word */
				wdvarput(shf, va_arg(va, char *), 0, WDS_TPUTS);
				break;
			case ORD('d'):
				/* signed decimal */
				shf_fprintf(shf, Tf_d, va_arg(va, int));
				break;
			case ORD('u'):
				/* unsigned decimal */
				shf_fprintf(shf, "%u", va_arg(va, unsigned int));
				break;
			case ORD('T'):
				/* format tree */
				ptree(va_arg(va, struct op *), indent, shf);
				goto dont_trash_prevent_semicolon;
			case ORD(';'):
				/* newline or ; */
			case ORD('N'):
				/* newline or space */
				if (shf->flags & SHF_STRING) {
					if ((unsigned int)c == ORD(';') &&
					    !prevent_semicolon)
						shf_putc(';', shf);
					shf_putc(' ', shf);
				} else {
					int i;

					shf_putc('\n', shf);
					i = indent;
					while (i >= 8) {
						shf_putc('\t', shf);
						i -= 8;
					}
					while (i--)
						shf_putc(' ', shf);
				}
				break;
			case ORD('R'):
				/* I/O redirection */
				pioact(shf, va_arg(va, struct ioword *));
				break;
			default:
				shf_putc(c, shf);
				break;
			}
		} else
			shf_putc(c, shf);
		prevent_semicolon = false;
 dont_trash_prevent_semicolon:
		;
	}
}

/*
 * copy tree (for function definition)
 */
struct op *
tcopy(struct op *t, Area *ap)
{
	struct op *r;
	const char **tw;
	char **rw;

	if (t == NULL)
		return (NULL);

	r = alloc(sizeof(struct op), ap);

	r->type = t->type;
	r->u.evalflags = t->u.evalflags;

	if (t->type == TCASE)
		r->str = wdcopy(t->str, ap);
	else
		strdupx(r->str, t->str, ap);

	if (t->vars == NULL)
		r->vars = NULL;
	else {
		tw = (const char **)t->vars;
		while (*tw)
			++tw;
		rw = r->vars = alloc2(tw - (const char **)t->vars + 1,
		    sizeof(*tw), ap);
		tw = (const char **)t->vars;
		while (*tw)
			*rw++ = wdcopy(*tw++, ap);
		*rw = NULL;
	}

	if (t->args == NULL)
		r->args = NULL;
	else {
		tw = t->args;
		while (*tw)
			++tw;
		r->args = (const char **)(rw = alloc2(tw - t->args + 1,
		    sizeof(*tw), ap));
		tw = t->args;
		while (*tw)
			*rw++ = wdcopy(*tw++, ap);
		*rw = NULL;
	}

	r->ioact = (t->ioact == NULL) ? NULL : iocopy(t->ioact, ap);

	r->left = tcopy(t->left, ap);
	r->right = tcopy(t->right, ap);
	r->lineno = t->lineno;

	return (r);
}

char *
wdcopy(const char *wp, Area *ap)
{
	size_t len;

	len = wdscan(wp, EOS) - wp;
	return (memcpy(alloc(len, ap), wp, len));
}

/* return the position of prefix c in wp plus 1 */
const char *
wdscan(const char *wp, int c)
{
	int nest = 0;

	while (/* CONSTCOND */ 1)
		switch (*wp++) {
		case EOS:
			return (wp);
		case ADELIM:
			if (c == ADELIM && nest == 0)
				return (wp + 1);
			if (ord(*wp) == ORD(/*{*/ '}'))
				goto wdscan_csubst;
			/* FALLTHROUGH */
		case CHAR:
		case QCHAR:
			wp++;
			break;
		case COMASUB:
		case COMSUB:
		case FUNASUB:
		case FUNSUB:
		case VALSUB:
		case EXPRSUB:
			while (*wp++ != 0)
				;
			break;
		case OQUOTE:
		case CQUOTE:
			break;
		case OSUBST:
			nest++;
			while (*wp++ != '\0')
				;
			break;
		case CSUBST:
 wdscan_csubst:
			wp++;
			if (c == CSUBST && nest == 0)
				return (wp);
			nest--;
			break;
		case OPAT:
			nest++;
			wp++;
			break;
		case SPAT:
		case CPAT:
			if (c == wp[-1] && nest == 0)
				return (wp);
			if (wp[-1] == CPAT)
				nest--;
			break;
		default:
			internal_warningf(
			    "wdscan: unknown char 0x%X (carrying on)",
			    (unsigned char)wp[-1]);
		}
}

/*
 * return a copy of wp without any of the mark up characters and with
 * quote characters (" ' \) stripped. (string is allocated from ATEMP)
 */
char *
wdstrip(const char *wp, int opmode)
{
	struct shf shf;

	shf_sopen(NULL, 32, SHF_WR | SHF_DYNAMIC, &shf);
	wdvarput(&shf, wp, 0, opmode);
	/* shf_sclose NUL terminates */
	return (shf_sclose(&shf));
}

static struct ioword **
iocopy(struct ioword **iow, Area *ap)
{
	struct ioword **ior;
	int i;

	ior = iow;
	while (*ior)
		++ior;
	ior = alloc2(ior - iow + 1, sizeof(struct ioword *), ap);

	for (i = 0; iow[i] != NULL; i++) {
		struct ioword *p, *q;

		p = iow[i];
		q = alloc(sizeof(struct ioword), ap);
		ior[i] = q;
		*q = *p;
		if (p->ioname != NULL)
			q->ioname = wdcopy(p->ioname, ap);
		if (p->delim != NULL)
			q->delim = wdcopy(p->delim, ap);
		if (p->heredoc != NULL)
			strdupx(q->heredoc, p->heredoc, ap);
	}
	ior[i] = NULL;

	return (ior);
}

/*
 * free tree (for function definition)
 */
void
tfree(struct op *t, Area *ap)
{
	char **w;

	if (t == NULL)
		return;

	afree(t->str, ap);

	if (t->vars != NULL) {
		for (w = t->vars; *w != NULL; w++)
			afree(*w, ap);
		afree(t->vars, ap);
	}

	if (t->args != NULL) {
		/*XXX we assume the caller is right */
		union mksh_ccphack cw;

		cw.ro = t->args;
		for (w = cw.rw; *w != NULL; w++)
			afree(*w, ap);
		afree(t->args, ap);
	}

	if (t->ioact != NULL)
		iofree(t->ioact, ap);

	tfree(t->left, ap);
	tfree(t->right, ap);

	afree(t, ap);
}

static void
iofree(struct ioword **iow, Area *ap)
{
	struct ioword **iop;
	struct ioword *p;

	iop = iow;
	while ((p = *iop++) != NULL) {
		afree(p->ioname, ap);
		afree(p->delim, ap);
		afree(p->heredoc, ap);
		afree(p, ap);
	}
	afree(iow, ap);
}

void
fpFUNCTf(struct shf *shf, int i, bool isksh, const char *k, struct op *v)
{
	if (isksh)
		fptreef(shf, i, "%s %s %T", Tfunction, k, v);
	else if (ktsearch(&keywords, k, hash(k)))
		fptreef(shf, i, "%s %s() %T", Tfunction, k, v);
	else
		fptreef(shf, i, "%s() %T", k, v);
}


/* for jobs.c */
void
vistree(char *dst, size_t sz, struct op *t)
{
	unsigned int c;
	char *cp, *buf;
	size_t n;

	buf = alloc(sz + 16, ATEMP);
	snptreef(buf, sz + 16, Tf_T, t);
	cp = buf;
 vist_loop:
	if (UTFMODE && (n = utf_mbtowc(&c, cp)) != (size_t)-1) {
		if (c == 0 || n >= sz)
			/* NUL or not enough free space */
			goto vist_out;
		/* copy multibyte char */
		sz -= n;
		while (n--)
			*dst++ = *cp++;
		goto vist_loop;
	}
	if (--sz == 0 || (c = ord(*cp++)) == 0)
		/* NUL or not enough free space */
		goto vist_out;
	if (ksh_isctrl(c)) {
		/* C0 or C1 control character or DEL */
		if (--sz == 0)
			/* not enough free space for two chars */
			goto vist_out;
		*dst++ = '^';
		c = ksh_unctrl(c);
	} else if (UTFMODE && rtt2asc(c) > 0x7F) {
		/* better not try to display broken multibyte chars */
		/* also go easy on the UCS: no U+FFFD here */
		c = ORD('?');
	}
	*dst++ = c;
	goto vist_loop;

 vist_out:
	*dst = '\0';
	afree(buf, ATEMP);
}

#ifdef DEBUG
void
dumpchar(struct shf *shf, unsigned char c)
{
	if (ksh_isctrl(c)) {
		/* C0 or C1 control character or DEL */
		shf_putc('^', shf);
		c = ksh_unctrl(c);
	}
	shf_putc(c, shf);
}

/* see: wdvarput */
static const char *
dumpwdvar_i(struct shf *shf, const char *wp, int quotelevel)
{
	int c;

	while (/* CONSTCOND */ 1) {
		switch(*wp++) {
		case EOS:
			shf_puts("EOS", shf);
			return (--wp);
		case ADELIM:
			if (ord(*wp) == ORD(/*{*/ '}')) {
				shf_puts(/*{*/ "]ADELIM(})", shf);
				return (wp + 1);
			}
			shf_puts("ADELIM=", shf);
			if (0)
				/* FALLTHROUGH */
		case CHAR:
			  shf_puts("CHAR=", shf);
			dumpchar(shf, *wp++);
			break;
		case QCHAR:
			shf_puts("QCHAR<", shf);
			c = ord(*wp++);
			if (quotelevel == 0 || c == ORD('"') ||
			    c == ORD('\\') || ctype(c, C_DOLAR | C_GRAVE))
				shf_putc('\\', shf);
			dumpchar(shf, c);
			goto closeandout;
		case COMASUB:
			shf_puts("COMASUB<", shf);
			goto dumpsub;
		case COMSUB:
			shf_puts("COMSUB<", shf);
 dumpsub:
			while ((c = *wp++) != 0)
				dumpchar(shf, c);
 closeandout:
			shf_putc('>', shf);
			break;
		case FUNASUB:
			shf_puts("FUNASUB<", shf);
			goto dumpsub;
		case FUNSUB:
			shf_puts("FUNSUB<", shf);
			goto dumpsub;
		case VALSUB:
			shf_puts("VALSUB<", shf);
			goto dumpsub;
		case EXPRSUB:
			shf_puts("EXPRSUB<", shf);
			goto dumpsub;
		case OQUOTE:
			shf_fprintf(shf, "OQUOTE{%d" /*}*/, ++quotelevel);
			break;
		case CQUOTE:
			shf_fprintf(shf, /*{*/ "%d}CQUOTE", quotelevel);
			if (quotelevel)
				quotelevel--;
			else
				shf_puts("(err)", shf);
			break;
		case OSUBST:
			shf_puts("OSUBST(", shf);
			dumpchar(shf, *wp++);
			shf_puts(")[", shf);
			while ((c = *wp++) != 0)
				dumpchar(shf, c);
			shf_putc('|', shf);
			wp = dumpwdvar_i(shf, wp, 0);
			break;
		case CSUBST:
			shf_puts("]CSUBST(", shf);
			dumpchar(shf, *wp++);
			shf_putc(')', shf);
			return (wp);
		case OPAT:
			shf_puts("OPAT=", shf);
			dumpchar(shf, *wp++);
			break;
		case SPAT:
			shf_puts("SPAT", shf);
			break;
		case CPAT:
			shf_puts("CPAT", shf);
			break;
		default:
			shf_fprintf(shf, "INVAL<%u>", (uint8_t)wp[-1]);
			break;
		}
		shf_putc(' ', shf);
	}
}
void
dumpwdvar(struct shf *shf, const char *wp)
{
	dumpwdvar_i(shf, wp, 0);
}

void
dumpioact(struct shf *shf, struct op *t)
{
	struct ioword **ioact, *iop;

	if ((ioact = t->ioact) == NULL)
		return;

	shf_puts("{IOACT", shf);
	while ((iop = *ioact++) != NULL) {
		unsigned short type = iop->ioflag & IOTYPE;
#define DT(x) case x: shf_puts(#x, shf); break;
#define DB(x) if (iop->ioflag & x) shf_puts("|" #x, shf);

		shf_putc(';', shf);
		switch (type) {
		DT(IOREAD)
		DT(IOWRITE)
		DT(IORDWR)
		DT(IOHERE)
		DT(IOCAT)
		DT(IODUP)
		default:
			shf_fprintf(shf, "unk%d", type);
		}
		DB(IOEVAL)
		DB(IOSKIP)
		DB(IOCLOB)
		DB(IORDUP)
		DB(IONAMEXP)
		DB(IOBASH)
		DB(IOHERESTR)
		DB(IONDELIM)
		shf_fprintf(shf, ",unit=%d", (int)iop->unit);
		if (iop->delim && !(iop->ioflag & IONDELIM)) {
			shf_puts(",delim<", shf);
			dumpwdvar(shf, iop->delim);
			shf_putc('>', shf);
		}
		if (iop->ioname) {
			if (iop->ioflag & IONAMEXP) {
				shf_puts(",name=", shf);
				print_value_quoted(shf, iop->ioname);
			} else {
				shf_puts(",name<", shf);
				dumpwdvar(shf, iop->ioname);
				shf_putc('>', shf);
			}
		}
		if (iop->heredoc) {
			shf_puts(",heredoc=", shf);
			print_value_quoted(shf, iop->heredoc);
		}
#undef DT
#undef DB
	}
	shf_putc('}', shf);
}

void
dumptree(struct shf *shf, struct op *t)
{
	int i, j;
	const char **w, *name;
	struct op *t1;
	static int nesting;

	for (i = 0; i < nesting; ++i)
		shf_putc('\t', shf);
	++nesting;
	shf_puts("{tree:" /*}*/, shf);
	if (t == NULL) {
		name = "(null)";
		goto out;
	}
	dumpioact(shf, t);
	switch (t->type) {
#define OPEN(x) case x: name = #x; shf_puts(" {" #x ":", shf); /*}*/

	OPEN(TCOM)
		if (t->vars) {
			i = 0;
			w = (const char **)t->vars;
			while (*w) {
				shf_putc('\n', shf);
				for (j = 0; j < nesting; ++j)
					shf_putc('\t', shf);
				shf_fprintf(shf, " var%d<", i++);
				dumpwdvar(shf, *w++);
				shf_putc('>', shf);
			}
		} else
			shf_puts(" #no-vars#", shf);
		if (t->args) {
			i = 0;
			w = t->args;
			while (*w) {
				shf_putc('\n', shf);
				for (j = 0; j < nesting; ++j)
					shf_putc('\t', shf);
				shf_fprintf(shf, " arg%d<", i++);
				dumpwdvar(shf, *w++);
				shf_putc('>', shf);
			}
		} else
			shf_puts(" #no-args#", shf);
		break;
	OPEN(TEXEC)
 dumpleftandout:
		t = t->left;
 dumpandout:
		shf_putc('\n', shf);
		dumptree(shf, t);
		break;
	OPEN(TPAREN)
		goto dumpleftandout;
	OPEN(TPIPE)
 dumpleftmidrightandout:
		shf_putc('\n', shf);
		dumptree(shf, t->left);
/* middumprightandout: (unused) */
		shf_fprintf(shf, "/%s:", name);
 dumprightandout:
		t = t->right;
		goto dumpandout;
	OPEN(TLIST)
		goto dumpleftmidrightandout;
	OPEN(TOR)
		goto dumpleftmidrightandout;
	OPEN(TAND)
		goto dumpleftmidrightandout;
	OPEN(TBANG)
		goto dumprightandout;
	OPEN(TDBRACKET)
		i = 0;
		w = t->args;
		while (*w) {
			shf_putc('\n', shf);
			for (j = 0; j < nesting; ++j)
				shf_putc('\t', shf);
			shf_fprintf(shf, " arg%d<", i++);
			dumpwdvar(shf, *w++);
			shf_putc('>', shf);
		}
		break;
	OPEN(TFOR)
 dumpfor:
		shf_fprintf(shf, " str<%s>", t->str);
		if (t->vars != NULL) {
			i = 0;
			w = (const char **)t->vars;
			while (*w) {
				shf_putc('\n', shf);
				for (j = 0; j < nesting; ++j)
					shf_putc('\t', shf);
				shf_fprintf(shf, " var%d<", i++);
				dumpwdvar(shf, *w++);
				shf_putc('>', shf);
			}
		}
		goto dumpleftandout;
	OPEN(TSELECT)
		goto dumpfor;
	OPEN(TCASE)
		shf_fprintf(shf, " str<%s>", t->str);
		i = 0;
		for (t1 = t->left; t1 != NULL; t1 = t1->right) {
			shf_putc('\n', shf);
			for (j = 0; j < nesting; ++j)
				shf_putc('\t', shf);
			shf_fprintf(shf, " sub%d[(", i);
			w = (const char **)t1->vars;
			while (*w) {
				dumpwdvar(shf, *w);
				if (w[1] != NULL)
					shf_putc('|', shf);
				++w;
			}
			shf_putc(')', shf);
			dumpioact(shf, t);
			shf_putc('\n', shf);
			dumptree(shf, t1->left);
			shf_fprintf(shf, " ;%c/%d]", t1->u.charflag, i++);
		}
		break;
	OPEN(TWHILE)
		goto dumpleftmidrightandout;
	OPEN(TUNTIL)
		goto dumpleftmidrightandout;
	OPEN(TBRACE)
		goto dumpleftandout;
	OPEN(TCOPROC)
		goto dumpleftandout;
	OPEN(TASYNC)
		goto dumpleftandout;
	OPEN(TFUNCT)
		shf_fprintf(shf, " str<%s> ksh<%s>", t->str,
		    t->u.ksh_func ? Ttrue : Tfalse);
		goto dumpleftandout;
	OPEN(TTIME)
		goto dumpleftandout;
	OPEN(TIF)
 dumpif:
		shf_putc('\n', shf);
		dumptree(shf, t->left);
		t = t->right;
		dumpioact(shf, t);
		if (t->left != NULL) {
			shf_puts(" /TTHEN:\n", shf);
			dumptree(shf, t->left);
		}
		if (t->right && t->right->type == TELIF) {
			shf_puts(" /TELIF:", shf);
			t = t->right;
			dumpioact(shf, t);
			goto dumpif;
		}
		if (t->right != NULL) {
			shf_puts(" /TELSE:\n", shf);
			dumptree(shf, t->right);
		}
		break;
	OPEN(TEOF)
 dumpunexpected:
		shf_puts(Tunexpected, shf);
		break;
	OPEN(TELIF)
		goto dumpunexpected;
	OPEN(TPAT)
		goto dumpunexpected;
	default:
		name = "TINVALID";
		shf_fprintf(shf, "{T<%d>:" /*}*/, t->type);
		goto dumpunexpected;

#undef OPEN
	}
 out:
	shf_fprintf(shf, /*{*/ " /%s}\n", name);
	--nesting;
}
#endif
