# $NetBSD: buildlink2.mk,v 1.9 2003/09/23 09:58:12 yyamano Exp $
#
# Optionally define:
#
# USE_NCURSES		force use of ncurses
# INCOMPAT_CURSES	specify MACHINE_PLATFORM versions that are missing
#			some needed functions.

.if !defined(NCURSES_BUILDLINK2_MK)
NCURSES_BUILDLINK2_MK=     # defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.ncurses?=	ncurses>=5.3nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses

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
#
# Similarly for IRIX and Darwin
#
_INCOMPAT_CURSES+=      IRIX-*-*
_INCOMPAT_CURSES+=     	Darwin-*-* 
INCOMPAT_CURSES?=	# empty
.  for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_NCURSES=		YES
.    endif
.  endfor
.endif

.if ${_NEED_NCURSES} == "YES"
BUILDLINK_PACKAGES+=		ncurses
EVAL_PREFIX+=			BUILDLINK_PREFIX.ncurses=ncurses
BUILDLINK_PREFIX.ncurses_DEFAULT= ${LOCALBASE}
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
BUILDLINK_FILES.ncurses+=	include/ncurses_dll.h
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
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"
BUILDLINK_TRANSFORM+=		l:ncurses:curses
.  endif
.endif

BUILDLINK_TARGETS+=	ncurses-buildlink
BUILDLINK_TARGETS+=	ncurses-curses-h
BUILDLINK_TARGETS+=	ncurses-extra-includes-buildlink

ncurses-buildlink: _BUILDLINK_USE

ncurses-extra-includes-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extra_includes="						\
		include/term.h						\
	";								\
	for f in $${extra_includes}; do				\
		if [ ! -f ${BUILDLINK_DIR}/$${f} ]; then		\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($${f}) in ${BUILDLINK_DIR}."; \
			${TOUCH} ${TOUCH_FLAGS} ${BUILDLINK_DIR}/$${f}; \
		fi;							\
	done

ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/curses.h ]; then		\
		${ECHO_BUILDLINK_MSG} "Linking curses.h to ncurses.h in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_PREFIX.ncurses}/include/ncurses.h ${BUILDLINK_DIR}/include/curses.h; \
	fi

.endif  # NCURSES_BUILDLINK2_MK
