/*-
 * Copyright (c) 2016, 2020
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

#if defined(EXPRTOK_DEFNS)
__RCSID("$MirOS: src/bin/mksh/exprtok.h,v 1.4 2020/04/07 11:56:46 tg Exp $");
/* see range comment below */
#define IS_ASSIGNOP(op) ((int)(op) >= (int)O_ASN && (int)(op) <= (int)O_BORASN)
#define FN(name,len,prec,enum)		/* nothing */
#define F1(enum)			/* nothing */
#elif defined(EXPRTOK_ENUM)
#define F0(name,len,prec,enum)		enum = 0,
#define FN(name,len,prec,enum)		enum,
#define F1(enum)			enum,
#define F2(enum)			enum,
#define F9(enum)			enum
#elif defined(EXPRTOK_NAME)
#define FN(name,len,prec,enum)		name,
#define F1(enum)			""
#elif defined(EXPRTOK_LEN)
#define FN(name,len,prec,enum)		len,
#define F1(enum)			0
#elif defined(EXPRTOK_PREC)
#define FN(name,len,prec,enum)		prec,
#define F1(enum)			P_PRIMARY
#endif

#ifndef F0
#define F0 FN
#endif

#ifndef F2
#define F2(enum)			/* nothing */
#define F9(enum)			/* nothing */
#endif

/* tokens must be ordered so the longest are first (e.g. += before +) */

/* some (long) unary operators */
F0("++", 2, P_PRIMARY, O_PLUSPLUS)	/* before + */
FN("--", 2, P_PRIMARY, O_MINUSMINUS)	/* before - */
/* binary operators */
FN("==", 2, P_EQUALITY, O_EQ)		/* before = */
FN("!=", 2, P_EQUALITY, O_NE)		/* before ! */
/* assignments are assumed to be in range O_ASN .. O_BORASN */
FN("=", 1, P_ASSIGN, O_ASN)
FN("*=", 2, P_ASSIGN, O_TIMESASN)
FN("/=", 2, P_ASSIGN, O_DIVASN)
FN("%=", 2, P_ASSIGN, O_MODASN)
FN("+=", 2, P_ASSIGN, O_PLUSASN)
FN("-=", 2, P_ASSIGN, O_MINUSASN)
#ifndef MKSH_LEGACY_MODE
FN("^<=", 3, P_ASSIGN, O_ROLASN)	/* before ^< */
FN("^>=", 3, P_ASSIGN, O_RORASN)	/* before ^> */
#endif
FN("<<=", 3, P_ASSIGN, O_LSHIFTASN)
FN(">>=", 3, P_ASSIGN, O_RSHIFTASN)
FN("&=", 2, P_ASSIGN, O_BANDASN)
FN("^=", 2, P_ASSIGN, O_BXORASN)
FN("|=", 2, P_ASSIGN, O_BORASN)
/* binary non-assignment operators */
#ifndef MKSH_LEGACY_MODE
FN("^<", 2, P_SHIFT, O_ROL)		/* before ^ */
FN("^>", 2, P_SHIFT, O_ROR)		/* before ^ */
#endif
FN("<<", 2, P_SHIFT, O_LSHIFT)
FN(">>", 2, P_SHIFT, O_RSHIFT)
FN("<=", 2, P_RELATION, O_LE)
FN(">=", 2, P_RELATION, O_GE)
FN("<", 1, P_RELATION, O_LT)
FN(">", 1, P_RELATION, O_GT)
FN("&&", 2, P_LAND, O_LAND)
FN("||", 2, P_LOR, O_LOR)
FN("*", 1, P_MULT, O_TIMES)
FN("/", 1, P_MULT, O_DIV)
FN("%", 1, P_MULT, O_MOD)
FN("+", 1, P_ADD, O_PLUS)
FN("-", 1, P_ADD, O_MINUS)
FN("&", 1, P_BAND, O_BAND)
FN("^", 1, P_BXOR, O_BXOR)
FN("|", 1, P_BOR, O_BOR)
FN("?", 1, P_TERN, O_TERN)
FN(",", 1, P_COMMA, O_COMMA)
/* things after this aren't used as binary operators */
/* unary that are not also binaries */
FN("~", 1, P_PRIMARY, O_BNOT)
FN("!", 1, P_PRIMARY, O_LNOT)
/* misc */
FN("(", 1, P_PRIMARY, OPEN_PAREN)
FN(")", 1, P_PRIMARY, CLOSE_PAREN)
FN(":", 1, P_PRIMARY, CTERN)
/* things that don't appear in the opinfo[] table */
F1(VAR)				/*XXX should be F2 */
F2(LIT)
F2(END)
F9(BAD)

#undef FN
#undef F0
#undef F1
#undef F2
#undef F9
#undef EXPRTOK_DEFNS
#undef EXPRTOK_ENUM
#undef EXPRTOK_NAME
#undef EXPRTOK_LEN
#undef EXPRTOK_PREC
