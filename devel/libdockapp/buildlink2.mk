# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:30 jlam Exp $

.if !defined(LIBDOCKAPP_BUILDLINK2_MK)
LIBDOCKAPP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdockapp
BUILDLINK_DEPENDS.libdockapp?=		libdockapp>=0.4.0
BUILDLINK_PKGSRCDIR.libdockapp?=	../../devel/libdockapp

EVAL_PREFIX+=			BUILDLINK_PREFIX.libdockapp=libdockapp
BUILDLINK_PREFIX.libdockapp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdockapp=	include/dockapp.h
BUILDLINK_FILES.libdockapp+=	lib/libdockapp.*

.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	libdockapp-buildlink

libdockapp-buildlink: _BUILDLINK_USE

.endif	# LIBDOCKAPP_BUILDLINK2_MK
