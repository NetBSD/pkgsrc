# $NetBSD: buildlink2.mk,v 1.10 2004/04/01 18:31:25 jmmv Exp $

.if !defined(LIBWNCK_BUILDLINK2_MK)
LIBWNCK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libwnck
BUILDLINK_DEPENDS.libwnck?=	libwnck>=2.6.0
BUILDLINK_PKGSRCDIR.libwnck?=	../../devel/libwnck

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwnck=libwnck
BUILDLINK_PREFIX.libwnck_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libwnck=	include/libwnck-1.0/libwnck/*
BUILDLINK_FILES.libwnck+=	lib/libwnck-1.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libwnck-buildlink

libwnck-buildlink: _BUILDLINK_USE

.endif	# LIBWNCK_BUILDLINK2_MK
