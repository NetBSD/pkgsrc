/*	$OpenBSD: syn.c,v 1.30 2015/09/01 13:12:31 tedu Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009,
 *		 2011, 2012, 2013, 2014, 2015, 2016, 2017,
 *		 2018, 2020
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

__RCSID("$MirOS: src/bin/mksh/syn.c,v 1.128 2020/03/31 00:30:05 tg Exp $");

struct nesting_state {
	int start_token;	/* token than began nesting (eg, FOR) */
	int start_line;		/* line nesting began on */
};

struct yyrecursive_state {
	struct ioword *old_heres[HERES];
	struct yyrecursive_state *next;
	struct ioword **old_herep;
	int old_symbol;
	unsigned int old_nesting_type;
	bool old_reject;
};

static void yyparse(bool);
static struct op *pipeline(int, int);
static struct op *andor(int);
static struct op *c_list(int, bool);
static struct ioword *synio(int);
static struct op *nested(int, int, int, int);
static struct op *get_command(int, int);
static struct op *dogroup(int);
static struct op *thenpart(int);
static struct op *elsepart(int);
static struct op *caselist(int);
static struct op *casepart(int, int);
static struct op *function_body(char *, int, bool);
static char **wordlist(int);
static struct op *block(int, struct op *, struct op *);
static struct op *newtp(int);
static void syntaxerr(const char *) MKSH_A_NORETURN;
static void nesting_push(struct nesting_state *, int);
static void nesting_pop(struct nesting_state *);
static int inalias(struct source *) MKSH_A_PURE;
static Test_op dbtestp_isa(Test_env *, Test_meta);
static const char *dbtestp_getopnd(Test_env *, Test_op, bool);
static int dbtestp_eval(Test_env *, Test_op, const char *,
    const char *, bool);
static void dbtestp_error(Test_env *, int, const char *) MKSH_A_NORETURN;

static struct op *outtree;		/* yyparse output */
static struct nesting_state nesting;	/* \n changed to ; */

static bool reject;			/* token(cf) gets symbol again */
static int symbol;			/* yylex value */

#define REJECT		(reject = true)
#define ACCEPT		(reject = false)
#define token(cf)	((reject) ? (ACCEPT, symbol) : (symbol = yylex(cf)))
#define tpeek(cf)	((reject) ? (symbol) : (REJECT, symbol = yylex(cf)))
#define musthave(c,cf)	do { 					\
	if ((unsigned int)token(cf) != (unsigned int)(c))	\
		syntaxerr(NULL);				\
} while (/* CONSTCOND */ 0)

static const char Tcbrace[] = "}";
static const char Tesac[] = "esac";

static void
yyparse(bool doalias)
{
	int c;

	ACCEPT;

	outtree = c_list(doalias ? ALIAS : 0, source->type == SSTRING);
	c = tpeek(0);
	if (c == 0 && !outtree)
		outtree = newtp(TEOF);
	else if (!cinttype(c, C_LF | C_NUL))
		syntaxerr(NULL);
}

static struct op *
pipeline(int cf, int sALIAS)
{
	struct op *t, *p, *tl = NULL;

	t = get_command(cf, sALIAS);
	if (t != NULL) {
		while (token(0) == '|') {
			if ((p = get_command(CONTIN, sALIAS)) == NULL)
				syntaxerr(NULL);
			if (tl == NULL)
				t = tl = block(TPIPE, t, p);
			else
				tl = tl->right = block(TPIPE, tl->right, p);
		}
		REJECT;
	}
	return (t);
}

static struct op *
andor(int sALIAS)
{
	struct op *t, *p;
	int c;

	t = pipeline(0, sALIAS);
	if (t != NULL) {
		while ((c = token(0)) == LOGAND || c == LOGOR) {
			if ((p = pipeline(CONTIN, sALIAS)) == NULL)
				syntaxerr(NULL);
			t = block(c == LOGAND? TAND: TOR, t, p);
		}
		REJECT;
	}
	return (t);
}

static struct op *
c_list(int sALIAS, bool multi)
{
	struct op *t = NULL, *p, *tl = NULL;
	int c;
	bool have_sep;

	while (/* CONSTCOND */ 1) {
		p = andor(sALIAS);
		/*
		 * Token has always been read/rejected at this point, so
		 * we don't worry about what flags to pass token()
		 */
		c = token(0);
		have_sep = true;
		if (c == '\n' && (multi || inalias(source))) {
			if (!p)
				/* ignore blank lines */
				continue;
		} else if (!p)
			break;
		else if (c == '&' || c == COPROC)
			p = block(c == '&' ? TASYNC : TCOPROC, p, NULL);
		else if (c != ';')
			have_sep = false;
		if (!t)
			t = p;
		else if (!tl)
			t = tl = block(TLIST, t, p);
		else
			tl = tl->right = block(TLIST, tl->right, p);
		if (!have_sep)
			break;
	}
	REJECT;
	return (t);
}

static const char IONDELIM_delim[] = { CHAR, '<', CHAR, '<', EOS };

static struct ioword *
synio(int cf)
{
	struct ioword *iop;
	static struct ioword *nextiop;
	bool ishere;

	if (nextiop != NULL) {
		iop = nextiop;
		nextiop = NULL;
		return (iop);
	}

	if (tpeek(cf) != REDIR)
		return (NULL);
	ACCEPT;
	iop = yylval.iop;
	ishere = (iop->ioflag & IOTYPE) == IOHERE;
	if (iop->ioflag & IOHERESTR) {
		musthave(LWORD, 0);
	} else if (ishere && tpeek(HEREDELIM) == '\n') {
		ACCEPT;
		yylval.cp = wdcopy(IONDELIM_delim, ATEMP);
		iop->ioflag |= IOEVAL | IONDELIM;
	} else
		musthave(LWORD, ishere ? HEREDELIM : 0);
	if (ishere) {
		iop->delim = yylval.cp;
		if (*ident != 0 && !(iop->ioflag & IOHERESTR)) {
			/* unquoted */
			iop->ioflag |= IOEVAL;
		}
		if (herep > &heres[HERES - 1])
			yyerror(Tf_toomany, "<<");
		*herep++ = iop;
	} else
		iop->ioname = yylval.cp;

	if (iop->ioflag & IOBASH) {
		char *cp;

		nextiop = alloc(sizeof(*iop), ATEMP);
		nextiop->ioname = cp = alloc(3, ATEMP);
		*cp++ = CHAR;
		*cp++ = digits_lc[iop->unit % 10];
		*cp = EOS;

		iop->ioflag &= ~IOBASH;
		nextiop->unit = 2;
		nextiop->ioflag = IODUP;
		nextiop->delim = NULL;
		nextiop->heredoc = NULL;
	}
	return (iop);
}

static struct op *
nested(int type, int smark, int emark, int sALIAS)
{
	struct op *t;
	struct nesting_state old_nesting;

	nesting_push(&old_nesting, smark);
	t = c_list(sALIAS, true);
	musthave(emark, KEYWORD|sALIAS);
	nesting_pop(&old_nesting);
	return (block(type, t, NULL));
}

static const char builtin_cmd[] = {
	QCHAR, '\\', CHAR, 'b', CHAR, 'u', CHAR, 'i',
	CHAR, 'l', CHAR, 't', CHAR, 'i', CHAR, 'n', EOS
};
static const char let_cmd[] = {
	CHAR, 'l', CHAR, 'e', CHAR, 't', EOS
};
static const char setA_cmd0[] = {
	CHAR, 's', CHAR, 'e', CHAR, 't', EOS
};
static const char setA_cmd1[] = {
	CHAR, '-', CHAR, 'A', EOS
};
static const char setA_cmd2[] = {
	CHAR, '-', CHAR, '-', EOS
};

static struct op *
get_command(int cf, int sALIAS)
{
	struct op *t;
	int c, iopn = 0, syniocf, lno;
	struct ioword *iop, **iops;
	XPtrV args, vars;
	struct nesting_state old_nesting;
	bool check_decl_utility;

	/* NUFILE is small enough to leave this addition unchecked */
	iops = alloc2((NUFILE + 1), sizeof(struct ioword *), ATEMP);
	XPinit(args, 16);
	XPinit(vars, 16);

	syniocf = KEYWORD|sALIAS;
	switch (c = token(cf|KEYWORD|sALIAS|CMDASN)) {
	default:
		REJECT;
		afree(iops, ATEMP);
		XPfree(args);
		XPfree(vars);
		/* empty line */
		return (NULL);

	case LWORD:
	case REDIR:
		REJECT;
		syniocf &= ~(KEYWORD|sALIAS);
		t = newtp(TCOM);
		t->lineno = source->line;
		goto get_command_start;

 get_command_loop:
		if (XPsize(args) == 0) {
 get_command_start:
			check_decl_utility = true;
			cf = sALIAS | CMDASN;
		} else if (t->u.evalflags)
			cf = CMDWORD | CMDASN;
		else
			cf = CMDWORD;

		switch (tpeek(cf)) {
		case REDIR:
			while ((iop = synio(cf)) != NULL) {
				if (iopn >= NUFILE)
					yyerror(Tf_toomany, Tredirection);
				iops[iopn++] = iop;
			}
			goto get_command_loop;

		case LWORD:
			ACCEPT;
			if (check_decl_utility) {
				struct tbl *tt = get_builtin(ident);
				uint32_t flag;

				flag = tt ? tt->flag : 0;
				if (flag & DECL_UTIL)
					t->u.evalflags = DOVACHECK;
				if (!(flag & DECL_FWDR))
					check_decl_utility = false;
			}
			if ((XPsize(args) == 0 || Flag(FKEYWORD)) &&
			    is_wdvarassign(yylval.cp))
				XPput(vars, yylval.cp);
			else
				XPput(args, yylval.cp);
			goto get_command_loop;

		case ORD('(' /*)*/):
			if (XPsize(args) == 0 && XPsize(vars) == 1 &&
			    is_wdvarassign(yylval.cp)) {
				char *tcp;

				/* wdarrassign: foo=(bar) */
				ACCEPT;

				/* manipulate the vars string */
				tcp = XPptrv(vars)[(vars.len = 0)];
				/* 'varname=' -> 'varname' */
				tcp[wdscan(tcp, EOS) - tcp - 3] = EOS;

				/* construct new args strings */
				XPput(args, wdcopy(builtin_cmd, ATEMP));
				XPput(args, wdcopy(setA_cmd0, ATEMP));
				XPput(args, wdcopy(setA_cmd1, ATEMP));
				XPput(args, tcp);
				XPput(args, wdcopy(setA_cmd2, ATEMP));

				/* slurp in words till closing paren */
				while (token(CONTIN) == LWORD)
					XPput(args, yylval.cp);
				if (symbol != /*(*/ ')')
					syntaxerr(NULL);
				break;
			}

			afree(t, ATEMP);

			/*
			 * Check for "> foo (echo hi)" which AT&T ksh allows
			 * (not POSIX, but not disallowed)
			 */
			if (XPsize(args) == 0 && XPsize(vars) == 0) {
				ACCEPT;
				goto Subshell;
			}

			/* must be a function */
			if (iopn != 0 || XPsize(args) != 1 || XPsize(vars) != 0)
				syntaxerr(NULL);
			ACCEPT;
			musthave(/*(*/ ')', 0);
			t = function_body(XPptrv(args)[0],
			    sALIAS, false);
			break;
		}
		break;

	case ORD('(' /*)*/): {
		unsigned int subshell_nesting_type_saved;
 Subshell:
		subshell_nesting_type_saved = subshell_nesting_type;
		subshell_nesting_type = ORD(')');
		t = nested(TPAREN, ORD('('), ORD(')'), sALIAS);
		subshell_nesting_type = subshell_nesting_type_saved;
		break;
	    }

	case ORD('{' /*}*/):
		t = nested(TBRACE, ORD('{'), ORD('}'), sALIAS);
		break;

	case MDPAREN:
		/* leave KEYWORD in syniocf (allow if (( 1 )) then ...) */
		lno = source->line;
		ACCEPT;
		switch (token(LETEXPR)) {
		case LWORD:
			break;
		case ORD('(' /*)*/):
			c = ORD('(');
			goto Subshell;
		default:
			syntaxerr(NULL);
		}
		t = newtp(TCOM);
		t->lineno = lno;
		XPput(args, wdcopy(builtin_cmd, ATEMP));
		XPput(args, wdcopy(let_cmd, ATEMP));
		XPput(args, yylval.cp);
		break;

	case DBRACKET: /* [[ .. ]] */
		/* leave KEYWORD in syniocf (allow if [[ -n 1 ]] then ...) */
		t = newtp(TDBRACKET);
		ACCEPT;
		{
			Test_env te;

			te.flags = TEF_DBRACKET;
			te.pos.av = &args;
			te.isa = dbtestp_isa;
			te.getopnd = dbtestp_getopnd;
			te.eval = dbtestp_eval;
			te.error = dbtestp_error;

			test_parse(&te);
		}
		break;

	case FOR:
	case SELECT:
		t = newtp((c == FOR) ? TFOR : TSELECT);
		musthave(LWORD, CMDASN);
		if (!is_wdvarname(yylval.cp, true))
			yyerror("%s: bad identifier",
			    c == FOR ? "for" : Tselect);
		strdupx(t->str, ident, ATEMP);
		nesting_push(&old_nesting, c);
		t->vars = wordlist(sALIAS);
		t->left = dogroup(sALIAS);
		nesting_pop(&old_nesting);
		break;

	case WHILE:
	case UNTIL:
		nesting_push(&old_nesting, c);
		t = newtp((c == WHILE) ? TWHILE : TUNTIL);
		t->left = c_list(sALIAS, true);
		t->right = dogroup(sALIAS);
		nesting_pop(&old_nesting);
		break;

	case CASE:
		t = newtp(TCASE);
		musthave(LWORD, 0);
		t->str = yylval.cp;
		nesting_push(&old_nesting, c);
		t->left = caselist(sALIAS);
		nesting_pop(&old_nesting);
		break;

	case IF:
		nesting_push(&old_nesting, c);
		t = newtp(TIF);
		t->left = c_list(sALIAS, true);
		t->right = thenpart(sALIAS);
		musthave(FI, KEYWORD|sALIAS);
		nesting_pop(&old_nesting);
		break;

	case BANG:
		syniocf &= ~(KEYWORD|sALIAS);
		t = pipeline(0, sALIAS);
		if (t == NULL)
			syntaxerr(NULL);
		t = block(TBANG, NULL, t);
		break;

	case TIME:
		syniocf &= ~(KEYWORD|sALIAS);
		t = pipeline(0, sALIAS);
		if (t && t->type == TCOM) {
			t->str = alloc(2, ATEMP);
			/* TF_* flags */
			t->str[0] = '\0';
			t->str[1] = '\0';
		}
		t = block(TTIME, t, NULL);
		break;

	case FUNCTION:
		musthave(LWORD, 0);
		t = function_body(yylval.cp, sALIAS, true);
		break;
	}

	while ((iop = synio(syniocf)) != NULL) {
		if (iopn >= NUFILE)
			yyerror(Tf_toomany, Tredirection);
		iops[iopn++] = iop;
	}

	if (iopn == 0) {
		afree(iops, ATEMP);
		t->ioact = NULL;
	} else {
		iops[iopn++] = NULL;
		iops = aresize2(iops, iopn, sizeof(struct ioword *), ATEMP);
		t->ioact = iops;
	}

	if (t->type == TCOM || t->type == TDBRACKET) {
		XPput(args, NULL);
		t->args = (const char **)XPclose(args);
		XPput(vars, NULL);
		t->vars = (char **)XPclose(vars);
	} else {
		XPfree(args);
		XPfree(vars);
	}

	if (c == MDPAREN) {
		t = block(TBRACE, t, NULL);
		t->ioact = t->left->ioact;
		t->left->ioact = NULL;
	}

	return (t);
}

static struct op *
dogroup(int sALIAS)
{
	int c;
	struct op *list;

	c = token(CONTIN|KEYWORD|sALIAS);
	/*
	 * A {...} can be used instead of do...done for for/select loops
	 * but not for while/until loops - we don't need to check if it
	 * is a while loop because it would have been parsed as part of
	 * the conditional command list...
	 */
	if (c == DO)
		c = DONE;
	else if ((unsigned int)c == ORD('{'))
		c = ORD('}');
	else
		syntaxerr(NULL);
	list = c_list(sALIAS, true);
	musthave(c, KEYWORD|sALIAS);
	return (list);
}

static struct op *
thenpart(int sALIAS)
{
	struct op *t;

	musthave(THEN, KEYWORD|sALIAS);
	t = newtp(0);
	t->left = c_list(sALIAS, true);
	if (t->left == NULL)
		syntaxerr(NULL);
	t->right = elsepart(sALIAS);
	return (t);
}

static struct op *
elsepart(int sALIAS)
{
	struct op *t;

	switch (token(KEYWORD|sALIAS|CMDASN)) {
	case ELSE:
		if ((t = c_list(sALIAS, true)) == NULL)
			syntaxerr(NULL);
		return (t);

	case ELIF:
		t = newtp(TELIF);
		t->left = c_list(sALIAS, true);
		t->right = thenpart(sALIAS);
		return (t);

	default:
		REJECT;
	}
	return (NULL);
}

static struct op *
caselist(int sALIAS)
{
	struct op *t, *tl;
	int c;

	c = token(CONTIN|KEYWORD|sALIAS);
	/* A {...} can be used instead of in...esac for case statements */
	if (c == IN)
		c = ESAC;
	else if ((unsigned int)c == ORD('{'))
		c = ORD('}');
	else
		syntaxerr(NULL);
	t = tl = NULL;
	/* no ALIAS here */
	while ((tpeek(CONTIN|KEYWORD|ESACONLY)) != c) {
		struct op *tc = casepart(c, sALIAS);
		if (tl == NULL)
			t = tl = tc, tl->right = NULL;
		else
			tl->right = tc, tl = tc;
	}
	musthave(c, KEYWORD|sALIAS);
	return (t);
}

static struct op *
casepart(int endtok, int sALIAS)
{
	struct op *t;
	XPtrV ptns;

	XPinit(ptns, 16);
	t = newtp(TPAT);
	/* no ALIAS here */
	if ((unsigned int)token(CONTIN | KEYWORD) != ORD('('))
		REJECT;
	do {
		switch (token(0)) {
		case LWORD:
			break;
		case ORD('}'):
		case ESAC:
			if (symbol != endtok) {
				strdupx(yylval.cp, (unsigned int)symbol ==
				    ORD('}') ? Tcbrace : Tesac, ATEMP);
				break;
			}
			/* FALLTHROUGH */
		default:
			syntaxerr(NULL);
		}
		XPput(ptns, yylval.cp);
	} while (token(0) == '|');
	REJECT;
	XPput(ptns, NULL);
	t->vars = (char **)XPclose(ptns);
	musthave(ORD(')'), 0);

	t->left = c_list(sALIAS, true);

	/* initialise to default for ;; or omitted */
	t->u.charflag = ORD(';');
	/* SUSv4 requires the ;; except in the last casepart */
	if ((tpeek(CONTIN|KEYWORD|sALIAS)) != endtok)
		switch (symbol) {
		default:
			syntaxerr(NULL);
		case BRKEV:
			t->u.charflag = ORD('|');
			if (0)
				/* FALLTHROUGH */
		case BRKFT:
			  t->u.charflag = ORD('&');
			/* FALLTHROUGH */
		case BREAK:
			/* initialised above, but we need to eat the token */
			ACCEPT;
		}
	return (t);
}

static struct op *
function_body(char *name, int sALIAS,
    /* function foo { ... } vs foo() { .. } */
    bool ksh_func)
{
	char *sname, *p;
	struct op *t;

	sname = wdstrip(name, 0);
	/*-
	 * Check for valid characters in name. POSIX and AT&T ksh93 say
	 * only allow [a-zA-Z_0-9] but this allows more as old pdkshs
	 * have allowed more; the following were never allowed:
	 *	NUL TAB NL SP " $ & ' ( ) ; < = > \ ` |
	 * C_QUOTE|C_SPC covers all but adds # * ? [ ]
	 */
	for (p = sname; *p; p++)
		if (ctype(*p, C_QUOTE | C_SPC))
			yyerror(Tinvname, sname, Tfunction);

	/*
	 * Note that POSIX allows only compound statements after foo(),
	 * sh and AT&T ksh allow any command, go with the later since it
	 * shouldn't break anything. However, for function foo, AT&T ksh
	 * only accepts an open-brace.
	 */
	if (ksh_func) {
		if ((unsigned int)tpeek(CONTIN|KEYWORD|sALIAS) == ORD('(' /*)*/)) {
			/* function foo () { //}*/
			ACCEPT;
			musthave(ORD(/*(*/ ')'), 0);
			/* degrade to POSIX function */
			ksh_func = false;
		}
		musthave(ORD('{' /*}*/), CONTIN|KEYWORD|sALIAS);
		REJECT;
	}

	t = newtp(TFUNCT);
	t->str = sname;
	t->u.ksh_func = tobool(ksh_func);
	t->lineno = source->line;

	if ((t->left = get_command(CONTIN, sALIAS)) == NULL) {
		char *tv;
		/*
		 * Probably something like foo() followed by EOF or ';'.
		 * This is accepted by sh and ksh88.
		 * To make "typeset -f foo" work reliably (so its output can
		 * be used as input), we pretend there is a colon here.
		 */
		t->left = newtp(TCOM);
		/* (2 * sizeof(char *)) is small enough */
		t->left->args = alloc(2 * sizeof(char *), ATEMP);
		t->left->args[0] = tv = alloc(3, ATEMP);
		tv[0] = QCHAR;
		tv[1] = ':';
		tv[2] = EOS;
		t->left->args[1] = NULL;
		t->left->vars = alloc(sizeof(char *), ATEMP);
		t->left->vars[0] = NULL;
		t->left->lineno = 1;
	}

	return (t);
}

static char **
wordlist(int sALIAS)
{
	int c;
	XPtrV args;

	XPinit(args, 16);
	/* POSIX does not do alias expansion here... */
	if ((c = token(CONTIN|KEYWORD|sALIAS)) != IN) {
		if (c != ';')
			/* non-POSIX, but AT&T ksh accepts a ; here */
			REJECT;
		return (NULL);
	}
	while ((c = token(0)) == LWORD)
		XPput(args, yylval.cp);
	if (c != '\n' && c != ';')
		syntaxerr(NULL);
	XPput(args, NULL);
	return ((char **)XPclose(args));
}

/*
 * supporting functions
 */

static struct op *
block(int type, struct op *t1, struct op *t2)
{
	struct op *t;

	t = newtp(type);
	t->left = t1;
	t->right = t2;
	return (t);
}

static const struct tokeninfo {
	const char *name;
	short val;
	short reserved;
} tokentab[] = {
	/* Reserved words */
	{ "if",		IF,	true },
	{ "then",	THEN,	true },
	{ "else",	ELSE,	true },
	{ "elif",	ELIF,	true },
	{ "fi",		FI,	true },
	{ "case",	CASE,	true },
	{ Tesac,	ESAC,	true },
	{ "for",	FOR,	true },
	{ Tselect,	SELECT,	true },
	{ "while",	WHILE,	true },
	{ "until",	UNTIL,	true },
	{ "do",		DO,	true },
	{ "done",	DONE,	true },
	{ "in",		IN,	true },
	{ Tfunction,	FUNCTION, true },
	{ Ttime,	TIME,	true },
	{ "{",		ORD('{'), true },
	{ Tcbrace,	ORD('}'), true },
	{ "!",		BANG,	true },
	{ "[[",		DBRACKET, true },
	/* Lexical tokens (0[EOF], LWORD and REDIR handled specially) */
	{ "&&",		LOGAND,	false },
	{ "||",		LOGOR,	false },
	{ ";;",		BREAK,	false },
	{ ";|",		BRKEV,	false },
	{ ";&",		BRKFT,	false },
	{ "((",		MDPAREN, false },
	{ "|&",		COPROC,	false },
	/* and some special cases... */
	{ "newline",	ORD('\n'), false },
	{ NULL,		0,	false }
};

void
initkeywords(void)
{
	struct tokeninfo const *tt;
	struct tbl *p;

	ktinit(APERM, &keywords,
	    /* currently 28 keywords: 75% of 64 = 2^6 */
	    6);
	for (tt = tokentab; tt->name; tt++) {
		if (tt->reserved) {
			p = ktenter(&keywords, tt->name, hash(tt->name));
			p->flag |= DEFINED|ISSET;
			p->type = CKEYWD;
			p->val.i = tt->val;
		}
	}
}

static void
syntaxerr(const char *what)
{
	/* 23<<- is the longest redirection, I think */
	char redir[8];
	const char *s;
	struct tokeninfo const *tt;
	int c;

	if (!what)
		what = Tunexpected;
	REJECT;
	c = token(0);
 Again:
	switch (c) {
	case 0:
		if (nesting.start_token) {
			c = nesting.start_token;
			source->errline = nesting.start_line;
			what = "unmatched";
			goto Again;
		}
		/* don't quote the EOF */
		yyerror("%s: unexpected EOF", Tsynerr);
		/* NOTREACHED */

	case LWORD:
		s = snptreef(NULL, 32, Tf_S, yylval.cp);
		break;

	case REDIR:
		s = snptreef(redir, sizeof(redir), Tft_R, yylval.iop);
		break;

	default:
		for (tt = tokentab; tt->name; tt++)
			if (tt->val == c)
			    break;
		if (tt->name)
			s = tt->name;
		else {
			if (c > 0 && c < 256) {
				redir[0] = c;
				redir[1] = '\0';
			} else
				shf_snprintf(redir, sizeof(redir),
					"?%d", c);
			s = redir;
		}
	}
	yyerror(Tf_sD_s_qs, Tsynerr, what, s);
}

static void
nesting_push(struct nesting_state *save, int tok)
{
	*save = nesting;
	nesting.start_token = tok;
	nesting.start_line = source->line;
}

static void
nesting_pop(struct nesting_state *saved)
{
	nesting = *saved;
}

static struct op *
newtp(int type)
{
	struct op *t;

	t = alloc(sizeof(struct op), ATEMP);
	t->type = type;
	t->u.evalflags = 0;
	t->args = NULL;
	t->vars = NULL;
	t->ioact = NULL;
	t->left = t->right = NULL;
	t->str = NULL;
	return (t);
}

struct op *
compile(Source *s, bool skiputf8bom, bool doalias)
{
	nesting.start_token = 0;
	nesting.start_line = 0;
	herep = heres;
	source = s;
	if (skiputf8bom)
		yyskiputf8bom();
	yyparse(doalias);
	return (outtree);
}

/* Check if we are in the middle of reading an alias */
static int
inalias(struct source *s)
{
	while (s && s->type == SALIAS) {
		if (!(s->flags & SF_ALIASEND))
			return (1);
		s = s->next;
	}
	return (0);
}


/*
 * Order important - indexed by Test_meta values
 * Note that ||, &&, ( and ) can't appear in as unquoted strings
 * in normal shell input, so these can be interpreted unambiguously
 * in the evaluation pass.
 */
static const char dbtest_or[] = { CHAR, '|', CHAR, '|', EOS };
static const char dbtest_and[] = { CHAR, '&', CHAR, '&', EOS };
static const char dbtest_not[] = { CHAR, '!', EOS };
static const char dbtest_oparen[] = { CHAR, '(', EOS };
static const char dbtest_cparen[] = { CHAR, ')', EOS };
const char * const dbtest_tokens[] = {
	dbtest_or, dbtest_and, dbtest_not,
	dbtest_oparen, dbtest_cparen
};
static const char db_close[] = { CHAR, ']', CHAR, ']', EOS };
static const char db_lthan[] = { CHAR, '<', EOS };
static const char db_gthan[] = { CHAR, '>', EOS };

/*
 * Test if the current token is a whatever. Accepts the current token if
 * it is. Returns 0 if it is not, non-zero if it is (in the case of
 * TM_UNOP and TM_BINOP, the returned value is a Test_op).
 */
static Test_op
dbtestp_isa(Test_env *te, Test_meta meta)
{
	int c = tpeek(CMDASN | (meta == TM_BINOP ? 0 : CONTIN));
	bool uqword;
	char *save = NULL;
	Test_op ret = TO_NONOP;

	/* unquoted word? */
	uqword = c == LWORD && *ident;

	if (meta == TM_OR)
		ret = c == LOGOR ? TO_NONNULL : TO_NONOP;
	else if (meta == TM_AND)
		ret = c == LOGAND ? TO_NONNULL : TO_NONOP;
	else if (meta == TM_NOT)
		ret = (uqword && !strcmp(yylval.cp,
		    dbtest_tokens[(int)TM_NOT])) ? TO_NONNULL : TO_NONOP;
	else if (meta == TM_OPAREN)
		ret = (unsigned int)c == ORD('(') /*)*/ ? TO_NONNULL : TO_NONOP;
	else if (meta == TM_CPAREN)
		ret = (unsigned int)c == /*(*/ ORD(')') ? TO_NONNULL : TO_NONOP;
	else if (meta == TM_UNOP || meta == TM_BINOP) {
		if (meta == TM_BINOP && c == REDIR &&
		    (yylval.iop->ioflag == IOREAD ||
		    yylval.iop->ioflag == IOWRITE)) {
			ret = TO_NONNULL;
			save = wdcopy(yylval.iop->ioflag == IOREAD ?
			    db_lthan : db_gthan, ATEMP);
		} else if (uqword && (ret = test_isop(meta, ident)))
			save = yylval.cp;
	} else
		/* meta == TM_END */
		ret = (uqword && !strcmp(yylval.cp,
		    db_close)) ? TO_NONNULL : TO_NONOP;
	if (ret != TO_NONOP) {
		ACCEPT;
		if ((unsigned int)meta < NELEM(dbtest_tokens))
			save = wdcopy(dbtest_tokens[(int)meta], ATEMP);
		if (save)
			XPput(*te->pos.av, save);
	}
	return (ret);
}

static const char *
dbtestp_getopnd(Test_env *te, Test_op op MKSH_A_UNUSED,
    bool do_eval MKSH_A_UNUSED)
{
	int c = tpeek(CMDASN);

	if (c != LWORD)
		return (NULL);

	ACCEPT;
	XPput(*te->pos.av, yylval.cp);

	return (null);
}

static int
dbtestp_eval(Test_env *te MKSH_A_UNUSED, Test_op op MKSH_A_UNUSED,
    const char *opnd1 MKSH_A_UNUSED, const char *opnd2 MKSH_A_UNUSED,
    bool do_eval MKSH_A_UNUSED)
{
	return (1);
}

static void
dbtestp_error(Test_env *te, int offset, const char *msg)
{
	te->flags |= TEF_ERROR;

	if (offset < 0) {
		REJECT;
		/* Kludgy to say the least... */
		symbol = LWORD;
		yylval.cp = *(XPptrv(*te->pos.av) + XPsize(*te->pos.av) +
		    offset);
	}
	syntaxerr(msg);
}

#if HAVE_SELECT

#ifndef EOVERFLOW
#ifdef ERANGE
#define EOVERFLOW	ERANGE
#else
#define EOVERFLOW	EINVAL
#endif
#endif

bool
parse_usec(const char *s, struct timeval *tv)
{
	struct timeval tt;
	int i;

	tv->tv_sec = 0;
	/* parse integral part */
	while (ctype(*s, C_DIGIT)) {
		tt.tv_sec = tv->tv_sec * 10 + ksh_numdig(*s++);
		/*XXX this overflow check maybe UB */
		if (tt.tv_sec / 10 != tv->tv_sec) {
			errno = EOVERFLOW;
			return (true);
		}
		tv->tv_sec = tt.tv_sec;
	}

	tv->tv_usec = 0;
	if (!*s)
		/* no decimal fraction */
		return (false);
	else if (*s++ != '.') {
		/* junk after integral part */
		errno = EINVAL;
		return (true);
	}

	/* parse decimal fraction */
	i = 100000;
	while (ctype(*s, C_DIGIT)) {
		tv->tv_usec += i * ksh_numdig(*s++);
		if (i == 1)
			break;
		i /= 10;
	}
	/* check for junk after fractional part */
	while (ctype(*s, C_DIGIT))
		++s;
	if (*s) {
		errno = EINVAL;
		return (true);
	}

	/* end of input string reached, no errors */
	return (false);
}
#endif

/*
 * Helper function called from within lex.c:yylex() to parse
 * a COMSUB recursively using the main shell parser and lexer
 */
char *
yyrecursive(int subtype)
{
	struct op *t;
	char *cp;
	struct yyrecursive_state *ys;
	unsigned int stok, etok;

	if (subtype != COMSUB) {
		stok = ORD('{');
		etok = ORD('}');
	} else {
		stok = ORD('(');
		etok = ORD(')');
	}

	ys = alloc(sizeof(struct yyrecursive_state), ATEMP);

	/* tell the lexer to accept a closing parenthesis as EOD */
	ys->old_nesting_type = subshell_nesting_type;
	subshell_nesting_type = etok;

	/* push reject state, parse recursively, pop reject state */
	ys->old_reject = reject;
	ys->old_symbol = symbol;
	ACCEPT;
	memcpy(ys->old_heres, heres, sizeof(heres));
	ys->old_herep = herep;
	herep = heres;
	ys->next = e->yyrecursive_statep;
	e->yyrecursive_statep = ys;
	/* we use TPAREN as a helper container here */
	t = nested(TPAREN, stok, etok, ALIAS);
	yyrecursive_pop(false);

	/* t->left because nested(TPAREN, ...) hides our goodies there */
	cp = snptreef(NULL, 0, Tf_T, t->left);
	tfree(t, ATEMP);

	return (cp);
}

void
yyrecursive_pop(bool popall)
{
	struct yyrecursive_state *ys;

 popnext:
	if (!(ys = e->yyrecursive_statep))
		return;
	e->yyrecursive_statep = ys->next;

	memcpy(heres, ys->old_heres, sizeof(heres));
	herep = ys->old_herep;
	reject = ys->old_reject;
	symbol = ys->old_symbol;

	subshell_nesting_type = ys->old_nesting_type;

	afree(ys, ATEMP);
	if (popall)
		goto popnext;
}
