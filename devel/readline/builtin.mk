# $NetBSD: builtin.mk,v 1.3 2004/03/29 05:43:30 jlam Exp $

.if !defined(_BLNK_LIBREADLINE_FOUND)
_BLNK_LIBREADLINE_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libreadline.*`" = "/usr/lib/libreadline.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBREADLINE_FOUND
.endif

.if !defined(_BLNK_LIBEDIT_FOUND)
_BLNK_LIBEDIT_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libedit.*`" = "/usr/lib/libedit.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBEDIT_FOUND
.endif

_READLINE_H=		/usr/include/readline.h
_READLINE_READLINE_H=	/usr/include/readline/readline.h

.if !defined(IS_BUILTIN.readline)
IS_BUILTIN.readline=	no
.  if !empty(_BLNK_LIBREADLINE_FOUND:M[yY][eE][sS])
IS_BUILTIN.readline=	yes
.  elif exists(${_READLINE_H}) || exists(${_READLINE_READLINE_H})
.    if exists(${_READLINE_H})
_READLINE_HEADER=	${_READLINE_H}
.    else
_READLINE_HEADER=	${_READLINE_READLINE_H}
.    endif
IS_BUILTIN.readline!=	\
	if ${GREP} -q "\#define[ 	]*RL_VERSION_MAJOR" ${_READLINE_HEADER}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.readline:M[yY][eE][sS])
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
_READLINE_MAJOR!=							\
	${AWK} '/\#define[ 	]*RL_VERSION_MAJOR/ { print $$3 }'	\
		${_READLINE_HEADER}
_READLINE_MINOR!=							\
	${AWK} '/\#define[ 	]*RL_VERSION_MINOR/ { print $$3 }'	\
		${_READLINE_HEADER}
_READLINE_VERSION=	${_READLINE_MAJOR}.${_READLINE_MINOR}
BUILTIN_PKG.readline=	readline-${_READLINE_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.readline
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.readline
.endif	# IS_BUILTIN.readline

.if !defined(USE_BUILTIN.readline)
USE_BUILTIN.readline?=	${IS_BUILTIN.readline}
PREFER.readline?=	pkgsrc

.  if defined(BUILTIN_PKG.readline)
USE_BUILTIN.readline=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.readline}
.      if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
USE_BUILTIN.readline!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.readline}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if ${PREFER.readline} == "native"
# XXX
# XXX By default, assume that the native editline library supports readline.
# XXX
.    if !empty(_BLNK_LIBREADLINE_FOUND:M[nN][oO]) && \
        !empty(_BLNK_LIBEDIT_FOUND:M[yY][eE][sS])
USE_BUILTIN.readline=	yes
_INCOMPAT_READLINE?=	SunOS-*-*
.      for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.readline=	no
.        endif
.      endfor
.    endif
.  endif

.  if defined(USE_GNU_READLINE)
.    if !empty(IS_BUILTIN.readline:M[nN][oO]) || \
        (${PREFER.readline} == "pkgsrc")
USE_BUILTIN.readline=	no
.    endif
.  endif
.endif	# USE_BUILTIN.readline

CHECK_BUILTIN.readline?=	no
.if !empty(CHECK_BUILTIN.readline:M[nN][oO])

.if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
.  if !empty(_BLNK_LIBREADLINE_FOUND:M[nN][oO]) && \
      !empty(_BLNK_LIBEDIT_FOUND:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		l:history:edit
BUILDLINK_TRANSFORM+=		l:readline:edit:termcap
.  endif
.endif

.endif	# CHECK_BUILTIN.readline
