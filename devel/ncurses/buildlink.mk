# $NetBSD: buildlink.mk,v 1.23 2002/09/02 20:35:09 tron Exp $
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
_NEED_NCURSES=		NO
#
# These versions of NetBSD didn't have a curses library that was capable of
# replacing ncurses.
#
_INCOMPAT_CURSES=       NetBSD-0.*-* NetBSD-1.[0123]*-*
_INCOMPAT_CURSES+=      NetBSD-1.4.*-* NetBSD-1.4[A-X]-*
#
# This catch-all for SunOS is probably too broad, but better to err on
# the safe side.  We can narrow down the match when we have better
# information.
#
_INCOMPAT_CURSES+=	SunOS-*-*
INCOMPAT_CURSES?=	# empty
.  for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_NCURSES=		YES
.    endif
.  endfor
.endif

.if ${_NEED_NCURSES} == "YES"
EVAL_PREFIX+=			BUILDLINK_PREFIX.ncurses=ncurses
BUILDLINK_PREFIX.ncurses_DEFAULT=	${LOCALBASE}
DEPENDS+=			${BUILDLINK_DEPENDS.ncurses}:../../devel/ncurses
.else
BUILDLINK_PREFIX.ncurses=	/usr
.endif

BUILDLINK_FILES.ncurses+=	include/curses.h
BUILDLINK_FILES.ncurses+=	include/cursesapp.h
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

.if ${_NEED_NCURSES} == "NO"
_BLNK_LIBNCURSES_LIST!=		${ECHO} /usr/lib/libncurses.*
.  if ${_BLNK_LIBNCURSES_LIST} == "/usr/lib/libncurses.*"
BUILDLINK_FILES.ncurses+=	lib/libcurses.*
BUILDLINK_TRANSFORM.ncurses=	-e "s|libcurses\.|libncurses.|g"
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"
REPLACE_LIBNAMES_SED+=		-e "s|-lncurses|-lcurses|g"
.  endif
.endif

BUILDLINK_TARGETS.ncurses+=	ncurses-buildlink
BUILDLINK_TARGETS.ncurses+=	ncurses-curses-h
BUILDLINK_TARGETS.ncurses+=	ncurses-extra-includes-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ncurses}

pre-configure: ${BUILDLINK_TARGETS.ncurses}
ncurses-buildlink: _BUILDLINK_USE

ncurses-extra-includes-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extra_includes="						\
		include/term.h						\
	";								\
	for file in $${extra_includes}; do				\
		if [ ! -f ${BUILDLINK_DIR}/$${file} ]; then		\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($${file}) in ${BUILDLINK_DIR}."; \
			${TOUCH} ${TOUCH_FLAGS} ${BUILDLINK_DIR}/$${file}; \
		fi;							\
	done

ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/curses.h ]; then		\
		${ECHO_BUILDLINK_MSG} "Linking curses.h to ncurses.h in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_PREFIX.ncurses}/include/ncurses.h ${BUILDLINK_DIR}/include/curses.h; \
	fi

.endif  # NCURSES_BUILDLINK_MK
