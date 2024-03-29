#include <stdio.h>
#include "awk.h"
#include "awkgram.tab.h"

static const char * const printname[95] = {
	"FIRSTTOKEN",	/* 257 */
	"PROGRAM",	/* 258 */
	"PASTAT",	/* 259 */
	"PASTAT2",	/* 260 */
	"XBEGIN",	/* 261 */
	"XEND",	/* 262 */
	"NL",	/* 263 */
	"ARRAY",	/* 264 */
	"MATCH",	/* 265 */
	"NOTMATCH",	/* 266 */
	"MATCHOP",	/* 267 */
	"FINAL",	/* 268 */
	"DOT",	/* 269 */
	"ALL",	/* 270 */
	"CCL",	/* 271 */
	"NCCL",	/* 272 */
	"CHAR",	/* 273 */
	"OR",	/* 274 */
	"STAR",	/* 275 */
	"QUEST",	/* 276 */
	"PLUS",	/* 277 */
	"EMPTYRE",	/* 278 */
	"ZERO",	/* 279 */
	"AND",	/* 280 */
	"BOR",	/* 281 */
	"APPEND",	/* 282 */
	"EQ",	/* 283 */
	"GE",	/* 284 */
	"GT",	/* 285 */
	"LE",	/* 286 */
	"LT",	/* 287 */
	"NE",	/* 288 */
	"IN",	/* 289 */
	"ARG",	/* 290 */
	"BLTIN",	/* 291 */
	"BREAK",	/* 292 */
	"CLOSE",	/* 293 */
	"CONTINUE",	/* 294 */
	"DELETE",	/* 295 */
	"DO",	/* 296 */
	"EXIT",	/* 297 */
	"FOR",	/* 298 */
	"FUNC",	/* 299 */
	"SUB",	/* 300 */
	"GSUB",	/* 301 */
	"IF",	/* 302 */
	"INDEX",	/* 303 */
	"LSUBSTR",	/* 304 */
	"MATCHFCN",	/* 305 */
	"NEXT",	/* 306 */
	"NEXTFILE",	/* 307 */
	"ADD",	/* 308 */
	"MINUS",	/* 309 */
	"MULT",	/* 310 */
	"DIVIDE",	/* 311 */
	"MOD",	/* 312 */
	"ASSIGN",	/* 313 */
	"ASGNOP",	/* 314 */
	"ADDEQ",	/* 315 */
	"SUBEQ",	/* 316 */
	"MULTEQ",	/* 317 */
	"DIVEQ",	/* 318 */
	"MODEQ",	/* 319 */
	"POWEQ",	/* 320 */
	"PRINT",	/* 321 */
	"PRINTF",	/* 322 */
	"SPRINTF",	/* 323 */
	"ELSE",	/* 324 */
	"INTEST",	/* 325 */
	"CONDEXPR",	/* 326 */
	"POSTINCR",	/* 327 */
	"PREINCR",	/* 328 */
	"POSTDECR",	/* 329 */
	"PREDECR",	/* 330 */
	"VAR",	/* 331 */
	"IVAR",	/* 332 */
	"VARNF",	/* 333 */
	"CALL",	/* 334 */
	"NUMBER",	/* 335 */
	"STRING",	/* 336 */
	"REGEXPR",	/* 337 */
	"GETLINE",	/* 338 */
	"RETURN",	/* 339 */
	"SPLIT",	/* 340 */
	"SUBSTR",	/* 341 */
	"WHILE",	/* 342 */
	"CAT",	/* 343 */
	"NOT",	/* 344 */
	"UMINUS",	/* 345 */
	"UPLUS",	/* 346 */
	"POWER",	/* 347 */
	"DECR",	/* 348 */
	"INCR",	/* 349 */
	"INDIRECT",	/* 350 */
	"LASTTOKEN",	/* 351 */
};


Cell *(*proctab[95])(Node **, int) = {
	nullproc,	/* FIRSTTOKEN */
	program,	/* PROGRAM */
	pastat,	/* PASTAT */
	dopa2,	/* PASTAT2 */
	nullproc,	/* XBEGIN */
	nullproc,	/* XEND */
	nullproc,	/* NL */
	array,	/* ARRAY */
	matchop,	/* MATCH */
	matchop,	/* NOTMATCH */
	nullproc,	/* MATCHOP */
	nullproc,	/* FINAL */
	nullproc,	/* DOT */
	nullproc,	/* ALL */
	nullproc,	/* CCL */
	nullproc,	/* NCCL */
	nullproc,	/* CHAR */
	nullproc,	/* OR */
	nullproc,	/* STAR */
	nullproc,	/* QUEST */
	nullproc,	/* PLUS */
	nullproc,	/* EMPTYRE */
	nullproc,	/* ZERO */
	boolop,	/* AND */
	boolop,	/* BOR */
	nullproc,	/* APPEND */
	relop,	/* EQ */
	relop,	/* GE */
	relop,	/* GT */
	relop,	/* LE */
	relop,	/* LT */
	relop,	/* NE */
	instat,	/* IN */
	arg,	/* ARG */
	bltin,	/* BLTIN */
	jump,	/* BREAK */
	closefile,	/* CLOSE */
	jump,	/* CONTINUE */
	awkdelete,	/* DELETE */
	dostat,	/* DO */
	jump,	/* EXIT */
	forstat,	/* FOR */
	nullproc,	/* FUNC */
	sub,	/* SUB */
	gsub,	/* GSUB */
	ifstat,	/* IF */
	sindex,	/* INDEX */
	nullproc,	/* LSUBSTR */
	matchop,	/* MATCHFCN */
	jump,	/* NEXT */
	jump,	/* NEXTFILE */
	arith,	/* ADD */
	arith,	/* MINUS */
	arith,	/* MULT */
	arith,	/* DIVIDE */
	arith,	/* MOD */
	assign,	/* ASSIGN */
	nullproc,	/* ASGNOP */
	assign,	/* ADDEQ */
	assign,	/* SUBEQ */
	assign,	/* MULTEQ */
	assign,	/* DIVEQ */
	assign,	/* MODEQ */
	assign,	/* POWEQ */
	printstat,	/* PRINT */
	awkprintf,	/* PRINTF */
	awksprintf,	/* SPRINTF */
	nullproc,	/* ELSE */
	intest,	/* INTEST */
	condexpr,	/* CONDEXPR */
	incrdecr,	/* POSTINCR */
	incrdecr,	/* PREINCR */
	incrdecr,	/* POSTDECR */
	incrdecr,	/* PREDECR */
	nullproc,	/* VAR */
	nullproc,	/* IVAR */
	getnf,	/* VARNF */
	call,	/* CALL */
	nullproc,	/* NUMBER */
	nullproc,	/* STRING */
	nullproc,	/* REGEXPR */
	awkgetline,	/* GETLINE */
	jump,	/* RETURN */
	split,	/* SPLIT */
	substr,	/* SUBSTR */
	whilestat,	/* WHILE */
	cat,	/* CAT */
	boolop,	/* NOT */
	arith,	/* UMINUS */
	arith,	/* UPLUS */
	arith,	/* POWER */
	nullproc,	/* DECR */
	nullproc,	/* INCR */
	indirect,	/* INDIRECT */
	nullproc,	/* LASTTOKEN */
};

const char *tokname(int n)
{
	static char buf[100];

	if (n < FIRSTTOKEN || n > LASTTOKEN) {
		snprintf(buf, sizeof(buf), "token %d", n);
		return buf;
	}
	return printname[n-FIRSTTOKEN];
}
