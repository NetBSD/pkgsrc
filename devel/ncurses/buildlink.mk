# $NetBSD: buildlink.mk,v 1.13 2001/11/30 17:21:54 jlam Exp $
#
# This Makefile fragment is included by packages that use ncurses.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_NCURSES to force use of ncurses.
# (2) Optionally define BUILDLINK_DEPENDS.ncurses to the dependency pattern
#     for the version of ncurses desired.
# (3) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(NCURSES_BUILDLINK_MK)
NCURSES_BUILDLINK_MK=     # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ncurses?=	ncurses>=5.0

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
.if ${OPSYS} != "SunOS"
_NEED_NCURSES=		YES
.endif
.endif
.endif

.if ${_NEED_NCURSES} == "YES"
EVAL_PREFIX+=			BUILDLINK_PREFIX.ncurses=ncurses
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
BUILDLINK_TRANSFORM.ncurses=	-e "s|libcurses\.|libncurses.|g"
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"
REPLACE_LIBNAMES_SED+=		-e "s|-lncurses|-lcurses|g"
.endif

BUILDLINK_TARGETS.ncurses+=	ncurses-buildlink
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

.endif  # NCURSES_BUILDLINK_MK
