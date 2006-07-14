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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 25 "awkgram.y"

#include <stdio.h>
#include <string.h>
#include "awk.h"

void checkdup(Node *list, Cell *item);
int yywrap(void) { return(1); }

Node	*beginloc = 0;
Node	*endloc = 0;
int	infunc	= 0;	/* = 1 if in arglist or body of func */
int	inloop	= 0;	/* = 1 if in while, for, do */
char	*curfname = 0;	/* current function name */
Node	*arglist = 0;	/* list of args for current function */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 41 "awkgram.y"
typedef union YYSTYPE {
	Node	*p;
	Cell	*cp;
	int	i;
	char	*s;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 286 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 298 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4569

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  49
/* YYNRULES -- Number of rules. */
#define YYNRULES  185
/* YYNRULES -- Number of states. */
#define YYNSTATES  367

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   103,     2,     2,
      12,    16,   102,   100,     9,   101,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,    14,
       2,     2,     2,    92,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    11,    13,    17,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    10,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    94,    95,    96,
      97,    98,    99,   104,   105,   106,   107,   108,   109,   110
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    17,    19,
      22,    24,    27,    29,    32,    33,    46,    47,    58,    59,
      68,    70,    72,    77,    79,    82,    84,    87,    88,    90,
      91,    93,    94,    96,    98,   102,   104,   106,   111,   115,
     122,   126,   131,   136,   137,   147,   149,   153,   155,   159,
     163,   169,   173,   177,   181,   185,   189,   195,   198,   200,
     202,   206,   212,   216,   220,   224,   228,   232,   236,   240,
     244,   248,   252,   256,   262,   267,   271,   274,   276,   278,
     282,   286,   288,   292,   293,   295,   299,   301,   303,   305,
     307,   310,   313,   315,   318,   320,   323,   324,   329,   331,
     334,   339,   344,   349,   352,   358,   361,   363,   365,   367,
     370,   373,   376,   377,   378,   388,   392,   395,   397,   402,
     405,   409,   412,   415,   419,   422,   425,   426,   430,   433,
     435,   438,   440,   442,   447,   451,   455,   459,   463,   467,
     471,   474,   477,   480,   484,   489,   491,   495,   500,   503,
     506,   509,   512,   515,   520,   524,   527,   529,   536,   543,
     547,   554,   561,   563,   572,   581,   588,   593,   595,   602,
     609,   618,   627,   636,   643,   645,   647,   652,   654,   657,
     658,   660,   664,   666,   668,   670
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     112,     0,    -1,   129,    -1,     1,    -1,    34,    -1,   113,
      10,    -1,    35,    -1,   114,    10,    -1,     9,    -1,   115,
      10,    -1,    50,    -1,   116,    10,    -1,    78,    -1,   117,
      10,    -1,    -1,    52,    12,   128,    14,   126,   136,    14,
     126,   128,   146,   119,   149,    -1,    -1,    52,    12,   128,
      14,    14,   126,   128,   146,   120,   149,    -1,    -1,    52,
      12,   158,    43,   158,   146,   121,   149,    -1,    85,    -1,
      88,    -1,    56,    12,   136,   146,    -1,    11,    -1,   124,
      10,    -1,    10,    -1,   125,    10,    -1,    -1,   125,    -1,
      -1,   141,    -1,    -1,   147,    -1,   127,    -1,   127,   133,
     127,    -1,   136,    -1,   130,    -1,   130,   124,   153,    17,
      -1,   130,     9,   130,    -1,   130,     9,   130,   124,   153,
      17,    -1,   124,   153,    17,    -1,     7,   124,   153,    17,
      -1,     8,   124,   153,    17,    -1,    -1,    53,   122,    12,
     157,   146,   132,   124,   153,    17,    -1,   131,    -1,   133,
     127,   131,    -1,   136,    -1,   134,   115,   136,    -1,   156,
      68,   135,    -1,   135,    92,   135,    93,   135,    -1,   135,
     114,   135,    -1,   135,   113,   135,    -1,   135,    23,   144,
      -1,   135,    23,   135,    -1,   135,    43,   158,    -1,    12,
     137,    16,    43,   158,    -1,   135,   155,    -1,   143,    -1,
     155,    -1,   156,    68,   136,    -1,   136,    92,   136,    93,
     136,    -1,   136,   114,   136,    -1,   136,   113,   136,    -1,
     136,    37,   136,    -1,   136,    38,   136,    -1,   136,    39,
     136,    -1,   136,    40,   136,    -1,   136,    41,   136,    -1,
     136,    42,   136,    -1,   136,    23,   144,    -1,   136,    23,
     136,    -1,   136,    43,   158,    -1,    12,   137,    16,    43,
     158,    -1,   136,    13,    94,   156,    -1,   136,    13,    94,
      -1,   136,   155,    -1,   143,    -1,   155,    -1,   136,   115,
     136,    -1,   137,   115,   136,    -1,   135,    -1,   138,   115,
     135,    -1,    -1,   138,    -1,    12,   137,    16,    -1,    75,
      -1,    76,    -1,    10,    -1,    14,    -1,   141,    10,    -1,
     141,    14,    -1,    17,    -1,   142,    10,    -1,   144,    -1,
     105,   143,    -1,    -1,    15,   145,    91,    15,    -1,    16,
      -1,   146,    10,    -1,   140,   139,    13,   155,    -1,   140,
     139,    36,   155,    -1,   140,   139,    39,   155,    -1,   140,
     139,    -1,    49,   158,    18,   134,    19,    -1,    49,   158,
      -1,   136,    -1,     1,    -1,   125,    -1,    14,   126,    -1,
      46,   148,    -1,    48,   148,    -1,    -1,    -1,   116,   150,
     149,   151,    98,    12,   136,    16,   148,    -1,    51,   136,
     148,    -1,    51,   148,    -1,   118,    -1,   123,   149,   117,
     149,    -1,   123,   149,    -1,   124,   153,   142,    -1,    60,
     148,    -1,    61,   148,    -1,    97,   136,   148,    -1,    97,
     148,    -1,   147,   148,    -1,    -1,   159,   152,   149,    -1,
      14,   126,    -1,   149,    -1,   153,   149,    -1,    54,    -1,
      55,    -1,   155,    15,    68,   155,    -1,   155,   100,   155,
      -1,   155,   101,   155,    -1,   155,   102,   155,    -1,   155,
      15,   155,    -1,   155,   103,   155,    -1,   155,   106,   155,
      -1,   101,   155,    -1,   100,   155,    -1,   105,   155,    -1,
      45,    12,    16,    -1,    45,    12,   134,    16,    -1,    45,
      -1,    88,    12,    16,    -1,    88,    12,   134,    16,    -1,
      47,   155,    -1,   108,   156,    -1,   107,   156,    -1,   156,
     108,    -1,   156,   107,    -1,    94,   156,    41,   155,    -1,
      94,    41,   155,    -1,    94,   156,    -1,    94,    -1,    57,
      12,   136,   115,   136,    16,    -1,    57,    12,   136,   115,
     144,    16,    -1,    12,   136,    16,    -1,    59,    12,   136,
     115,   144,    16,    -1,    59,    12,   136,   115,   136,    16,
      -1,    89,    -1,    96,    12,   136,   115,   158,   115,   136,
      16,    -1,    96,    12,   136,   115,   158,   115,   144,    16,
      -1,    96,    12,   136,   115,   158,    16,    -1,    77,    12,
     134,    16,    -1,    90,    -1,   154,    12,   144,   115,   136,
      16,    -1,   154,    12,   136,   115,   136,    16,    -1,   154,
      12,   144,   115,   136,   115,   156,    16,    -1,   154,    12,
     136,   115,   136,   115,   156,    16,    -1,    95,    12,   136,
     115,   136,   115,   136,    16,    -1,    95,    12,   136,   115,
     136,    16,    -1,   156,    -1,   158,    -1,   158,    18,   134,
      19,    -1,    86,    -1,   109,   155,    -1,    -1,    85,    -1,
     157,   115,    85,    -1,    85,    -1,    44,    -1,    87,    -1,
      98,    12,   136,   146,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    98,    98,   100,   104,   104,   108,   108,   112,   112,
     116,   116,   120,   120,   124,   124,   126,   126,   128,   128,
     133,   134,   138,   142,   142,   146,   146,   150,   151,   155,
     156,   161,   162,   166,   167,   171,   175,   176,   177,   178,
     179,   180,   182,   184,   184,   189,   190,   194,   195,   199,
     200,   202,   204,   206,   207,   212,   213,   214,   215,   216,
     220,   221,   223,   225,   227,   228,   229,   230,   231,   232,
     233,   234,   239,   240,   241,   244,   247,   248,   249,   253,
     254,   258,   259,   263,   264,   265,   269,   269,   273,   273,
     273,   273,   277,   277,   281,   283,   287,   287,   291,   291,
     295,   298,   301,   304,   305,   306,   307,   308,   312,   313,
     317,   319,   321,   321,   321,   323,   324,   325,   326,   327,
     328,   329,   332,   335,   336,   337,   338,   338,   339,   343,
     344,   348,   348,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   378,   381,
     382,   384,   389,   390,   392,   394,   396,   397,   398,   400,
     405,   407,   412,   414,   416,   420,   421,   422,   423,   427,
     428,   429,   435,   436,   437,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FIRSTTOKEN", "PROGRAM", "PASTAT", 
  "PASTAT2", "XBEGIN", "XEND", "','", "NL", "'{'", "'('", "'|'", "';'", 
  "'/'", "')'", "'}'", "'['", "']'", "ARRAY", "MATCH", "NOTMATCH", 
  "MATCHOP", "FINAL", "DOT", "ALL", "CCL", "NCCL", "CHAR", "OR", "STAR", 
  "QUEST", "PLUS", "AND", "BOR", "APPEND", "EQ", "GE", "GT", "LE", "LT", 
  "NE", "IN", "ARG", "BLTIN", "BREAK", "CLOSE", "CONTINUE", "DELETE", 
  "DO", "EXIT", "FOR", "FUNC", "SUB", "GSUB", "IF", "INDEX", "LSUBSTR", 
  "MATCHFCN", "NEXT", "NEXTFILE", "ADD", "MINUS", "MULT", "DIVIDE", "MOD", 
  "ASSIGN", "ASGNOP", "ADDEQ", "SUBEQ", "MULTEQ", "DIVEQ", "MODEQ", 
  "POWEQ", "PRINT", "PRINTF", "SPRINTF", "ELSE", "INTEST", "CONDEXPR", 
  "POSTINCR", "PREINCR", "POSTDECR", "PREDECR", "VAR", "IVAR", "VARNF", 
  "CALL", "NUMBER", "STRING", "REGEXPR", "'?'", "':'", "GETLINE", 
  "SUBSTR", "SPLIT", "RETURN", "WHILE", "CAT", "'+'", "'-'", "'*'", "'%'", 
  "UMINUS", "NOT", "POWER", "INCR", "DECR", "INDIRECT", "LASTTOKEN", 
  "$accept", "program", "and", "bor", "comma", "do", "else", "for", "@1", 
  "@2", "@3", "funcname", "if", "lbrace", "nl", "opt_nl", "opt_pst", 
  "opt_simple_stmt", "pas", "pa_pat", "pa_stat", "@4", "pa_stats", 
  "patlist", "ppattern", "pattern", "plist", "pplist", "prarg", "print", 
  "pst", "rbrace", "re", "reg_expr", "@5", "rparen", "simple_stmt", "st", 
  "stmt", "@6", "@7", "@8", "stmtlist", "subop", "term", "var", "varlist", 
  "varname", "while", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    44,
     264,   123,    40,   124,    59,    47,    41,   125,    91,    93,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,    63,    58,   337,   338,   339,   340,   341,   342,
      43,    45,    42,    37,   343,   344,   345,   346,   347,   348,
     349
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   119,   118,   120,   118,   121,   118,
     122,   122,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   131,   131,   131,   131,
     131,   131,   131,   132,   131,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     141,   141,   142,   142,   143,   143,   145,   144,   146,   146,
     147,   147,   147,   147,   147,   147,   147,   147,   148,   148,
     149,   149,   150,   151,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   152,   149,   149,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   156,   156,   156,   156,   157,
     157,   157,   158,   158,   158,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     0,    12,     0,    10,     0,     8,
       1,     1,     4,     1,     2,     1,     2,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     1,     4,     3,     6,
       3,     4,     4,     0,     9,     1,     3,     1,     3,     3,
       5,     3,     3,     3,     3,     3,     5,     2,     1,     1,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     3,     2,     1,     1,     3,
       3,     1,     3,     0,     1,     3,     1,     1,     1,     1,
       2,     2,     1,     2,     1,     2,     0,     4,     1,     2,
       4,     4,     4,     2,     5,     2,     1,     1,     1,     2,
       2,     2,     0,     0,     9,     3,     2,     1,     4,     2,
       3,     2,     2,     3,     2,     2,     0,     3,     2,     1,
       2,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     3,     4,     1,     3,     4,     2,     2,
       2,     2,     2,     4,     3,     2,     1,     6,     6,     3,
       6,     6,     1,     8,     8,     6,     4,     1,     6,     6,
       8,     8,     8,     6,     1,     1,     4,     1,     2,     0,
       1,     3,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     3,    88,    89,     0,    33,     2,    30,     1,     0,
       0,    23,     0,    96,   183,   145,     0,     0,   131,   132,
       0,     0,     0,   182,   177,   184,     0,   162,   167,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      45,    29,    35,    77,    94,     0,    78,   174,   175,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     174,    20,    21,     0,     0,     0,     0,     0,     0,   155,
       0,     0,   141,   140,    95,   142,   150,   149,   178,   107,
      24,    27,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    86,    87,     0,     0,   112,   117,     0,     0,   106,
      83,     0,   129,     0,   126,     0,     0,    34,     0,     0,
       4,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   151,     0,     0,     0,     8,   159,     0,     0,
       0,     0,   143,     0,    47,     0,   179,     0,     0,     0,
     146,     0,   154,     0,     0,     0,    25,    28,   128,    27,
     108,   110,   111,   105,     0,   116,     0,     0,   121,   122,
       0,   124,     0,    11,     0,   119,     0,     0,    81,    84,
     103,    58,    59,   174,   125,    40,   130,     0,    38,     0,
      46,    75,    71,    70,    64,    65,    66,    67,    68,    69,
      72,     0,     5,    63,     7,    62,     0,    94,     0,   137,
     134,   135,   136,   138,   139,    60,     0,    41,    42,     9,
      79,     0,    80,    97,   144,     0,   180,     0,     0,     0,
     166,   147,   153,     0,     0,    26,   109,     0,   115,     0,
      32,   175,     0,   123,     0,   113,    12,     0,    92,   120,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,   127,     0,    37,    74,     0,     0,     0,   133,
     176,    73,    48,    98,     0,    43,     0,    94,     0,    94,
       0,     0,     0,    27,     0,    22,   185,     0,    13,   118,
      93,    85,     0,    54,    53,    55,     0,    52,    51,    82,
     100,   101,   102,    49,     0,    61,     0,     0,   181,    99,
       0,   157,   158,   161,   160,   173,     0,   165,     0,   104,
      27,     0,     0,     0,     0,     0,     0,    39,   169,     0,
     168,     0,     0,     0,     0,    94,     0,     0,    18,     0,
      56,     0,    50,     0,     0,     0,   172,   163,   164,     0,
      27,     0,     0,   171,   170,    44,    16,     0,    19,     0,
       0,     0,   114,    17,    14,     0,    15
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     4,   120,   121,   225,    95,   247,    96,   365,   360,
     351,    63,    97,    98,   160,   158,     5,   239,     6,    39,
      40,   310,    41,   143,   178,    99,    54,   179,   180,   100,
       7,   249,    43,    44,    55,   275,   101,   161,   102,   174,
     287,   187,   103,    45,    46,    47,   227,    48,   104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -323
static const short yypact[] =
{
     680,  -323,  -323,  -323,    34,  1573,  -323,   106,  -323,    29,
      29,  -323,  4106,  -323,  -323,    41,  4460,   -73,  -323,  -323,
      44,    92,   105,  -323,  -323,  -323,   113,  -323,  -323,   -11,
     121,   131,  4460,  4460,  4165,   255,   255,  4460,   812,    94,
    -323,   174,  3436,  -323,  -323,   132,   130,   -61,    30,  -323,
    -323,   812,   812,  1663,    53,    64,  3929,  4106,  4460,   130,
     -21,  -323,  -323,   159,  4106,  4106,  4106,  3988,  4460,    65,
    4106,  4106,    60,    60,  -323,    60,  -323,  -323,  -323,  -323,
    -323,   162,   188,   188,     7,  -323,  2182,   161,   196,   188,
     188,  -323,  -323,  2182,   199,   176,  -323,  1416,   812,  3436,
    4224,   188,  -323,   879,  -323,  4106,   812,  1573,   118,  4106,
    -323,  -323,  4106,  4106,  4106,  4106,  4106,  4106,     7,  4106,
    2241,  2300,   130,  4106,  4283,  4460,  4460,  4460,  4460,  4460,
    4106,  -323,  -323,  4106,   946,  1013,  -323,  -323,  2359,   157,
    2359,   202,  -323,    61,  3436,  2626,   133,  2023,  2023,    62,
    -323,    81,   130,  4460,  2023,  2023,  -323,   214,  -323,   162,
     214,  -323,  -323,   209,  2123,  -323,  1482,  4106,  -323,  -323,
    2123,  -323,  4106,  -323,  1416,   156,  1080,  4106,  3811,   237,
      83,  -323,   130,   -41,  -323,  -323,  -323,  1416,    29,  1147,
    -323,   255,  3684,  -323,  3684,  3684,  3684,  3684,  3684,  3684,
    -323,  2716,  -323,  3605,  -323,  3526,  2023,   237,  4460,    60,
      58,    58,    60,    60,    60,  3436,    22,  -323,  -323,  -323,
    3436,     7,  3436,  -323,  -323,  2359,  -323,    98,  2359,  2359,
    -323,  -323,   130,  2359,    55,  -323,  -323,  4106,  -323,   233,
    -323,    -7,  2806,  -323,  2806,  -323,  -323,  1215,  -323,   238,
     140,  4342,     7,  4342,  2418,  2477,   130,  2536,  4460,  4460,
    4460,  4342,  -323,   812,  -323,  -323,  4106,  2359,  2359,   130,
    -323,  -323,  3436,  -323,    -5,   242,  2896,   239,  2986,   241,
    1753,   149,    36,   191,     7,   242,   242,   163,  -323,  -323,
    -323,   225,  4106,  4401,  -323,  -323,  3743,  4047,  3870,  3811,
     130,   130,   130,  3811,  1282,  3436,  1843,  1933,  -323,  -323,
      29,  -323,  -323,  -323,  -323,  -323,  2359,  -323,  2359,  -323,
     162,  4106,   256,   259,     7,   154,  4342,  -323,  -323,    15,
    -323,    15,   812,  3076,  3166,   258,  1548,  3256,   242,  4106,
    -323,   225,  3811,   260,   262,  1349,  -323,  -323,  -323,   256,
     162,  1416,  3346,  -323,  -323,  -323,   242,  1548,  -323,   188,
    1416,   256,  -323,  -323,   242,  1416,  -323
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -323,  -323,  -146,   -83,   200,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,    19,   -80,  -153,   234,  -322,  -323,   179,
     172,  -323,  -323,   -44,    12,   526,  -174,  -323,  -323,  -323,
    -323,  -323,   -32,   -60,  -323,  -234,  -162,   -29,   -53,  -323,
    -323,  -323,   -13,  -323,   269,   -16,  -323,   -75,  -323
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -32
static const short yytable[] =
{
      60,   157,    74,   250,   240,   219,   236,   130,   285,   163,
     286,   133,    61,    69,   349,    62,    60,    60,    60,    76,
      77,    60,   149,   151,    38,   219,    60,   261,    51,    52,
      68,   136,   254,    14,     8,   361,   284,    60,   134,   135,
      11,   270,    60,   200,   175,   136,   131,   132,   133,   193,
     186,    14,    60,    56,   162,   319,    64,   165,   106,    14,
     168,   169,   136,   207,   171,   219,   131,   132,   181,   139,
     136,   136,   184,   124,    23,    24,    25,   224,   230,   157,
     308,   186,   186,    60,   183,   176,   131,   132,   338,   216,
     136,   241,    23,   189,    25,   255,   258,   231,    37,    14,
      23,    24,    25,   105,    65,    11,   153,   136,    60,    60,
      60,    60,    60,    60,   273,   356,    49,    66,   325,   259,
      50,   245,   260,   186,    37,    67,    38,   364,    60,    60,
     321,    60,    60,    70,   262,   238,   186,    60,    60,    60,
      23,   243,    25,    71,   123,   124,   271,   254,    60,   136,
     254,   254,   254,   254,    60,   141,   291,   254,   136,   281,
     127,   128,    60,   136,   129,   317,   129,   336,   277,   279,
     341,   146,   156,   166,   240,   265,    60,   295,    60,    60,
      60,    60,    60,    60,     2,    60,   173,    60,     3,    60,
      60,   294,    60,   282,   289,   240,   254,   357,   156,    60,
     221,   156,   159,   157,    60,   320,    60,   263,   167,   322,
     255,   172,   191,   255,   255,   255,   255,   223,   226,   181,
     255,   181,   181,   181,   235,   181,    60,   237,    60,   181,
     125,   126,   127,   128,   246,   183,   129,   183,   183,   183,
     157,   183,    60,    60,    60,   183,   136,   283,   290,   340,
     304,   186,   309,   138,   140,   312,    60,   314,   335,   255,
      60,   323,    60,   293,    60,   296,   297,   298,   324,   299,
     157,   339,   273,   303,   348,   107,   353,    60,   354,   190,
      60,    60,    60,    60,   188,    59,     0,    60,     0,    60,
      60,    60,   186,     0,   181,     0,     0,     0,   358,    14,
       0,    72,    73,    75,     0,     0,    78,   363,     0,     0,
     183,   122,   366,   343,     0,   344,     0,    60,    60,   345,
       0,    60,   122,     0,     0,     0,    60,    75,     0,   332,
     362,     0,     0,     0,     0,     0,    60,   152,   342,     0,
      23,    24,    25,     0,     0,     0,     0,   228,   229,     0,
       0,     0,     0,     0,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,   122,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   210,   211,   212,   213,   214,     0,
       0,     0,     0,     0,     0,     0,   267,   268,     0,     0,
       0,     0,     0,   122,   122,     0,   122,   122,     0,     0,
       0,     0,   232,   122,   122,     0,     0,   274,     0,     0,
       0,     0,     0,   122,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   122,   122,   122,   122,   122,   122,     0,
     122,     0,   122,     0,   122,   122,     0,   269,     0,     0,
     316,   318,     0,     0,   122,     0,     0,     0,     0,   122,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   329,   331,     0,     0,
       0,   122,     0,   122,     0,     0,     0,     0,     0,     0,
     182,     0,   182,   182,   182,   140,   182,   300,   301,   302,
     182,    42,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   122,     0,     0,     0,   122,     0,   122,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,   256,   256,   256,   256,     0,
       0,     0,   256,     0,   122,   122,   122,     0,     0,     0,
       0,     0,   144,   145,     0,     0,     0,     0,     0,     0,
     147,   148,   144,   144,     0,   182,   154,   155,     0,     0,
       0,     0,   122,   122,     0,     0,   122,     0,     0,     0,
       0,   256,   164,     0,     0,     0,     0,     0,     0,   170,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    42,     0,   192,     0,     0,   194,   195,
     196,   197,   198,   199,     0,   201,   203,   205,     0,   206,
       0,     0,     0,     0,     0,     0,   215,     0,     0,   144,
       0,     0,     0,     0,   220,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -29,     1,     0,     0,     0,     0,     0,   -29,   -29,     0,
       2,   -29,   -29,   242,     3,   -29,     0,     0,   244,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -29,   -29,     0,   -29,     0,     0,
       0,     0,     0,   -29,   -29,   -29,     0,   -29,     0,   -29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,   276,   278,     0,   -29,     0,   280,
       0,     0,     0,   144,     0,   -29,   -29,   -29,   -29,   -29,
     -29,     0,     0,     0,   -29,   -29,   -29,     0,     0,     0,
     -29,   -29,     0,     0,     0,   -29,     0,   -29,   -29,   -29,
       0,     0,   305,   306,   307,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,    53,     0,
       0,     0,    80,    11,    12,     0,    81,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,   334,     0,     0,   337,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    82,    16,
      83,    84,    85,    86,    87,   352,    18,    19,    88,    20,
       0,    21,    89,    90,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,    91,    92,    22,
      11,    12,     0,    81,    13,     0,   185,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    93,
      94,     0,    32,    33,     0,     0,     0,    34,     0,    35,
      36,    37,     0,    14,    15,    82,    16,    83,    84,    85,
      86,    87,     0,    18,    19,    88,    20,     0,    21,    89,
      90,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,    91,    92,    22,    11,    12,     0,
      81,    13,     0,   217,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    93,    94,     0,    32,
      33,     0,     0,     0,    34,     0,    35,    36,    37,     0,
      14,    15,    82,    16,    83,    84,    85,    86,    87,     0,
      18,    19,    88,    20,     0,    21,    89,    90,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,    91,    92,    22,    11,    12,     0,    81,    13,     0,
     218,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    93,    94,     0,    32,    33,     0,     0,
       0,    34,     0,    35,    36,    37,     0,    14,    15,    82,
      16,    83,    84,    85,    86,    87,     0,    18,    19,    88,
      20,     0,    21,    89,    90,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,    91,    92,
      22,    11,    12,     0,    81,    13,     0,   248,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      93,    94,     0,    32,    33,     0,     0,     0,    34,     0,
      35,    36,    37,     0,    14,    15,    82,    16,    83,    84,
      85,    86,    87,     0,    18,    19,    88,    20,     0,    21,
      89,    90,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,    91,    92,    22,    11,    12,
       0,    81,    13,     0,   264,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    93,    94,     0,
      32,    33,     0,     0,     0,    34,     0,    35,    36,    37,
       0,    14,    15,    82,    16,    83,    84,    85,    86,    87,
       0,    18,    19,    88,    20,     0,    21,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,    91,    92,    22,   288,    11,    12,     0,    81,
      13,     0,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    93,    94,     0,    32,    33,     0,
       0,     0,    34,     0,    35,    36,    37,     0,     0,    14,
      15,    82,    16,    83,    84,    85,    86,    87,     0,    18,
      19,    88,    20,     0,    21,    89,    90,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
      91,    92,    22,    11,    12,     0,    81,    13,     0,   327,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    93,    94,     0,    32,    33,     0,     0,     0,
      34,     0,    35,    36,    37,     0,    14,    15,    82,    16,
      83,    84,    85,    86,    87,     0,    18,    19,    88,    20,
       0,    21,    89,    90,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,    91,    92,    22,
      11,    12,     0,    81,    13,     0,   355,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    93,
      94,     0,    32,    33,     0,     0,     0,    34,     0,    35,
      36,    37,     0,    14,    15,    82,    16,    83,    84,    85,
      86,    87,     0,    18,    19,    88,    20,     0,    21,    89,
      90,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,    91,    92,    22,    11,    12,     0,
      81,    13,     0,     0,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    93,    94,     0,    32,
      33,     0,     0,     0,    34,     0,    35,    36,    37,     0,
      14,    15,    82,    16,    83,    84,    85,    86,    87,     0,
      18,    19,    88,    20,     0,    21,    89,    90,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    22,    12,     0,   -31,    13,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    93,    94,     0,    32,    33,     0,     0,
       0,    34,     0,    35,    36,    37,    14,    15,     0,    16,
       0,    84,     0,     0,     0,     0,    18,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    22,
      12,     0,     0,    13,   -31,     0,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,     0,
       9,    10,    32,    33,    11,    12,     0,    34,    13,    35,
      36,    37,    14,    15,     0,    16,     0,    84,     0,     0,
       0,     0,    18,    19,     0,    20,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     0,    91,    92,    22,    17,    18,    19,     0,
      20,     0,    21,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,     0,     0,     0,    32,    33,
      22,     0,     0,    34,     0,    35,    36,    37,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
       0,     0,   136,    32,    33,    57,   108,     0,    34,   137,
      35,    36,    37,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,   136,    32,    33,    57,   108,     0,    58,   315,
      35,    36,    37,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,   136,    32,    33,    57,   108,     0,    58,   328,
      35,    36,    37,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,   136,    32,    33,    57,   108,     0,    58,   330,
      35,    36,    37,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,   136,    32,    33,    57,   108,     0,    58,     0,
      35,    36,    37,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,     0,    32,    33,     0,     0,     0,    58,     0,
      35,    36,    37,   156,     0,    57,   108,   159,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,   117,   118,    14,    15,     0,
      16,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,    12,     0,   159,    13,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   119,     0,    29,    30,    31,
       0,     0,     0,    32,    33,     0,    14,    15,    58,    16,
      35,    36,    37,     0,     0,     0,    18,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,     0,    12,     0,     0,    13,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,     0,
       0,     0,    32,    33,     0,    14,    15,    34,    16,    35,
      36,    37,     0,     0,     0,    18,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,    12,     0,     0,    13,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,     0,     0,
       0,    32,    33,     0,    14,    15,    34,    16,    35,    36,
      37,     0,     0,     0,    18,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
       0,    12,     0,     0,    13,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,     0,     0,     0,
      32,    33,     0,    14,    15,    34,    16,    35,    36,    37,
       0,     0,     0,    18,    19,     0,    20,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
     292,     0,     0,    13,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,     0,     0,     0,    32,
      33,     0,    14,    15,    34,    16,    35,    36,    37,     0,
       0,     0,    18,    19,     0,    20,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,     0,   292,
       0,     0,    13,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,     0,     0,     0,    32,    33,
       0,    14,    15,    34,    16,    35,    36,    37,     0,     0,
       0,    18,    19,     0,    20,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,     0,   292,     0,
       0,    13,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,     0,     0,     0,    32,    33,     0,
      14,    15,    34,    16,    35,    36,    37,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    34,   137,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,     0,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,   266,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   273,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   311,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   313,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   346,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   347,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
     350,    58,     0,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,   359,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,     0,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,   119,     0,
      29,    30,    31,     0,     0,     0,    32,    33,    57,   108,
       0,    58,     0,    35,    36,    37,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,   112,   113,   114,   115,   116,   117,   118,
      14,    15,     0,    16,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    57,   108,     0,
      29,    30,    31,     0,     0,     0,    32,    33,   109,     0,
       0,    58,     0,    35,    36,    37,     0,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,    14,
      15,     0,    16,     0,     0,     0,     0,     0,     0,    18,
      19,     0,    20,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    57,   -32,     0,    29,
      30,    31,     0,     0,     0,    32,    33,   -32,     0,     0,
      58,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       0,   -32,   -32,   -32,   -32,   -32,   -32,   -32,    14,    15,
       0,    16,     0,     0,     0,     0,     0,     0,    18,    19,
       0,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,   251,     0,     0,    23,
      24,    25,    26,    27,    28,     0,     0,   110,   111,    30,
      31,     0,     0,     0,    32,    33,   252,    14,    15,    58,
      16,    35,    36,    37,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,    57,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,   251,   253,   326,    29,    30,    31,
       0,     0,     0,    32,    33,   110,   111,     0,    58,     0,
      35,    36,    37,     0,   252,    14,    15,     0,    16,     0,
       0,     0,     0,     0,     0,    18,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,   251,     0,     0,    23,    24,    25,    26,
      27,    28,     0,   253,   110,    29,    30,    31,     0,     0,
       0,    32,    33,   252,    14,    15,    58,    16,    35,    36,
      37,     0,     0,     0,    18,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    13,   142,     0,    22,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,     0,     0,     0,
      32,    33,     0,    14,    15,    58,    16,    35,    36,    37,
       0,     0,     0,    18,    19,     0,    20,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,    13,   150,     0,    22,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,     0,     0,     0,    32,
      33,     0,    14,    15,    34,    16,    35,    36,    37,     0,
       0,     0,    18,    19,     0,    20,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
     251,     0,     0,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,     0,     0,     0,    32,    33,
     252,    14,    15,    34,    16,    35,    36,    37,     0,     0,
       0,    18,    19,     0,    20,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,    13,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,     0,     0,     0,    32,    33,     0,
      14,    15,    58,    16,    35,    36,    37,     0,     0,     0,
      18,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
      13,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,     0,     0,     0,    32,    33,     0,    14,
      15,    34,    16,    35,    36,    37,     0,     0,     0,    18,
      19,     0,    20,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,     0,     0,    13,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,     0,     0,     0,    32,    33,     0,    14,    15,
      34,    16,    35,    36,    37,     0,     0,     0,    18,    19,
       0,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,     0,     0,     0,    32,    33,     0,    14,    15,    34,
      16,    35,    36,    37,     0,     0,     0,    18,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   292,     0,     0,    13,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
       0,     0,     0,    32,    33,     0,    14,    15,    58,    16,
      35,    36,    37,     0,     0,     0,    18,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,   -32,     0,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,     0,
       0,     0,    32,    33,   -32,    14,    15,    34,    16,    35,
      36,    37,     0,     0,     0,    18,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,    30,    31,     0,     0,
       0,    32,    33,     0,    14,    15,    58,    16,    35,    36,
      37,     0,     0,     0,    18,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,     0,     0,     0,
      32,    33,     0,     0,     0,    58,     0,    35,    36,    37
};

static const short yycheck[] =
{
      16,    81,    34,   177,   166,    10,   159,    68,   242,    84,
     244,    18,    85,    29,   336,    88,    32,    33,    34,    35,
      36,    37,    66,    67,     5,    10,    42,    68,     9,    10,
      41,     9,   178,    44,     0,   357,    43,    53,    51,    52,
      11,    19,    58,   118,    97,     9,   107,   108,    18,   109,
     103,    44,    68,    12,    83,    19,    12,    86,    39,    44,
      89,    90,     9,   123,    93,    10,   107,   108,   100,    16,
       9,     9,   101,    15,    85,    86,    87,    16,    16,   159,
      85,   134,   135,    99,   100,    98,   107,   108,   322,   133,
       9,   166,    85,   106,    87,   178,    13,    16,   109,    44,
      85,    86,    87,     9,    12,    11,    41,     9,   124,   125,
     126,   127,   128,   129,    16,   349,    10,    12,   292,    36,
      14,   174,    39,   176,   109,    12,   107,   361,   144,   145,
     283,   147,   148,    12,   187,   164,   189,   153,   154,   155,
      85,   170,    87,    12,    12,    15,   221,   293,   164,     9,
     296,   297,   298,   299,   170,    91,    16,   303,     9,   234,
     102,   103,   178,     9,   106,    16,   106,   320,   228,   229,
      16,    12,    10,    12,   336,   191,   192,   252,   194,   195,
     196,   197,   198,   199,    10,   201,    10,   203,    14,   205,
     206,   251,   208,   237,   247,   357,   342,   350,    10,   215,
      43,    10,    14,   283,   220,    14,   222,   188,    12,   284,
     293,    12,    94,   296,   297,   298,   299,    15,    85,   251,
     303,   253,   254,   255,    10,   257,   242,    18,   244,   261,
     100,   101,   102,   103,    78,   251,   106,   253,   254,   255,
     320,   257,   258,   259,   260,   261,     9,    14,    10,   324,
     263,   304,    10,    53,    54,    16,   272,    16,   318,   342,
     276,    98,   278,   251,   280,   253,   254,   255,    43,   257,
     350,    12,    16,   261,    16,    41,    16,   293,    16,   107,
     296,   297,   298,   299,   105,    16,    -1,   303,    -1,   305,
     306,   307,   345,    -1,   326,    -1,    -1,    -1,   351,    44,
      -1,    32,    33,    34,    -1,    -1,    37,   360,    -1,    -1,
     326,    42,   365,   329,    -1,   331,    -1,   333,   334,   332,
      -1,   337,    53,    -1,    -1,    -1,   342,    58,    -1,   310,
     359,    -1,    -1,    -1,    -1,    -1,   352,    68,   326,    -1,
      85,    86,    87,    -1,    -1,    -1,    -1,   147,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,   147,   148,    -1,    -1,
      -1,    -1,   153,   154,   155,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,    -1,
     201,    -1,   203,    -1,   205,   206,    -1,   208,    -1,    -1,
     280,   281,    -1,    -1,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   306,   307,    -1,    -1,
      -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,   254,   255,   325,   257,   258,   259,   260,
     261,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,   272,    -1,    -1,    -1,   276,    -1,   278,    -1,   280,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   293,    -1,    -1,   296,   297,   298,   299,    -1,
      -1,    -1,   303,    -1,   305,   306,   307,    -1,    -1,    -1,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,   326,    70,    71,    -1,    -1,
      -1,    -1,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,
      -1,   342,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
      10,    11,    12,   167,    14,    15,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,    -1,   228,   229,    -1,    77,    -1,   233,
      -1,    -1,    -1,   237,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,    -1,   107,   108,   109,
      -1,    -1,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   316,    -1,   318,    -1,    -1,   321,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   339,    54,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      11,    12,    -1,    14,    15,    -1,    17,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,   107,
     108,   109,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    11,    12,    -1,
      14,    15,    -1,    17,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    11,    12,    -1,    14,    15,    -1,
      17,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,    -1,    -1,
      -1,   105,    -1,   107,   108,   109,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    11,    12,    -1,    14,    15,    -1,    17,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,
     107,   108,   109,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    11,    12,
      -1,    14,    15,    -1,    17,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,    -1,    -1,    -1,   105,    -1,   107,   108,   109,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    10,    11,    12,    -1,    14,
      15,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    11,    12,    -1,    14,    15,    -1,    17,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      11,    12,    -1,    14,    15,    -1,    17,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,   107,
     108,   109,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    11,    12,    -1,
      14,    15,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    12,    -1,    14,    15,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,    -1,    -1,
      -1,   105,    -1,   107,   108,   109,    44,    45,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      12,    -1,    -1,    15,    16,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
       7,     8,   100,   101,    11,    12,    -1,   105,    15,   107,
     108,   109,    44,    45,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    -1,    75,    76,    77,    53,    54,    55,    -1,
      57,    -1,    59,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,
      77,    -1,    -1,   105,    -1,   107,   108,   109,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      -1,    -1,     9,   100,   101,    12,    13,    -1,   105,    16,
     107,   108,   109,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,     9,   100,   101,    12,    13,    -1,   105,    16,
     107,   108,   109,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,     9,   100,   101,    12,    13,    -1,   105,    16,
     107,   108,   109,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,     9,   100,   101,    12,    13,    -1,   105,    16,
     107,   108,   109,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,     9,   100,   101,    12,    13,    -1,   105,    -1,
     107,   108,   109,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,
     107,   108,   109,    10,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,    -1,    44,    45,   105,    47,
     107,   108,   109,    -1,    -1,    -1,    54,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    12,    -1,    -1,    15,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,   101,    -1,    44,    45,   105,    47,   107,
     108,   109,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    12,    -1,    -1,    15,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,
      -1,   100,   101,    -1,    44,    45,   105,    47,   107,   108,
     109,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    12,    -1,    -1,    15,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
     100,   101,    -1,    44,    45,   105,    47,   107,   108,   109,
      -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      12,    -1,    -1,    15,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
     101,    -1,    44,    45,   105,    47,   107,   108,   109,    -1,
      -1,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    12,
      -1,    -1,    15,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,
      -1,    44,    45,   105,    47,   107,   108,   109,    -1,    -1,
      -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    12,    -1,
      -1,    15,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,    -1,
      44,    45,   105,    47,   107,   108,   109,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    -1,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      14,   105,    -1,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    16,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    -1,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    12,    13,
      -1,   105,    -1,   107,   108,   109,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    12,    13,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    23,    -1,
      -1,   105,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    12,    13,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,   101,    23,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    23,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    34,    35,    95,
      96,    -1,    -1,    -1,   100,   101,    43,    44,    45,   105,
      47,   107,   108,   109,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    12,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    23,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,    34,    35,    -1,   105,    -1,
     107,   108,   109,    -1,    43,    44,    45,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    34,    94,    95,    96,    -1,    -1,
      -1,   100,   101,    43,    44,    45,   105,    47,   107,   108,
     109,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
     100,   101,    -1,    44,    45,   105,    47,   107,   108,   109,
      -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
     101,    -1,    44,    45,   105,    47,   107,   108,   109,    -1,
      -1,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,
      43,    44,    45,   105,    47,   107,   108,   109,    -1,    -1,
      -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,    -1,
      44,    45,   105,    47,   107,   108,   109,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    -1,    -1,    -1,   100,   101,    -1,    44,
      45,   105,    47,   107,   108,   109,    -1,    -1,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,   101,    -1,    44,    45,
     105,    47,   107,   108,   109,    -1,    -1,    -1,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,   101,    -1,    44,    45,   105,
      47,   107,   108,   109,    -1,    -1,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,    -1,    44,    45,   105,    47,
     107,   108,   109,    -1,    -1,    -1,    54,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,   101,    43,    44,    45,   105,    47,   107,
     108,   109,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,   100,   101,    -1,    44,    45,   105,    47,   107,   108,
     109,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,    -1,   107,   108,   109
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,    10,    14,   112,   127,   129,   141,     0,     7,
       8,    11,    12,    15,    44,    45,    47,    53,    54,    55,
      57,    59,    77,    85,    86,    87,    88,    89,    90,    94,
      95,    96,   100,   101,   105,   107,   108,   109,   124,   130,
     131,   133,   136,   143,   144,   154,   155,   156,   158,    10,
      14,   124,   124,   136,   137,   145,    12,    12,   105,   155,
     156,    85,    88,   122,    12,    12,    12,    12,    41,   156,
      12,    12,   155,   155,   143,   155,   156,   156,   155,     1,
      10,    14,    46,    48,    49,    50,    51,    52,    56,    60,
      61,    75,    76,    97,    98,   116,   118,   123,   124,   136,
     140,   147,   149,   153,   159,     9,   124,   127,    13,    23,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    92,
     113,   114,   155,    12,    15,   100,   101,   102,   103,   106,
      68,   107,   108,    18,   153,   153,     9,    16,   115,    16,
     115,    91,    16,   134,   136,   136,    12,   136,   136,   134,
      16,   134,   155,    41,   136,   136,    10,   125,   126,    14,
     125,   148,   148,   158,   136,   148,    12,    12,   148,   148,
     136,   148,    12,    10,   150,   149,   153,    12,   135,   138,
     139,   143,   155,   156,   148,    17,   149,   152,   130,   153,
     131,    94,   136,   144,   136,   136,   136,   136,   136,   136,
     158,   136,    10,   136,    10,   136,   136,   144,    68,   155,
     155,   155,   155,   155,   155,   136,   134,    17,    17,    10,
     136,    43,   136,    15,    16,   115,    85,   157,   115,   115,
      16,    16,   155,   115,   115,    10,   126,    18,   148,   128,
     147,   158,   136,   148,   136,   149,    78,   117,    17,   142,
     137,    23,    43,    92,   113,   114,   155,   115,    13,    36,
      39,    68,   149,   124,    17,   156,    93,   115,   115,   155,
      19,   158,   136,    16,   115,   146,   136,   144,   136,   144,
     136,   158,   134,    14,    43,   146,   146,   151,    10,   149,
      10,    16,    12,   135,   144,   158,   135,   135,   135,   135,
     155,   155,   155,   135,   153,   136,   136,   136,    85,    10,
     132,    16,    16,    16,    16,    16,   115,    16,   115,    19,
      14,   126,   158,    98,    43,   137,    93,    17,    16,   115,
      16,   115,   124,   136,   136,   144,   126,   136,   146,    12,
     158,    16,   135,   156,   156,   153,    16,    16,    16,   128,
      14,   121,   136,    16,    16,    17,   146,   126,   149,    16,
     120,   128,   148,   149,   146,   119,   149
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "awkgram.y"
    { if (errorflag==0)
			winner = (Node *)stat3(PROGRAM, beginloc, yyvsp[0].p, endloc); }
    break;

  case 3:
#line 100 "awkgram.y"
    { yyclearin; bracecheck(); SYNTAX("bailing out"); }
    break;

  case 14:
#line 124 "awkgram.y"
    {inloop++;}
    break;

  case 15:
#line 125 "awkgram.y"
    { --inloop; yyval.p = stat4(FOR, yyvsp[-9].p, notnull(yyvsp[-6].p), yyvsp[-3].p, yyvsp[0].p); }
    break;

  case 16:
#line 126 "awkgram.y"
    {inloop++;}
    break;

  case 17:
#line 127 "awkgram.y"
    { --inloop; yyval.p = stat4(FOR, yyvsp[-7].p, NIL, yyvsp[-3].p, yyvsp[0].p); }
    break;

  case 18:
#line 128 "awkgram.y"
    {inloop++;}
    break;

  case 19:
#line 129 "awkgram.y"
    { --inloop; yyval.p = stat3(IN, yyvsp[-5].p, makearr(yyvsp[-3].p), yyvsp[0].p); }
    break;

  case 20:
#line 133 "awkgram.y"
    { setfname(yyvsp[0].cp); }
    break;

  case 21:
#line 134 "awkgram.y"
    { setfname(yyvsp[0].cp); }
    break;

  case 22:
#line 138 "awkgram.y"
    { yyval.p = notnull(yyvsp[-1].p); }
    break;

  case 27:
#line 150 "awkgram.y"
    { yyval.i = 0; }
    break;

  case 29:
#line 155 "awkgram.y"
    { yyval.i = 0; }
    break;

  case 31:
#line 161 "awkgram.y"
    { yyval.p = 0; }
    break;

  case 33:
#line 166 "awkgram.y"
    { yyval.p = 0; }
    break;

  case 34:
#line 167 "awkgram.y"
    { yyval.p = yyvsp[-1].p; }
    break;

  case 35:
#line 171 "awkgram.y"
    { yyval.p = notnull(yyvsp[0].p); }
    break;

  case 36:
#line 175 "awkgram.y"
    { yyval.p = stat2(PASTAT, yyvsp[0].p, stat2(PRINT, rectonode(), NIL)); }
    break;

  case 37:
#line 176 "awkgram.y"
    { yyval.p = stat2(PASTAT, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 38:
#line 177 "awkgram.y"
    { yyval.p = pa2stat(yyvsp[-2].p, yyvsp[0].p, stat2(PRINT, rectonode(), NIL)); }
    break;

  case 39:
#line 178 "awkgram.y"
    { yyval.p = pa2stat(yyvsp[-5].p, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 40:
#line 179 "awkgram.y"
    { yyval.p = stat2(PASTAT, NIL, yyvsp[-1].p); }
    break;

  case 41:
#line 181 "awkgram.y"
    { beginloc = linkum(beginloc, yyvsp[-1].p); yyval.p = 0; }
    break;

  case 42:
#line 183 "awkgram.y"
    { endloc = linkum(endloc, yyvsp[-1].p); yyval.p = 0; }
    break;

  case 43:
#line 184 "awkgram.y"
    {infunc++;}
    break;

  case 44:
#line 185 "awkgram.y"
    { infunc--; curfname=0; defn((Cell *)yyvsp[-7].p, yyvsp[-5].p, yyvsp[-1].p); yyval.p = 0; }
    break;

  case 46:
#line 190 "awkgram.y"
    { yyval.p = linkum(yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 48:
#line 195 "awkgram.y"
    { yyval.p = linkum(yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 49:
#line 199 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 50:
#line 201 "awkgram.y"
    { yyval.p = op3(CONDEXPR, notnull(yyvsp[-4].p), yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 51:
#line 203 "awkgram.y"
    { yyval.p = op2(BOR, notnull(yyvsp[-2].p), notnull(yyvsp[0].p)); }
    break;

  case 52:
#line 205 "awkgram.y"
    { yyval.p = op2(AND, notnull(yyvsp[-2].p), notnull(yyvsp[0].p)); }
    break;

  case 53:
#line 206 "awkgram.y"
    { yyval.p = op3(yyvsp[-1].i, NIL, yyvsp[-2].p, (Node*)makedfa(yyvsp[0].s, 0)); }
    break;

  case 54:
#line 208 "awkgram.y"
    { if (constnode(yyvsp[0].p))
			yyval.p = op3(yyvsp[-1].i, NIL, yyvsp[-2].p, (Node*)makedfa(strnode(yyvsp[0].p), 0));
		  else
			yyval.p = op3(yyvsp[-1].i, (Node *)1, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 55:
#line 212 "awkgram.y"
    { yyval.p = op2(INTEST, yyvsp[-2].p, makearr(yyvsp[0].p)); }
    break;

  case 56:
#line 213 "awkgram.y"
    { yyval.p = op2(INTEST, yyvsp[-3].p, makearr(yyvsp[0].p)); }
    break;

  case 57:
#line 214 "awkgram.y"
    { yyval.p = op2(CAT, yyvsp[-1].p, yyvsp[0].p); }
    break;

  case 60:
#line 220 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 61:
#line 222 "awkgram.y"
    { yyval.p = op3(CONDEXPR, notnull(yyvsp[-4].p), yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 62:
#line 224 "awkgram.y"
    { yyval.p = op2(BOR, notnull(yyvsp[-2].p), notnull(yyvsp[0].p)); }
    break;

  case 63:
#line 226 "awkgram.y"
    { yyval.p = op2(AND, notnull(yyvsp[-2].p), notnull(yyvsp[0].p)); }
    break;

  case 64:
#line 227 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 65:
#line 228 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 66:
#line 229 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 67:
#line 230 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 68:
#line 231 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 69:
#line 232 "awkgram.y"
    { yyval.p = op2(yyvsp[-1].i, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 70:
#line 233 "awkgram.y"
    { yyval.p = op3(yyvsp[-1].i, NIL, yyvsp[-2].p, (Node*)makedfa(yyvsp[0].s, 0)); }
    break;

  case 71:
#line 235 "awkgram.y"
    { if (constnode(yyvsp[0].p))
			yyval.p = op3(yyvsp[-1].i, NIL, yyvsp[-2].p, (Node*)makedfa(strnode(yyvsp[0].p), 0));
		  else
			yyval.p = op3(yyvsp[-1].i, (Node *)1, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 72:
#line 239 "awkgram.y"
    { yyval.p = op2(INTEST, yyvsp[-2].p, makearr(yyvsp[0].p)); }
    break;

  case 73:
#line 240 "awkgram.y"
    { yyval.p = op2(INTEST, yyvsp[-3].p, makearr(yyvsp[0].p)); }
    break;

  case 74:
#line 241 "awkgram.y"
    { 
			if (safe) SYNTAX("cmd | getline is unsafe");
			else yyval.p = op3(GETLINE, yyvsp[0].p, itonp(yyvsp[-2].i), yyvsp[-3].p); }
    break;

  case 75:
#line 244 "awkgram.y"
    { 
			if (safe) SYNTAX("cmd | getline is unsafe");
			else yyval.p = op3(GETLINE, (Node*)0, itonp(yyvsp[-1].i), yyvsp[-2].p); }
    break;

  case 76:
#line 247 "awkgram.y"
    { yyval.p = op2(CAT, yyvsp[-1].p, yyvsp[0].p); }
    break;

  case 79:
#line 253 "awkgram.y"
    { yyval.p = linkum(yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 80:
#line 254 "awkgram.y"
    { yyval.p = linkum(yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 82:
#line 259 "awkgram.y"
    { yyval.p = linkum(yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 83:
#line 263 "awkgram.y"
    { yyval.p = rectonode(); }
    break;

  case 85:
#line 265 "awkgram.y"
    { yyval.p = yyvsp[-1].p; }
    break;

  case 94:
#line 282 "awkgram.y"
    { yyval.p = op3(MATCH, NIL, rectonode(), (Node*)makedfa(yyvsp[0].s, 0)); }
    break;

  case 95:
#line 283 "awkgram.y"
    { yyval.p = op1(NOT, notnull(yyvsp[0].p)); }
    break;

  case 96:
#line 287 "awkgram.y"
    {startreg();}
    break;

  case 97:
#line 287 "awkgram.y"
    { yyval.s = yyvsp[-1].s; }
    break;

  case 100:
#line 295 "awkgram.y"
    { 
			if (safe) SYNTAX("print | is unsafe");
			else yyval.p = stat3(yyvsp[-3].i, yyvsp[-2].p, itonp(yyvsp[-1].i), yyvsp[0].p); }
    break;

  case 101:
#line 298 "awkgram.y"
    {
			if (safe) SYNTAX("print >> is unsafe");
			else yyval.p = stat3(yyvsp[-3].i, yyvsp[-2].p, itonp(yyvsp[-1].i), yyvsp[0].p); }
    break;

  case 102:
#line 301 "awkgram.y"
    {
			if (safe) SYNTAX("print > is unsafe");
			else yyval.p = stat3(yyvsp[-3].i, yyvsp[-2].p, itonp(yyvsp[-1].i), yyvsp[0].p); }
    break;

  case 103:
#line 304 "awkgram.y"
    { yyval.p = stat3(yyvsp[-1].i, yyvsp[0].p, NIL, NIL); }
    break;

  case 104:
#line 305 "awkgram.y"
    { yyval.p = stat2(DELETE, makearr(yyvsp[-3].p), yyvsp[-1].p); }
    break;

  case 105:
#line 306 "awkgram.y"
    { yyval.p = stat2(DELETE, makearr(yyvsp[0].p), 0); }
    break;

  case 106:
#line 307 "awkgram.y"
    { yyval.p = exptostat(yyvsp[0].p); }
    break;

  case 107:
#line 308 "awkgram.y"
    { yyclearin; SYNTAX("illegal statement"); }
    break;

  case 110:
#line 317 "awkgram.y"
    { if (!inloop) SYNTAX("break illegal outside of loops");
				  yyval.p = stat1(BREAK, NIL); }
    break;

  case 111:
#line 319 "awkgram.y"
    {  if (!inloop) SYNTAX("continue illegal outside of loops");
				  yyval.p = stat1(CONTINUE, NIL); }
    break;

  case 112:
#line 321 "awkgram.y"
    {inloop++;}
    break;

  case 113:
#line 321 "awkgram.y"
    {--inloop;}
    break;

  case 114:
#line 322 "awkgram.y"
    { yyval.p = stat2(DO, yyvsp[-6].p, notnull(yyvsp[-2].p)); }
    break;

  case 115:
#line 323 "awkgram.y"
    { yyval.p = stat1(EXIT, yyvsp[-1].p); }
    break;

  case 116:
#line 324 "awkgram.y"
    { yyval.p = stat1(EXIT, NIL); }
    break;

  case 118:
#line 326 "awkgram.y"
    { yyval.p = stat3(IF, yyvsp[-3].p, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 119:
#line 327 "awkgram.y"
    { yyval.p = stat3(IF, yyvsp[-1].p, yyvsp[0].p, NIL); }
    break;

  case 120:
#line 328 "awkgram.y"
    { yyval.p = yyvsp[-1].p; }
    break;

  case 121:
#line 329 "awkgram.y"
    { if (infunc)
				SYNTAX("next is illegal inside a function");
			  yyval.p = stat1(NEXT, NIL); }
    break;

  case 122:
#line 332 "awkgram.y"
    { if (infunc)
				SYNTAX("nextfile is illegal inside a function");
			  yyval.p = stat1(NEXTFILE, NIL); }
    break;

  case 123:
#line 335 "awkgram.y"
    { yyval.p = stat1(RETURN, yyvsp[-1].p); }
    break;

  case 124:
#line 336 "awkgram.y"
    { yyval.p = stat1(RETURN, NIL); }
    break;

  case 126:
#line 338 "awkgram.y"
    {inloop++;}
    break;

  case 127:
#line 338 "awkgram.y"
    { --inloop; yyval.p = stat2(WHILE, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 128:
#line 339 "awkgram.y"
    { yyval.p = 0; }
    break;

  case 130:
#line 344 "awkgram.y"
    { yyval.p = linkum(yyvsp[-1].p, yyvsp[0].p); }
    break;

  case 133:
#line 352 "awkgram.y"
    { yyval.p = op2(DIVEQ, yyvsp[-3].p, yyvsp[0].p); }
    break;

  case 134:
#line 353 "awkgram.y"
    { yyval.p = op2(ADD, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 135:
#line 354 "awkgram.y"
    { yyval.p = op2(MINUS, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 136:
#line 355 "awkgram.y"
    { yyval.p = op2(MULT, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 137:
#line 356 "awkgram.y"
    { yyval.p = op2(DIVIDE, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 138:
#line 357 "awkgram.y"
    { yyval.p = op2(MOD, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 139:
#line 358 "awkgram.y"
    { yyval.p = op2(POWER, yyvsp[-2].p, yyvsp[0].p); }
    break;

  case 140:
#line 359 "awkgram.y"
    { yyval.p = op1(UMINUS, yyvsp[0].p); }
    break;

  case 141:
#line 360 "awkgram.y"
    { yyval.p = yyvsp[0].p; }
    break;

  case 142:
#line 361 "awkgram.y"
    { yyval.p = op1(NOT, notnull(yyvsp[0].p)); }
    break;

  case 143:
#line 362 "awkgram.y"
    { yyval.p = op2(BLTIN, itonp(yyvsp[-2].i), rectonode()); }
    break;

  case 144:
#line 363 "awkgram.y"
    { yyval.p = op2(BLTIN, itonp(yyvsp[-3].i), yyvsp[-1].p); }
    break;

  case 145:
#line 364 "awkgram.y"
    { yyval.p = op2(BLTIN, itonp(yyvsp[0].i), rectonode()); }
    break;

  case 146:
#line 365 "awkgram.y"
    { yyval.p = op2(CALL, celltonode(yyvsp[-2].cp,CVAR), NIL); }
    break;

  case 147:
#line 366 "awkgram.y"
    { yyval.p = op2(CALL, celltonode(yyvsp[-3].cp,CVAR), yyvsp[-1].p); }
    break;

  case 148:
#line 367 "awkgram.y"
    { yyval.p = op1(CLOSE, yyvsp[0].p); }
    break;

  case 149:
#line 368 "awkgram.y"
    { yyval.p = op1(PREDECR, yyvsp[0].p); }
    break;

  case 150:
#line 369 "awkgram.y"
    { yyval.p = op1(PREINCR, yyvsp[0].p); }
    break;

  case 151:
#line 370 "awkgram.y"
    { yyval.p = op1(POSTDECR, yyvsp[-1].p); }
    break;

  case 152:
#line 371 "awkgram.y"
    { yyval.p = op1(POSTINCR, yyvsp[-1].p); }
    break;

  case 153:
#line 372 "awkgram.y"
    { yyval.p = op3(GETLINE, yyvsp[-2].p, itonp(yyvsp[-1].i), yyvsp[0].p); }
    break;

  case 154:
#line 373 "awkgram.y"
    { yyval.p = op3(GETLINE, NIL, itonp(yyvsp[-1].i), yyvsp[0].p); }
    break;

  case 155:
#line 374 "awkgram.y"
    { yyval.p = op3(GETLINE, yyvsp[0].p, NIL, NIL); }
    break;

  case 156:
#line 375 "awkgram.y"
    { yyval.p = op3(GETLINE, NIL, NIL, NIL); }
    break;

  case 157:
#line 377 "awkgram.y"
    { yyval.p = op2(INDEX, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 158:
#line 379 "awkgram.y"
    { SYNTAX("index() doesn't permit regular expressions");
		  yyval.p = op2(INDEX, yyvsp[-3].p, (Node*)yyvsp[-1].s); }
    break;

  case 159:
#line 381 "awkgram.y"
    { yyval.p = yyvsp[-1].p; }
    break;

  case 160:
#line 383 "awkgram.y"
    { yyval.p = op3(MATCHFCN, NIL, yyvsp[-3].p, (Node*)makedfa(yyvsp[-1].s, 1)); }
    break;

  case 161:
#line 385 "awkgram.y"
    { if (constnode(yyvsp[-1].p))
			yyval.p = op3(MATCHFCN, NIL, yyvsp[-3].p, (Node*)makedfa(strnode(yyvsp[-1].p), 1));
		  else
			yyval.p = op3(MATCHFCN, (Node *)1, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 162:
#line 389 "awkgram.y"
    { yyval.p = celltonode(yyvsp[0].cp, CCON); }
    break;

  case 163:
#line 391 "awkgram.y"
    { yyval.p = op4(SPLIT, yyvsp[-5].p, makearr(yyvsp[-3].p), yyvsp[-1].p, (Node*)STRING); }
    break;

  case 164:
#line 393 "awkgram.y"
    { yyval.p = op4(SPLIT, yyvsp[-5].p, makearr(yyvsp[-3].p), (Node*)makedfa(yyvsp[-1].s, 1), (Node *)REGEXPR); }
    break;

  case 165:
#line 395 "awkgram.y"
    { yyval.p = op4(SPLIT, yyvsp[-3].p, makearr(yyvsp[-1].p), NIL, (Node*)STRING); }
    break;

  case 166:
#line 396 "awkgram.y"
    { yyval.p = op1(yyvsp[-3].i, yyvsp[-1].p); }
    break;

  case 167:
#line 397 "awkgram.y"
    { yyval.p = celltonode(yyvsp[0].cp, CCON); }
    break;

  case 168:
#line 399 "awkgram.y"
    { yyval.p = op4(yyvsp[-5].i, NIL, (Node*)makedfa(yyvsp[-3].s, 1), yyvsp[-1].p, rectonode()); }
    break;

  case 169:
#line 401 "awkgram.y"
    { if (constnode(yyvsp[-3].p))
			yyval.p = op4(yyvsp[-5].i, NIL, (Node*)makedfa(strnode(yyvsp[-3].p), 1), yyvsp[-1].p, rectonode());
		  else
			yyval.p = op4(yyvsp[-5].i, (Node *)1, yyvsp[-3].p, yyvsp[-1].p, rectonode()); }
    break;

  case 170:
#line 406 "awkgram.y"
    { yyval.p = op4(yyvsp[-7].i, NIL, (Node*)makedfa(yyvsp[-5].s, 1), yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 171:
#line 408 "awkgram.y"
    { if (constnode(yyvsp[-5].p))
			yyval.p = op4(yyvsp[-7].i, NIL, (Node*)makedfa(strnode(yyvsp[-5].p), 1), yyvsp[-3].p, yyvsp[-1].p);
		  else
			yyval.p = op4(yyvsp[-7].i, (Node *)1, yyvsp[-5].p, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 172:
#line 413 "awkgram.y"
    { yyval.p = op3(SUBSTR, yyvsp[-5].p, yyvsp[-3].p, yyvsp[-1].p); }
    break;

  case 173:
#line 415 "awkgram.y"
    { yyval.p = op3(SUBSTR, yyvsp[-3].p, yyvsp[-1].p, NIL); }
    break;

  case 176:
#line 421 "awkgram.y"
    { yyval.p = op2(ARRAY, makearr(yyvsp[-3].p), yyvsp[-1].p); }
    break;

  case 177:
#line 422 "awkgram.y"
    { yyval.p = op1(INDIRECT, celltonode(yyvsp[0].cp, CVAR)); }
    break;

  case 178:
#line 423 "awkgram.y"
    { yyval.p = op1(INDIRECT, yyvsp[0].p); }
    break;

  case 179:
#line 427 "awkgram.y"
    { arglist = yyval.p = 0; }
    break;

  case 180:
#line 428 "awkgram.y"
    { arglist = yyval.p = celltonode(yyvsp[0].cp,CVAR); }
    break;

  case 181:
#line 429 "awkgram.y"
    {
			checkdup(yyvsp[-2].p, yyvsp[0].cp);
			arglist = yyval.p = linkum(yyvsp[-2].p,celltonode(yyvsp[0].cp,CVAR)); }
    break;

  case 182:
#line 435 "awkgram.y"
    { yyval.p = celltonode(yyvsp[0].cp, CVAR); }
    break;

  case 183:
#line 436 "awkgram.y"
    { yyval.p = op1(ARG, itonp(yyvsp[0].i)); }
    break;

  case 184:
#line 437 "awkgram.y"
    { yyval.p = op1(VARNF, (Node *) yyvsp[0].cp); }
    break;

  case 185:
#line 442 "awkgram.y"
    { yyval.p = notnull(yyvsp[-1].p); }
    break;


    }

/* Line 991 of yacc.c.  */
#line 3099 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 445 "awkgram.y"


void setfname(Cell *p)
{
	if (isarr(p))
		SYNTAX("%s is an array, not a function", p->nval);
	else if (isfcn(p))
		SYNTAX("you can't define function %s more than once", p->nval);
	curfname = p->nval;
}

int constnode(Node *p)
{
	return isvalue(p) && ((Cell *) (p->narg[0]))->csub == CCON;
}

char *strnode(Node *p)
{
	return ((Cell *)(p->narg[0]))->sval;
}

Node *notnull(Node *n)
{
	switch (n->nobj) {
	case LE: case LT: case EQ: case NE: case GT: case GE:
	case BOR: case AND: case NOT:
		return n;
	default:
		return op2(NE, n, nullnode);
	}
}

void checkdup(Node *vl, Cell *cp)	/* check if name already in list */
{
	char *s = cp->nval;
	for ( ; vl; vl = vl->nnext) {
		if (strcmp(s, ((Cell *)(vl->narg[0]))->nval) == 0) {
			SYNTAX("duplicate argument %s", s);
			break;
		}
	}
}

