# $NetBSD: buildlink3.mk,v 1.1 2021/05/03 06:25:11 thor Exp $

BUILDLINK_TREE+=	pcl

.if !defined(PCL_BUILDLINK3_MK)
PCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcl+=	pcl>=1.10.0
BUILDLINK_ABI_DEPENDS.pcl+=	pcl>=1.10.0
BUILDLINK_PKGSRCDIR.pcl?=	../../wip/pcl

.include "../../graphics/pcl/depends.mk"

.endif # PCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcl
