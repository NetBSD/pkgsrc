# $NetBSD: buildlink3.mk,v 1.5 2004/01/10 08:40:07 jlam Exp $
#
# Optionally define USE_GNU_READLINE to force use of GNU readline.
#
# NOTE:	You may need to do some more work to get libedit recognized over
#	libreadline, especially by GNU configure scripts.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
READLINE_BUILDLINK3_MK:=	${READLINE_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(READLINE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		readline
BUILDLINK_DEPENDS.readline?=	readline>=2.2
BUILDLINK_PKGSRCDIR.readline?=	../../devel/readline
.endif	# READLINE_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.readline?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.readline)
BUILDLINK_IS_BUILTIN.readline=	NO
.  if exists(/usr/include/readline.h) || \
      exists(/usr/include/readline/readline.h)
BUILDLINK_IS_BUILTIN.readline=	YES
.  endif
.endif

.if defined(USE_GNU_READLINE)
BUILDLINK_USE_BUILTIN.readline=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.readline:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.readline=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.readline)
.  if !empty(BUILDLINK_IS_BUILTIN.readline:M[nN][oO])
BUILDLINK_USE_BUILTIN.readline=	NO
.  else
BUILDLINK_USE_BUILTIN.readline=	YES
#
# These catch-alls are probably too broad, but better to err on the safe
# side.  We can narrow down the match when we have better information.
#
_INCOMPAT_READLINE=	SunOS-*-*
INCOMPAT_READLINE?=	# empty
.    for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_USE_BUILTIN.readline=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	\
	BUILDLINK_USE_BUILTIN.readline="${BUILDLINK_USE_BUILTIN.readline}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.readline:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	readline
.  endif
.endif

.if !empty(READLINE_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.readline:M[yY][eE][sS])
.    if !defined(_BLNK_LIBEDIT_FOUND)
_BLNK_LIBEDIT_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libedit.*`" = "/usr/lib/libedit.*" ]; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_BLNK_LIBEDIT_FOUND="${_BLNK_LIBEDIT_FOUND}"
.    endif
.    if ${_BLNK_LIBEDIT_FOUND} == "YES"
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
