# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:31:51 pho Exp $

BUILDLINK_TREE+=	hs-data-default-instances-base

.if !defined(HS_DATA_DEFAULT_INSTANCES_BASE_BUILDLINK3_MK)
HS_DATA_DEFAULT_INSTANCES_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-instances-base+=	hs-data-default-instances-base>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-data-default-instances-base+=	hs-data-default-instances-base>=0.1.0.1nb8
BUILDLINK_PKGSRCDIR.hs-data-default-instances-base?=	../../devel/hs-data-default-instances-base

.include "../../devel/hs-data-default-class/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_INSTANCES_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-instances-base
