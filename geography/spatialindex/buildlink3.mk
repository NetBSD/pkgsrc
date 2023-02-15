# $NetBSD: buildlink3.mk,v 1.2 2023/02/15 23:17:32 wiz Exp $

BUILDLINK_TREE+=	spatialindex

.if !defined(SPATIALINDEX_BUILDLINK3_MK)
SPATIALINDEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spatialindex+=	spatialindex>=1.8.5
BUILDLINK_ABI_DEPENDS.spatialindex+=	spatialindex>=1.9.3
BUILDLINK_PKGSRCDIR.spatialindex?=	../../geography/spatialindex
.endif	# SPATIALINDEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-spatialindex
