# $NetBSD: buildlink2.mk,v 1.14 2004/04/01 18:13:31 jmmv Exp $

.if !defined(GLIB2_BUILDLINK2_MK)
GLIB2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glib2
BUILDLINK_DEPENDS.glib2?=	glib2>=2.4.0
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2

EVAL_PREFIX+=		BUILDLINK_PREFIX.glib2=glib2
BUILDLINK_PREFIX.glib2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glib2=	include/glib/glib-2.0/*/*
BUILDLINK_FILES.glib2+=	include/glib/glib-2.0/*
BUILDLINK_FILES.glib2+=	lib/glib-2.0/*/*
BUILDLINK_FILES.glib2+=	lib/libglib-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgmodule-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgobject-2.0.*
BUILDLINK_FILES.glib2+=	lib/libgthread-2.0.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	glib2-buildlink

glib2-buildlink: _BUILDLINK_USE

.endif	# GLIB2_BUILDLINK2_MK
