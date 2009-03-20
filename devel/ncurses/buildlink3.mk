# $NetBSD: buildlink3.mk,v 1.33 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	ncurses

.if !defined(NCURSES_BUILDLINK3_MK)
NCURSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncurses+=	ncurses>=5.3nb1
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses>=5.4nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses

BUILDLINK_LIBNAME.ncurses=	ncurses
BUILDLINK_LDADD.ncurses?=	${BUILDLINK_LIBNAME.ncurses:S/^/-l/:S/^-l$//}

# Many packages expect the ncurses headers and libraries to be usable as
# <curses.h> and -lcurses.
#
BUILDLINK_TARGETS+=		buildlink-ncurses-curses-h
BUILDLINK_TRANSFORM+=		l:curses:${BUILDLINK_LIBNAME.ncurses}

.PHONY: buildlink-ncurses-curses-h
buildlink-ncurses-curses-h:
	${RUN}								\
	src=${BUILDLINK_PREFIX.ncurses:Q}"/include/ncurses.h";		\
	dest=${BUILDLINK_DIR:Q}"/include/curses.h";			\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		${ECHO_BUILDLINK_MSG} "Linking curses.h -> ncurses.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.endif # NCURSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncurses
