# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/10/05 16:43:08 jschauma Exp $
#
# This Makefile fragment is included by packages that use vis5d+.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(VIS5D+_BUILDLINK2_MK)
VIS5D+_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			vis5d+
BUILDLINK_DEPENDS.vis5d+?=		vis5d+>=1.2.1
BUILDLINK_PKGSRCDIR.vis5d+?=		../../gis/vis5dx

EVAL_PREFIX+=	BUILDLINK_PREFIX.vis5d+=vis5d+
BUILDLINK_PREFIX.vis5d+_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.vis5d++=	include/vis5d+/api-config.h
BUILDLINK_FILES.vis5d++=	include/vis5d+/api.h
BUILDLINK_FILES.vis5d++=	include/vis5d+/binio.h
BUILDLINK_FILES.vis5d++=	include/vis5d+/v5d.h
BUILDLINK_FILES.vis5d++=	include/vis5d+/v5df.h
BUILDLINK_FILES.vis5d++=	lib/libv5d.*
BUILDLINK_FILES.vis5d++=	lib/libvis5d.*

.include "../../graphics/Mesa/buildlink2.mk"

BUILDLINK_TARGETS+=	vis5d+-buildlink

vis5d+-buildlink: _BUILDLINK_USE

.endif	# VIS5D+_BUILDLINK2_MK
