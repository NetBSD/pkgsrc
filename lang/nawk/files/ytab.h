/* $NetBSD: ytab.h,v 1.1 2006/07/14 14:23:06 jlam Exp $ */

/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FIRSTTOKEN = 258,
     PROGRAM = 259,
     PASTAT = 260,
     PASTAT2 = 261,
     XBEGIN = 262,
     XEND = 263,
     NL = 264,
     ARRAY = 265,
     MATCH = 266,
     NOTMATCH = 267,
     MATCHOP = 268,
     FINAL = 269,
     DOT = 270,
     ALL = 271,
     CCL = 272,
     NCCL = 273,
     CHAR = 274,
     OR = 275,
     STAR = 276,
     QUEST = 277,
     PLUS = 278,
     AND = 279,
     BOR = 280,
     APPEND = 281,
     EQ = 282,
     GE = 283,
     GT = 284,
     LE = 285,
     LT = 286,
     NE = 287,
     IN = 288,
     ARG = 289,
     BLTIN = 290,
     BREAK = 291,
     CLOSE = 292,
     CONTINUE = 293,
     DELETE = 294,
     DO = 295,
     EXIT = 296,
     FOR = 297,
     FUNC = 298,
     SUB = 299,
     GSUB = 300,
     IF = 301,
     INDEX = 302,
     LSUBSTR = 303,
     MATCHFCN = 304,
     NEXT = 305,
     NEXTFILE = 306,
     ADD = 307,
     MINUS = 308,
     MULT = 309,
     DIVIDE = 310,
     MOD = 311,
     ASSIGN = 312,
     ASGNOP = 313,
     ADDEQ = 314,
     SUBEQ = 315,
     MULTEQ = 316,
     DIVEQ = 317,
     MODEQ = 318,
     POWEQ = 319,
     PRINT = 320,
     PRINTF = 321,
     SPRINTF = 322,
     ELSE = 323,
     INTEST = 324,
     CONDEXPR = 325,
     POSTINCR = 326,
     PREINCR = 327,
     POSTDECR = 328,
     PREDECR = 329,
     VAR = 330,
     IVAR = 331,
     VARNF = 332,
     CALL = 333,
     NUMBER = 334,
     STRING = 335,
     REGEXPR = 336,
     GETLINE = 337,
     SUBSTR = 338,
     SPLIT = 339,
     RETURN = 340,
     WHILE = 341,
     CAT = 342,
     UMINUS = 343,
     NOT = 344,
     POWER = 345,
     INCR = 346,
     DECR = 347,
     INDIRECT = 348,
     LASTTOKEN = 349
   };
#endif
#define FIRSTTOKEN 258
#define PROGRAM 259
#define PASTAT 260
#define PASTAT2 261
#define XBEGIN 262
#define XEND 263
#define NL 264
#define ARRAY 265
#define MATCH 266
#define NOTMATCH 267
#define MATCHOP 268
#define FINAL 269
#define DOT 270
#define ALL 271
#define CCL 272
#define NCCL 273
#define CHAR 274
#define OR 275
#define STAR 276
#define QUEST 277
#define PLUS 278
#define AND 279
#define BOR 280
#define APPEND 281
#define EQ 282
#define GE 283
#define GT 284
#define LE 285
#define LT 286
#define NE 287
#define IN 288
#define ARG 289
#define BLTIN 290
#define BREAK 291
#define CLOSE 292
#define CONTINUE 293
#define DELETE 294
#define DO 295
#define EXIT 296
#define FOR 297
#define FUNC 298
#define SUB 299
#define GSUB 300
#define IF 301
#define INDEX 302
#define LSUBSTR 303
#define MATCHFCN 304
#define NEXT 305
#define NEXTFILE 306
#define ADD 307
#define MINUS 308
#define MULT 309
#define DIVIDE 310
#define MOD 311
#define ASSIGN 312
#define ASGNOP 313
#define ADDEQ 314
#define SUBEQ 315
#define MULTEQ 316
#define DIVEQ 317
#define MODEQ 318
#define POWEQ 319
#define PRINT 320
#define PRINTF 321
#define SPRINTF 322
#define ELSE 323
#define INTEST 324
#define CONDEXPR 325
#define POSTINCR 326
#define PREINCR 327
#define POSTDECR 328
#define PREDECR 329
#define VAR 330
#define IVAR 331
#define VARNF 332
#define CALL 333
#define NUMBER 334
#define STRING 335
#define REGEXPR 336
#define GETLINE 337
#define SUBSTR 338
#define SPLIT 339
#define RETURN 340
#define WHILE 341
#define CAT 342
#define UMINUS 343
#define NOT 344
#define POWER 345
#define INCR 346
#define DECR 347
#define INDIRECT 348
#define LASTTOKEN 349




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 41 "awkgram.y"
typedef union YYSTYPE {
	Node	*p;
	Cell	*cp;
	int	i;
	char	*s;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 231 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



