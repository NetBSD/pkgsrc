# $NetBSD: buildlink3.mk,v 1.9 2023/11/02 06:36:25 pho Exp $

BUILDLINK_TREE+=	hs-data-default-instances-containers

.if !defined(HS_DATA_DEFAULT_INSTANCES_CONTAINERS_BUILDLINK3_MK)
HS_DATA_DEFAULT_INSTANCES_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-instances-containers+=	hs-data-default-instances-containers>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-data-default-instances-containers+=	hs-data-default-instances-containers>=0.0.1nb7
BUILDLINK_PKGSRCDIR.hs-data-default-instances-containers?=	../../devel/hs-data-default-instances-containers

.include "../../devel/hs-data-default-class/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_INSTANCES_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-instances-containers
