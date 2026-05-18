# $NetBSD: buildlink3.mk,v 1.3 2026/05/18 15:36:44 gdt Exp $

BUILDLINK_TREE+=	spatialindex

.if !defined(SPATIALINDEX_BUILDLINK3_MK)
SPATIALINDEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spatialindex+=	spatialindex>=1.8.5
BUILDLINK_ABI_DEPENDS.spatialindex+=	spatialindex>=2.0.0
BUILDLINK_PKGSRCDIR.spatialindex?=	../../geography/spatialindex
.endif	# SPATIALINDEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-spatialindex
