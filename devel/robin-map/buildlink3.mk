# $NetBSD: buildlink3.mk,v 1.1 2021/01/18 12:01:10 nia Exp $

BUILDLINK_TREE+=	robin-map

.if !defined(ROBIN_MAP_BUILDLINK3_MK)
ROBIN_MAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.robin-map+=	robin-map>=0.6.3
BUILDLINK_PKGSRCDIR.robin-map?=		../../devel/robin-map
BUILDLINK_DEPMETHOD.robin-map?=		build
.endif	# ROBIN_MAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-robin-map
