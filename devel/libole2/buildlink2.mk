# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:31 jlam Exp $

.if !defined(LIBOLE2_BUILDLINK2_MK)
LIBOLE2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libole2
BUILDLINK_DEPENDS.libole2?=	libole2>=0.2.4
BUILDLINK_PKGSRCDIR.libole2?=	../../devel/libole2

EVAL_PREFIX+=		BUILDLINK_PREFIX.libole2=libole2
BUILDLINK_PREFIX.libole2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libole2+=	include/libole2/*
BUILDLINK_FILES.libole2+=	lib/libgnomeole2.*

.include "../../devel/glib/buildlink2.mk"

BUILDLINK_TARGETS+=	libole2-buildlink

libole2-buildlink: _BUILDLINK_USE

.endif	# LIBOLE2_BUILDLINK2_MK
