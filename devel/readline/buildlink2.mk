# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:06 jlam Exp $
#
# This Makefile fragment is included by packages that use readline().
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_GNU_READLINE to force use of GNU readline.
# (2) Optionally define BUILDLINK_DEPENDS.readline to the dependency pattern
#     for the version of GNU readline desired.
#
# NOTE:	You may need to do some more work to get libedit recognized over
#	libreadline, especially by GNU configure scripts.

.if !defined(READLINE_BUILDLINK2_MK)
READLINE_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.readline?=	readline>=2.2

.if defined(USE_GNU_READLINE)
_NEED_GNU_READLINE=	YES
.elif exists(/usr/include/readline.h) || \
      exists(/usr/include/readline/readline.h)
_NEED_GNU_READLINE=	NO
.else
_NEED_GNU_READLINE=	YES
.endif

.if ${_NEED_GNU_READLINE} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.readline}:../../devel/readline
BUILDLINK_PREFIX.readline=	${LOCALBASE}
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
