# $NetBSD: buildlink3.mk,v 1.2 2012/10/24 05:49:25 asau Exp $

BUILDLINK_TREE+=	hwloc

.if !defined(HWLOC_BUILDLINK3_MK)
HWLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hwloc+=	hwloc>=1.4
BUILDLINK_PKGSRCDIR.hwloc?=	../../parallel/hwloc

.include "../../textproc/libxml2/buildlink3.mk" # optional
.endif	# HWLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwloc
