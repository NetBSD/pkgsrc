# $NetBSD: buildlink2.mk,v 1.4 2002/09/10 19:50:36 jlam Exp $

.if !defined(GLIB2_BUILDLINK2_MK)
GLIB2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glib2
BUILDLINK_DEPENDS.glib2?=	glib2>=2.0.6nb1
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

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"

PTHREAD_OPTS+=	native

.include "../../mk/pthread.buildlink.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CPPFLAGS+=	-I${BUILDLINK_PREFIX.ptl2}/PTL/include
.  include "../../devel/ptl2/buildlink.mk"
.endif

BUILDLINK_TARGETS+=	glib2-buildlink

glib2-buildlink: _BUILDLINK_USE

.endif	# GLIB2_BUILDLINK2_MK
