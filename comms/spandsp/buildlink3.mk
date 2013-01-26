# $NetBSD: buildlink3.mk,v 1.4 2013/01/26 21:36:15 adam Exp $

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=0.0.6pre18
BUILDLINK_ABI_DEPENDS.spandsp+=	spandsp>=0.0.6pre18nb2
BUILDLINK_PKGSRCDIR.spandsp?=	../../comms/spandsp

.include "../../graphics/tiff/buildlink3.mk"
.endif	# SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
