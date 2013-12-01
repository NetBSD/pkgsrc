# $NetBSD: buildlink3.mk,v 1.43 2013/12/01 02:18:14 obache Exp $

BUILDLINK_TREE+=	ncurses

.if !defined(NCURSES_BUILDLINK3_MK)
NCURSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncurses+=	ncurses>=5.3nb1
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses>=5.4nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses

BUILDLINK_LIBNAME.ncurses=	ncurses
BUILDLINK_LDADD.ncurses?=	${BUILDLINK_LIBNAME.ncurses:S/^/-l/:S/^-l$//}

# Many packages expect the ncurses headers and libraries to be usable as
# <curses.h> and -lcurses and they often only look in include/ rather than
# some properly written autoconf macros which also try to pick up
# ncurses/ncurses.h.
#
BUILDLINK_TARGETS+=		buildlink-ncurses-curses-h
BUILDLINK_TARGETS+=		buildlink-ncurses-ncurses-h
BUILDLINK_TARGETS+=		buildlink-ncurses-term-h
BUILDLINK_TRANSFORM+=		l:curses:${BUILDLINK_LIBNAME.ncurses}
BUILDLINK_INCDIRS.ncurses+=	include/ncurses

# Many packages will prefer ncursesw over ncurses if its available (say as
# a native library), so unless this file is being included by ncursesw
# don't allow ncursesw to be used by causing linkage failure.
#
.  include "../../mk/bsd.fast.prefs.mk"
.  if empty(BUILDLINK_TREE:Mncursesw) && empty(PKGPATH:Mdevel/ncursesw)
BUILDLINK_TRANSFORM+=		l:ncursesw:__nonexistent__
.  endif

.PHONY: buildlink-ncurses-curses-h buildlink-ncurses-ncurses-h
.PHONY: buildlink-ncurses-term-h
buildlink-ncurses-curses-h:
	${RUN}									\
	src=${BUILDLINK_PREFIX.ncurses}"/include/ncurses/curses.h";		\
	dest=${BUILDLINK_DIR}"/include/curses.h";				\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then				\
		${ECHO_BUILDLINK_MSG} "Linking ncurses/curses.h -> curses.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;					\
		${LN} -s "$$src" "$$dest";					\
	fi

buildlink-ncurses-ncurses-h:
	${RUN}									\
	src=${BUILDLINK_PREFIX.ncurses}"/include/ncurses/ncurses.h";		\
	dest=${BUILDLINK_DIR}"/include/ncurses.h";				\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then				\
		${ECHO_BUILDLINK_MSG} "Linking ncurses/ncurses.h -> ncurses.h.";\
		${MKDIR} `${DIRNAME} "$$dest"`;					\
		${LN} -s "$$src" "$$dest";					\
	fi

buildlink-ncurses-term-h:
	${RUN}									\
	src=${BUILDLINK_PREFIX.ncurses}"/include/ncurses/term.h";		\
	dest=${BUILDLINK_DIR}"/include/term.h";				\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then				\
		${ECHO_BUILDLINK_MSG} "Linking ncurses/term.h -> term.h.";\
		${MKDIR} `${DIRNAME} "$$dest"`;					\
		${LN} -s "$$src" "$$dest";					\
	fi

.endif # NCURSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncurses
