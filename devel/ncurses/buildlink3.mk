# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 09:34:23 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NCURSES_BUILDLINK3_MK:=	${NCURSES_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(NCURSES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		ncurses
BUILDLINK_DEPENDS.ncurses?=	ncurses>=5.3nb1
BUILDLINK_PKGSRCDIR.ncurses?=	../../devel/ncurses
.endif	# NCURSES_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.ncurses?=	NO

.if !defined(_BLNK_LIBNCURSES_FOUND)
_BLNK_LIBNCURSES_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libncurses.*`" = "/usr/lib/libncurses.*" ]; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_BLNK_LIBNCURSES_FOUND="${_BLNK_LIBNCURSES_FOUND}"
.endif

.if !defined(BUILDLINK_IS_BUILTIN.ncurses)
BUILDLINK_IS_BUILTIN.ncurses=	NO
.  if ${_BLNK_LIBNCURSES_FOUND} == "YES"
BUILDLINK_IS_BUILTIN.ncurses=	YES
.  endif
.endif

.if defined(USE_NCURSES)
BUILDLINK_USE_BUILTIN.ncurses=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.ncurses:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.ncurses=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.ncurses)
.  if !empty(BUILDLINK_IS_BUILTIN.ncurses:M[nN][oO])
BUILDLINK_USE_BUILTIN.ncurses=	YES
.  else
#
# These versions of NetBSD didn't have a curses library that was capable of
# replacing ncurses.
#
_INCOMPAT_CURSES=	NetBSD-0.*-* NetBSD-1.[0123]*-*
_INCOMPAT_CURSES+=	NetBSD-1.4.*-* NetBSD-1.4[A-X]-*
#
# These catch-alls are probably too broad, but better to err on the safe
# side.  We can narrow down the match when we have better information.
#
_INCOMPAT_CURSES+=	SunOS-*-*
_INCOMPAT_CURSES+=      IRIX-*-*
_INCOMPAT_CURSES+=      Darwin-*-*

INCOMPAT_CURSES?=	# empty
.    for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_USE_BUILTIN.ncurses=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	\
	BUILDLINK_USE_BUILTIN.ncurses="${BUILDLINK_USE_BUILTIN.ncurses}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.ncurses:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ncurses
.  endif
.endif

.if !empty(NCURSES_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.ncurses:M[yY][eE][sS])
.    if ${_BLNK_LIBNCURSES_FOUND} == "NO"
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses.h|/ncurses.h|g"
BUILDLINK_TRANSFORM+=		l:ncurses:curses
.    endif
.  endif

BUILDLINK_FILES.ncurses=	include/curses.h
BUILDLINK_FILES.ncurses+=	include/term.h

BUILDLINK_TARGETS+=	buildlink-ncurses-curses-h
BUILDLINK_TARGETS+=	buildlink-ncurses-extra-includes

.PHONY: buildlink-ncurses-extra-includes
buildlink-ncurses-extra-includes:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extra_includes="include/term.h";				\
	for f in $${extra_includes}; do					\
		if [ ! -f ${BUILDLINK_DIR}/$${f} ]; then		\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($${f}) in ${BUILDLINK_DIR}."; \
			${TOUCH} ${TOUCH_FLAGS} ${BUILDLINK_DIR}/$${f}; \
		fi;							\
	done

.PHONY: buildlink-ncurses-curses-h
buildlink-ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/curses.h ]; then		\
		${ECHO_BUILDLINK_MSG} "Linking curses.h to ncurses.h in ${BUILDLINK_DIR}."; \
		${LN} -s ncurses.h ${BUILDLINK_DIR}/include/curses.h;	\
	fi 
.endif	# NCURSES_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
