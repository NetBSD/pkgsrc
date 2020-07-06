/*	$OpenBSD: expr.c,v 1.24 2014/12/08 14:26:31 otto Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *		 2011, 2012, 2013, 2014, 2016, 2017, 2018, 2019
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

__RCSID("$MirOS: src/bin/mksh/expr.c,v 1.107 2020/03/27 02:49:40 tg Exp $");

#define EXPRTOK_DEFNS
#include "exprtok.h"

/* precisions; used to be enum prec but we do arithmetics on it */
#define P_PRIMARY	0	/* VAR, LIT, (), ! ~ ++ -- */
#define P_MULT		1	/* * / % */
#define P_ADD		2	/* + - */
#define P_SHIFT		3	/* ^< ^> << >> */
#define P_RELATION	4	/* < <= > >= */
#define P_EQUALITY	5	/* == != */
#define P_BAND		6	/* & */
#define P_BXOR		7	/* ^ */
#define P_BOR		8	/* | */
#define P_LAND		9	/* && */
#define P_LOR		10	/* || */
#define P_TERN		11	/* ?: */
	/* = += -= *= /= %= ^<= ^>= <<= >>= &= ^= |= */
#define P_ASSIGN	12
#define P_COMMA		13	/* , */
#define MAX_PREC	P_COMMA

enum token {
#define EXPRTOK_ENUM
#include "exprtok.h"
};

static const char opname[][4] = {
#define EXPRTOK_NAME
#include "exprtok.h"
};

static const uint8_t oplen[] = {
#define EXPRTOK_LEN
#include "exprtok.h"
};

static const uint8_t opprec[] = {
#define EXPRTOK_PREC
#include "exprtok.h"
};

typedef struct expr_state {
	/* expression being evaluated */
	const char *expression;
	/* lexical position */
	const char *tokp;
	/* value from token() */
	struct tbl *val;
	/* variable that is being recursively expanded (EXPRINEVAL flag set) */
	struct tbl *evaling;
	/* token from token() */
	enum token tok;
	/* don't do assignments (for ?:, &&, ||) */
	uint8_t noassign;
	/* evaluating an $(()) expression? */
	bool arith;
	/* unsigned arithmetic calculation */
	bool natural;
} Expr_state;

enum error_type {
	ET_UNEXPECTED, ET_BADLIT, ET_RECURSIVE,
	ET_LVALUE, ET_RDONLY, ET_STR
};

static void evalerr(Expr_state *, enum error_type, const char *)
    MKSH_A_NORETURN;
static struct tbl *evalexpr(Expr_state *, unsigned int);
static void exprtoken(Expr_state *);
static struct tbl *do_ppmm(Expr_state *, enum token, struct tbl *, bool);
static void assign_check(Expr_state *, enum token, struct tbl *);
static struct tbl *intvar(Expr_state *, struct tbl *);

/*
 * parse and evaluate expression
 */
int
evaluate(const char *expr, mksh_ari_t *rval, int error_ok, bool arith)
{
	struct tbl v;
	int ret;

	v.flag = DEFINED | INTEGER;
	v.type = 0;
	ret = v_evaluate(&v, expr, error_ok, arith);
	*rval = v.val.i;
	return (ret);
}

/*
 * parse and evaluate expression, storing result in vp.
 */
int
v_evaluate(struct tbl *vp, const char *expr, volatile int error_ok,
    bool arith)
{
	struct tbl *v;
	Expr_state curstate;
	Expr_state * const es = &curstate;
	int i;

	/* save state to allow recursive calls */
	memset(&curstate, 0, sizeof(curstate));
	curstate.expression = curstate.tokp = expr;
	curstate.tok = BAD;
	curstate.arith = arith;

	newenv(E_ERRH);
	if ((i = kshsetjmp(e->jbuf))) {
		/* Clear EXPRINEVAL in of any variables we were playing with */
		if (curstate.evaling)
			curstate.evaling->flag &= ~EXPRINEVAL;
		quitenv(NULL);
		if (i == LAEXPR) {
			if (error_ok == KSH_RETURN_ERROR)
				return (0);
			errorfz();
		}
		unwind(i);
		/* NOTREACHED */
	}

	exprtoken(es);
	if (es->tok == END) {
		es->tok = LIT;
		es->val = tempvar("");
	}
	v = intvar(es, evalexpr(es, MAX_PREC));

	if (es->tok != END)
		evalerr(es, ET_UNEXPECTED, NULL);

	if (es->arith && es->natural)
		vp->flag |= INT_U;
	if (vp->flag & INTEGER)
		setint_v(vp, v, es->arith);
	else
		/* can fail if readonly */
		setstr(vp, str_val(v), error_ok);

	quitenv(NULL);

	return (1);
}

static void
evalerr(Expr_state *es, enum error_type type, const char *str)
{
	char tbuf[2];
	const char *s;

	es->arith = false;
	switch (type) {
	case ET_UNEXPECTED:
		switch (es->tok) {
		case VAR:
			s = es->val->name;
			break;
		case LIT:
			s = str_val(es->val);
			break;
		case END:
			s = "end of expression";
			break;
		case BAD:
			tbuf[0] = *es->tokp;
			tbuf[1] = '\0';
			s = tbuf;
			break;
		default:
			s = opname[(int)es->tok];
		}
		warningf(true, Tf_sD_s_qs, es->expression,
		    Tunexpected, s);
		break;

	case ET_BADLIT:
		warningf(true, Tf_sD_s_qs, es->expression,
		    Tbadnum, str);
		break;

	case ET_RECURSIVE:
		warningf(true, Tf_sD_s_qs, es->expression,
		    "expression recurses on parameter", str);
		break;

	case ET_LVALUE:
		warningf(true, Tf_sD_s_s,
		    es->expression, str, "requires lvalue");
		break;

	case ET_RDONLY:
		warningf(true, Tf_sD_s_s,
		    es->expression, str, "applied to read-only variable");
		break;

	default: /* keep gcc happy */
	case ET_STR:
		warningf(true, Tf_sD_s, es->expression, str);
		break;
	}
	unwind(LAEXPR);
}

/* do a ++ or -- operation */
static struct tbl *
do_ppmm(Expr_state *es, enum token op, struct tbl *vasn, bool is_prefix)
{
	struct tbl *vl;
	mksh_uari_t oval;

	assign_check(es, op, vasn);

	vl = intvar(es, vasn);
	oval = vl->val.u;
	if (op == O_PLUSPLUS)
		++vl->val.u;
	else
		--vl->val.u;
	if (!es->noassign) {
		if (vasn->flag & INTEGER)
			setint_v(vasn, vl, es->arith);
		else
			setint(vasn, vl->val.i);
	}
	if (!is_prefix)
		/* undo the increment/decrement */
		vl->val.u = oval;

	return (vl);
}

static struct tbl *
evalexpr(Expr_state *es, unsigned int prec)
{
	struct tbl *vl, *vr = NULL, *vasn;
	enum token op;
	mksh_uari_t res = 0, t1, t2, t3;

	if (prec == P_PRIMARY) {
		switch ((int)(op = es->tok)) {
		case O_BNOT:
		case O_LNOT:
		case O_MINUS:
		case O_PLUS:
			exprtoken(es);
			vl = intvar(es, evalexpr(es, P_PRIMARY));
			switch ((int)op) {
			case O_BNOT:
				vl->val.u = ~vl->val.u;
				break;
			case O_LNOT:
				vl->val.u = !vl->val.u;
				break;
			case O_MINUS:
				vl->val.u = -vl->val.u;
				break;
			case O_PLUS:
				/* nop */
				break;
			}
			break;

		case OPEN_PAREN:
			exprtoken(es);
			vl = evalexpr(es, MAX_PREC);
			if (es->tok != CLOSE_PAREN)
				evalerr(es, ET_STR, "missing )");
			exprtoken(es);
			break;

		case O_PLUSPLUS:
		case O_MINUSMINUS:
			exprtoken(es);
			vl = do_ppmm(es, op, es->val, true);
			exprtoken(es);
			break;

		case VAR:
		case LIT:
			vl = es->val;
			exprtoken(es);
			break;

		default:
			evalerr(es, ET_UNEXPECTED, NULL);
			/* NOTREACHED */
		}

		if (es->tok == O_PLUSPLUS || es->tok == O_MINUSMINUS) {
			vl = do_ppmm(es, es->tok, vl, false);
			exprtoken(es);
		}

		return (vl);
		/* prec == P_PRIMARY */
	}

	vl = evalexpr(es, prec - 1);
	while ((int)(op = es->tok) >= (int)O_EQ && (int)op <= (int)O_COMMA &&
	    opprec[(int)op] == prec) {
		switch ((int)op) {
		case O_TERN:
		case O_LAND:
		case O_LOR:
			break;
		default:
			exprtoken(es);
		}

		vasn = vl;
		if (op != O_ASN)
			/* vl may not have a value yet */
			vl = intvar(es, vl);
		if (IS_ASSIGNOP(op)) {
			if (!es->noassign)
				assign_check(es, op, vasn);
			vr = intvar(es, evalexpr(es, P_ASSIGN));
		} else if (op == O_TERN) {
			bool ev = vl->val.u != 0;

			if (!ev)
				es->noassign++;
			exprtoken(es);
			vl = evalexpr(es, MAX_PREC);
			if (!ev)
				es->noassign--;
			if (es->tok != CTERN)
				evalerr(es, ET_STR, "missing :");
			if (ev)
				es->noassign++;
			exprtoken(es);
			vr = evalexpr(es, P_TERN);
			if (ev)
				es->noassign--;
			vl = ev ? vl : vr;
			continue;
		} else if (op != O_LAND && op != O_LOR)
			vr = intvar(es, evalexpr(es, prec - 1));

		/* common ops setup */
		switch ((int)op) {
		case O_DIV:
		case O_DIVASN:
		case O_MOD:
		case O_MODASN:
			if (vr->val.u == 0) {
				if (!es->noassign)
					evalerr(es, ET_STR, "zero divisor");
				vr->val.u = 1;
			}
			/* calculate the absolute values */
			t1 = vl->val.i < 0 ? -vl->val.u : vl->val.u;
			t2 = vr->val.i < 0 ? -vr->val.u : vr->val.u;
			break;
#ifndef MKSH_LEGACY_MODE
		case O_LSHIFT:
		case O_LSHIFTASN:
		case O_RSHIFT:
		case O_RSHIFTASN:
		case O_ROL:
		case O_ROLASN:
		case O_ROR:
		case O_RORASN:
			t1 = vl->val.u;
			t2 = vr->val.u & 31;
			break;
#endif
		case O_LAND:
		case O_LOR:
			t1 = vl->val.u;
			t2 = 0;	/* gcc */
			break;
		default:
			t1 = vl->val.u;
			t2 = vr->val.u;
			break;
		}

#define cmpop(op)	(es->natural ?			\
	(mksh_uari_t)(vl->val.u op vr->val.u) :		\
	(mksh_uari_t)(vl->val.i op vr->val.i)		\
)

		/* op calculation */
		switch ((int)op) {
		case O_TIMES:
		case O_TIMESASN:
			res = t1 * t2;
			break;
		case O_MOD:
		case O_MODASN:
			if (es->natural) {
				res = vl->val.u % vr->val.u;
				break;
			}
			goto signed_division;
		case O_DIV:
		case O_DIVASN:
			if (es->natural) {
				res = vl->val.u / vr->val.u;
				break;
			}
 signed_division:
			/*
			 * a / b = abs(a) / abs(b) * sgn((u)a^(u)b)
			 */
			t3 = t1 / t2;
#ifndef MKSH_LEGACY_MODE
			res = ((vl->val.u ^ vr->val.u) & 0x80000000) ? -t3 : t3;
#else
			res = ((t1 == vl->val.u ? 0 : 1) ^
			    (t2 == vr->val.u ? 0 : 1)) ? -t3 : t3;
#endif
			if (op == O_MOD || op == O_MODASN) {
				/*
				 * primitive modulo, to get the sign of
				 * the result correct:
				 * (a % b) = a - ((a / b) * b)
				 * the subtraction and multiplication
				 * are, amazingly enough, sign ignorant
				 */
				res = vl->val.u - (res * vr->val.u);
			}
			break;
		case O_PLUS:
		case O_PLUSASN:
			res = t1 + t2;
			break;
		case O_MINUS:
		case O_MINUSASN:
			res = t1 - t2;
			break;
#ifndef MKSH_LEGACY_MODE
		case O_ROL:
		case O_ROLASN:
			res = (t1 << t2) | (t1 >> (32 - t2));
			break;
		case O_ROR:
		case O_RORASN:
			res = (t1 >> t2) | (t1 << (32 - t2));
			break;
#endif
		case O_LSHIFT:
		case O_LSHIFTASN:
			res = t1 << t2;
			break;
		case O_RSHIFT:
		case O_RSHIFTASN:
			res = es->natural || vl->val.i >= 0 ?
			    t1 >> t2 :
			    ~(~t1 >> t2);
			break;
		case O_LT:
			res = cmpop(<);
			break;
		case O_LE:
			res = cmpop(<=);
			break;
		case O_GT:
			res = cmpop(>);
			break;
		case O_GE:
			res = cmpop(>=);
			break;
		case O_EQ:
			res = t1 == t2;
			break;
		case O_NE:
			res = t1 != t2;
			break;
		case O_BAND:
		case O_BANDASN:
			res = t1 & t2;
			break;
		case O_BXOR:
		case O_BXORASN:
			res = t1 ^ t2;
			break;
		case O_BOR:
		case O_BORASN:
			res = t1 | t2;
			break;
		case O_LAND:
			if (!t1)
				es->noassign++;
			exprtoken(es);
			vr = intvar(es, evalexpr(es, prec - 1));
			res = t1 && vr->val.u;
			if (!t1)
				es->noassign--;
			break;
		case O_LOR:
			if (t1)
				es->noassign++;
			exprtoken(es);
			vr = intvar(es, evalexpr(es, prec - 1));
			res = t1 || vr->val.u;
			if (t1)
				es->noassign--;
			break;
		case O_ASN:
		case O_COMMA:
			res = t2;
			break;
		}

#undef cmpop

		if (IS_ASSIGNOP(op)) {
			vr->val.u = res;
			if (!es->noassign) {
				if (vasn->flag & INTEGER)
					setint_v(vasn, vr, es->arith);
				else
					setint(vasn, vr->val.i);
			}
			vl = vr;
		} else
			vl->val.u = res;
	}
	return (vl);
}

static void
exprtoken(Expr_state *es)
{
	const char *cp = es->tokp;
	int c;
	char *tvar;

	/* skip whitespace */
 skip_spaces:
	--cp;
	do {
		c = ord(*++cp);
	} while (ctype(c, C_SPACE));
	if (es->tokp == es->expression && (unsigned int)c == ORD('#')) {
		/* expression begins with # */
		/* switch to unsigned */
		es->natural = true;
		++cp;
		goto skip_spaces;
	}
	es->tokp = cp;

	if (c == '\0')
		es->tok = END;
	else if (ctype(c, C_ALPHX)) {
		do {
			c = ord(*++cp);
		} while (ctype(c, C_ALNUX));
		if ((unsigned int)c == ORD('[')) {
			size_t len;

			len = array_ref_len(cp);
			if (len == 0)
				evalerr(es, ET_STR, "missing ]");
			cp += len;
		}
		if (es->noassign) {
			es->val = tempvar("");
			es->val->flag |= EXPRLVALUE;
		} else {
			strndupx(tvar, es->tokp, cp - es->tokp, ATEMP);
			es->val = global(tvar);
			afree(tvar, ATEMP);
		}
		es->tok = VAR;
	} else if (c == '1' && cp[1] == '#') {
		cp += 2;
		if (*cp)
			cp += utf_ptradj(cp);
		strndupx(tvar, es->tokp, cp - es->tokp, ATEMP);
		goto process_tvar;
#ifndef MKSH_SMALL
	} else if (c == '\'') {
		if (*++cp == '\0') {
			es->tok = END;
			evalerr(es, ET_UNEXPECTED, NULL);
		}
		cp += utf_ptradj(cp);
		if (*cp++ != '\'')
			evalerr(es, ET_STR,
			    "multi-character character constant");
		/* 'x' -> 1#x (x = one multibyte character) */
		c = cp - es->tokp;
		tvar = alloc(c + /* NUL */ 1, ATEMP);
		tvar[0] = '1';
		tvar[1] = '#';
		memcpy(tvar + 2, es->tokp + 1, c - 2);
		tvar[c] = '\0';
		goto process_tvar;
#endif
	} else if (ctype(c, C_DIGIT)) {
		while (ctype(c, C_ALNUM | C_HASH))
			c = ord(*cp++);
		strndupx(tvar, es->tokp, --cp - es->tokp, ATEMP);
 process_tvar:
		es->val = tempvar("");
		es->val->flag &= ~INTEGER;
		es->val->type = 0;
		es->val->val.s = tvar;
		if (setint_v(es->val, es->val, es->arith) == NULL)
			evalerr(es, ET_BADLIT, tvar);
		afree(tvar, ATEMP);
		es->tok = LIT;
	} else {
		int i, n0;

		for (i = 0; (n0 = ord(opname[i][0])); i++)
			if (c == n0 && strncmp(cp, opname[i],
			    (size_t)oplen[i]) == 0) {
				es->tok = (enum token)i;
				cp += oplen[i];
				break;
			}
		if (!n0)
			es->tok = BAD;
	}
	es->tokp = cp;
}

static void
assign_check(Expr_state *es, enum token op, struct tbl *vasn)
{
	if (es->tok == END || !vasn ||
	    (vasn->name[0] == '\0' && !(vasn->flag & EXPRLVALUE)))
		evalerr(es, ET_LVALUE, opname[(int)op]);
	else if (vasn->flag & RDONLY)
		evalerr(es, ET_RDONLY, opname[(int)op]);
}

struct tbl *
tempvar(const char *vname)
{
	struct tbl *vp;
	size_t vsize;

	vsize = strlen(vname) + 1;
	vp = alloc(offsetof(struct tbl, name[0]) + vsize, ATEMP);
	memcpy(vp->name, vname, vsize);
	vp->flag = ISSET|INTEGER;
	vp->type = 0;
	vp->areap = ATEMP;
	vp->ua.hval = 0;
	vp->val.i = 0;
	return (vp);
}

/* cast (string) variable to temporary integer variable */
static struct tbl *
intvar(Expr_state *es, struct tbl *vp)
{
	struct tbl *vq;

	/* try to avoid replacing a temp var with another temp var */
	if (vp->name[0] == '\0' &&
	    (vp->flag & (ISSET|INTEGER|EXPRLVALUE)) == (ISSET|INTEGER))
		return (vp);

	vq = tempvar("");
	if (setint_v(vq, vp, es->arith) == NULL) {
		if (vp->flag & EXPRINEVAL)
			evalerr(es, ET_RECURSIVE, vp->name);
		es->evaling = vp;
		vp->flag |= EXPRINEVAL;
		v_evaluate(vq, str_val(vp), KSH_UNWIND_ERROR, es->arith);
		vp->flag &= ~EXPRINEVAL;
		es->evaling = NULL;
	}
	return (vq);
}


/*
 * UTF-8 support code: high-level functions
 */

int
utf_widthadj(const char *src, const char **dst)
{
	size_t len;
	unsigned int wc;
	int width;

	if (!UTFMODE || (len = utf_mbtowc(&wc, src)) == (size_t)-1 ||
	    wc == 0)
		len = width = 1;
	else if ((width = utf_wcwidth(wc)) < 0)
		/* XXX use 2 for x_zotc3 here? */
		width = 1;

	if (dst)
		*dst = src + len;
	return (width);
}

size_t
utf_mbswidth(const char *s)
{
	size_t len, width = 0;
	unsigned int wc;
	int cw;

	if (!UTFMODE)
		return (strlen(s));

	while (*s)
		if (((len = utf_mbtowc(&wc, s)) == (size_t)-1) ||
		    ((cw = utf_wcwidth(wc)) == -1)) {
			s++;
			width += 1;
		} else {
			s += len;
			width += cw;
		}
	return (width);
}

const char *
utf_skipcols(const char *p, int cols, int *colp)
{
	int c = 0;
	const char *q;

	while (c < cols) {
		if (!*p) {
			/* end of input; special handling for edit.c */
			if (!colp)
				return (p + cols - c);
			*colp = c;
			return (p);
		}
		c += utf_widthadj(p, &p);
	}
	if (UTFMODE)
		while (utf_widthadj(p, &q) == 0)
			p = q;
	if (colp)
		*colp = c;
	return (p);
}

size_t
utf_ptradj(const char *src)
{
	register size_t n;

	if (!UTFMODE || rtt2asc(*src) < 0xC2 ||
	    (n = utf_mbtowc(NULL, src)) == (size_t)-1)
		n = 1;
	return (n);
}

/*
 * UTF-8 support code: low-level functions
 */

/* CESU-8 multibyte and wide character conversion crafted for mksh */

size_t
utf_mbtowc(unsigned int *dst, const char *src)
{
	const unsigned char *s = (const unsigned char *)src;
	unsigned int c, wc;

	if ((wc = ord(rtt2asc(*s++))) < 0x80) {
 out:
		if (dst != NULL)
			*dst = wc;
		return (wc ? ((const char *)s - src) : 0);
	}
	if (wc < 0xC2 || wc >= 0xF0)
		/* < 0xC0: spurious second byte */
		/* < 0xC2: non-minimalistic mapping error in 2-byte seqs */
		/* > 0xEF: beyond BMP */
		goto ilseq;

	if (wc < 0xE0) {
		wc = (wc & 0x1F) << 6;
		if (((c = ord(rtt2asc(*s++))) & 0xC0) != 0x80)
			goto ilseq;
		wc |= c & 0x3F;
		goto out;
	}

	wc = (wc & 0x0F) << 12;

	if (((c = ord(rtt2asc(*s++))) & 0xC0) != 0x80)
		goto ilseq;
	wc |= (c & 0x3F) << 6;

	if (((c = ord(rtt2asc(*s++))) & 0xC0) != 0x80)
		goto ilseq;
	wc |= c & 0x3F;

	/* Check for non-minimalistic mapping error in 3-byte seqs */
	if (wc >= 0x0800 && wc <= 0xFFFD)
		goto out;
 ilseq:
	return ((size_t)(-1));
}

size_t
utf_wctomb(char *dst, unsigned int wc)
{
	unsigned char *d;

	if (wc < 0x80) {
		*dst = asc2rtt(wc);
		return (1);
	}

	d = (unsigned char *)dst;
	if (wc < 0x0800)
		*d++ = asc2rtt((wc >> 6) | 0xC0);
	else {
		*d++ = asc2rtt(((wc = wc > 0xFFFD ? 0xFFFD : wc) >> 12) | 0xE0);
		*d++ = asc2rtt(((wc >> 6) & 0x3F) | 0x80);
	}
	*d++ = asc2rtt((wc & 0x3F) | 0x80);
	return ((char *)d - dst);
}

/*
 * Wrapper around access(2) because it says root can execute everything
 * on some operating systems. Does not set errno, no user needs it. Use
 * this iff mode can have the X_OK bit set, access otherwise.
 */
int
ksh_access(const char *fn, int mode)
{
#ifdef __OS2__
	return (access_ex(access, fn, mode));
#else
	int rv;
	struct stat sb;

	if ((rv = access(fn, mode)) == 0 && (mode & X_OK) &&
	    (kshuid == 0 || ksheuid == 0) &&
	    (rv = stat(fn, &sb)) == 0 && !S_ISDIR(sb.st_mode) &&
	    (sb.st_mode & (S_IXUSR|S_IXGRP|S_IXOTH)) == 0)
		rv = -1;

	return (rv);
#endif
}

#ifndef MIRBSD_BOOTFLOPPY
/* From: X11/xc/programs/xterm/wcwidth.c,v 1.10 */

struct mb_ucsrange {
	unsigned short beg;
	unsigned short end;
};

static int mb_ucsbsearch(const struct mb_ucsrange arr[], size_t elems,
    unsigned int val) MKSH_A_PURE;

/*
 * Generated from the UCD 13.0.0 by
 * MirOS: contrib/code/Snippets/eawparse,v 1.14 2020/03/27 01:33:21 tg Exp $
 */

/*-
 * Parts Copyright © 1991–2020 Unicode, Inc. All rights reserved.
 * Distributed under the Terms of Use in
 *     https://www.unicode.org/copyright.html.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of the Unicode data files and any associated documentation
 * (the "Data Files") or Unicode software and any associated documentation
 * (the "Software") to deal in the Data Files or Software
 * without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, and/or sell copies of
 * the Data Files or Software, and to permit persons to whom the Data Files
 * or Software are furnished to do so, provided that either
 * (a) this copyright and permission notice appear with all copies
 * of the Data Files or Software, or
 * (b) this copyright and permission notice appear in associated
 * Documentation.
 *
 * THE DATA FILES AND SOFTWARE ARE PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT OF THIRD PARTY RIGHTS.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS
 * NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL
 * DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THE DATA FILES OR SOFTWARE.
 *
 * Except as contained in this notice, the name of a copyright holder
 * shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in these Data Files or Software without prior
 * written authorization of the copyright holder.
 */

static const struct mb_ucsrange mb_ucs_combining[] = {
	{ 0x0300, 0x036F },
	{ 0x0483, 0x0489 },
	{ 0x0591, 0x05BD },
	{ 0x05BF, 0x05BF },
	{ 0x05C1, 0x05C2 },
	{ 0x05C4, 0x05C5 },
	{ 0x05C7, 0x05C7 },
	{ 0x0610, 0x061A },
	{ 0x061C, 0x061C },
	{ 0x064B, 0x065F },
	{ 0x0670, 0x0670 },
	{ 0x06D6, 0x06DC },
	{ 0x06DF, 0x06E4 },
	{ 0x06E7, 0x06E8 },
	{ 0x06EA, 0x06ED },
	{ 0x0711, 0x0711 },
	{ 0x0730, 0x074A },
	{ 0x07A6, 0x07B0 },
	{ 0x07EB, 0x07F3 },
	{ 0x07FD, 0x07FD },
	{ 0x0816, 0x0819 },
	{ 0x081B, 0x0823 },
	{ 0x0825, 0x0827 },
	{ 0x0829, 0x082D },
	{ 0x0859, 0x085B },
	{ 0x08D3, 0x08E1 },
	{ 0x08E3, 0x0902 },
	{ 0x093A, 0x093A },
	{ 0x093C, 0x093C },
	{ 0x0941, 0x0948 },
	{ 0x094D, 0x094D },
	{ 0x0951, 0x0957 },
	{ 0x0962, 0x0963 },
	{ 0x0981, 0x0981 },
	{ 0x09BC, 0x09BC },
	{ 0x09C1, 0x09C4 },
	{ 0x09CD, 0x09CD },
	{ 0x09E2, 0x09E3 },
	{ 0x09FE, 0x09FE },
	{ 0x0A01, 0x0A02 },
	{ 0x0A3C, 0x0A3C },
	{ 0x0A41, 0x0A42 },
	{ 0x0A47, 0x0A48 },
	{ 0x0A4B, 0x0A4D },
	{ 0x0A51, 0x0A51 },
	{ 0x0A70, 0x0A71 },
	{ 0x0A75, 0x0A75 },
	{ 0x0A81, 0x0A82 },
	{ 0x0ABC, 0x0ABC },
	{ 0x0AC1, 0x0AC5 },
	{ 0x0AC7, 0x0AC8 },
	{ 0x0ACD, 0x0ACD },
	{ 0x0AE2, 0x0AE3 },
	{ 0x0AFA, 0x0AFF },
	{ 0x0B01, 0x0B01 },
	{ 0x0B3C, 0x0B3C },
	{ 0x0B3F, 0x0B3F },
	{ 0x0B41, 0x0B44 },
	{ 0x0B4D, 0x0B4D },
	{ 0x0B55, 0x0B56 },
	{ 0x0B62, 0x0B63 },
	{ 0x0B82, 0x0B82 },
	{ 0x0BC0, 0x0BC0 },
	{ 0x0BCD, 0x0BCD },
	{ 0x0C00, 0x0C00 },
	{ 0x0C04, 0x0C04 },
	{ 0x0C3E, 0x0C40 },
	{ 0x0C46, 0x0C48 },
	{ 0x0C4A, 0x0C4D },
	{ 0x0C55, 0x0C56 },
	{ 0x0C62, 0x0C63 },
	{ 0x0C81, 0x0C81 },
	{ 0x0CBC, 0x0CBC },
	{ 0x0CBF, 0x0CBF },
	{ 0x0CC6, 0x0CC6 },
	{ 0x0CCC, 0x0CCD },
	{ 0x0CE2, 0x0CE3 },
	{ 0x0D00, 0x0D01 },
	{ 0x0D3B, 0x0D3C },
	{ 0x0D41, 0x0D44 },
	{ 0x0D4D, 0x0D4D },
	{ 0x0D62, 0x0D63 },
	{ 0x0D81, 0x0D81 },
	{ 0x0DCA, 0x0DCA },
	{ 0x0DD2, 0x0DD4 },
	{ 0x0DD6, 0x0DD6 },
	{ 0x0E31, 0x0E31 },
	{ 0x0E34, 0x0E3A },
	{ 0x0E47, 0x0E4E },
	{ 0x0EB1, 0x0EB1 },
	{ 0x0EB4, 0x0EBC },
	{ 0x0EC8, 0x0ECD },
	{ 0x0F18, 0x0F19 },
	{ 0x0F35, 0x0F35 },
	{ 0x0F37, 0x0F37 },
	{ 0x0F39, 0x0F39 },
	{ 0x0F71, 0x0F7E },
	{ 0x0F80, 0x0F84 },
	{ 0x0F86, 0x0F87 },
	{ 0x0F8D, 0x0F97 },
	{ 0x0F99, 0x0FBC },
	{ 0x0FC6, 0x0FC6 },
	{ 0x102D, 0x1030 },
	{ 0x1032, 0x1037 },
	{ 0x1039, 0x103A },
	{ 0x103D, 0x103E },
	{ 0x1058, 0x1059 },
	{ 0x105E, 0x1060 },
	{ 0x1071, 0x1074 },
	{ 0x1082, 0x1082 },
	{ 0x1085, 0x1086 },
	{ 0x108D, 0x108D },
	{ 0x109D, 0x109D },
	{ 0x1160, 0x11FF },
	{ 0x135D, 0x135F },
	{ 0x1712, 0x1714 },
	{ 0x1732, 0x1734 },
	{ 0x1752, 0x1753 },
	{ 0x1772, 0x1773 },
	{ 0x17B4, 0x17B5 },
	{ 0x17B7, 0x17BD },
	{ 0x17C6, 0x17C6 },
	{ 0x17C9, 0x17D3 },
	{ 0x17DD, 0x17DD },
	{ 0x180B, 0x180E },
	{ 0x1885, 0x1886 },
	{ 0x18A9, 0x18A9 },
	{ 0x1920, 0x1922 },
	{ 0x1927, 0x1928 },
	{ 0x1932, 0x1932 },
	{ 0x1939, 0x193B },
	{ 0x1A17, 0x1A18 },
	{ 0x1A1B, 0x1A1B },
	{ 0x1A56, 0x1A56 },
	{ 0x1A58, 0x1A5E },
	{ 0x1A60, 0x1A60 },
	{ 0x1A62, 0x1A62 },
	{ 0x1A65, 0x1A6C },
	{ 0x1A73, 0x1A7C },
	{ 0x1A7F, 0x1A7F },
	{ 0x1AB0, 0x1AC0 },
	{ 0x1B00, 0x1B03 },
	{ 0x1B34, 0x1B34 },
	{ 0x1B36, 0x1B3A },
	{ 0x1B3C, 0x1B3C },
	{ 0x1B42, 0x1B42 },
	{ 0x1B6B, 0x1B73 },
	{ 0x1B80, 0x1B81 },
	{ 0x1BA2, 0x1BA5 },
	{ 0x1BA8, 0x1BA9 },
	{ 0x1BAB, 0x1BAD },
	{ 0x1BE6, 0x1BE6 },
	{ 0x1BE8, 0x1BE9 },
	{ 0x1BED, 0x1BED },
	{ 0x1BEF, 0x1BF1 },
	{ 0x1C2C, 0x1C33 },
	{ 0x1C36, 0x1C37 },
	{ 0x1CD0, 0x1CD2 },
	{ 0x1CD4, 0x1CE0 },
	{ 0x1CE2, 0x1CE8 },
	{ 0x1CED, 0x1CED },
	{ 0x1CF4, 0x1CF4 },
	{ 0x1CF8, 0x1CF9 },
	{ 0x1DC0, 0x1DF9 },
	{ 0x1DFB, 0x1DFF },
	{ 0x200B, 0x200F },
	{ 0x202A, 0x202E },
	{ 0x2060, 0x2064 },
	{ 0x2066, 0x206F },
	{ 0x20D0, 0x20F0 },
	{ 0x2CEF, 0x2CF1 },
	{ 0x2D7F, 0x2D7F },
	{ 0x2DE0, 0x2DFF },
	{ 0x302A, 0x302D },
	{ 0x3099, 0x309A },
	{ 0xA66F, 0xA672 },
	{ 0xA674, 0xA67D },
	{ 0xA69E, 0xA69F },
	{ 0xA6F0, 0xA6F1 },
	{ 0xA802, 0xA802 },
	{ 0xA806, 0xA806 },
	{ 0xA80B, 0xA80B },
	{ 0xA825, 0xA826 },
	{ 0xA82C, 0xA82C },
	{ 0xA8C4, 0xA8C5 },
	{ 0xA8E0, 0xA8F1 },
	{ 0xA8FF, 0xA8FF },
	{ 0xA926, 0xA92D },
	{ 0xA947, 0xA951 },
	{ 0xA980, 0xA982 },
	{ 0xA9B3, 0xA9B3 },
	{ 0xA9B6, 0xA9B9 },
	{ 0xA9BC, 0xA9BD },
	{ 0xA9E5, 0xA9E5 },
	{ 0xAA29, 0xAA2E },
	{ 0xAA31, 0xAA32 },
	{ 0xAA35, 0xAA36 },
	{ 0xAA43, 0xAA43 },
	{ 0xAA4C, 0xAA4C },
	{ 0xAA7C, 0xAA7C },
	{ 0xAAB0, 0xAAB0 },
	{ 0xAAB2, 0xAAB4 },
	{ 0xAAB7, 0xAAB8 },
	{ 0xAABE, 0xAABF },
	{ 0xAAC1, 0xAAC1 },
	{ 0xAAEC, 0xAAED },
	{ 0xAAF6, 0xAAF6 },
	{ 0xABE5, 0xABE5 },
	{ 0xABE8, 0xABE8 },
	{ 0xABED, 0xABED },
	{ 0xFB1E, 0xFB1E },
	{ 0xFE00, 0xFE0F },
	{ 0xFE20, 0xFE2F },
	{ 0xFEFF, 0xFEFF },
	{ 0xFFF9, 0xFFFB }
};

static const struct mb_ucsrange mb_ucs_fullwidth[] = {
	{ 0x1100, 0x115F },
	{ 0x231A, 0x231B },
	{ 0x2329, 0x232A },
	{ 0x23E9, 0x23EC },
	{ 0x23F0, 0x23F0 },
	{ 0x23F3, 0x23F3 },
	{ 0x25FD, 0x25FE },
	{ 0x2614, 0x2615 },
	{ 0x2648, 0x2653 },
	{ 0x267F, 0x267F },
	{ 0x2693, 0x2693 },
	{ 0x26A1, 0x26A1 },
	{ 0x26AA, 0x26AB },
	{ 0x26BD, 0x26BE },
	{ 0x26C4, 0x26C5 },
	{ 0x26CE, 0x26CE },
	{ 0x26D4, 0x26D4 },
	{ 0x26EA, 0x26EA },
	{ 0x26F2, 0x26F3 },
	{ 0x26F5, 0x26F5 },
	{ 0x26FA, 0x26FA },
	{ 0x26FD, 0x26FD },
	{ 0x2705, 0x2705 },
	{ 0x270A, 0x270B },
	{ 0x2728, 0x2728 },
	{ 0x274C, 0x274C },
	{ 0x274E, 0x274E },
	{ 0x2753, 0x2755 },
	{ 0x2757, 0x2757 },
	{ 0x2795, 0x2797 },
	{ 0x27B0, 0x27B0 },
	{ 0x27BF, 0x27BF },
	{ 0x2B1B, 0x2B1C },
	{ 0x2B50, 0x2B50 },
	{ 0x2B55, 0x2B55 },
	{ 0x2E80, 0x3029 },
	{ 0x302E, 0x303E },
	{ 0x3040, 0x3098 },
	{ 0x309B, 0xA4CF },
	{ 0xA960, 0xA97F },
	{ 0xAC00, 0xD7A3 },
	{ 0xF900, 0xFAFF },
	{ 0xFE10, 0xFE19 },
	{ 0xFE30, 0xFE6F },
	{ 0xFF01, 0xFF60 },
	{ 0xFFE0, 0xFFE6 }
};

/* simple binary search in ranges, with bounds optimisation */
static int
mb_ucsbsearch(const struct mb_ucsrange arr[], size_t elems, unsigned int val)
{
	size_t min = 0, mid, max = elems;

	if (val < arr[min].beg || val > arr[max - 1].end)
		return (0);

	while (min < max) {
		mid = (min + max) / 2;

		if (val < arr[mid].beg)
			max = mid;
		else if (val > arr[mid].end)
			min = mid + 1;
		else
			return (1);
	}
	return (0);
}

/* Unix column width of a wide character (UCS code point, really) */
int
utf_wcwidth(unsigned int wc)
{
	/* except NUL, C0/C1 control characters and DEL yield -1 */
	if (wc < 0x20 || (wc >= 0x7F && wc < 0xA0))
		return (wc ? -1 : 0);

	/* combining characters use 0 screen columns */
	if (mb_ucsbsearch(mb_ucs_combining, NELEM(mb_ucs_combining), wc))
		return (0);

	/* all others use 1 or 2 screen columns */
	if (mb_ucsbsearch(mb_ucs_fullwidth, NELEM(mb_ucs_fullwidth), wc))
		return (2);
	return (1);
}
#endif
