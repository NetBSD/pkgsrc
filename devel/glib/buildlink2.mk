# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:03 jlam Exp $
#
# This Makefile fragment is included by packages that use glib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.glib to the dependency pattern
#     for the version of glib desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(GLIB_BUILDLINK2_MK)
GLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.glib?=	glib>=1.2.8
DEPENDS+=	${BUILDLINK_DEPENDS.glib}:../../devel/glib

BUILDLINK_PREFIX.glib=	${LOCALBASE}
BUILDLINK_FILES.glib=	include/glib/glib-1.2/*
BUILDLINK_FILES.glib+=	include/glib/*
BUILDLINK_FILES.glib+=	lib/glib/*/*
BUILDLINK_FILES.glib+=	lib/libglib.*
BUILDLINK_FILES.glib+=	lib/libgmodule.*
BUILDLINK_FILES.glib+=	lib/libgthread.*

USE_PTHREAD=		native pth

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
