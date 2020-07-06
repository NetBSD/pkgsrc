/*	$OpenBSD: var.c,v 1.44 2015/09/10 11:37:42 jca Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *		 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018,
 *		 2019
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
#include "mirhash.h"

#if defined(__OpenBSD__)
#include <sys/sysctl.h>
#endif

__RCSID("$MirOS: src/bin/mksh/var.c,v 1.236 2020/04/13 16:29:34 tg Exp $");

/*-
 * Variables
 *
 * WARNING: unreadable code, needs a rewrite
 *
 * if (flag&INTEGER), val.i contains integer value, and type contains base.
 * otherwise, (val.s + type) contains string value.
 * if (flag&EXPORT), val.s contains "name=value" for E-Z exporting.
 */

static struct table specials;
static uint32_t lcg_state = 5381, qh_state = 4711;
/* may only be set by typeset() just before call to array_index_calc() */
static enum namerefflag innermost_refflag = SRF_NOP;

static void c_typeset_vardump(struct tbl *, uint32_t, int, int, bool, bool);
static void c_typeset_vardump_recursive(struct block *, uint32_t, int, bool,
    bool);
static char *formatstr(struct tbl *, const char *);
static void exportprep(struct tbl *, const char *, size_t);
static int special(const char *);
static void unspecial(const char *);
static void getspec(struct tbl *);
static void setspec(struct tbl *);
static void unsetspec(struct tbl *, bool);
static int getint(struct tbl *, mksh_ari_u *, bool);
static const char *array_index_calc(const char *, bool *, uint32_t *);
static struct tbl *vtypeset(int *, const char *, uint32_t, uint32_t, int, int);

/*
 * create a new block for function calls and simple commands
 * assume caller has allocated and set up e->loc
 */
void
newblock(void)
{
	struct block *l;
	static const char *empty[] = { null };

	l = alloc(sizeof(struct block), ATEMP);
	l->flags = 0;
	/* TODO: could use e->area (l->area => l->areap) */
	ainit(&l->area);
	if (!e->loc) {
		l->argc = 0;
		l->argv = empty;
	} else {
		l->argc = e->loc->argc;
		l->argv = e->loc->argv;
	}
	l->exit = l->error = NULL;
	ktinit(&l->area, &l->vars, 0);
	ktinit(&l->area, &l->funs, 0);
	l->next = e->loc;
	e->loc = l;
}

/*
 * pop a block handling special variables
 */
void
popblock(void)
{
	ssize_t i;
	struct block *l = e->loc;
	struct tbl *vp, **vpp = l->vars.tbls, *vq;

	/* pop block */
	e->loc = l->next;

	i = 1 << (l->vars.tshift);
	while (--i >= 0)
		if ((vp = *vpp++) != NULL && (vp->flag&SPECIAL)) {
			if ((vq = global(vp->name))->flag & ISSET)
				setspec(vq);
			else
				unsetspec(vq, false);
		}
	if (l->flags & BF_DOGETOPTS)
		user_opt = l->getopts_state;
	afreeall(&l->area);
	afree(l, ATEMP);
}

/* called by main() to initialise variable data structures */
#define VARSPEC_DEFNS
#include "var_spec.h"

enum var_specs {
#define VARSPEC_ENUMS
#include "var_spec.h"
	V_MAX
};

/* this is biased with -1 relative to VARSPEC_ENUMS */
static const char * const initvar_names[] = {
#define VARSPEC_ITEMS
#include "var_spec.h"
};

void
initvar(void)
{
	int i = 0;
	struct tbl *tp;

	ktinit(APERM, &specials,
	    /* currently 21 specials: 75% of 32 = 2^5 */
	    5);
	while (i < V_MAX - 1) {
		tp = ktenter(&specials, initvar_names[i],
		    hash(initvar_names[i]));
		tp->flag = DEFINED|ISSET;
		tp->type = ++i;
	}
}

/* common code for several functions below and c_typeset() */
struct block *
varsearch(struct block *l, struct tbl **vpp, const char *vn, uint32_t h)
{
	register struct tbl *vp;

	if (l) {
 varsearch_loop:
		if ((vp = ktsearch(&l->vars, vn, h)) != NULL)
			goto varsearch_out;
		if (l->next != NULL) {
			l = l->next;
			goto varsearch_loop;
		}
	}
	vp = NULL;
 varsearch_out:
	*vpp = vp;
	return (l);
}

/*
 * Used to calculate an array index for global()/local(). Sets *arrayp
 * to true if this is an array, sets *valp to the array index, returns
 * the basename of the array. May only be called from global()/local()
 * and must be their first callee.
 */
static const char *
array_index_calc(const char *n, bool *arrayp, uint32_t *valp)
{
	const char *p;
	size_t len;
	char *ap = NULL;

	*arrayp = false;
 redo_from_ref:
	p = skip_varname(n, false);
	if (innermost_refflag == SRF_NOP && (p != n) && ctype(n[0], C_ALPHX)) {
		struct tbl *vp;
		char *vn;

		strndupx(vn, n, p - n, ATEMP);
		/* check if this is a reference */
		varsearch(e->loc, &vp, vn, hash(vn));
		afree(vn, ATEMP);
		if (vp && (vp->flag & (DEFINED | ASSOC | ARRAY)) ==
		    (DEFINED | ASSOC)) {
			char *cp;

			/* gotcha! */
			strdup2x(cp, str_val(vp), p);
			afree(ap, ATEMP);
			n = ap = cp;
			goto redo_from_ref;
		}
	}
	innermost_refflag = SRF_NOP;

	if (p != n && ord(*p) == ORD('[') && (len = array_ref_len(p))) {
		char *sub, *tmp;
		mksh_ari_t rval;
		size_t tmplen = p - n;

		/* calculate the value of the subscript */
		*arrayp = true;
		len -= 2;
		tmp = alloc((len > tmplen ? len : tmplen) + 1, ATEMP);
		memcpy(tmp, p + 1, len);
		tmp[len] = '\0';
		sub = substitute(tmp, 0);
		evaluate(sub, &rval, KSH_UNWIND_ERROR, true);
		*valp = (uint32_t)rval;
		afree(sub, ATEMP);
		memcpy(tmp, n, tmplen);
		tmp[tmplen] = '\0';
		n = tmp;
	}
	return (n);
}

#define vn vname.ro
/*
 * Search for variable, if not found create globally.
 */
struct tbl *
global(const char *n)
{
	return (isglobal(n, true));
}

/* search for variable; if not found, return NULL or create globally */
struct tbl *
isglobal(const char *n, bool docreate)
{
	struct tbl *vp;
	union mksh_cchack vname;
	struct block *l = e->loc;
	int c;
	bool array;
	uint32_t h, val;

	/*
	 * check to see if this is an array;
	 * dereference namerefs; must come first
	 */
	vn = array_index_calc(n, &array, &val);
	h = hash(vn);
	c = (unsigned char)vn[0];
	if (!ctype(c, C_ALPHX)) {
		if (array)
			errorf(Tbadsubst);
		vp = vtemp;
		vp->flag = DEFINED;
		vp->type = 0;
		vp->areap = ATEMP;
		if (ctype(c, C_DIGIT)) {
			if (getn(vn, &c)) {
				/* main.c:main_init() says 12 */
				shf_snprintf(vp->name, 12, Tf_d, c);
				if (c <= l->argc) {
					/* setstr can't fail here */
					setstr(vp, l->argv[c],
					    KSH_RETURN_ERROR);
				}
			} else
				vp->name[0] = '\0';
			vp->flag |= RDONLY;
			goto out;
		}
		vp->name[0] = c;
		vp->name[1] = '\0';
		vp->flag |= RDONLY;
		if (!c || vn[1] != '\0')
			goto out;
		vp->flag |= ISSET|INTEGER;
		switch (c) {
		case '$':
			vp->val.i = kshpid;
			break;
		case '!':
			/* if no job, expand to nothing */
			if ((vp->val.i = j_async()) == 0)
				vp->flag &= ~(ISSET|INTEGER);
			break;
		case '?':
			vp->val.i = exstat & 0xFF;
			break;
		case '#':
			vp->val.i = l->argc;
			break;
		case '-':
			vp->flag &= ~INTEGER;
			vp->val.s = getoptions();
			break;
		default:
			vp->flag &= ~(ISSET|INTEGER);
		}
		goto out;
	}
	l = varsearch(e->loc, &vp, vn, h);
	if (vp == NULL && docreate)
		vp = ktenter(&l->vars, vn, h);
	else
		docreate = false;
	if (vp != NULL) {
		if (array)
			vp = arraysearch(vp, val);
		if (docreate) {
			vp->flag |= DEFINED;
			if (special(vn))
				vp->flag |= SPECIAL;
		}
	}
 out:
	last_lookup_was_array = array;
	if (vn != n)
		afree(vname.rw, ATEMP);
	return (vp);
}

/*
 * Search for local variable, if not found create locally.
 */
struct tbl *
local(const char *n, bool copy)
{
	struct tbl *vp;
	union mksh_cchack vname;
	struct block *l = e->loc;
	bool array;
	uint32_t h, val;

	/*
	 * check to see if this is an array;
	 * dereference namerefs; must come first
	 */
	vn = array_index_calc(n, &array, &val);
	h = hash(vn);
	if (!ctype(*vn, C_ALPHX)) {
		vp = vtemp;
		vp->flag = DEFINED|RDONLY;
		vp->type = 0;
		vp->areap = ATEMP;
		goto out;
	}
	vp = ktenter(&l->vars, vn, h);
	if (copy && !(vp->flag & DEFINED)) {
		struct tbl *vq;

		varsearch(l->next, &vq, vn, h);
		if (vq != NULL) {
			vp->flag |= vq->flag &
			    (EXPORT | INTEGER | RDONLY | LJUST | RJUST |
			    ZEROFIL | LCASEV | UCASEV_AL | INT_U | INT_L);
			if (vq->flag & INTEGER)
				vp->type = vq->type;
			vp->u2.field = vq->u2.field;
		}
	}
	if (array)
		vp = arraysearch(vp, val);
	vp->flag |= DEFINED;
	if (special(vn))
		vp->flag |= SPECIAL;
 out:
	last_lookup_was_array = array;
	if (vn != n)
		afree(vname.rw, ATEMP);
	return (vp);
}
#undef vn

/* get variable string value */
char *
str_val(struct tbl *vp)
{
	char *s;

	if ((vp->flag&SPECIAL))
		getspec(vp);
	if (!(vp->flag&ISSET))
		/* special to dollar() */
		s = null;
	else if (!(vp->flag&INTEGER))
		/* string source */
		s = vp->val.s + vp->type;
	else {
		/* integer source */
		mksh_uari_t n;
		unsigned int base;
		/**
		 * worst case number length is when base == 2:
		 *	1 (minus) + 2 (base, up to 36) + 1 ('#') +
		 *	number of bits in the mksh_uari_t + 1 (NUL)
		 */
		char strbuf[1 + 2 + 1 + 8 * sizeof(mksh_uari_t) + 1];
		const char *digits = (vp->flag & UCASEV_AL) ?
		    digits_uc : digits_lc;

		s = strbuf + sizeof(strbuf);
		if (vp->flag & INT_U)
			n = vp->val.u;
		else
			n = (vp->val.i < 0) ? -vp->val.u : vp->val.u;
		base = (vp->type == 0) ? 10U : (unsigned int)vp->type;

		if (base == 1 && n == 0)
			base = 2;
		if (base == 1) {
			size_t sz = 1;

			*(s = strbuf) = '1';
			s[1] = '#';
			if (!UTFMODE)
				s[2] = (unsigned char)n;
			else if ((n & 0xFF80) == 0xEF80)
				/* OPTU-16 -> raw octet */
				s[2] = asc2rtt(n & 0xFF);
			else
				sz = utf_wctomb(s + 2, n);
			s[2 + sz] = '\0';
		} else {
			*--s = '\0';
			do {
				*--s = digits[n % base];
				n /= base;
			} while (n != 0);
			if (base != 10) {
				*--s = '#';
				*--s = digits[base % 10];
				if (base >= 10)
					*--s = digits[base / 10];
			}
			if (!(vp->flag & INT_U) && vp->val.i < 0)
				*--s = '-';
		}
		if (vp->flag & (RJUST|LJUST))
			/* case already dealt with */
			s = formatstr(vp, s);
		else
			strdupx(s, s, ATEMP);
	}
	return (s);
}

/* set variable to string value */
int
setstr(struct tbl *vq, const char *s, int error_ok)
{
	bool no_ro_check = tobool(error_ok & 0x4);

	error_ok &= ~0x4;
	if ((vq->flag & RDONLY) && !no_ro_check) {
		warningf(true, Tf_ro, vq->name);
		if (!error_ok)
			errorfxz(2);
		return (0);
	}
	if (!(vq->flag&INTEGER)) {
		/* string dest */
		char *salloc = NULL;
		size_t cursz;
		if ((vq->flag&ALLOC)) {
			cursz = strlen(vq->val.s) + 1;
#ifndef MKSH_SMALL
			/* debugging */
			if (s >= vq->val.s && s < (vq->val.s + cursz)) {
				internal_errorf(
				    "setstr: %s=%s: assigning to self",
				    vq->name, s);
			}
#endif
		} else
			cursz = 0;
		if (s && (vq->flag & (UCASEV_AL|LCASEV|LJUST|RJUST)))
			s = salloc = formatstr(vq, s);
		if ((vq->flag&EXPORT))
			exportprep(vq, s, cursz);
		else {
			size_t n = strlen(s) + 1;
			vq->val.s = aresizeif(cursz, (vq->flag & ALLOC) ?
			    vq->val.s : NULL, n, vq->areap);
			memcpy(vq->val.s, s, n);
			vq->flag |= ALLOC;
			vq->type = 0;
		}
		afree(salloc, ATEMP);
	} else {
		/* integer dest */
		if (!v_evaluate(vq, s, error_ok, true))
			return (0);
	}
	vq->flag |= ISSET;
	if ((vq->flag&SPECIAL))
		setspec(vq);
	return (1);
}

/* set variable to integer */
void
setint(struct tbl *vq, mksh_ari_t n)
{
	if (!(vq->flag&INTEGER)) {
		vtemp->flag = (ISSET|INTEGER);
		vtemp->type = 0;
		vtemp->areap = ATEMP;
		vtemp->val.i = n;
		/* setstr can't fail here */
		setstr(vq, str_val(vtemp), KSH_RETURN_ERROR);
	} else
		vq->val.i = n;
	vq->flag |= ISSET;
	if ((vq->flag&SPECIAL))
		setspec(vq);
}

static int
getint(struct tbl *vp, mksh_ari_u *nump, bool arith)
{
	mksh_uari_t c, num = 0, base = 10;
	const char *s;
	bool have_base = false, neg = false;

	if (vp->flag & SPECIAL)
		getspec(vp);
	/* XXX is it possible for ISSET to be set and val.s to be NULL? */
	if (!(vp->flag & ISSET) || (!(vp->flag & INTEGER) && vp->val.s == NULL))
		return (-1);
	if (vp->flag & INTEGER) {
		nump->i = vp->val.i;
		return (vp->type);
	}
	s = vp->val.s + vp->type;

	do {
		c = (unsigned char)*s++;
	} while (ctype(c, C_SPACE));

	switch (c) {
	case '-':
		neg = true;
		/* FALLTHROUGH */
	case '+':
		c = (unsigned char)*s++;
		break;
	}

	if (c == '0' && arith) {
		if (ksh_eq(s[0], 'X', 'x')) {
			/* interpret as hexadecimal */
			base = 16;
			++s;
			goto getint_c_style_base;
		} else if (Flag(FPOSIX) && ctype(s[0], C_DIGIT) &&
		    !(vp->flag & ZEROFIL)) {
			/* interpret as octal (deprecated) */
			base = 8;
 getint_c_style_base:
			have_base = true;
			c = (unsigned char)*s++;
		}
	}

	do {
		if (c == '#') {
			/* ksh-style base determination */
			if (have_base || num < 1)
				return (-1);
			if ((base = num) == 1) {
				/* mksh-specific extension */
				unsigned int wc;

				if (!UTFMODE)
					wc = *(const unsigned char *)s;
				else if (utf_mbtowc(&wc, s) == (size_t)-1)
					/* OPTU-8 -> OPTU-16 */
					/*
					 * (with a twist: 1#\uEF80 converts
					 * the same as 1#\x80 does, thus is
					 * not round-tripping correctly XXX)
					 */
					wc = 0xEF00 + rtt2asc(*s);
				nump->u = (mksh_uari_t)wc;
				return (1);
			} else if (base > 36)
				base = 10;
			num = 0;
			have_base = true;
			continue;
		}
		if (ctype(c, C_DIGIT))
			c = ksh_numdig(c);
		else if (ctype(c, C_UPPER))
			c = ksh_numuc(c) + 10;
		else if (ctype(c, C_LOWER))
			c = ksh_numlc(c) + 10;
		else
			return (-1);
		if (c >= base)
			return (-1);
		/* handle overflow as truncation */
		num = num * base + c;
	} while ((c = (unsigned char)*s++));

	if (neg)
		num = -num;
	nump->u = num;
	return (base);
}

/*
 * convert variable vq to integer variable, setting its value from vp
 * (vq and vp may be the same)
 */
struct tbl *
setint_v(struct tbl *vq, struct tbl *vp, bool arith)
{
	int base;
	mksh_ari_u num;

	if ((base = getint(vp, &num, arith)) == -1)
		return (NULL);
	setint_n(vq, num.i, 0);
	if (vq->type == 0)
		/* default base */
		vq->type = base;
	return (vq);
}

/* convert variable vq to integer variable, setting its value to num */
void
setint_n(struct tbl *vq, mksh_ari_t num, int newbase)
{
	if (!(vq->flag & INTEGER) && (vq->flag & ALLOC)) {
		vq->flag &= ~ALLOC;
		vq->type = 0;
		afree(vq->val.s, vq->areap);
	}
	vq->val.i = num;
	if (newbase != 0)
		vq->type = newbase;
	vq->flag |= ISSET|INTEGER;
	if (vq->flag&SPECIAL)
		setspec(vq);
}

static char *
formatstr(struct tbl *vp, const char *s)
{
	int olen, nlen;
	char *p, *q;
	size_t psiz;

	olen = (int)utf_mbswidth(s);

	if (vp->flag & (RJUST|LJUST)) {
		if (!vp->u2.field)
			/* default field width */
			vp->u2.field = olen;
		nlen = vp->u2.field;
	} else
		nlen = olen;

	p = alloc((psiz = nlen * /* MB_LEN_MAX */ 3 + 1), ATEMP);
	if (vp->flag & (RJUST|LJUST)) {
		int slen = olen;

		if (vp->flag & RJUST) {
			const char *qq;
			int n = 0;

			qq = utf_skipcols(s, slen, &slen);

			/* strip trailing spaces (AT&T uses qq[-1] == ' ') */
			while (qq > s && ctype(qq[-1], C_SPACE)) {
				--qq;
				--slen;
			}
			if (vp->flag & ZEROFIL && vp->flag & INTEGER) {
				if (!s[0] || !s[1])
					goto uhm_no;
				if (s[1] == '#')
					n = 2;
				else if (s[2] == '#')
					n = 3;
 uhm_no:
				if (vp->u2.field <= n)
					n = 0;
			}
			if (n) {
				memcpy(p, s, n);
				s += n;
			}
			while (slen > vp->u2.field)
				slen -= utf_widthadj(s, &s);
			if (vp->u2.field - slen)
				memset(p + n, (vp->flag & ZEROFIL) ? '0' : ' ',
				    vp->u2.field - slen);
			slen -= n;
			shf_snprintf(p + vp->u2.field - slen,
			    psiz - (vp->u2.field - slen),
			    "%.*s", slen, s);
		} else {
			/* strip leading spaces/zeros */
			while (ctype(*s, C_SPACE))
				s++;
			if (vp->flag & ZEROFIL)
				while (*s == '0')
					s++;
			shf_snprintf(p, psiz, "%-*.*s",
				vp->u2.field, vp->u2.field, s);
		}
	} else
		memcpy(p, s, strlen(s) + 1);

	if (vp->flag & UCASEV_AL) {
		for (q = p; *q; q++)
			*q = ksh_toupper(*q);
	} else if (vp->flag & LCASEV) {
		for (q = p; *q; q++)
			*q = ksh_tolower(*q);
	}

	return (p);
}

/*
 * make vp->val.s be "name=value" for quick exporting.
 */
static void
exportprep(struct tbl *vp, const char *val, size_t cursz)
{
	char *cp = (vp->flag & ALLOC) ? vp->val.s : NULL;
	size_t namelen = strlen(vp->name);
	size_t vallen = strlen(val) + 1;

	vp->flag |= ALLOC;
	vp->type = namelen + 1;
	/* since name+val are both in memory this can go unchecked */
	vp->val.s = aresizeif(cursz, cp, vp->type + vallen, vp->areap);
	memmove(vp->val.s + vp->type, val == cp ? vp->val.s : val, vallen);
	memcpy(vp->val.s, vp->name, namelen);
	vp->val.s[namelen] = '=';
}

/*
 * lookup variable (according to (set&LOCAL)), set its attributes
 * (INTEGER, RDONLY, EXPORT, TRACE, LJUST, RJUST, ZEROFIL, LCASEV,
 * UCASEV_AL), and optionally set its value if an assignment.
 */
struct tbl *
typeset(const char *var, uint32_t set, uint32_t clr, int field, int base)
{
	return (vtypeset(NULL, var, set, clr, field, base));
}
static struct tbl *
vtypeset(int *ep, const char *var, uint32_t set, uint32_t clr,
    int field, int base)
{
	struct tbl *vp;
	struct tbl *vpbase, *t;
	char *tvar, tvarbuf[32];
	const char *val;
	size_t len;
	bool vappend = false;
	enum namerefflag new_refflag = SRF_NOP;

	if (ep)
		*ep = 0;

	if ((set & (ARRAY | ASSOC)) == ASSOC) {
		new_refflag = SRF_ENABLE;
		set &= ~(ARRAY | ASSOC);
	}
	if ((clr & (ARRAY | ASSOC)) == ASSOC) {
		new_refflag = SRF_DISABLE;
		clr &= ~(ARRAY | ASSOC);
	}

	/* check for valid variable name, search for value */
	val = skip_varname(var, false);
	if (val == var) {
		/* no variable name given */
		return (NULL);
	}
	if (ord(*val) == ORD('[')) {
		if (new_refflag != SRF_NOP)
			return (maybe_errorf(ep, 1, Tf_sD_s, var,
			    "reference variable can't be an array"), NULL);
		len = array_ref_len(val);
		if (len == 0)
			return (NULL);
		/*
		 * IMPORT is only used when the shell starts up and is
		 * setting up its environment. Allow only simple array
		 * references at this time since parameter/command
		 * substitution is performed on the [expression] which
		 * would be a major security hole.
		 */
		if (set & IMPORT) {
			size_t i;

			for (i = 1; i < len - 1; i++)
				if (!ctype(val[i], C_DIGIT))
					return (NULL);
		}
		val += len;
	}
	if (ord(val[0]) == ORD('=')) {
		len = val - var;
		tvar = len < sizeof(tvarbuf) ? tvarbuf : alloc(len + 1, ATEMP);
		memcpy(tvar, var, len);
		tvar[len] = '\0';
		++val;
	} else if (set & IMPORT) {
		/* environment invalid variable name or no assignment */
		return (NULL);
	} else if (ord(val[0]) == ORD('+') && ord(val[1]) == ORD('=')) {
		len = val - var;
		tvar = len < sizeof(tvarbuf) ? tvarbuf : alloc(len + 1, ATEMP);
		memcpy(tvar, var, len);
		tvar[len] = '\0';
		val += 2;
		vappend = true;
	} else if (val[0] != '\0') {
		/* other invalid variable names (not from environment) */
		return (NULL);
	} else {
		/* just varname with no value part nor equals sign */
		len = strlen(var);
		tvar = len < sizeof(tvarbuf) ? tvarbuf : alloc(len + 1, ATEMP);
		memcpy(tvar, var, len);
		tvar[len] = '\0';
		val = NULL;
		/* handle foo[*] => foo (whole array) mapping for R39b */
		if (len > 3 && ord(tvar[len - 3]) == ORD('[') &&
		    ord(tvar[len - 2]) == ORD('*') &&
		    ord(tvar[len - 1]) == ORD(']'))
			tvar[len - 3] = '\0';
	}

	if (new_refflag == SRF_ENABLE) {
		const char *qval, *ccp;

		/* bail out on 'nameref foo+=bar' */
		if (vappend)
			return (maybe_errorf(ep, 1,
			    "appending not allowed for nameref"), NULL);
		/* find value if variable already exists */
		if ((qval = val) == NULL) {
			varsearch(e->loc, &vp, tvar, hash(tvar));
			if (vp == NULL)
				goto nameref_empty;
			qval = str_val(vp);
		}
		/* check target value for being a valid variable name */
		ccp = skip_varname(qval, false);
		if (ccp == qval) {
			int c;

			if (!(c = (unsigned char)qval[0]))
				goto nameref_empty;
			else if (ctype(c, C_DIGIT) && getn(qval, &c))
				goto nameref_rhs_checked;
			else if (qval[1] == '\0') switch (c) {
			case '$':
			case '!':
			case '?':
			case '#':
			case '-':
				goto nameref_rhs_checked;
			}
 nameref_empty:
			return (maybe_errorf(ep, 1, Tf_sD_s, var,
			    "empty nameref target"), NULL);
		}
		len = (ord(*ccp) == ORD('[')) ? array_ref_len(ccp) : 0;
		if (ccp[len]) {
			/*
			 * works for cases "no array", "valid array with
			 * junk after it" and "invalid array"; in the
			 * latter case, len is also 0 and points to '['
			 */
			return (maybe_errorf(ep, 1, Tf_sD_s, qval,
			    "nameref target not a valid parameter name"), NULL);
		}
 nameref_rhs_checked:
		/* prevent nameref loops */
		while (qval) {
			if (!strcmp(qval, tvar))
				return (maybe_errorf(ep, 1, Tf_sD_s, qval,
				    "expression recurses on parameter"), NULL);
			varsearch(e->loc, &vp, qval, hash(qval));
			qval = NULL;
			if (vp && ((vp->flag & (ARRAY | ASSOC)) == ASSOC))
				qval = str_val(vp);
		}
	}

	/* prevent typeset from creating a local PATH/ENV/SHELL */
	if (Flag(FRESTRICTED) && (strcmp(tvar, TPATH) == 0 ||
	    strcmp(tvar, TENV) == 0 || strcmp(tvar, TSHELL) == 0))
		return (maybe_errorf(ep, 1, Tf_sD_s,
		    tvar, "restricted"), NULL);

	innermost_refflag = new_refflag;
	vp = (set & LOCAL) ? local(tvar, tobool(set & LOCAL_COPY)) :
	    global(tvar);
	if (new_refflag == SRF_DISABLE && (vp->flag & (ARRAY|ASSOC)) == ASSOC)
		vp->flag &= ~ASSOC;
	else if (new_refflag == SRF_ENABLE) {
		if (vp->flag & ARRAY) {
			struct tbl *a, *tmp;

			/* free up entire array */
			for (a = vp->u.array; a; ) {
				tmp = a;
				a = a->u.array;
				if (tmp->flag & ALLOC)
					afree(tmp->val.s, tmp->areap);
				afree(tmp, tmp->areap);
			}
			vp->u.array = NULL;
			vp->flag &= ~ARRAY;
		}
		vp->flag |= ASSOC;
	}

	set &= ~(LOCAL|LOCAL_COPY);

	vpbase = (vp->flag & ARRAY) ? global(arrayname(tvar)) : vp;

	/*
	 * only allow export and readonly flag to be set; AT&T ksh
	 * allows any attribute to be changed which means it can be
	 * truncated or modified (-L/-R/-Z/-i)
	 */
	if ((vpbase->flag & RDONLY) &&
	    (val || clr || (set & ~(EXPORT | RDONLY))))
		return (maybe_errorf(ep, 2, Tf_ro, tvar), NULL);
	if (tvar != tvarbuf)
		afree(tvar, ATEMP);

	/* most calls are with set/clr == 0 */
	if (set | clr) {
		bool ok = true;

		/*
		 * XXX if x[0] isn't set, there will be problems: need
		 * to have one copy of attributes for arrays...
		 */
		for (t = vpbase; t; t = t->u.array) {
			bool fake_assign;
			char *s = NULL;
			char *free_me = NULL;

			fake_assign = (t->flag & ISSET) && (!val || t != vp) &&
			    ((set & (UCASEV_AL|LCASEV|LJUST|RJUST|ZEROFIL)) ||
			    ((t->flag & INTEGER) && (clr & INTEGER)) ||
			    (!(t->flag & INTEGER) && (set & INTEGER)));
			if (fake_assign) {
				if (t->flag & INTEGER) {
					s = str_val(t);
					free_me = NULL;
				} else {
					s = t->val.s + t->type;
					free_me = (t->flag & ALLOC) ? t->val.s :
					    NULL;
				}
				t->flag &= ~ALLOC;
			}
			if (!(t->flag & INTEGER) && (set & INTEGER)) {
				t->type = 0;
				t->flag &= ~ALLOC;
			}
			t->flag = (t->flag | set) & ~clr;
			/*
			 * Don't change base if assignment is to be
			 * done, in case assignment fails.
			 */
			if ((set & INTEGER) && base > 0 && (!val || t != vp))
				t->type = base;
			if (set & (LJUST|RJUST|ZEROFIL))
				t->u2.field = field;
			if (fake_assign) {
				if (!setstr(t, s, KSH_RETURN_ERROR)) {
					/*
					 * Somewhat arbitrary action
					 * here: zap contents of
					 * variable, but keep the flag
					 * settings.
					 */
					ok = false;
					if (t->flag & INTEGER)
						t->flag &= ~ISSET;
					else {
						if (t->flag & ALLOC)
							afree(t->val.s, t->areap);
						t->flag &= ~(ISSET|ALLOC);
						t->type = 0;
					}
				}
				afree(free_me, t->areap);
			}
		}
		if (!ok)
			return (maybe_errorf(ep, 1, NULL), NULL);
	}

	if (vappend) {
		size_t tlen;
		if ((vp->flag & (ISSET|ALLOC|SPECIAL|INTEGER|UCASEV_AL|LCASEV|LJUST|RJUST)) != (ISSET|ALLOC)) {
			/* cannot special-case this */
			strdup2x(tvar, str_val(vp), val);
			val = tvar;
			goto vassign;
		}
		/* trivial string appending */
		len = strlen(vp->val.s);
		tlen = strlen(val) + 1;
		vp->val.s = aresize(vp->val.s, len + tlen, vp->areap);
		memcpy(vp->val.s + len, val, tlen);
	} else if (val != NULL) {
 vassign:
		if (vp->flag&INTEGER) {
			/* do not zero base before assignment */
			setstr(vp, val, KSH_UNWIND_ERROR | 0x4);
			/* done after assignment to override default */
			if (base > 0)
				vp->type = base;
		} else
			/* setstr can't fail (readonly check already done) */
			setstr(vp, val, KSH_RETURN_ERROR | 0x4);

		/* came here from vappend? need to free temp val */
		if (vappend)
			afree(tvar, ATEMP);
	}

	/* only x[0] is ever exported, so use vpbase */
	if ((vpbase->flag & (EXPORT|INTEGER)) == EXPORT &&
	    vpbase->type == 0)
		exportprep(vpbase, (vpbase->flag & ISSET) ?
		    vpbase->val.s : null, 0);

	return (vp);
}

/**
 * Unset a variable. The flags can be:
 * |1	= tear down entire array
 * |2	= keep attributes, only unset content
 */
void
unset(struct tbl *vp, int flags)
{
	if (vp->flag & ALLOC)
		afree(vp->val.s, vp->areap);
	if ((vp->flag & ARRAY) && (flags & 1)) {
		struct tbl *a, *tmp;

		/* free up entire array */
		for (a = vp->u.array; a; ) {
			tmp = a;
			a = a->u.array;
			if (tmp->flag & ALLOC)
				afree(tmp->val.s, tmp->areap);
			afree(tmp, tmp->areap);
		}
		vp->u.array = NULL;
	}
	if (flags & 2) {
		vp->flag &= ~(ALLOC|ISSET);
		return;
	}
	/* if foo[0] is being unset, the remainder of the array is kept... */
	vp->flag &= SPECIAL | ((flags & 1) ? 0 : ARRAY|DEFINED);
	if (vp->flag & SPECIAL)
		/* responsible for 'unspecial'ing var */
		unsetspec(vp, true);
}

/*
 * Return a pointer to the first char past a legal variable name
 * (returns the argument if there is no legal name, returns a pointer to
 * the terminating NUL if whole string is legal).
 */
const char *
skip_varname(const char *s, bool aok)
{
	size_t alen;

	if (s && ctype(*s, C_ALPHX)) {
		do {
			++s;
		} while (ctype(*s, C_ALNUX));
		if (aok && ord(*s) == ORD('[') && (alen = array_ref_len(s)))
			s += alen;
	}
	return (s);
}

/* Return a pointer to the first character past any legal variable name */
const char *
skip_wdvarname(const char *s,
    /* skip array de-reference? */
    bool aok)
{
	if (s[0] == CHAR && ctype(s[1], C_ALPHX)) {
		do {
			s += 2;
		} while (s[0] == CHAR && ctype(s[1], C_ALNUX));
		if (aok && s[0] == CHAR && ord(s[1]) == ORD('[')) {
			/* skip possible array de-reference */
			const char *p = s;
			char c;
			int depth = 0;

			while (/* CONSTCOND */ 1) {
				if (p[0] != CHAR)
					break;
				c = p[1];
				p += 2;
				if (ord(c) == ORD('['))
					depth++;
				else if (ord(c) == ORD(']') && --depth == 0) {
					s = p;
					break;
				}
			}
		}
	}
	return (s);
}

/* Check if coded string s is a variable name */
int
is_wdvarname(const char *s, bool aok)
{
	const char *p = skip_wdvarname(s, aok);

	return (p != s && p[0] == EOS);
}

/* Check if coded string s is a variable assignment */
int
is_wdvarassign(const char *s)
{
	const char *p = skip_wdvarname(s, true);

	return (p != s && p[0] == CHAR &&
	    (p[1] == '=' || (p[1] == '+' && p[2] == CHAR && p[3] == '=')));
}

/*
 * Make the exported environment from the exported names in the dictionary.
 */
char **
makenv(void)
{
	ssize_t i;
	struct block *l;
	XPtrV denv;
	struct tbl *vp, **vpp;

	XPinit(denv, 64);
	for (l = e->loc; l != NULL; l = l->next) {
		vpp = l->vars.tbls;
		i = 1 << (l->vars.tshift);
		while (--i >= 0)
			if ((vp = *vpp++) != NULL &&
			    (vp->flag&(ISSET|EXPORT)) == (ISSET|EXPORT)) {
				struct block *l2;
				struct tbl *vp2;
				uint32_t h = hash(vp->name);

				/* unexport any redefined instances */
				for (l2 = l->next; l2 != NULL; l2 = l2->next) {
					vp2 = ktsearch(&l2->vars, vp->name, h);
					if (vp2 != NULL)
						vp2->flag &= ~EXPORT;
				}
				if ((vp->flag&INTEGER)) {
					/* integer to string */
					char *val;
					val = str_val(vp);
					vp->flag &= ~(INTEGER|RDONLY|SPECIAL);
					/* setstr can't fail here */
					setstr(vp, val, KSH_RETURN_ERROR);
				}
#ifdef __OS2__
				/* these special variables are not exported */
				if (!strcmp(vp->name, "BEGINLIBPATH") ||
				    !strcmp(vp->name, "ENDLIBPATH") ||
				    !strcmp(vp->name, "LIBPATHSTRICT"))
					continue;
#endif
				XPput(denv, vp->val.s);
			}
		if (l->flags & BF_STOPENV)
			break;
	}
	XPput(denv, NULL);
	return ((char **)XPclose(denv));
}

/*
 * handle special variables with side effects - PATH, SECONDS.
 */

/* Test if name is a special parameter */
static int
special(const char *name)
{
	struct tbl *tp;

	tp = ktsearch(&specials, name, hash(name));
	return (tp && (tp->flag & ISSET) ? tp->type : V_NONE);
}

/* Make a variable non-special */
static void
unspecial(const char *name)
{
	struct tbl *tp;

	tp = ktsearch(&specials, name, hash(name));
	if (tp)
		ktdelete(tp);
}

static time_t seconds;		/* time SECONDS last set */
static mksh_uari_t user_lineno;	/* what user set $LINENO to */

/* minimum values from the OS we consider sane, lowered for R53 */
#define MIN_COLS	4
#define MIN_LINS	2

static void
getspec(struct tbl *vp)
{
	mksh_ari_u num;
	int st;
	struct timeval tv;

	switch ((st = special(vp->name))) {
	case V_COLUMNS:
	case V_LINES:
		/*
		 * Do NOT export COLUMNS/LINES. Many applications
		 * check COLUMNS/LINES before checking ws.ws_col/row,
		 * so if the app is started with C/L in the environ
		 * and the window is then resized, the app won't
		 * see the change cause the environ doesn't change.
		 */
		if (got_winch)
			change_winsz();
		break;
	}
	switch (st) {
	case V_BASHPID:
		num.u = (mksh_uari_t)procpid;
		break;
	case V_COLUMNS:
		num.i = x_cols;
		break;
	case V_HISTSIZE:
		num.i = histsize;
		break;
	case V_LINENO:
		num.u = (mksh_uari_t)current_lineno + user_lineno;
		break;
	case V_LINES:
		num.i = x_lins;
		break;
	case V_EPOCHREALTIME: {
		/* 10(%u) + 1(.) + 6 + NUL */
		char buf[18];

		vp->flag &= ~SPECIAL;
		mksh_TIME(tv);
		shf_snprintf(buf, sizeof(buf), "%u.%06u",
		    (unsigned)tv.tv_sec, (unsigned)tv.tv_usec);
		setstr(vp, buf, KSH_RETURN_ERROR | 0x4);
		vp->flag |= SPECIAL;
		return;
	}
	case V_OPTIND:
		num.i = user_opt.uoptind;
		break;
	case V_RANDOM:
		num.i = rndget();
		break;
	case V_SECONDS:
		/*
		 * On start up the value of SECONDS is used before
		 * it has been set - don't do anything in this case
		 * (see initcoms[] in main.c).
		 */
		if (vp->flag & ISSET) {
			mksh_TIME(tv);
			num.i = tv.tv_sec - seconds;
		} else
			return;
		break;
	default:
		/* do nothing, do not touch vp at all */
		return;
	}
	vp->flag &= ~SPECIAL;
	setint_n(vp, num.i, 0);
	vp->flag |= SPECIAL;
}

static void
setspec(struct tbl *vp)
{
	mksh_ari_u num;
	char *s;
	int st = special(vp->name);

#ifdef MKSH_DOSPATH
	switch (st) {
	case V_PATH:
	case V_TMPDIR:
#ifdef __OS2__
	case V_BEGINLIBPATH:
	case V_ENDLIBPATH:
#endif
		/* convert backslashes to slashes for convenience */
		if (!(vp->flag&INTEGER)) {
			s = str_val(vp);
			do {
				if (*s == ORD('\\'))
					*s = '/';
			} while (*s++);
		}
		break;
	}
#endif

	switch (st) {
#ifdef __OS2__
	case V_BEGINLIBPATH:
	case V_ENDLIBPATH:
	case V_LIBPATHSTRICT:
		setextlibpath(vp->name, str_val(vp));
		return;
#endif
#if HAVE_PERSISTENT_HISTORY
	case V_HISTFILE:
		sethistfile(str_val(vp));
		return;
#endif
	case V_IFS:
		set_ifs(str_val(vp));
		return;
	case V_PATH:
		afree(path, APERM);
		s = str_val(vp);
		strdupx(path, s, APERM);
		/* clear tracked aliases */
		flushcom(true);
		return;
#ifndef MKSH_NO_CMDLINE_EDITING
	case V_TERM:
		x_initterm(str_val(vp));
		return;
#endif
	case V_TMPDIR:
		afree(tmpdir, APERM);
		tmpdir = NULL;
		/*
		 * Use tmpdir iff it is an absolute path, is writable
		 * and searchable and is a directory...
		 */
		{
			struct stat statb;

			s = str_val(vp);
			/* LINTED use of access */
			if (mksh_abspath(s) && access(s, W_OK|X_OK) == 0 &&
			    stat(s, &statb) == 0 && S_ISDIR(statb.st_mode))
				strdupx(tmpdir, s, APERM);
		}
		return;
	/* common sub-cases */
	case V_COLUMNS:
	case V_LINES:
		if (vp->flag & IMPORT) {
			/* do not touch */
			unspecial(vp->name);
			vp->flag &= ~SPECIAL;
			return;
		}
		/* FALLTHROUGH */
	case V_HISTSIZE:
	case V_LINENO:
	case V_OPTIND:
	case V_RANDOM:
	case V_SECONDS:
	case V_TMOUT:
		vp->flag &= ~SPECIAL;
		if (getint(vp, &num, false) == -1) {
			s = str_val(vp);
			if (st != V_RANDOM)
				errorf(Tf_sD_sD_s, vp->name, Tbadnum, s);
			num.u = hash(s);
		}
		vp->flag |= SPECIAL;
		break;
#ifdef MKSH_EARLY_LOCALE_TRACKING
	case V_LANG:
	case V_LC_ALL:
	case V_LC_CTYPE:
		recheck_ctype();
		return;
#endif
	default:
		/* do nothing, do not touch vp at all */
		return;
	}

	/* process the singular parts of the common cases */

	switch (st) {
	case V_COLUMNS:
		if (num.i >= MIN_COLS)
			x_cols = num.i;
		break;
	case V_HISTSIZE:
		sethistsize(num.i);
		break;
	case V_LINENO:
		/* The -1 is because line numbering starts at 1. */
		user_lineno = num.u - (mksh_uari_t)current_lineno - 1;
		break;
	case V_LINES:
		if (num.i >= MIN_LINS)
			x_lins = num.i;
		break;
	case V_OPTIND:
		getopts_reset((int)num.i);
		break;
	case V_RANDOM:
		/*
		 * mksh R39d+ no longer has the traditional repeatability
		 * of $RANDOM sequences, but always retains state
		 */
		rndset((unsigned long)num.u);
		break;
	case V_SECONDS:
		{
			struct timeval tv;

			mksh_TIME(tv);
			seconds = tv.tv_sec - num.i;
		}
		break;
	case V_TMOUT:
		ksh_tmout = num.i >= 0 ? num.i : 0;
		break;
	}
}

static void
unsetspec(struct tbl *vp, bool dounset)
{
	/*
	 * AT&T ksh man page says OPTIND, OPTARG and _ lose special
	 * meaning, but OPTARG does not (still set by getopts) and _ is
	 * also still set in various places. Don't know what AT&T does
	 * for HISTSIZE, HISTFILE. Unsetting these in AT&T ksh does not
	 * loose the 'specialness': IFS, COLUMNS, PATH, TMPDIR
	 */

	switch (special(vp->name)) {
#ifdef __OS2__
	case V_BEGINLIBPATH:
	case V_ENDLIBPATH:
	case V_LIBPATHSTRICT:
		setextlibpath(vp->name, "");
		return;
#endif
#if HAVE_PERSISTENT_HISTORY
	case V_HISTFILE:
		sethistfile(NULL);
		return;
#endif
	case V_IFS:
		set_ifs(TC_IFSWS);
		return;
	case V_PATH:
		afree(path, APERM);
		strdupx(path, def_path, APERM);
		/* clear tracked aliases */
		flushcom(true);
		return;
#ifndef MKSH_NO_CMDLINE_EDITING
	case V_TERM:
		x_initterm(null);
		return;
#endif
	case V_TMPDIR:
		/* should not become unspecial */
		if (tmpdir) {
			afree(tmpdir, APERM);
			tmpdir = NULL;
		}
		return;
	case V_LINENO:
	case V_RANDOM:
	case V_SECONDS:
	case V_TMOUT:
		/* AT&T ksh leaves previous value in place */
		unspecial(vp->name);
		return;
#ifdef MKSH_EARLY_LOCALE_TRACKING
	case V_LANG:
	case V_LC_ALL:
	case V_LC_CTYPE:
		recheck_ctype();
		return;
#endif
	/* should not become unspecial, but allow unsetting */
	case V_COLUMNS:
	case V_LINES:
		if (dounset)
			unspecial(vp->name);
		return;
	}
}

/*
 * Search for (and possibly create) a table entry starting with
 * vp, indexed by val.
 */
struct tbl *
arraysearch(struct tbl *vp, uint32_t val)
{
	struct tbl *prev, *curr, *news;
	size_t len;

	vp->flag = (vp->flag | (ARRAY | DEFINED)) & ~ASSOC;
	/* the table entry is always [0] */
	if (val == 0)
		return (vp);
	prev = vp;
	curr = vp->u.array;
	while (curr && curr->ua.index < val) {
		prev = curr;
		curr = curr->u.array;
	}
	if (curr && curr->ua.index == val) {
		if (curr->flag&ISSET)
			return (curr);
		news = curr;
	} else
		news = NULL;
	if (!news) {
		len = strlen(vp->name);
		checkoktoadd(len, 1 + offsetof(struct tbl, name[0]));
		news = alloc(offsetof(struct tbl, name[0]) + ++len, vp->areap);
		memcpy(news->name, vp->name, len);
	}
	news->flag = (vp->flag & ~(ALLOC|DEFINED|ISSET|SPECIAL)) | AINDEX;
	news->type = vp->type;
	news->areap = vp->areap;
	news->u2.field = vp->u2.field;
	news->ua.index = val;

	if (curr != news) {
		/* not reusing old array entry */
		prev->u.array = news;
		news->u.array = curr;
	}
	return (news);
}

/*
 * Return the length of an array reference (eg, [1+2]) - cp is assumed
 * to point to the open bracket. Returns 0 if there is no matching
 * closing bracket.
 *
 * XXX this should parse the actual arithmetic syntax
 */
size_t
array_ref_len(const char *cp)
{
	const char *s = cp;
	char c;
	int depth = 0;

	while ((c = *s++) && (ord(c) != ORD(']') || --depth))
		if (ord(c) == ORD('['))
			depth++;
	if (!c)
		return (0);
	return (s - cp);
}

/*
 * Make a copy of the base of an array name
 */
char *
arrayname(const char *str)
{
	const char *p;
	char *rv;

	if (!(p = cstrchr(str, '[')))
		/* Shouldn't happen, but why worry? */
		strdupx(rv, str, ATEMP);
	else
		strndupx(rv, str, p - str, ATEMP);

	return (rv);
}

/* set (or overwrite, if reset) the array variable var to the values in vals */
mksh_uari_t
set_array(const char *var, bool reset, const char **vals)
{
	struct tbl *vp, *vq;
	mksh_uari_t i = 0, j = 0;
	const char *ccp = var;
	char *cp = NULL;
	size_t n;

	/* to get local array, use "local foo; set -A foo" */
	n = strlen(var);
	if (n > 0 && var[n - 1] == '+') {
		/* append mode */
		reset = false;
		strndupx(cp, var, n - 1, ATEMP);
		ccp = cp;
	}
	vp = global(ccp);

	/* Note: AT&T ksh allows set -A but not set +A of a read-only var */
	if ((vp->flag&RDONLY))
		errorfx(2, Tf_ro, ccp);
	/* This code is quite non-optimal */
	if (reset) {
		/* trash existing values and attributes */
		unset(vp, 1);
		/* allocate-by-access the [0] element to keep in scope */
		arraysearch(vp, 0);
		/* honour set -o allexport */
		if (Flag(FEXPORT))
			typeset(ccp, EXPORT, 0, 0, 0);
	}
	/*
	 * TODO: would be nice for assignment to completely succeed or
	 * completely fail. Only really effects integer arrays:
	 * evaluation of some of vals[] may fail...
	 */
	if (cp != NULL) {
		/* find out where to set when appending */
		for (vq = vp; vq; vq = vq->u.array) {
			if (!(vq->flag & ISSET))
				continue;
			if (arrayindex(vq) >= j)
				j = arrayindex(vq) + 1;
		}
		afree(cp, ATEMP);
	}
	while ((ccp = vals[i])) {
#if 0 /* temporarily taken out due to regression */
		if (ord(*ccp) == ORD('[')) {
			int level = 0;

			while (*ccp) {
				if (ord(*ccp) == ORD(']') && --level == 0)
					break;
				if (ord(*ccp) == ORD('['))
					++level;
				++ccp;
			}
			if (ord(*ccp) == ORD(']') && level == 0 &&
			    ord(ccp[1]) == ORD('=')) {
				strndupx(cp, vals[i] + 1, ccp - (vals[i] + 1),
				    ATEMP);
				evaluate(substitute(cp, 0), (mksh_ari_t *)&j,
				    KSH_UNWIND_ERROR, true);
				afree(cp, ATEMP);
				ccp += 2;
			} else
				ccp = vals[i];
		}
#endif

		vq = arraysearch(vp, j);
		/* would be nice to deal with errors here... (see above) */
		setstr(vq, ccp, KSH_RETURN_ERROR);
		i++;
		j++;
	}

	return (i);
}

void
change_winsz(void)
{
	struct timeval tv;

	mksh_TIME(tv);
	BAFHUpdateMem_mem(qh_state, &tv, sizeof(tv));

#ifdef TIOCGWINSZ
	/* check if window size has changed */
	if (tty_init_fd() < 2) {
		struct winsize ws;

		if (ioctl(tty_fd, TIOCGWINSZ, &ws) >= 0) {
			if (ws.ws_col)
				x_cols = ws.ws_col;
			if (ws.ws_row)
				x_lins = ws.ws_row;
		}
	}
#endif

	/* bounds check for sane values, use defaults otherwise */
	if (x_cols < MIN_COLS)
		x_cols = 80;
	if (x_lins < MIN_LINS)
		x_lins = 24;

#ifdef SIGWINCH
	got_winch = 0;
#endif
}

uint32_t
hash(const void *s)
{
	register uint32_t h;

	BAFHInit(h);
	BAFHUpdateStr_reg(h, s);
	BAFHFinish_reg(h);
	return (h);
}

uint32_t
chvt_rndsetup(const void *bp, size_t sz)
{
	register uint32_t h;

	/* use LCG as seed but try to get them to deviate immediately */
	h = lcg_state;
	(void)rndget();
	BAFHFinish_reg(h);
	/* variation through pid, ppid, and the works */
	BAFHUpdateMem_reg(h, &rndsetupstate, sizeof(rndsetupstate));
	/* some variation, some possibly entropy, depending on OE */
	BAFHUpdateMem_reg(h, bp, sz);
	/* mix them all up */
	BAFHFinish_reg(h);

	return (h);
}

mksh_ari_t
rndget(void)
{
	/*
	 * this is the same Linear Congruential PRNG as Borland
	 * C/C++ allegedly uses in its built-in rand() function
	 */
	return (((lcg_state = 22695477 * lcg_state + 1) >> 16) & 0x7FFF);
}

void
rndset(unsigned long v)
{
	register uint32_t h;
#if defined(arc4random_pushb_fast) || defined(MKSH_A4PB)
	register uint32_t t;
#endif
	struct {
		struct timeval tv;
		void *sp;
		uint32_t qh;
		pid_t pp;
		short r;
	} z;

	/* clear the allocated space, for valgrind and to avoid UB */
	memset(&z, 0, sizeof(z));

	h = lcg_state;
	BAFHFinish_reg(h);
	BAFHUpdateMem_reg(h, &v, sizeof(v));

	mksh_TIME(z.tv);
	z.sp = &lcg_state;
	z.pp = procpid;
	z.r = (short)rndget();

#if defined(arc4random_pushb_fast) || defined(MKSH_A4PB)
	t = qh_state;
	BAFHFinish_reg(t);
	z.qh = (t & 0xFFFF8000) | rndget();
	lcg_state = (t << 15) | rndget();
	/*
	 * either we have very chap entropy get and push available,
	 * with malloc() pulling in this code already anyway, or the
	 * user requested us to use the old functions
	 */
	t = h;
	BAFHUpdateMem_reg(t, &lcg_state, sizeof(lcg_state));
	BAFHFinish_reg(t);
	lcg_state = t;
#if defined(arc4random_pushb_fast)
	arc4random_pushb_fast(&lcg_state, sizeof(lcg_state));
	lcg_state = arc4random();
#else
	lcg_state = arc4random_pushb(&lcg_state, sizeof(lcg_state));
#endif
	BAFHUpdateMem_reg(h, &lcg_state, sizeof(lcg_state));
#else
	z.qh = qh_state;
#endif

	BAFHUpdateMem_reg(h, &z, sizeof(z));
	BAFHFinish_reg(h);
	lcg_state = h;
}

void
rndpush(const void *s)
{
	register uint32_t h = qh_state;

	BAFHUpdateStr_reg(h, s);
	BAFHUpdateOctet_reg(h, 0);
	qh_state = h;
}

/* record last glob match */
void
record_match(const char *istr)
{
	struct tbl *vp;

	vp = local("KSH_MATCH", false);
	unset(vp, 1);
	vp->flag = DEFINED | RDONLY;
	setstr(vp, istr, 0x4);
}

/* typeset, export and readonly */
int
c_typeset(const char **wp)
{
	struct tbl *vp, **p;
	uint32_t fset = 0, fclr = 0, flag;
	int thing = 0, field = 0, base = 0, i;
	struct block *l;
	const char *opts;
	const char *fieldstr = NULL, *basestr = NULL;
	bool localv = false, func = false, pflag = false, istset = true;
	enum namerefflag new_refflag = SRF_NOP;

	switch (**wp) {

	/* export */
	case 'e':
		fset |= EXPORT;
		istset = false;
		break;

	/* readonly */
	case 'r':
		fset |= RDONLY;
		istset = false;
		break;

	/* set */
	case 's':
		/* called with 'typeset -' */
		break;

	/* typeset */
	case 't':
		localv = true;
		break;
	}

	/* see comment below regarding possible opions */
	opts = istset ? "L#R#UZ#afgi#lnprtux" : "p";

	builtin_opt.flags |= GF_PLUSOPT;
	/*
	 * AT&T ksh seems to have 0-9 as options which are multiplied
	 * to get a number that is used with -L, -R, -Z or -i (eg, -1R2
	 * sets right justify in a field of 12). This allows options
	 * to be grouped in an order (eg, -Lu12), but disallows -i8 -L3 and
	 * does not allow the number to be specified as a separate argument
	 * Here, the number must follow the RLZi option, but is optional
	 * (see the # kludge in ksh_getopt()).
	 */
	while ((i = ksh_getopt(wp, &builtin_opt, opts)) != -1) {
		flag = 0;
		switch (i) {
		case 'L':
			flag = LJUST;
			fieldstr = builtin_opt.optarg;
			break;
		case 'R':
			flag = RJUST;
			fieldstr = builtin_opt.optarg;
			break;
		case 'U':
			/*
			 * AT&T ksh uses u, but this conflicts with
			 * upper/lower case. If this option is changed,
			 * need to change the -U below as well
			 */
			flag = INT_U;
			break;
		case 'Z':
			flag = ZEROFIL;
			fieldstr = builtin_opt.optarg;
			break;
		case 'a':
			/*
			 * this is supposed to set (-a) or unset (+a) the
			 * indexed array attribute; it does nothing on an
			 * existing regular string or indexed array though
			 */
			break;
		case 'f':
			func = true;
			break;
		case 'g':
			localv = (builtin_opt.info & GI_PLUS) ? true : false;
			break;
		case 'i':
			flag = INTEGER;
			basestr = builtin_opt.optarg;
			break;
		case 'l':
			flag = LCASEV;
			break;
		case 'n':
			new_refflag = (builtin_opt.info & GI_PLUS) ?
			    SRF_DISABLE : SRF_ENABLE;
			break;
		/* export, readonly: POSIX -p flag */
		case 'p':
			/* typeset: show values as well */
			pflag = true;
			if (istset)
				continue;
			break;
		case 'r':
			flag = RDONLY;
			break;
		case 't':
			flag = TRACE;
			break;
		case 'u':
			/* upper case / autoload */
			flag = UCASEV_AL;
			break;
		case 'x':
			flag = EXPORT;
			break;
		case '?':
			return (1);
		}
		if (builtin_opt.info & GI_PLUS) {
			fclr |= flag;
			fset &= ~flag;
			thing = '+';
		} else {
			fset |= flag;
			fclr &= ~flag;
			thing = '-';
		}
	}

	if (fieldstr && !getn(fieldstr, &field)) {
		bi_errorf(Tf_sD_s, Tbadnum, fieldstr);
		return (1);
	}
	if (basestr) {
		if (!getn(basestr, &base)) {
			bi_errorf(Tf_sD_s, "bad integer base", basestr);
			return (1);
		}
		if (base < 1 || base > 36)
			base = 10;
	}

	if (!(builtin_opt.info & GI_MINUSMINUS) && wp[builtin_opt.optind] &&
	    (wp[builtin_opt.optind][0] == '-' ||
	    wp[builtin_opt.optind][0] == '+') &&
	    wp[builtin_opt.optind][1] == '\0') {
		thing = wp[builtin_opt.optind][0];
		builtin_opt.optind++;
	}

	if (func && (((fset|fclr) & ~(TRACE|UCASEV_AL|EXPORT)) ||
	    new_refflag != SRF_NOP)) {
		bi_errorf("only -t, -u and -x options may be used with -f");
		return (1);
	}
	if (wp[builtin_opt.optind]) {
		/*
		 * Take care of exclusions.
		 * At this point, flags in fset are cleared in fclr and vice
		 * versa. This property should be preserved.
		 */
		if (fset & LCASEV)
			/* LCASEV has priority over UCASEV_AL */
			fset &= ~UCASEV_AL;
		if (fset & LJUST)
			/* LJUST has priority over RJUST */
			fset &= ~RJUST;
		if ((fset & (ZEROFIL|LJUST)) == ZEROFIL) {
			/* -Z implies -ZR */
			fset |= RJUST;
			fclr &= ~RJUST;
		}
		/*
		 * Setting these attributes clears the others, unless they
		 * are also set in this command
		 */
		if ((fset & (LJUST | RJUST | ZEROFIL | UCASEV_AL | LCASEV |
		    INTEGER | INT_U | INT_L)) || new_refflag != SRF_NOP)
			fclr |= ~fset & (LJUST | RJUST | ZEROFIL | UCASEV_AL |
			    LCASEV | INTEGER | INT_U | INT_L);
	}
	if (new_refflag != SRF_NOP) {
		fclr &= ~(ARRAY | ASSOC);
		fset &= ~(ARRAY | ASSOC);
		fclr |= EXPORT;
		fset |= ASSOC;
		if (new_refflag == SRF_DISABLE)
			fclr |= ASSOC;
	}

	/* set variables and attributes */
	if (wp[builtin_opt.optind] &&
	    /* not "typeset -p varname" */
	    !(!func && pflag && !(fset | fclr))) {
		int rv = 0, x;
		struct tbl *f;

		if (localv && !func)
			fset |= LOCAL;
		for (i = builtin_opt.optind; wp[i]; i++) {
			if (func) {
				f = findfunc(wp[i], hash(wp[i]),
				    tobool(fset & UCASEV_AL));
				if (!f) {
					/* AT&T ksh does ++rv: bogus */
					rv = 1;
					continue;
				}
				if (fset | fclr) {
					f->flag |= fset;
					f->flag &= ~fclr;
				} else {
					fpFUNCTf(shl_stdout, 0,
					    tobool(f->flag & FKSH),
					    wp[i], f->val.t);
					shf_putc('\n', shl_stdout);
				}
			} else if (!vtypeset(&x, wp[i], fset, fclr,
			    field, base)) {
				if (x)
					return (x);
				bi_errorf(Tf_sD_s, wp[i], Tnot_ident);
				return (1);
			}
		}
		return (rv);
	}

	/* list variables and attributes */

	/* no difference at this point.. */
	flag = fset | fclr;
	if (func) {
		for (l = e->loc; l; l = l->next) {
			for (p = ktsort(&l->funs); (vp = *p++); ) {
				if (flag && (vp->flag & flag) == 0)
					continue;
				if (thing == '-')
					fpFUNCTf(shl_stdout, 0,
					    tobool(vp->flag & FKSH),
					    vp->name, vp->val.t);
				else
					shf_puts(vp->name, shl_stdout);
				shf_putc('\n', shl_stdout);
			}
		}
	} else if (wp[builtin_opt.optind]) {
		for (i = builtin_opt.optind; wp[i]; i++) {
			vp = isglobal(wp[i], false);
			c_typeset_vardump(vp, flag, thing,
			    last_lookup_was_array ? 4 : 0, pflag, istset);
		}
	} else
		c_typeset_vardump_recursive(e->loc, flag, thing, pflag, istset);
	return (0);
}

static void
c_typeset_vardump_recursive(struct block *l, uint32_t flag, int thing,
    bool pflag, bool istset)
{
	struct tbl **blockvars, *vp;

	if (l->next)
		c_typeset_vardump_recursive(l->next, flag, thing, pflag, istset);
	blockvars = ktsort(&l->vars);
	while ((vp = *blockvars++))
		c_typeset_vardump(vp, flag, thing, 0, pflag, istset);
	/*XXX doesn’t this leak? */
}

static void
c_typeset_vardump(struct tbl *vp, uint32_t flag, int thing, int any_set,
    bool pflag, bool istset)
{
	struct tbl *tvp;
	char *s;

	if (!vp)
		return;

	/*
	 * See if the parameter is set (for arrays, if any
	 * element is set).
	 */
	for (tvp = vp; tvp; tvp = tvp->u.array)
		if (tvp->flag & ISSET) {
			any_set |= 1;
			break;
		}

	/*
	 * Check attributes - note that all array elements
	 * have (should have?) the same attributes, so checking
	 * the first is sufficient.
	 *
	 * Report an unset param only if the user has
	 * explicitly given it some attribute (like export);
	 * otherwise, after "echo $FOO", we would report FOO...
	 */
	if (!any_set && !(vp->flag & USERATTRIB))
		return;
	if (flag && (vp->flag & flag) == 0)
		return;
	if (!(vp->flag & ARRAY))
		/* optimise later conditionals */
		any_set = 0;
	do {
		/*
		 * Ignore array elements that aren't set unless there
		 * are no set elements, in which case the first is
		 * reported on
		 */
		if (any_set && !(vp->flag & ISSET))
			continue;
		/* no arguments */
		if (!thing && !flag) {
			if (any_set == 1) {
				shprintf(Tf_s_s_sN, Tset, "-A", vp->name);
				any_set = 2;
			}
			/*
			 * AT&T ksh prints things like export, integer,
			 * leftadj, zerofill, etc., but POSIX says must
			 * be suitable for re-entry...
			 */
			shprintf(Tf_s_s, Ttypeset, "");
			if (((vp->flag & (ARRAY | ASSOC)) == ASSOC))
				shprintf(Tf__c_, 'n');
			if ((vp->flag & INTEGER))
				shprintf(Tf__c_, 'i');
			if ((vp->flag & EXPORT))
				shprintf(Tf__c_, 'x');
			if ((vp->flag & RDONLY))
				shprintf(Tf__c_, 'r');
			if ((vp->flag & TRACE))
				shprintf(Tf__c_, 't');
			if ((vp->flag & LJUST))
				shprintf("-L%d ", vp->u2.field);
			if ((vp->flag & RJUST))
				shprintf("-R%d ", vp->u2.field);
			if ((vp->flag & ZEROFIL))
				shprintf(Tf__c_, 'Z');
			if ((vp->flag & LCASEV))
				shprintf(Tf__c_, 'l');
			if ((vp->flag & UCASEV_AL))
				shprintf(Tf__c_, 'u');
			if ((vp->flag & INT_U))
				shprintf(Tf__c_, 'U');
		} else if (pflag) {
			shprintf(Tf_s_s, istset ? Ttypeset :
			    (flag & EXPORT) ? Texport : Treadonly, "");
		}
		if (any_set)
			shprintf("%s[%lu]", vp->name, arrayindex(vp));
		else
			shf_puts(vp->name, shl_stdout);
		if ((!thing && !flag && pflag) ||
		    (thing == '-' && (vp->flag & ISSET))) {
			s = str_val(vp);
			shf_putc('=', shl_stdout);
			/* AT&T ksh can't have justified integers... */
			if ((vp->flag & (INTEGER | LJUST | RJUST)) == INTEGER)
				shf_puts(s, shl_stdout);
			else
				print_value_quoted(shl_stdout, s);
		}
		shf_putc('\n', shl_stdout);

		/*
		 * Only report first 'element' of an array with
		 * no set elements.
		 */
		if (!any_set)
			return;
	} while (!(any_set & 4) && (vp = vp->u.array));
}
