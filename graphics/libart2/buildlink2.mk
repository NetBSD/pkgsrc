# $NetBSD: buildlink2.mk,v 1.4 2002/10/16 10:14:38 rh Exp $

.if !defined(LIBART2_BUILDLINK2_MK)
LIBART2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libart2
BUILDLINK_DEPENDS.libart2?=	libart2>=2.3.10nb1
BUILDLINK_PKGSRCDIR.libart2?=	../../graphics/libart2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libart2=libart2
BUILDLINK_PREFIX.libart2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libart2=	bin/libart2-config
BUILDLINK_FILES.libart2+=	include/libart-2.0/libart_lgpl/*
BUILDLINK_FILES.libart2+=	lib/libart_lgpl_2.*

BUILDLINK_TARGETS+=	libart2-buildlink

libart2-buildlink: _BUILDLINK_USE

.endif	# LIBART2_BUILDLINK2_MK
