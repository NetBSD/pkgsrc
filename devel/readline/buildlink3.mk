# $NetBSD: buildlink3.mk,v 1.14 2004/02/17 15:57:55 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
READLINE_BUILDLINK3_MK:=	${READLINE_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(READLINE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		readline
BUILDLINK_DEPENDS.readline+=	readline>=2.2
BUILDLINK_PKGSRCDIR.readline?=	../../devel/readline
.endif	# READLINE_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.readline?=	NO

.if !defined(_BLNK_LIBREADLINE_FOUND)
_BLNK_LIBREADLINE_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libreadline.*`" = "/usr/lib/libreadline.*" ]; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_BLNK_LIBREADLINE_FOUND=${_BLNK_LIBREADLINE_FOUND}
.endif

.if !defined(_BLNK_LIBEDIT_FOUND)
_BLNK_LIBEDIT_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libedit.*`" = "/usr/lib/libedit.*" ]; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_BLNK_LIBEDIT_FOUND=${_BLNK_LIBEDIT_FOUND}
.endif

_READLINE_H=		/usr/include/readline.h
_READLINE_READLINE_H=	/usr/include/readline/readline.h

.if !defined(BUILDLINK_IS_BUILTIN.readline)
BUILDLINK_IS_BUILTIN.readline=	NO
.  if !empty(_BLNK_LIBREADLINE_FOUND:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.readline=	YES
.  elif exists(${_READLINE_H}) || exists(${_READLINE_READLINE_H})
.    if exists(${_READLINE_H})
_READLINE_HEADER=	${_READLINE_H}
.    else
_READLINE_HEADER=	${_READLINE_READLINE_H}
.    endif
_IS_BUILTIN.readline!=		\
	if ${GREP} -q "\#define[ 	]*RL_VERSION_MAJOR" ${_READLINE_HEADER}; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.readline=	${_IS_BUILTIN.readline}
.    if !empty(BUILDLINK_CHECK_BUILTIN.readline:M[nN][oO]) && \
        !empty(_IS_BUILTIN.readline:M[yY][eE][sS])
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
_READLINE_PKG=		readline-${_READLINE_VERSION}
BUILDLINK_IS_BUILTIN.readline=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.readline}
.        if !empty(BUILDLINK_IS_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.readline!=						\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_READLINE_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
#
# XXX By default, assume that the native editline library supports readline.
#
.  if !empty(_BLNK_LIBREADLINE_FOUND:M[nN][oO]) && \
      !empty(_BLNK_LIBEDIT_FOUND:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.readline=	YES
_INCOMPAT_READLINE?=	SunOS-*-*
.    for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_IS_BUILTIN.readline=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.readline=${BUILDLINK_IS_BUILTIN.readline}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	YES
.else
BUILDLINK_USE_BUILTIN.readline=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	NO
.endif
.if !empty(PREFER_NATIVE:Mreadline) && \
    !empty(BUILDLINK_IS_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	YES
.endif
.if !empty(PREFER_PKGSRC:Mreadline)
BUILDLINK_USE_BUILTIN.readline=	NO
.endif

.if defined(USE_GNU_READLINE)
.  if !empty(BUILDLINK_IS_BUILTIN.readline:M[yY][eE][sS]) && \
      !empty(_BLNK_LIBREADLINE_FOUND:M[nN][oO]) && \
      !empty(_BLNK_LIBEDIT_FOUND:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	NO
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.readline:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	readline
.  endif
.endif

.if !empty(READLINE_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.readline:M[yY][eE][sS])
.    if !empty(_BLNK_LIBREADLINE_FOUND:M[nN][oO]) && \
        !empty(_BLNK_LIBEDIT_FOUND:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		l:history:edit
BUILDLINK_TRANSFORM+=		l:readline:edit:termcap
.    endif
.  endif

BUILDLINK_FILES.readline=	include/history.h
BUILDLINK_FILES.readline+=	include/readline.h
BUILDLINK_TRANSFORM.readline=	\
	-e "s|include/history\.h|include/readline/history.h|g"		\
	-e "s|include/readline\.h|include/readline/readline.h|g"
.endif	# READLINE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
