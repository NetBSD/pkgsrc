/*	$OpenBSD: lex.c,v 1.51 2015/09/10 22:48:58 nicm Exp $	*/

/*-
 * Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *		 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018
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

__RCSID("$MirOS: src/bin/mksh/lex.c,v 1.251 2020/03/10 23:48:40 tg Exp $");

/*
 * states while lexing word
 */
#define SBASE		0	/* outside any lexical constructs */
#define SWORD		1	/* implicit quoting for substitute() */
#define SLETPAREN	2	/* inside (( )), implicit quoting */
#define SSQUOTE		3	/* inside '' */
#define SDQUOTE		4	/* inside "" */
#define SEQUOTE		5	/* inside $'' */
#define SBRACE		6	/* inside ${} */
#define SQBRACE		7	/* inside "${}" */
#define SBQUOTE		8	/* inside `` */
#define SASPAREN	9	/* inside $(( )) */
#define SHEREDELIM	10	/* parsing << or <<- delimiter */
#define SHEREDQUOTE	11	/* parsing " in << or <<- delimiter */
#define SPATTERN	12	/* parsing *(...|...) pattern (*+?@!) */
#define SADELIM		13	/* like SBASE, looking for delimiter */
#define STBRACEKORN	14	/* parsing ${...[#%]...} !FSH */
#define STBRACEBOURNE	15	/* parsing ${...[#%]...} FSH */
#define SINVALID	255	/* invalid state */

struct sretrace_info {
	struct sretrace_info *next;
	XString xs;
	char *xp;
};

/*
 * Structure to keep track of the lexing state and the various pieces of info
 * needed for each particular state.
 */
typedef struct lex_state {
	union {
		/* point to the next state block */
		struct lex_state *base;
		/* marks start of state output in output string */
		size_t start;
		/* SBQUOTE: true if in double quotes: "`...`" */
		/* SEQUOTE: got NUL, ignore rest of string */
		bool abool;
		/* SADELIM information */
		struct {
			/* character to search for */
			unsigned char delimiter;
			/* max. number of delimiters */
			unsigned char num;
		} adelim;
	} u;
	/* count open parentheses */
	short nparen;
	/* type of this state */
	uint8_t type;
	/* extra flags */
	uint8_t ls_flags;
} Lex_state;
#define ls_base		u.base
#define ls_start	u.start
#define ls_bool		u.abool
#define ls_adelim	u.adelim

/* ls_flags */
#define LS_HEREDOC	BIT(0)

typedef struct {
	Lex_state *base;
	Lex_state *end;
} State_info;

static void readhere(struct ioword *);
static void ungetsc(int);
static void ungetsc_i(int);
static int getsc_uu(void);
static void getsc_line(Source *);
static int getsc_bn(void);
static int getsc_i(void);
static char *get_brace_var(XString *, char *);
static bool arraysub(char **);
static void gethere(void);
static Lex_state *push_state_i(State_info *, Lex_state *);
static Lex_state *pop_state_i(State_info *, Lex_state *);

static int backslash_skip;
static int ignore_backslash_newline;

/* optimised getsc_bn() */
#define o_getsc()	(*source->str != '\0' && *source->str != '\\' && \
			    !backslash_skip ? *source->str++ : getsc_bn())
/* optimised getsc_uu() */
#define	o_getsc_u()	((*source->str != '\0') ? *source->str++ : getsc_uu())

/* retrace helper */
#define o_getsc_r(carg)					\
	int cev = (carg);				\
	struct sretrace_info *rp = retrace_info;	\
							\
	while (rp) {					\
		Xcheck(rp->xs, rp->xp);			\
		*rp->xp++ = cev;			\
		rp = rp->next;				\
	}						\
							\
	return (cev);

/* callback */
static int
getsc_i(void)
{
	o_getsc_r((unsigned int)(unsigned char)o_getsc());
}

#if defined(MKSH_SMALL) && !defined(MKSH_SMALL_BUT_FAST)
#define getsc()		getsc_i()
#else
static int getsc_r(int);

static int
getsc_r(int c)
{
	o_getsc_r(c);
}

#define getsc()		getsc_r((unsigned int)(unsigned char)o_getsc())
#endif

#define STATE_BSIZE	8

#define PUSH_STATE(s)	do {					\
	uint8_t state_flags = statep->ls_flags;			\
	if (++statep == state_info.end)				\
		statep = push_state_i(&state_info, statep);	\
	state = statep->type = (s);				\
	statep->ls_flags = state_flags;				\
} while (/* CONSTCOND */ 0)

#define POP_STATE()	do {					\
	if (--statep == state_info.base)			\
		statep = pop_state_i(&state_info, statep);	\
	state = statep->type;					\
} while (/* CONSTCOND */ 0)

#define PUSH_SRETRACE(s) do {					\
	struct sretrace_info *ri;				\
								\
	PUSH_STATE(s);						\
	statep->ls_start = Xsavepos(ws, wp);			\
	ri = alloc(sizeof(struct sretrace_info), ATEMP);	\
	Xinit(ri->xs, ri->xp, 64, ATEMP);			\
	ri->next = retrace_info;				\
	retrace_info = ri;					\
} while (/* CONSTCOND */ 0)

#define POP_SRETRACE()	do {					\
	wp = Xrestpos(ws, wp, statep->ls_start);		\
	*retrace_info->xp = '\0';				\
	sp = Xstring(retrace_info->xs, retrace_info->xp);	\
	dp = (void *)retrace_info;				\
	retrace_info = retrace_info->next;			\
	afree(dp, ATEMP);					\
	POP_STATE();						\
} while (/* CONSTCOND */ 0)

/**
 * Lexical analyser
 *
 * tokens are not regular expressions, they are LL(1).
 * for example, "${var:-${PWD}}", and "$(size $(whence ksh))".
 * hence the state stack. Note "$(...)" are now parsed recursively.
 */

int
yylex(int cf)
{
	Lex_state states[STATE_BSIZE], *statep, *s2, *base;
	State_info state_info;
	int c, c2, state;
	size_t cz;
	XString ws;		/* expandable output word */
	char *wp;		/* output word pointer */
	char *sp, *dp;

 Again:
	states[0].type = SINVALID;
	states[0].ls_base = NULL;
	statep = &states[1];
	state_info.base = states;
	state_info.end = &state_info.base[STATE_BSIZE];

	Xinit(ws, wp, 64, ATEMP);

	backslash_skip = 0;
	ignore_backslash_newline = 0;

	if (cf & ONEWORD)
		state = SWORD;
	else if (cf & LETEXPR) {
		/* enclose arguments in (double) quotes */
		*wp++ = OQUOTE;
		state = SLETPAREN;
		statep->nparen = 0;
	} else {
		/* normal lexing */
		state = (cf & HEREDELIM) ? SHEREDELIM : SBASE;
		do {
			c = getsc();
		} while (ctype(c, C_BLANK));
		if (c == '#') {
			ignore_backslash_newline++;
			do {
				c = getsc();
			} while (!ctype(c, C_NUL | C_LF));
			ignore_backslash_newline--;
		}
		ungetsc(c);
	}
	if (source->flags & SF_ALIAS) {
		/* trailing ' ' in alias definition */
		source->flags &= ~SF_ALIAS;
		/* POSIX: trailing space only counts if parsing simple cmd */
		if (!Flag(FPOSIX) || (cf & CMDWORD))
			cf |= ALIAS;
	}

	/* Initial state: one of SWORD SLETPAREN SHEREDELIM SBASE */
	statep->type = state;
	statep->ls_flags = (cf & HEREDOC) ? LS_HEREDOC : 0;

	/* collect non-special or quoted characters to form word */
	while (!((c = getsc()) == 0 ||
	    ((state == SBASE || state == SHEREDELIM) && ctype(c, C_LEX1)))) {
		if (state == SBASE &&
		    subshell_nesting_type == ORD(/*{*/ '}') &&
		    (unsigned int)c == ORD(/*{*/ '}'))
			/* possibly end ${ :;} */
			break;
		Xcheck(ws, wp);
		switch (state) {
		case SADELIM:
			if ((unsigned int)c == ORD('('))
				statep->nparen++;
			else if ((unsigned int)c == ORD(')'))
				statep->nparen--;
			else if (statep->nparen == 0 &&
			    ((unsigned int)c == ORD(/*{*/ '}') ||
			    c == (int)statep->ls_adelim.delimiter)) {
				*wp++ = ADELIM;
				*wp++ = c;
				if ((unsigned int)c == ORD(/*{*/ '}') ||
				    --statep->ls_adelim.num == 0)
					POP_STATE();
				if ((unsigned int)c == ORD(/*{*/ '}'))
					POP_STATE();
				break;
			}
			/* FALLTHROUGH */
		case SBASE:
			if ((unsigned int)c == ORD('[') && (cf & CMDASN)) {
				/* temporary */
				*wp = EOS;
				if (is_wdvarname(Xstring(ws, wp), false)) {
					char *p, *tmp;

					if (arraysub(&tmp)) {
						*wp++ = CHAR;
						*wp++ = c;
						for (p = tmp; *p; ) {
							Xcheck(ws, wp);
							*wp++ = CHAR;
							*wp++ = *p++;
						}
						afree(tmp, ATEMP);
						break;
					}
				}
				*wp++ = CHAR;
				*wp++ = c;
				break;
			}
			/* FALLTHROUGH */
 Sbase1:		/* includes *(...|...) pattern (*+?@!) */
			if (ctype(c, C_PATMO)) {
				c2 = getsc();
				if ((unsigned int)c2 == ORD('(' /*)*/)) {
					*wp++ = OPAT;
					*wp++ = c;
					PUSH_STATE(SPATTERN);
					break;
				}
				ungetsc(c2);
			}
			/* FALLTHROUGH */
 Sbase2:		/* doesn't include *(...|...) pattern (*+?@!) */
			switch (c) {
			case ORD('\\'):
 getsc_qchar:
				if ((c = getsc())) {
					/* trailing \ is lost */
					*wp++ = QCHAR;
					*wp++ = c;
				}
				break;
			case ORD('\''):
 open_ssquote_unless_heredoc:
				if ((statep->ls_flags & LS_HEREDOC))
					goto store_char;
				*wp++ = OQUOTE;
				ignore_backslash_newline++;
				PUSH_STATE(SSQUOTE);
				break;
			case ORD('"'):
 open_sdquote:
				*wp++ = OQUOTE;
				PUSH_STATE(SDQUOTE);
				break;
			case ORD('$'):
				/*
				 * processing of dollar sign belongs into
				 * Subst, except for those which can open
				 * a string: $'…' and $"…"
				 */
 subst_dollar_ex:
				c = getsc();
				switch (c) {
				case ORD('"'):
					goto open_sdquote;
				case ORD('\''):
					goto open_sequote;
				default:
					goto SubstS;
				}
			default:
				goto Subst;
			}
			break;

 Subst:
			switch (c) {
			case ORD('\\'):
				c = getsc();
				switch (c) {
				case ORD('"'):
					if ((statep->ls_flags & LS_HEREDOC))
						goto heredocquote;
					/* FALLTHROUGH */
				case ORD('\\'):
				case ORD('$'):
				case ORD('`'):
 store_qchar:
					*wp++ = QCHAR;
					*wp++ = c;
					break;
				default:
 heredocquote:
					Xcheck(ws, wp);
					if (c) {
						/* trailing \ is lost */
						*wp++ = CHAR;
						*wp++ = '\\';
						*wp++ = CHAR;
						*wp++ = c;
					}
					break;
				}
				break;
			case ORD('$'):
				c = getsc();
 SubstS:
				if ((unsigned int)c == ORD('(' /*)*/)) {
					c = getsc();
					if ((unsigned int)c == ORD('(' /*)*/)) {
						*wp++ = EXPRSUB;
						PUSH_SRETRACE(SASPAREN);
						/* unneeded? */
						/*statep->ls_flags &= ~LS_HEREDOC;*/
						statep->nparen = 2;
						*retrace_info->xp++ = '(';
					} else {
						ungetsc(c);
 subst_command:
						c = COMSUB;
 subst_command2:
						sp = yyrecursive(c);
						cz = strlen(sp) + 1;
						XcheckN(ws, wp, cz);
						*wp++ = c;
						memcpy(wp, sp, cz);
						wp += cz;
					}
				} else if ((unsigned int)c == ORD('{' /*}*/)) {
					if ((unsigned int)(c = getsc()) == ORD('|')) {
						/*
						 * non-subenvironment
						 * value substitution
						 */
						c = VALSUB;
						goto subst_command2;
					} else if (ctype(c, C_IFSWS)) {
						/*
						 * non-subenvironment
						 * "command" substitution
						 */
						c = FUNSUB;
						goto subst_command2;
					}
					ungetsc(c);
					*wp++ = OSUBST;
					*wp++ = '{' /*}*/;
					wp = get_brace_var(&ws, wp);
					c = getsc();
					/* allow :# and :% (ksh88 compat) */
					if ((unsigned int)c == ORD(':')) {
						*wp++ = CHAR;
						*wp++ = c;
						c = getsc();
						if ((unsigned int)c == ORD(':')) {
							*wp++ = CHAR;
							*wp++ = '0';
							*wp++ = ADELIM;
							*wp++ = ':';
							PUSH_STATE(SBRACE);
							/* perhaps unneeded? */
							statep->ls_flags &= ~LS_HEREDOC;
							PUSH_STATE(SADELIM);
							statep->ls_adelim.delimiter = ':';
							statep->ls_adelim.num = 1;
							statep->nparen = 0;
							break;
						} else if (ctype(c, C_ALNUX | C_DOLAR | C_SPC) ||
						    c == '(' /*)*/) {
							/* substring subst. */
							if (c != ' ') {
								*wp++ = CHAR;
								*wp++ = ' ';
							}
							ungetsc(c);
							PUSH_STATE(SBRACE);
							/* perhaps unneeded? */
							statep->ls_flags &= ~LS_HEREDOC;
							PUSH_STATE(SADELIM);
							statep->ls_adelim.delimiter = ':';
							statep->ls_adelim.num = 2;
							statep->nparen = 0;
							break;
						}
					} else if (c == '/') {
						c2 = ADELIM;
 parse_adelim_slash:
						*wp++ = CHAR;
						*wp++ = c;
						if ((unsigned int)(c = getsc()) == ORD('/')) {
							*wp++ = c2;
							*wp++ = c;
						} else
							ungetsc(c);
						PUSH_STATE(SBRACE);
						/* perhaps unneeded? */
						statep->ls_flags &= ~LS_HEREDOC;
						PUSH_STATE(SADELIM);
						statep->ls_adelim.delimiter = '/';
						statep->ls_adelim.num = 1;
						statep->nparen = 0;
						break;
					} else if (c == '@') {
						c2 = getsc();
						ungetsc(c2);
						if ((unsigned int)c2 == ORD('/')) {
							c2 = CHAR;
							goto parse_adelim_slash;
						}
					}
					/*
					 * If this is a trim operation,
					 * treat (,|,) specially in STBRACE.
					 */
					if (ctype(c, C_SUB2)) {
						ungetsc(c);
						if (Flag(FSH))
							PUSH_STATE(STBRACEBOURNE);
						else
							PUSH_STATE(STBRACEKORN);
						/* single-quotes-in-heredoc-trim */
						statep->ls_flags &= ~LS_HEREDOC;
					} else {
						ungetsc(c);
						if (state == SDQUOTE ||
						    state == SQBRACE)
							PUSH_STATE(SQBRACE);
						else
							PUSH_STATE(SBRACE);
						/* here no LS_HEREDOC removal */
						/* single-quotes-in-heredoc-braces */
					}
				} else if (ctype(c, C_ALPHX)) {
					*wp++ = OSUBST;
					*wp++ = 'X';
					do {
						Xcheck(ws, wp);
						*wp++ = c;
						c = getsc();
					} while (ctype(c, C_ALNUX));
					*wp++ = '\0';
					*wp++ = CSUBST;
					*wp++ = 'X';
					ungetsc(c);
				} else if (ctype(c, C_VAR1 | C_DIGIT)) {
					Xcheck(ws, wp);
					*wp++ = OSUBST;
					*wp++ = 'X';
					*wp++ = c;
					*wp++ = '\0';
					*wp++ = CSUBST;
					*wp++ = 'X';
				} else {
					*wp++ = CHAR;
					*wp++ = '$';
					ungetsc(c);
				}
				break;
			case ORD('`'):
 subst_gravis:
				PUSH_STATE(SBQUOTE);
				*wp++ = COMASUB;
				/*
				 * We need to know whether we are within double
				 * quotes in order to translate \" to " within
				 * "…`…\"…`…" because, unlike for COMSUBs, the
				 * outer double quoteing changes the backslash
				 * meaning for the inside. For more details:
				 * http://austingroupbugs.net/view.php?id=1015
				 */
				statep->ls_bool = false;
				s2 = statep;
				base = state_info.base;
				while (/* CONSTCOND */ 1) {
					for (; s2 != base; s2--) {
						if (s2->type == SDQUOTE) {
							statep->ls_bool = true;
							break;
						}
					}
					if (s2 != base)
						break;
					if (!(s2 = s2->ls_base))
						break;
					base = s2-- - STATE_BSIZE;
				}
				break;
			case QCHAR:
				if (cf & LQCHAR) {
					*wp++ = QCHAR;
					*wp++ = getsc();
					break;
				}
				/* FALLTHROUGH */
			default:
 store_char:
				*wp++ = CHAR;
				*wp++ = c;
			}
			break;

		case SEQUOTE:
			if ((unsigned int)c == ORD('\'')) {
				POP_STATE();
				*wp++ = CQUOTE;
				ignore_backslash_newline--;
			} else if ((unsigned int)c == ORD('\\')) {
				if ((c2 = unbksl(true, getsc_i, ungetsc)) == -1)
					c2 = getsc();
				if (c2 == 0)
					statep->ls_bool = true;
				if (!statep->ls_bool) {
					char ts[4];

					if ((unsigned int)c2 < 0x100) {
						*wp++ = QCHAR;
						*wp++ = c2;
					} else {
						cz = utf_wctomb(ts, c2 - 0x100);
						ts[cz] = 0;
						cz = 0;
						do {
							*wp++ = QCHAR;
							*wp++ = ts[cz];
						} while (ts[++cz]);
					}
				}
			} else if (!statep->ls_bool) {
				*wp++ = QCHAR;
				*wp++ = c;
			}
			break;

		case SSQUOTE:
			if ((unsigned int)c == ORD('\'')) {
				POP_STATE();
				if ((statep->ls_flags & LS_HEREDOC) ||
				    state == SQBRACE)
					goto store_char;
				*wp++ = CQUOTE;
				ignore_backslash_newline--;
			} else {
				*wp++ = QCHAR;
				*wp++ = c;
			}
			break;

		case SDQUOTE:
			if ((unsigned int)c == ORD('"')) {
				POP_STATE();
				*wp++ = CQUOTE;
			} else
				goto Subst;
			break;

		/* $(( ... )) */
		case SASPAREN:
			if ((unsigned int)c == ORD('('))
				statep->nparen++;
			else if ((unsigned int)c == ORD(')')) {
				statep->nparen--;
				if (statep->nparen == 1) {
					/* end of EXPRSUB */
					POP_SRETRACE();

					if ((unsigned int)(c2 = getsc()) == ORD(/*(*/ ')')) {
						cz = strlen(sp) - 2;
						XcheckN(ws, wp, cz);
						memcpy(wp, sp + 1, cz);
						wp += cz;
						afree(sp, ATEMP);
						*wp++ = '\0';
						break;
					} else {
						Source *s;

						ungetsc(c2);
						/*
						 * mismatched parenthesis -
						 * assume we were really
						 * parsing a $(...) expression
						 */
						--wp;
						s = pushs(SREREAD,
						    source->areap);
						s->start = s->str =
						    s->u.freeme = sp;
						s->next = source;
						source = s;
						goto subst_command;
					}
				}
			}
			/* reuse existing state machine */
			goto Sbase2;

		case SQBRACE:
			if ((unsigned int)c == ORD('\\')) {
				/*
				 * perform POSIX "quote removal" if the back-
				 * slash is "special", i.e. same cases as the
				 * {case '\\':} in Subst: plus closing brace;
				 * in mksh code "quote removal" on '\c' means
				 * write QCHAR+c, otherwise CHAR+\+CHAR+c are
				 * emitted (in heredocquote:)
				 */
				if ((unsigned int)(c = getsc()) == ORD('"') ||
				    (unsigned int)c == ORD('\\') ||
				    ctype(c, C_DOLAR | C_GRAVE) ||
				    (unsigned int)c == ORD(/*{*/ '}'))
					goto store_qchar;
				goto heredocquote;
			}
			goto common_SQBRACE;

		case SBRACE:
			if ((unsigned int)c == ORD('\''))
				goto open_ssquote_unless_heredoc;
			else if ((unsigned int)c == ORD('\\'))
				goto getsc_qchar;
 common_SQBRACE:
			if ((unsigned int)c == ORD('"'))
				goto open_sdquote;
			else if ((unsigned int)c == ORD('$'))
				goto subst_dollar_ex;
			else if ((unsigned int)c == ORD('`'))
				goto subst_gravis;
			else if ((unsigned int)c != ORD(/*{*/ '}'))
				goto store_char;
			POP_STATE();
			*wp++ = CSUBST;
			*wp++ = /*{*/ '}';
			break;

		/* Same as SBASE, except (,|,) treated specially */
		case STBRACEKORN:
			if ((unsigned int)c == ORD('|'))
				*wp++ = SPAT;
			else if ((unsigned int)c == ORD('(')) {
				*wp++ = OPAT;
				/* simile for @ */
				*wp++ = ' ';
				PUSH_STATE(SPATTERN);
			} else /* FALLTHROUGH */
		case STBRACEBOURNE:
			  if ((unsigned int)c == ORD(/*{*/ '}')) {
				POP_STATE();
				*wp++ = CSUBST;
				*wp++ = /*{*/ '}';
			} else
				goto Sbase1;
			break;

		case SBQUOTE:
			if ((unsigned int)c == ORD('`')) {
				*wp++ = 0;
				POP_STATE();
			} else if ((unsigned int)c == ORD('\\')) {
				switch (c = getsc()) {
				case 0:
					/* trailing \ is lost */
					break;
				case ORD('$'):
				case ORD('`'):
				case ORD('\\'):
					*wp++ = c;
					break;
				case ORD('"'):
					if (statep->ls_bool) {
						*wp++ = c;
						break;
					}
					/* FALLTHROUGH */
				default:
					*wp++ = '\\';
					*wp++ = c;
					break;
				}
			} else
				*wp++ = c;
			break;

		/* ONEWORD */
		case SWORD:
			goto Subst;

		/* LETEXPR: (( ... )) */
		case SLETPAREN:
			if ((unsigned int)c == ORD(/*(*/ ')')) {
				if (statep->nparen > 0)
					--statep->nparen;
				else if ((unsigned int)(c2 = getsc()) == ORD(/*(*/ ')')) {
					c = 0;
					*wp++ = CQUOTE;
					goto Done;
				} else {
					Source *s;

					ungetsc(c2);
					ungetsc(c);
					/*
					 * mismatched parenthesis -
					 * assume we were really
					 * parsing a (...) expression
					 */
					*wp = EOS;
					sp = Xstring(ws, wp);
					dp = wdstrip(sp + 1, WDS_TPUTS);
					s = pushs(SREREAD, source->areap);
					s->start = s->str = s->u.freeme = dp;
					s->next = source;
					source = s;
					ungetsc('(' /*)*/);
					return (ORD('(' /*)*/));
				}
			} else if ((unsigned int)c == ORD('('))
				/*
				 * parentheses inside quotes and
				 * backslashes are lost, but AT&T ksh
				 * doesn't count them either
				 */
				++statep->nparen;
			goto Sbase2;

		/* << or <<- delimiter */
		case SHEREDELIM:
			/*
			 * here delimiters need a special case since
			 * $ and `...` are not to be treated specially
			 */
			switch (c) {
			case ORD('\\'):
				if ((c = getsc())) {
					/* trailing \ is lost */
					*wp++ = QCHAR;
					*wp++ = c;
				}
				break;
			case ORD('\''):
				goto open_ssquote_unless_heredoc;
			case ORD('$'):
				if ((unsigned int)(c2 = getsc()) == ORD('\'')) {
 open_sequote:
					*wp++ = OQUOTE;
					ignore_backslash_newline++;
					PUSH_STATE(SEQUOTE);
					statep->ls_bool = false;
					break;
				} else if ((unsigned int)c2 == ORD('"')) {
					/* FALLTHROUGH */
			case ORD('"'):
					PUSH_SRETRACE(SHEREDQUOTE);
					break;
				}
				ungetsc(c2);
				/* FALLTHROUGH */
			default:
				*wp++ = CHAR;
				*wp++ = c;
			}
			break;

		/* " in << or <<- delimiter */
		case SHEREDQUOTE:
			if ((unsigned int)c != ORD('"'))
				goto Subst;
			POP_SRETRACE();
			dp = strnul(sp) - 1;
			/* remove the trailing double quote */
			*dp = '\0';
			/* store the quoted string */
			*wp++ = OQUOTE;
			XcheckN(ws, wp, (dp - sp) * 2);
			dp = sp;
			while ((c = *dp++)) {
				if (c == '\\') {
					switch ((c = *dp++)) {
					case ORD('\\'):
					case ORD('"'):
					case ORD('$'):
					case ORD('`'):
						break;
					default:
						*wp++ = CHAR;
						*wp++ = '\\';
						break;
					}
				}
				*wp++ = CHAR;
				*wp++ = c;
			}
			afree(sp, ATEMP);
			*wp++ = CQUOTE;
			state = statep->type = SHEREDELIM;
			break;

		/* in *(...|...) pattern (*+?@!) */
		case SPATTERN:
			if ((unsigned int)c == ORD(/*(*/ ')')) {
				*wp++ = CPAT;
				POP_STATE();
			} else if ((unsigned int)c == ORD('|')) {
				*wp++ = SPAT;
			} else if ((unsigned int)c == ORD('(')) {
				*wp++ = OPAT;
				/* simile for @ */
				*wp++ = ' ';
				PUSH_STATE(SPATTERN);
			} else
				goto Sbase1;
			break;
		}
	}
 Done:
	Xcheck(ws, wp);
	if (statep != &states[1])
		/* XXX figure out what is missing */
		yyerror("no closing quote");

	/* This done to avoid tests for SHEREDELIM wherever SBASE tested */
	if (state == SHEREDELIM)
		state = SBASE;

	dp = Xstring(ws, wp);
	if (state == SBASE && (
	    (c == '&' && !Flag(FSH) && !Flag(FPOSIX)) ||
	    ctype(c, C_ANGLE)) && ((c2 = Xlength(ws, wp)) == 0 ||
	    (c2 == 2 && dp[0] == CHAR && ctype(dp[1], C_DIGIT)))) {
		struct ioword *iop = alloc(sizeof(struct ioword), ATEMP);

		iop->unit = c2 == 2 ? ksh_numdig(dp[1]) : c == '<' ? 0 : 1;

		if (c == '&') {
			if ((unsigned int)(c2 = getsc()) != ORD('>')) {
				ungetsc(c2);
				goto no_iop;
			}
			c = c2;
			iop->ioflag = IOBASH;
		} else
			iop->ioflag = 0;

		c2 = getsc();
		/* <<, >>, <> are ok, >< is not */
		if (c == c2 || ((unsigned int)c == ORD('<') &&
		    (unsigned int)c2 == ORD('>'))) {
			iop->ioflag |= c == c2 ?
			    ((unsigned int)c == ORD('>') ? IOCAT : IOHERE) : IORDWR;
			if (iop->ioflag == IOHERE) {
				if ((unsigned int)(c2 = getsc()) == ORD('-'))
					iop->ioflag |= IOSKIP;
				else if ((unsigned int)c2 == ORD('<'))
					iop->ioflag |= IOHERESTR;
				else
					ungetsc(c2);
			}
		} else if ((unsigned int)c2 == ORD('&'))
			iop->ioflag |= IODUP | ((unsigned int)c == ORD('<') ? IORDUP : 0);
		else {
			iop->ioflag |= (unsigned int)c == ORD('>') ? IOWRITE : IOREAD;
			if ((unsigned int)c == ORD('>') && (unsigned int)c2 == ORD('|'))
				iop->ioflag |= IOCLOB;
			else
				ungetsc(c2);
		}

		iop->ioname = NULL;
		iop->delim = NULL;
		iop->heredoc = NULL;
		/* free word */
		Xfree(ws, wp);
		yylval.iop = iop;
		return (REDIR);
 no_iop:
		afree(iop, ATEMP);
	}

	if (wp == dp && state == SBASE) {
		/* free word */
		Xfree(ws, wp);
		/* no word, process LEX1 character */
		if (((unsigned int)c == ORD('|')) ||
		    ((unsigned int)c == ORD('&')) ||
		    ((unsigned int)c == ORD(';')) ||
		    ((unsigned int)c == ORD('(' /*)*/))) {
			if ((c2 = getsc()) == c)
				c = ((unsigned int)c == ORD(';')) ? BREAK :
				    ((unsigned int)c == ORD('|')) ? LOGOR :
				    ((unsigned int)c == ORD('&')) ? LOGAND :
				    /* (unsigned int)c == ORD('(' )) */ MDPAREN;
			else if ((unsigned int)c == ORD('|') && (unsigned int)c2 == ORD('&'))
				c = COPROC;
			else if ((unsigned int)c == ORD(';') && (unsigned int)c2 == ORD('|'))
				c = BRKEV;
			else if ((unsigned int)c == ORD(';') && (unsigned int)c2 == ORD('&'))
				c = BRKFT;
			else
				ungetsc(c2);
#ifndef MKSH_SMALL
			if (c == BREAK) {
				if ((unsigned int)(c2 = getsc()) == ORD('&'))
					c = BRKEV;
				else
					ungetsc(c2);
			}
#endif
		} else if ((unsigned int)c == ORD('\n')) {
			if (cf & HEREDELIM)
				ungetsc(c);
			else {
				gethere();
				if (cf & CONTIN)
					goto Again;
			}
		} else if (c == '\0' && !(cf & HEREDELIM)) {
			struct ioword **p = heres;

			while (p < herep)
				if ((*p)->ioflag & IOHERESTR)
					++p;
				else
					/* ksh -c 'cat <<EOF' can cause this */
					yyerror(Tf_heredoc,
					    evalstr((*p)->delim, 0));
		}
		return (c);
	}

	/* terminate word */
	*wp++ = EOS;
	yylval.cp = Xclose(ws, wp);
	if (state == SWORD || state == SLETPAREN
	    /* XXX ONEWORD? */)
		return (LWORD);

	/* unget terminator */
	ungetsc(c);

	/*
	 * note: the alias-vs-function code below depends on several
	 * interna: starting from here, source->str is not modified;
	 * the way getsc() and ungetsc() operate; etc.
	 */

	/* copy word to unprefixed string ident */
	sp = yylval.cp;
	dp = ident;
	while ((dp - ident) < IDENT && (c = *sp++) == CHAR)
		*dp++ = *sp++;
	if (c != EOS)
		/* word is not unquoted, or space ran out */
		dp = ident;
	/* make sure the ident array stays NUL padded */
	memset(dp, 0, (ident + IDENT) - dp + 1);

	if (*ident != '\0' && (cf & (KEYWORD | ALIAS))) {
		struct tbl *p;
		uint32_t h = hash(ident);

		if ((cf & KEYWORD) && (p = ktsearch(&keywords, ident, h)) &&
		    (!(cf & ESACONLY) || p->val.i == ESAC ||
		    (unsigned int)p->val.i == ORD(/*{*/ '}'))) {
			afree(yylval.cp, ATEMP);
			return (p->val.i);
		}
		if ((cf & ALIAS) && (p = ktsearch(&aliases, ident, h)) &&
		    (p->flag & ISSET)) {
			/*
			 * this still points to the same character as the
			 * ungetsc'd terminator from above
			 */
			const char *cp = source->str;

			/* prefer POSIX but not Korn functions over aliases */
			while (ctype(*cp, C_BLANK))
				/*
				 * this is like getsc() without skipping
				 * over Source boundaries (including not
				 * parsing ungetsc'd characters that got
				 * pushed into an SREREAD) which is what
				 * we want here anyway: find out whether
				 * the alias name is followed by a POSIX
				 * function definition
				 */
				++cp;
			/* prefer functions over aliases */
			if (cp[0] != '(' || cp[1] != ')') {
				Source *s = source;

				while (s && (s->flags & SF_HASALIAS))
					if (s->u.tblp == p)
						return (LWORD);
					else
						s = s->next;
				/* push alias expansion */
				s = pushs(SALIAS, source->areap);
				s->start = s->str = p->val.s;
				s->u.tblp = p;
				s->flags |= SF_HASALIAS;
				s->line = source->line;
				s->next = source;
				if (source->type == SEOF) {
					/* prevent infinite recursion at EOS */
					source->u.tblp = p;
					source->flags |= SF_HASALIAS;
				}
				source = s;
				afree(yylval.cp, ATEMP);
				goto Again;
			}
		}
	} else if (*ident == '\0') {
		/* retain typeset et al. even when quoted */
		struct tbl *tt = get_builtin((dp = wdstrip(yylval.cp, 0)));
		uint32_t flag = tt ? tt->flag : 0;

		if (flag & (DECL_UTIL | DECL_FWDR))
			strlcpy(ident, dp, sizeof(ident));
		afree(dp, ATEMP);
	}

	return (LWORD);
}

static void
gethere(void)
{
	struct ioword **p;

	for (p = heres; p < herep; p++)
		if (!((*p)->ioflag & IOHERESTR))
			readhere(*p);
	herep = heres;
}

/*
 * read "<<word" text into temp file
 */

static void
readhere(struct ioword *iop)
{
	int c;
	const char *eof, *eofp;
	XString xs;
	char *xp;
	size_t xpos;

	eof = evalstr(iop->delim, 0);

	if (!(iop->ioflag & IOEVAL))
		ignore_backslash_newline++;

	Xinit(xs, xp, 256, ATEMP);

 heredoc_read_line:
	/* beginning of line */
	eofp = eof;
	xpos = Xsavepos(xs, xp);
	if (iop->ioflag & IOSKIP) {
		/* skip over leading tabs */
		while ((c = getsc()) == '\t')
			;	/* nothing */
		goto heredoc_parse_char;
	}
 heredoc_read_char:
	c = getsc();
 heredoc_parse_char:
	/* compare with here document marker */
	if (!*eofp) {
		/* end of here document marker, what to do? */
		switch (c) {
		case ORD(/*(*/ ')'):
			if (!subshell_nesting_type)
				/*-
				 * not allowed outside $(...) or (...)
				 * => mismatch
				 */
				break;
			/* allow $(...) or (...) to close here */
			ungetsc(/*(*/ ')');
			/* FALLTHROUGH */
		case 0:
			/*
			 * Allow EOF here to commands without trailing
			 * newlines (mksh -c '...') will work as well.
			 */
		case ORD('\n'):
			/* Newline terminates here document marker */
			goto heredoc_found_terminator;
		}
	} else if ((unsigned int)c == ord(*eofp++))
		/* store; then read and compare next character */
		goto heredoc_store_and_loop;
	/* nope, mismatch; read until end of line */
	while (c != '\n') {
		if (!c)
			/* oops, reached EOF */
			yyerror(Tf_heredoc, eof);
		/* store character */
		Xcheck(xs, xp);
		Xput(xs, xp, c);
		/* read next character */
		c = getsc();
	}
	/* we read a newline as last character */
 heredoc_store_and_loop:
	/* store character */
	Xcheck(xs, xp);
	Xput(xs, xp, c);
	if (c == '\n')
		goto heredoc_read_line;
	goto heredoc_read_char;

 heredoc_found_terminator:
	/* jump back to saved beginning of line */
	xp = Xrestpos(xs, xp, xpos);
	/* terminate, close and store */
	Xput(xs, xp, '\0');
	iop->heredoc = Xclose(xs, xp);

	if (!(iop->ioflag & IOEVAL))
		ignore_backslash_newline--;
}

void
yyerror(const char *fmt, ...)
{
	va_list va;

	/* pop aliases and re-reads */
	while (source->type == SALIAS || source->type == SREREAD)
		source = source->next;
	/* zap pending input */
	source->str = null;

	error_prefix(true);
	va_start(va, fmt);
	shf_vfprintf(shl_out, fmt, va);
	shf_putc('\n', shl_out);
	va_end(va);
	errorfz();
}

/*
 * input for yylex with alias expansion
 */

Source *
pushs(int type, Area *areap)
{
	Source *s;

	s = alloc(sizeof(Source), areap);
	memset(s, 0, sizeof(Source));
	s->type = type;
	s->str = null;
	s->areap = areap;
	if (type == SFILE || type == SSTDIN)
		XinitN(s->xs, 256, s->areap);
	return (s);
}

static int
getsc_uu(void)
{
	Source *s = source;
	int c;

	while ((c = ord(*s->str++)) == 0) {
		/* return 0 for EOF by default */
		s->str = NULL;
		switch (s->type) {
		case SEOF:
			s->str = null;
			return (0);

		case SSTDIN:
		case SFILE:
			getsc_line(s);
			break;

		case SWSTR:
			break;

		case SSTRING:
		case SSTRINGCMDLINE:
			break;

		case SWORDS:
			s->start = s->str = *s->u.strv++;
			s->type = SWORDSEP;
			break;

		case SWORDSEP:
			if (*s->u.strv == NULL) {
				s->start = s->str = "\n";
				s->type = SEOF;
			} else {
				s->start = s->str = T1space;
				s->type = SWORDS;
			}
			break;

		case SALIAS:
			if (s->flags & SF_ALIASEND) {
				/* pass on an unused SF_ALIAS flag */
				source = s->next;
				source->flags |= s->flags & SF_ALIAS;
				s = source;
			} else if (*s->u.tblp->val.s &&
			    ctype((c = strnul(s->u.tblp->val.s)[-1]), C_SPACE)) {
				/* pop source stack */
				source = s = s->next;
				/*
				 * Note that this alias ended with a
				 * space, enabling alias expansion on
				 * the following word.
				 */
				s->flags |= SF_ALIAS;
			} else {
				/*
				 * At this point, we need to keep the current
				 * alias in the source list so recursive
				 * aliases can be detected and we also need to
				 * return the next character. Do this by
				 * temporarily popping the alias to get the
				 * next character and then put it back in the
				 * source list with the SF_ALIASEND flag set.
				 */
				/* pop source stack */
				source = s->next;
				source->flags |= s->flags & SF_ALIAS;
				c = getsc_uu();
				if (c) {
					s->flags |= SF_ALIASEND;
					s->ugbuf[0] = c; s->ugbuf[1] = '\0';
					s->start = s->str = s->ugbuf;
					s->next = source;
					source = s;
				} else {
					s = source;
					/* avoid reading EOF twice */
					s->str = NULL;
					break;
				}
			}
			continue;

		case SREREAD:
			if (s->start != s->ugbuf)
				/* yuck */
				afree(s->u.freeme, ATEMP);
			source = s = s->next;
			continue;
		}
		if (s->str == NULL) {
			s->type = SEOF;
			s->start = s->str = null;
			return ('\0');
		}
		if (s->flags & SF_ECHO) {
			shf_puts(s->str, shl_out);
			shf_flush(shl_out);
		}
	}
	return (c);
}

static void
getsc_line(Source *s)
{
	char *xp = Xstring(s->xs, xp), *cp;
	bool interactive = Flag(FTALKING) && s->type == SSTDIN;
	bool have_tty = interactive && (s->flags & SF_TTY) && tty_hasstate;

	/* Done here to ensure nothing odd happens when a timeout occurs */
	XcheckN(s->xs, xp, LINE);
	*xp = '\0';
	s->start = s->str = xp;

	if (have_tty && ksh_tmout) {
		ksh_tmout_state = TMOUT_READING;
		alarm(ksh_tmout);
	}
	if (interactive) {
		if (cur_prompt == PS1)
			histsave(&s->line, NULL, HIST_FLUSH, true);
		change_winsz();
	}
#ifndef MKSH_NO_CMDLINE_EDITING
	if (have_tty && (
#if !MKSH_S_NOVI
	    Flag(FVI) ||
#endif
	    Flag(FEMACS) || Flag(FGMACS))) {
		int nread;

		nread = x_read(xp);
		if (nread < 0)
			/* read error */
			nread = 0;
		xp[nread] = '\0';
		xp += nread;
	} else
#endif
	  {
		if (interactive)
			pprompt(prompt, 0);
		else
			s->line++;

		while (/* CONSTCOND */ 1) {
			char *p = shf_getse(xp, Xnleft(s->xs, xp), s->u.shf);

			if (!p && shf_error(s->u.shf) &&
			    shf_errno(s->u.shf) == EINTR) {
				shf_clearerr(s->u.shf);
				if (trap)
					runtraps(0);
				continue;
			}
			if (!p || (xp = p, xp[-1] == '\n'))
				break;
			/* double buffer size */
			/* move past NUL so doubling works... */
			xp++;
			XcheckN(s->xs, xp, Xlength(s->xs, xp));
			/* ...and move back again */
			xp--;
		}
		/*
		 * flush any unwanted input so other programs/builtins
		 * can read it. Not very optimal, but less error prone
		 * than flushing else where, dealing with redirections,
		 * etc.
		 * TODO: reduce size of shf buffer (~128?) if SSTDIN
		 */
		if (s->type == SSTDIN)
			shf_flush(s->u.shf);
	}
	/*
	 * XXX: temporary kludge to restore source after a
	 * trap may have been executed.
	 */
	source = s;
	if (have_tty && ksh_tmout) {
		ksh_tmout_state = TMOUT_EXECUTING;
		alarm(0);
	}
	cp = Xstring(s->xs, xp);
	rndpush(cp);
	s->start = s->str = cp;
	strip_nuls(Xstring(s->xs, xp), Xlength(s->xs, xp));
	/* Note: if input is all nulls, this is not eof */
	if (Xlength(s->xs, xp) == 0) {
		/* EOF */
		if (s->type == SFILE)
			shf_fdclose(s->u.shf);
		s->str = NULL;
	} else if (interactive && *s->str) {
		if (cur_prompt != PS1)
			histsave(&s->line, s->str, HIST_APPEND, true);
		else if (!ctype(*s->str, C_IFS | C_IFSWS))
			histsave(&s->line, s->str, HIST_QUEUE, true);
#if !defined(MKSH_SMALL) && HAVE_PERSISTENT_HISTORY
		else
			goto check_for_sole_return;
	} else if (interactive && cur_prompt == PS1) {
 check_for_sole_return:
		cp = Xstring(s->xs, xp);
		while (ctype(*cp, C_IFSWS))
			++cp;
		if (!*cp) {
			histsave(&s->line, NULL, HIST_FLUSH, true);
			histsync();
		}
#endif
	}
	if (interactive)
		set_prompt(PS2, NULL);
}

void
set_prompt(int to, Source *s)
{
	cur_prompt = (uint8_t)to;

	switch (to) {
	/* command */
	case PS1:
		/*
		 * Substitute ! and !! here, before substitutions are done
		 * so ! in expanded variables are not expanded.
		 * NOTE: this is not what AT&T ksh does (it does it after
		 * substitutions, POSIX doesn't say which is to be done.
		 */
		{
			struct shf *shf;
			char * volatile ps1;
			Area *saved_atemp;
			int saved_lineno;

			ps1 = str_val(global("PS1"));
			shf = shf_sopen(NULL, strlen(ps1) * 2,
			    SHF_WR | SHF_DYNAMIC, NULL);
			while (*ps1)
				if (*ps1 != '!' || *++ps1 == '!')
					shf_putchar(*ps1++, shf);
				else
					shf_fprintf(shf, Tf_lu, s ?
					    (unsigned long)s->line + 1 : 0UL);
			ps1 = shf_sclose(shf);
			saved_lineno = current_lineno;
			if (s)
				current_lineno = s->line + 1;
			saved_atemp = ATEMP;
			newenv(E_ERRH);
			if (kshsetjmp(e->jbuf)) {
				prompt = safe_prompt;
				/*
				 * Don't print an error - assume it has already
				 * been printed. Reason is we may have forked
				 * to run a command and the child may be
				 * unwinding its stack through this code as it
				 * exits.
				 */
			} else {
				char *cp = substitute(ps1, 0);
				strdupx(prompt, cp, saved_atemp);
			}
			current_lineno = saved_lineno;
			quitenv(NULL);
		}
		break;
	/* command continuation */
	case PS2:
		prompt = str_val(global("PS2"));
		break;
	}
}

int
pprompt(const char *cp, int ntruncate)
{
	char delimiter = 0;
	bool doprint = (ntruncate != -1);
	bool indelimit = false;
	int columns = 0, lines = 0;

	/*
	 * Undocumented AT&T ksh feature:
	 * If the second char in the prompt string is \r then the first
	 * char is taken to be a non-printing delimiter and any chars
	 * between two instances of the delimiter are not considered to
	 * be part of the prompt length
	 */
	if (*cp && cp[1] == '\r') {
		delimiter = *cp;
		cp += 2;
	}
	for (; *cp; cp++) {
		if (indelimit && *cp != delimiter)
			;
		else if (ctype(*cp, C_CR | C_LF)) {
			lines += columns / x_cols + ((*cp == '\n') ? 1 : 0);
			columns = 0;
		} else if (*cp == '\t') {
			columns = (columns | 7) + 1;
		} else if (*cp == '\b') {
			if (columns > 0)
				columns--;
		} else if (*cp == delimiter)
			indelimit = !indelimit;
		else if (UTFMODE && (rtt2asc(*cp) > 0x7F)) {
			const char *cp2;
			columns += utf_widthadj(cp, &cp2);
			if (doprint && (indelimit ||
			    (ntruncate < (x_cols * lines + columns))))
				shf_write(cp, cp2 - cp, shl_out);
			cp = cp2 - /* loop increment */ 1;
			continue;
		} else
			columns++;
		if (doprint && (*cp != delimiter) &&
		    (indelimit || (ntruncate < (x_cols * lines + columns))))
			shf_putc(*cp, shl_out);
	}
	if (doprint)
		shf_flush(shl_out);
	return (x_cols * lines + columns);
}

/*
 * Read the variable part of a ${...} expression (i.e. up to but not
 * including the :[-+?=#%] or close-brace).
 */
static char *
get_brace_var(XString *wsp, char *wp)
{
	char c;
	enum parse_state {
		PS_INITIAL, PS_SAW_PERCENT, PS_SAW_HASH, PS_SAW_BANG,
		PS_IDENT, PS_NUMBER, PS_VAR1
	} state = PS_INITIAL;

	while (/* CONSTCOND */ 1) {
		c = getsc();
		/* State machine to figure out where the variable part ends. */
		switch (state) {
		case PS_SAW_HASH:
			if (ctype(c, C_VAR1)) {
				char c2;

				c2 = getsc();
				ungetsc(c2);
				if (ord(c2) != ORD(/*{*/ '}')) {
					ungetsc(c);
					goto out;
				}
			}
			goto ps_common;
		case PS_SAW_BANG:
			switch (ord(c)) {
			case ORD('@'):
			case ORD('#'):
			case ORD('-'):
			case ORD('?'):
				goto out;
			}
			goto ps_common;
		case PS_INITIAL:
			switch (ord(c)) {
			case ORD('%'):
				state = PS_SAW_PERCENT;
				goto next;
			case ORD('#'):
				state = PS_SAW_HASH;
				goto next;
			case ORD('!'):
				state = PS_SAW_BANG;
				goto next;
			}
			/* FALLTHROUGH */
		case PS_SAW_PERCENT:
 ps_common:
			if (ctype(c, C_ALPHX))
				state = PS_IDENT;
			else if (ctype(c, C_DIGIT))
				state = PS_NUMBER;
			else if (ctype(c, C_VAR1))
				state = PS_VAR1;
			else
				goto out;
			break;
		case PS_IDENT:
			if (!ctype(c, C_ALNUX)) {
				if (ord(c) == ORD('[')) {
					char *tmp, *p;

					if (!arraysub(&tmp))
						yyerror("missing ]");
					*wp++ = c;
					p = tmp;
					while (*p) {
						Xcheck(*wsp, wp);
						*wp++ = *p++;
					}
					afree(tmp, ATEMP);
					/* the ] */
					c = getsc();
				}
				goto out;
			}
 next:
			break;
		case PS_NUMBER:
			if (!ctype(c, C_DIGIT))
				goto out;
			break;
		case PS_VAR1:
			goto out;
		}
		Xcheck(*wsp, wp);
		*wp++ = c;
	}
 out:
	/* end of variable part */
	*wp++ = '\0';
	ungetsc(c);
	return (wp);
}

/*
 * Save an array subscript - returns true if matching bracket found, false
 * if eof or newline was found.
 * (Returned string double null terminated)
 */
static bool
arraysub(char **strp)
{
	XString ws;
	char *wp, c;
	/* we are just past the initial [ */
	unsigned int depth = 1;

	Xinit(ws, wp, 32, ATEMP);

	do {
		c = getsc();
		Xcheck(ws, wp);
		*wp++ = c;
		if (ord(c) == ORD('['))
			depth++;
		else if (ord(c) == ORD(']'))
			depth--;
	} while (depth > 0 && c && c != '\n');

	*wp++ = '\0';
	*strp = Xclose(ws, wp);

	return (tobool(depth == 0));
}

/* Unget a char: handles case when we are already at the start of the buffer */
static void
ungetsc(int c)
{
	struct sretrace_info *rp = retrace_info;

	if (backslash_skip)
		backslash_skip--;
	/* Don't unget EOF... */
	if (source->str == null && c == '\0')
		return;
	while (rp) {
		if (Xlength(rp->xs, rp->xp))
			rp->xp--;
		rp = rp->next;
	}
	ungetsc_i(c);
}
static void
ungetsc_i(int c)
{
	if (source->str > source->start)
		source->str--;
	else {
		Source *s;

		s = pushs(SREREAD, source->areap);
		s->ugbuf[0] = c; s->ugbuf[1] = '\0';
		s->start = s->str = s->ugbuf;
		s->next = source;
		source = s;
	}
}


/* Called to get a char that isn't a \newline sequence. */
static int
getsc_bn(void)
{
	int c, c2;

	if (ignore_backslash_newline)
		return (o_getsc_u());

	if (backslash_skip == 1) {
		backslash_skip = 2;
		return (o_getsc_u());
	}

	backslash_skip = 0;

	while (/* CONSTCOND */ 1) {
		c = o_getsc_u();
		if (c == '\\') {
			if ((c2 = o_getsc_u()) == '\n')
				/* ignore the \newline; get the next char... */
				continue;
			ungetsc_i(c2);
			backslash_skip = 1;
		}
		return (c);
	}
}

void
yyskiputf8bom(void)
{
	int c;

	if (rtt2asc((c = o_getsc_u())) != 0xEF) {
		ungetsc_i(c);
		return;
	}
	if (rtt2asc((c = o_getsc_u())) != 0xBB) {
		ungetsc_i(c);
		ungetsc_i(asc2rtt(0xEF));
		return;
	}
	if (rtt2asc((c = o_getsc_u())) != 0xBF) {
		ungetsc_i(c);
		ungetsc_i(asc2rtt(0xBB));
		ungetsc_i(asc2rtt(0xEF));
		return;
	}
	UTFMODE |= 8;
}

static Lex_state *
push_state_i(State_info *si, Lex_state *old_end)
{
	Lex_state *news = alloc2(STATE_BSIZE, sizeof(Lex_state), ATEMP);

	news[0].ls_base = old_end;
	si->base = &news[0];
	si->end = &news[STATE_BSIZE];
	return (&news[1]);
}

static Lex_state *
pop_state_i(State_info *si, Lex_state *old_end)
{
	Lex_state *old_base = si->base;

	si->base = old_end->ls_base - STATE_BSIZE;
	si->end = old_end->ls_base;

	afree(old_base, ATEMP);

	return (si->base + STATE_BSIZE - 1);
}
