# $NetBSD: buildlink2.mk,v 1.23 2004/02/14 01:03:54 snj Exp $
#
# Optionally define:
#
# USE_NCURSES		force use of ncurses
# INCOMPAT_CURSES	specify MACHINE_PLATFORM versions that are missing
#			some needed functions.

.if !defined(NCURSES_BUILDLINK2_MK)
NCURSES_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.ncurses?=	ncurses>=5.3nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses

.if !defined(_BLNK_LIBNCURSES_FOUND)
_BLNK_LIBNCURSES_FOUND!=        \
	if [ "`${ECHO} /usr/lib/libncurses.*`" = "/usr/lib/libncurses.*" ]; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_BLNK_LIBNCURSES_FOUND=${_BLNK_LIBNCURSES_FOUND}
.endif

.if !defined(BUILDLINK_IS_BUILTIN.ncurses)
BUILDLINK_IS_BUILTIN.ncurses=	NO
.  if ${_BLNK_LIBNCURSES_FOUND} == "YES"
BUILDLINK_IS_BUILTIN.ncurses=	YES
.  elif exists(${_NCURSES_H})
BUILDLINK_IS_BUILTIN.ncurses!=						\
	if ${GREP} -q "\#define[ 	]*NCURSES_VERSION" ${_NCURSES_H}; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
#
# XXX By default, assume that the builtin curses on NetBSD systems
# XXX supports ncurses.
#
.  if ${OPSYS} == "NetBSD"
BUILDLINK_IS_BUILTIN.ncurses=	YES
#
# These versions of NetBSD didn't have a curses library that was
# capable of replacing ncurses.
#
# XXX In reality, no version of NetBSD has a curses library that can
# XXX completely replace ncurses; however, some version implement
# XXX enough of ncurses that some packages are happy.
#
_INCOMPAT_CURSES=	NetBSD-0.*-* NetBSD-1.[0123]*-*
_INCOMPAT_CURSES+=	NetBSD-1.4.*-* NetBSD-1.4[A-X]-*
.    for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_IS_BUILTIN.ncurses=   NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.ncurses=${BUILDLINK_IS_BUILTIN.ncurses}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.ncurses:M[yY][eE][sS])
_NEED_NCURSES=	NO
.else
_NEED_NCURSES=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${BUILDLINK_IS_BUILTIN.ncurses} == "YES"
_NEED_NCURSES=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_NCURSES=	YES
.endif
.if !empty(PREFER_NATIVE:Mncurses) && \
    ${BUILDLINK_IS_BUILTIN.ncurses} == "YES"
_NEED_NCURSES=	NO
.endif
.if !empty(PREFER_PKGSRC:Mncurses)
_NEED_NCURSES=	YES
.endif

.if defined(USE_NCURSES)
_NEED_NCURSES=	YES
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
.  if !empty(_BLNK_LIBNCURSES_FOUND:M[yY][eE][sS])
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
	for f in $${extra_includes}; do					\
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

.endif	# NCURSES_BUILDLINK2_MK
