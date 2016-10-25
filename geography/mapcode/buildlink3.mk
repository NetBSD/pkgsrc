# $NetBSD: buildlink3.mk,v 1.1 2016/10/25 08:22:27 fhajny Exp $

BUILDLINK_TREE+=	mapcode

.if !defined(MAPCODE_BUILDLINK3_MK)
MAPCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mapcode+=	mapcode>=2.3.0
BUILDLINK_ABI_DEPENDS.mapcode+=	mapcode>=2.3.0
BUILDLINK_PKGSRCDIR.mapcode?=	../../geography/mapcode
.endif	# MAPCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mapcode
