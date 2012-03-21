# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/21 13:31:35 asau Exp $

BUILDLINK_TREE+=	hwloc

.if !defined(HWLOC_BUILDLINK3_MK)
HWLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hwloc+=	hwloc>=1.4
BUILDLINK_PKGSRCDIR.hwloc?=	../../parallel/hwloc

.endif	# HWLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwloc
