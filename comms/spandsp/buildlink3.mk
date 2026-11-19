# $NetBSD: buildlink3.mk,v 1.9 2026/11/19 12:39:01 adam Exp $

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=3.1.1
BUILDLINK_ABI_DEPENDS.spandsp+=	spandsp>=3.1.1
BUILDLINK_PKGSRCDIR.spandsp?=	../../comms/spandsp

.include "../../graphics/tiff/buildlink3.mk"
.endif	# SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
