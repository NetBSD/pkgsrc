# $NetBSD: buildlink3.mk,v 1.3 2013/04/15 20:46:17 adam Exp $

BUILDLINK_TREE+=	hwloc

.if !defined(HWLOC_BUILDLINK3_MK)
HWLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hwloc+=	hwloc>=1.4
BUILDLINK_PKGSRCDIR.hwloc?=	../../parallel/hwloc

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# HWLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwloc
