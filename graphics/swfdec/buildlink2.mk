# $NetBSD: buildlink2.mk,v 1.5 2003/12/13 00:45:24 wiz Exp $
#
# This Makefile fragment is included by packages that use swfdec.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(SWFDEC_BUILDLINK2_MK)
SWFDEC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			swfdec
BUILDLINK_DEPENDS.swfdec?=		swfdec>=0.2.1nb5
BUILDLINK_PKGSRCDIR.swfdec?=		../../graphics/swfdec

EVAL_PREFIX+=	BUILDLINK_PREFIX.swfdec=swfdec
BUILDLINK_PREFIX.swfdec_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.swfdec+=	include/swfdec/*.h
BUILDLINK_FILES.swfdec+=	lib/gtk-2.0/2.2.0/loaders/swf_loader.*
BUILDLINK_FILES.swfdec+=	lib/libswfdec.*
BUILDLINK_FILES.swfdec+=	lib/pkgconfig/swfdec.pc

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	swfdec-buildlink

swfdec-buildlink: _BUILDLINK_USE

.endif	# SWFDEC_BUILDLINK2_MK
