# $NetBSD: buildlink2.mk,v 1.3 2002/10/31 08:00:27 jlam Exp $

.if !defined(LCMS_BUILDLINK2_MK)
LCMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lcms
BUILDLINK_DEPENDS.lcms?=	lcms>=1.06
BUILDLINK_PKGSRCDIR.lcms?=	../../graphics/lcms

EVAL_PREFIX+=	BUILDLINK_PREFIX.lcms=lcms
BUILDLINK_PREFIX.lcms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lcms=	include/lcms/*
BUILDLINK_FILES.lcms+=	lib/liblcms.*

BUILDLINK_CPPFLAGS.lcms=	-I${BUILDLINK_PREFIX.lcms}/include/lcms

BUILDLINK_TARGETS+=	lcms-buildlink

lcms-buildlink: _BUILDLINK_USE

.endif	# LCMS_BUILDLINK2_MK
