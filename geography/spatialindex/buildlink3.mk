# $NetBSD: buildlink3.mk,v 1.1 2015/11/27 17:51:58 adam Exp $

BUILDLINK_TREE+=	spatialindex

.if !defined(SPATIALINDEX_BUILDLINK3_MK)
SPATIALINDEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spatialindex+=	spatialindex>=1.8.5
BUILDLINK_PKGSRCDIR.spatialindex?=	../../geography/spatialindex
.endif	# SPATIALINDEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-spatialindex
