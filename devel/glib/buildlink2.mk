# $NetBSD: buildlink2.mk,v 1.6 2003/05/02 13:18:53 wiz Exp $

.if !defined(GLIB_BUILDLINK2_MK)
GLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glib
BUILDLINK_DEPENDS.glib?=	glib>=1.2.10nb5
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

glib-buildlink: _BUILDLINK_USE

.endif	# GLIB_BUILDLINK2_MK
