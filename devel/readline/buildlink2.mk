# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:29 jlam Exp $
#
# Optionally define USE_GNU_READLINE to force use of GNU readline.

.if !defined(READLINE_BUILDLINK2_MK)
READLINE_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.readline?=	readline>=2.2
BUILDLINK_PKGSRCDIR.readline?=	../../devel/readline

.if defined(USE_GNU_READLINE)
_NEED_GNU_READLINE=	YES
.elif exists(/usr/include/readline.h) || \
      exists(/usr/include/readline/readline.h)
_NEED_GNU_READLINE=	NO
.else
_NEED_GNU_READLINE=	YES
.endif

.if ${_NEED_GNU_READLINE} == "YES"
BUILDLINK_PACKAGES+=		readline
EVAL_PREFIX+=	BUILDLINK_PREFIX.readline=readline
BUILDLINK_PREFIX.readline_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.readline=	include/readline/*
BUILDLINK_FILES.readline+=	lib/libreadline.*

BUILDLINK_PREFIX.history=	${BUILDLINK_PREFIX.readline}
BUILDLINK_FILES.history+=	lib/libhistory.*
.elif ${OPSYS} == "Linux"
BUILDLINK_PREFIX.readline=	/usr
BUILDLINK_FILES.readline=	include/readline/*
BUILDLINK_FILES.readline+=	lib/libreadline.*

BUILDLINK_PREFIX.history=	/usr
BUILDLINK_FILES.history+=	lib/libhistory.*
.elif exists(/usr/include/readline.h)
BUILDLINK_PREFIX.readline=	/usr
BUILDLINK_FILES.readline=	include/readline.h
BUILDLINK_FILES.readline+=	lib/libedit.*
BUILDLINK_TRANSFORM.readline=	-e "s|/readline.h|/readline/readline.h|g"
BUILDLINK_TRANSFORM+=		l:readline:edit

BUILDLINK_PREFIX.history=	/usr
BUILDLINK_FILES.history=	include/history.h
BUILDLINK_FILES.history+=	lib/libedit.*
BUILDLINK_TRANSFORM.history=	-e "s|/history.h|/readline/history.h|g"
BUILDLINK_TRANSFORM+=		l:history:edit
.else # exists(/usr/include/readline/readline.h)
BUILDLINK_PREFIX.readline=	/usr
BUILDLINK_FILES.readline=	include/readline/*
BUILDLINK_FILES.readline+=	lib/libedit.*
BUILDLINK_TRANSFORM+=		l:readline:edit

BUILDLINK_PREFIX.history=	/usr
BUILDLINK_FILES.history+=	lib/libedit.*
BUILDLINK_TRANSFORM+=		l:history:edit
.endif

BUILDLINK_TARGETS+=	readline-buildlink
BUILDLINK_TARGETS+=	history-buildlink

readline-buildlink: _BUILDLINK_USE
history-buildlink: _BUILDLINK_USE

.endif	# READLINE_BUILDLINK2_MK
