# $NetBSD: buildlink3.mk,v 1.51 2024/05/06 15:08:02 jperkin Exp $

BUILDLINK_TREE+=	ncurses

.if !defined(NCURSES_BUILDLINK3_MK)
NCURSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncurses+=	ncurses>=5.3nb1
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses>=6.5
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses

BUILDLINK_INCDIRS.ncurses+=	include/ncurses
BUILDLINK_LIBNAME.ncurses=	ncurses
BUILDLINK_LDADD.ncurses?=	${BUILDLINK_LIBNAME.ncurses:S/^/-l/:S/^-l$//}

# If a package specifies USE_CURSES=wide then we must enable the wide API in
# the ncurses headers.  Using the NCURSES_WIDECHAR define is much less
# intrusive than setting _XOPEN_SOURCE_EXTENDED or _XOPEN_SOURCE.
#
.if ${USE_CURSES:U:Mwide}
BUILDLINK_CPPFLAGS.ncurses+=	-DNCURSES_WIDECHAR=1
.endif

# Many packages expect the ncurses headers and libraries to be usable as
# <curses.h> and -lcurses and they often only look in include/ rather than
# some properly written autoconf macros which also try to pick up
# ncurses/ncurses.h.
#
BUILDLINK_TARGETS+=		buildlink-ncurses-curses-h
BUILDLINK_TARGETS+=		buildlink-ncurses-ncurses-h
BUILDLINK_TARGETS+=		buildlink-ncurses-term-h
BUILDLINK_TARGETS+=		buildlink-ncursesw-pc

# Some packages will only enable wide curses support if they specifically
# find it in libncursesw, so redirect requests for it to libncurses.
#
BUILDLINK_TRANSFORM+=		l:curses:${BUILDLINK_LIBNAME.ncurses}
BUILDLINK_TRANSFORM+=		l:ncursesw:${BUILDLINK_LIBNAME.ncurses}

.PHONY: buildlink-ncurses-curses-h buildlink-ncurses-ncurses-h
.PHONY: buildlink-ncurses-term-h buildlink-ncursesw-pc
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

buildlink-ncursesw-pc:
	${RUN}									\
	src=${BUILDLINK_PREFIX.ncurses}"/lib/pkgconfig/ncurses.pc";		\
	dest=${BUILDLINK_DIR}"/lib/pkgconfig/ncursesw.pc";			\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then				\
		${ECHO_BUILDLINK_MSG} "Linking ncursesw.pc -> ncurses.pc.";\
		${MKDIR} `${DIRNAME} "$$dest"`;					\
		${LN} -s "$$src" "$$dest";					\
	fi

.endif # NCURSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncurses
