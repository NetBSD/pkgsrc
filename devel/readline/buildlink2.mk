# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:46 jlam Exp $
#
# Optionally define USE_GNU_READLINE to force use of GNU readline.
#
# NOTE:	You may need to do some more work to get libedit recognized over
#	libreadline, especially by GNU configure scripts.

.if !defined(READLINE_BUILDLINK2_MK)
READLINE_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.readline?=	readline>=2.2
BUILDLINK_PKGSRCDIR.readline?=	../../devel/readline

.if defined(USE_GNU_READLINE)
_NEED_GNU_READLINE=	YES
.else
.  if exists(/usr/include/readline.h) || \
      exists(/usr/include/readline/readline.h)
_NEED_GNU_READLINE=	NO
.  else
_NEED_GNU_READLINE=	YES
.  endif
#
# This catch-all for SunOS is probably too broad, but better to err on
# the safe side.  We can narrow down the match when we have better
# information.
#
_INCOMPAT_READLINE=	SunOS-*-*
INCOMPAT_READLINE?=	# empty
.  for _pattern_ in ${_INCOMPAT_READLINE} ${INCOMPAT_READLINE}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_GNU_READLINE=	YES
.    endif
.  endfor
.endif

.if ${_NEED_GNU_READLINE} == "YES"
BUILDLINK_PACKAGES+=		readline
EVAL_PREFIX+=			BUILDLINK_PREFIX.readline=readline
BUILDLINK_PREFIX.readline_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.readline=		/usr
.endif
BUILDLINK_PREFIX.history=		${BUILDLINK_PREFIX.readline}

BUILDLINK_FILES.readline=	include/readline.h
BUILDLINK_FILES.readline+=	include/readline/*
BUILDLINK_FILES.readline+=	lib/libreadline.*

BUILDLINK_FILES.history=	include/history.h
BUILDLINK_FILES.history+=	lib/libhistory.*

.if ${_NEED_GNU_READLINE} == "NO"
_BLNK_LIBEDIT_LIST!=		${ECHO} /usr/lib/libedit.*
.  if ${_BLNK_LIBEDIT_LIST} != "/usr/lib/libedit.*"
BUILDLINK_FILES.readline+=	lib/libedit.*
BUILDLINK_TRANSFORM.readline=	-e "s|/readline.h|/readline/readline.h|g"
BUILDLINK_TRANSFORM+=		l:readline:edit

BUILDLINK_FILES.history+=	lib/libedit.*
BUILDLINK_TRANSFORM.history=	-e "s|/history.h|/readline/history.h|g"
BUILDLINK_TRANSFORM+=		l:history:edit
.  endif
.endif

BUILDLINK_TARGETS+=	readline-buildlink
BUILDLINK_TARGETS+=	history-buildlink

readline-buildlink: _BUILDLINK_USE
history-buildlink: _BUILDLINK_USE

.endif	# READLINE_BUILDLINK2_MK
