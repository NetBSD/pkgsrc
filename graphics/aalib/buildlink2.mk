# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:21 jlam Exp $

.if !defined(AALIB_BUILDLINK2_MK)
aalib_BUILDLINK2_MK= # defined

BUILDLINK_PACKAGES+=		aalib
BUILDLINK_DEPENDS.aalib?=	aalib>=1.4.0.4
BUILDLINK_PKGSRCDIR.aalib?=	../../graphics/aalib

EVAL_PREFIX+= BUILDLINK_PREFIX.aalib=aalib
BUILDLINK_PREFIX.aalib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aalib=	include/aalib.h
BUILDLINK_FILES.aalib+=	lib/libaa.*

BUILDLINK_TARGETS+=	aalib-buildlink

aalib-buildlink: _BUILDLINK_USE

.endif # aalib_BUILDLINK2_MK
