# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:26 jlam Exp $

.if !defined(LIBART2_BUILDLINK2_MK)
LIBART2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libart2
BUILDLINK_DEPENDS.libart2?=	libart2>=2.3.8
BUILDLINK_PKGSRCDIR.libart2?=	../../graphics/libart2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libart2=libart2
BUILDLINK_PREFIX.libart2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libart2=	bin/libart22-config
BUILDLINK_FILES.libart2+=	include/libart2-2.0/libart2_lgpl/*
BUILDLINK_FILES.libart2+=	lib/libart2_lgpl_2.*

BUILDLINK_TARGETS+=	libart2-buildlink

libart2-buildlink: _BUILDLINK_USE

.endif	# LIBART2_BUILDLINK2_MK
