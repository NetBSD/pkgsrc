# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:26 jlam Exp $

.if !defined(JASPER_BUILDLINK2_MK)
JASPER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jasper
BUILDLINK_DEPENDS.jasper?=	jasper-1.500.0
BUILDLINK_PKGSRCDIR.jasper?=	../../graphics/jasper

EVAL_PREFIX+=		BUILDLINK_PREFIX.jasper=jasper
BUILDLINK_PREFIX.jasper_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jasper=		include/jasper/*
BUILDLINK_FILES.jasper+=	lib/libjasper.*

BUILDLINK_TARGETS+=	jasper-buildlink

jasper-buildlink: _BUILDLINK_USE

.endif	# JASPER_BUILDLINK2_MK
