# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:21 jlam Exp $

.if !defined(AALIB_X11_BUILDLINK2_MK)
AALIB_X11_BUILDLINK2_MK= # defined

BUILDLINK_PACKAGES+=		aalib-x11
BUILDLINK_DEPENDS.aalib-x11?=	aalib-x11>=1.4.0.4
BUILDLINK_PKGSRCDIR.aalib-x11?=	../../graphics/aalib-x11

EVAL_PREFIX+=	BUILDLINK_PREFIX.aalib-x11=aalib-x11
BUILDLINK_PREFIX.aalib-x11_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aalib-x11=	include/aalib.h
BUILDLINK_FILES.aalib-x11+=	lib/libaa.*

BUILDLINK_TARGETS+=	aalib-x11-buildlink

aalib-x11-buildlink: _BUILDLINK_USE

.endif # AALIB_X11_BUILDLINK2_MK
