# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:14 jlam Exp $

.if !defined(LCMS_BUILDLINK2_MK)
LCMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lcms
BUILDLINK_DEPENDS.lcms?=	lcms>=1.06
BUILDLINK_PKGSRCDIR.lcms?=	../../graphics/lcms

EVAL_PREFIX+=	BUILDLINK_PREFIX.lcms=lcms
BUILDLINK_PREFIX.lcms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lcms=	include/lcms/*
BUILDLINK_FILES.lcms+=	lib/liblcms.*

BUILDLINK_TARGETS+=	lcms-buildlink

lcms-buildlink: _BUILDLINK_USE

.endif	# LCMS_BUILDLINK2_MK
