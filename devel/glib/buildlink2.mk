# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 19:44:48 jlam Exp $

.if !defined(GLIB_BUILDLINK2_MK)
GLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glib
BUILDLINK_DEPENDS.glib?=	glib>=1.2.8
BUILDLINK_PKGSRCDIR.glib?=	../../devel/glib

EVAL_PREFIX+=	BUILDLINK_PREFIX.glib=glib
BUILDLINK_PREFIX.glib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glib=	include/glib/glib-1.2/*
BUILDLINK_FILES.glib+=	include/glib/*
BUILDLINK_FILES.glib+=	lib/glib/*/*
BUILDLINK_FILES.glib+=	lib/libglib.*
BUILDLINK_FILES.glib+=	lib/libgmodule.*
BUILDLINK_FILES.glib+=	lib/libgthread.*

PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	glib-buildlink
BUILDLINK_TARGETS+=	glib-fix-glib-h

glib-buildlink: _BUILDLINK_USE

glib-fix-glib-h:
.if exists(/usr/include/sys/null.h)
	@cd ${BUILDLINK_DIR}/include/glib/glib-1.2;			\
	if ${GREP} "^\#define.NULL" glib.h > /dev/null; then		\
		${ECHO} WARNING\!;					\
		${ECHO} The installed glib package is broken, please rebuild it from source.;\
		${ECHO} For more information, see PR 14150.;		\
		${SED}  -e "s|^#define.NULL.*|#include <sys/null.h>|"	\
			glib.h > glib.h.fixed;				\
		${RM} glib.h;						\
		${MV} glib.h.fixed glib.h;				\
	fi
.endif

.endif	# GLIB_BUILDLINK2_MK
