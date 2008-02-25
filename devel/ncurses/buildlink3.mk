# $NetBSD: buildlink3.mk,v 1.28 2008/02/25 04:19:34 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NCURSES_BUILDLINK3_MK:=	${NCURSES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ncurses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nncurses}
BUILDLINK_PACKAGES+=	ncurses
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ncurses

.if !empty(NCURSES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ncurses+=	ncurses>=5.3nb1
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses>=5.4nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses
BUILDLINK_LDADD.ncurses?=	-lncurses

# _PKG_USE_CURSES is defined by curses.buildlink3.mk to indicate that
# the headers and libraries should be usable as <curses.h> and -lcurses.
#
.  if defined(_PKG_USE_CURSES)
BUILDLINK_TARGETS+=	buildlink-ncurses-curses-h
BUILDLINK_TRANSFORM+=	l:curses:ncurses
.  endif

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

.endif	# NCURSES_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
