# $NetBSD: builtin.mk,v 1.4 2004/10/13 20:10:31 tv Exp $

.if !defined(_BLNK_LIBNCURSES_FOUND)
_BLNK_LIBNCURSES_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libncurses.*`" = "/usr/lib/libncurses.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBNCURSES_FOUND
.endif

_NCURSES_H=	/usr/include/curses.h

.if !defined(IS_BUILTIN.ncurses)
IS_BUILTIN.ncurses=	no
.  if !empty(_BLNK_LIBNCURSES_FOUND:M[yY][eE][sS])
IS_BUILTIN.ncurses=	yes
.  elif exists(${_NCURSES_H})
IS_BUILTIN.ncurses!=		\
	if ${GREP} -q "\#define[ 	]*NCURSES_VERSION" ${_NCURSES_H}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.ncurses:M[yY][eE][sS])
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
_NCURSES_VERSION!=							\
	${AWK} '/\#define[ 	]*NCURSES_VERSION[ 	]/ {		\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${_NCURSES_H}
BUILTIN_PKG.ncurses=	ncurses-${_NCURSES_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.ncurses
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.ncurses
.endif	# IS_BUILTIN.ncurses

.if !defined(USE_BUILTIN.ncurses)
USE_BUILTIN.ncurses?=	${IS_BUILTIN.ncurses}
PREFER.ncurses?=	pkgsrc

.  if defined(BUILTIN_PKG.ncurses)
USE_BUILTIN.ncurses=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.ncurses}
.      if !empty(IS_BUILTIN.ncurses:M[yY][eE][sS])
USE_BUILTIN.ncurses!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.ncurses}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if ${PREFER.ncurses} == "native"
# XXX
# XXX By default, assume that the native curses on NetBSD systems
# XXX supports ncurses.
# XXX
.    if ${OPSYS} == "NetBSD"
USE_BUILTIN.ncurses=	yes
#
# These versions of NetBSD didn't have a curses library that was
# capable of replacing ncurses.
#
# XXX In reality, no version of NetBSD has a curses library that can
# XXX completely replace ncurses; however, some versions implement
# XXX enough of ncurses that some packages are happy.
#
_INCOMPAT_CURSES=	NetBSD-0.*-* NetBSD-1.[0123]*-*
_INCOMPAT_CURSES+=	NetBSD-1.4.*-* NetBSD-1.4[A-X]-*
.      for _pattern_ in ${_INCOMPAT_CURSES} ${INCOMPAT_CURSES}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.ncurses=	no
.        endif
.      endfor
.    endif
.  endif

.  if defined(USE_NCURSES)
.    if !empty(IS_BUILTIN.ncurses:M[nN][oO]) || \
        (${PREFER.ncurses} == "pkgsrc")
USE_BUILTIN.ncurses=	no
.    endif
.  endif
.endif	# USE_BUILTIN.ncurses

CHECK_BUILTIN.ncurses?=	no
.if !empty(CHECK_BUILTIN.ncurses:M[nN][oO])

.if !empty(USE_BUILTIN.ncurses:M[yY][eE][sS])
.  include "../../mk/bsd.prefs.mk"
.  if !empty(_BLNK_LIBNCURSES_FOUND:M[nN][oO]) || ${OPSYS} == "Interix"
BUILDLINK_TRANSFORM.ncurses+=	-e "s|/curses\.h|/ncurses.h|g"
BUILDLINK_TRANSFORM+=		l:ncurses:curses
.  endif
BUILDLINK_FILES.ncurses+=	include/curses.h
BUILDLINK_TARGETS+=		buildlink-ncurses-extra-includes
.endif

BUILDLINK_TARGETS+=		buildlink-ncurses-curses-h

.if !target(buildlink-ncurses-extra-includes)
.PHONY: buildlink-ncurses-extra-includes
buildlink-ncurses-extra-includes:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extra_includes="include/term.h";				\
	for f in $${extra_includes}; do					\
		if [ ! -f ${BUILDLINK_PREFIX.ncurses}/$$f ]; then	\
			${ECHO_BUILDLINK_MSG} "Touching extra ncurses header ($$f) in ${BUILDLINK_DIR}."; \
			${TOUCH} ${TOUCH_FLAGS} ${BUILDLINK_DIR}/$$f;	\
		fi;							\
	done
.endif

.if !target(buildlink-ncurses-curses-h)
.PHONY: buildlink-ncurses-curses-h
buildlink-ncurses-curses-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/curses.h -a			\
	     -f ${BUILDLINK_PREFIX.ncurses}/include/ncurses.h ]; then	\
		${ECHO_BUILDLINK_MSG} "Linking curses.h -> ncurses.h.";	\
		${LN} -s ${BUILDLINK_PREFIX.ncurses}/include/ncurses.h	\
			${BUILDLINK_DIR}/include/curses.h;		\
	fi
.endif

.endif	# CHECK_BUILTIN.ncurses
