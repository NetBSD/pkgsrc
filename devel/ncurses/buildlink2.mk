# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:36 jlam Exp $
#
# This Makefile fragment is included by packages that use ncurses.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_NCURSES to force use of ncurses,
#     or define INCOMPAT_CURSES to specify NetBSD versions that are
#     missing some needed functions.
# (2) Optionally define BUILDLINK_DEPENDS.ncurses to the dependency pattern
#     for the version of ncurses desired.
# (3) Include this Makefile fragment in the package Makefile.

.if !defined(NCURSES_BUILDLINK2_MK)
NCURSES_BUILDLINK2_MK=     # defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.ncurses?=	ncurses>=5.0

.if defined(USE_NCURSES)
_NEED_NCURSES=		YES
.else
_NEED_NCURSES=		NO
.  if ${OPSYS} == "NetBSD"
_INCOMPAT_CURSES=	0.* 1.[0123]* 1.4.* 1.4[A-X] ${INCOMPAT_CURSES}
.    for PATTERN in ${_INCOMPAT_CURSES}
.      if ${OS_VERSION:M${PATTERN}} != ""
_NEED_NCURSES=		YES
.      endif
.    endfor
.  elif ${OPSYS} != "SunOS"
_NEED_NCURSES=		YES
.  endif
.endif

.if ${_NEED_NCURSES} == "YES"
EVAL_PREFIX+=	BUILDLINK_PREFIX.ncurses=ncurses
BUILDLINK_PREFIX.ncurses_DEFAULT=	${LOCALBASE}
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
DEPENDS+=			${BUILDLINK_DEPENDS.ncurses}:../../devel/ncurses
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
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"
BUILDLINK_TRANSFORM+=		l:ncurses:curses
.endif

BUILDLINK_TARGETS.ncurses+=	ncurses-buildlink
.if defined(USE_BUILDLINK2_ONLY)
BUILDLINK_TARGETS.ncurses+=	ncurses-curses-h
.endif
.if ${_NEED_NCURSES} == "NO"
BUILDLINK_TARGETS.ncurses+=	ncurses-extra-includes-buildlink
.endif
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ncurses}

pre-configure: ${BUILDLINK_TARGETS.ncurses}
ncurses-buildlink: _BUILDLINK_USE

ncurses-extra-includes-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_BUILDLINK_MSG} "Touching extra ncurses headers in ${BUILDLINK_DIR}."; \
	extra_includes="						\
		include/term.h						\
	";								\
	for file in $${extra_includes}; do				\
		${TOUCH} ${TOUCH_FLAGS} ${BUILDLINK_DIR}/$${file};	\
	done

ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_BUILDLINK_MSG} "Linking curses.h to ncurses.h in ${BUILDLINK_DIR}."; \
	${LN} -s ${BUILDLINK_PREFIX.ncurses}/include/ncurses.h ${BUILDLINK_DIR}/include/curses.h

.endif  # NCURSES_BUILDLINK2_MK
