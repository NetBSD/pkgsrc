# $NetBSD: buildlink.mk,v 1.1 2001/06/19 16:18:15 jlam Exp $
#
# This Makefile fragment is included by packages that use ncurses.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_NCURSES to force use of ncurses.
# (2) Optionally define NCURSES_REQD to the version of ncurses desired.
# (3) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

NCURSES_REQD?=		5.0

.if defined(USE_NCURSES)
_NEED_NCURSES=		YES
.else
.include "../../mk/bsd.prefs.mk"
_NEED_NCURSES=		NO
.if ${OPSYS} == "NetBSD"
_INCOMPAT_CURSES=	0.* 1.[0123]* 1.4.* 1.4[A-X]
.for PATTERN in ${_INCOMPAT_CURSES}
.if ${OS_VERSION:M${PATTERN}} != ""
_NEED_NCURSES=		YES
.endif
.endfor
.else
_NEED_NCURSES=		YES
.endif
.endif

.if ${_NEED_NCURSES} == "YES"
BUILDLINK_PREFIX.ncurses=	${LOCALBASE}
BUILDLINK_FILES.ncurses=	include/cursesapp.h
BUILDLINK_FILES.ncurses+=	include/cursesf.h
BUILDLINK_FILES.ncurses+=	include/cursesm.h
BUILDLINK_FILES.ncurses+=	include/cursesp.h
BUILDLINK_FILES.ncurses+=	include/cursesw.h
BUILDLINK_FILES.ncurses+=	include/cursslk.h
BUILDLINK_FILES.ncurses+=	include/eti.h
BUILDLINK_FILES.ncurses+=	include/etip.h
BUILDLINK_FILES.ncurses+=	include/form.h
BUILDLINK_FILES.ncurses+=	include/menu.h
BUILDLINK_FILES.ncurses+=	include/ncurses.h
BUILDLINK_FILES.ncurses+=	include/panel.h
BUILDLINK_FILES.ncurses+=	include/term.h
BUILDLINK_FILES.ncurses+=	include/termcap.h
BUILDLINK_FILES.ncurses+=	include/unctrl.h
BUILDLINK_FILES.ncurses+=	lib/libform.*
BUILDLINK_FILES.ncurses+=	lib/libmenu.*
BUILDLINK_FILES.ncurses+=	lib/libncurses++.*
BUILDLINK_FILES.ncurses+=	lib/libncurses.*
BUILDLINK_FILES.ncurses+=	lib/libpanel.*
DEPENDS+=			ncurses>=${NCURSES_REQD}:../../devel/ncurses
.else
BUILDLINK_PREFIX.ncurses=	/usr
BUILDLINK_FILES.ncurses=	include/curses.h
BUILDLINK_FILES.ncurses+=	include/eti.h
BUILDLINK_FILES.ncurses+=	include/form.h
BUILDLINK_FILES.ncurses+=	include/menu.h
BUILDLINK_FILES.ncurses+=	include/termcap.h
BUILDLINK_FILES.ncurses+=	include/unctrl.h
BUILDLINK_FILES.ncurses+=	lib/libcurses.*
BUILDLINK_FILES.ncurses+=	lib/libform.*
BUILDLINK_FILES.ncurses+=	lib/libmenu.*
.endif

BUILDLINK_TRANSFORM.ncurses=	-e "s|libcurses\.|libncurses.|g"
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"

BUILDLINK_TARGETS.ncurses=	ncurses-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ncurses}

pre-configure: ${BUILDLINK_TARGETS.ncurses}
ncurses-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"
