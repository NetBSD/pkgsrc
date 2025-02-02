# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:20 pho Exp $

BUILDLINK_TREE+=	hs-resource-pool

.if !defined(HS_RESOURCE_POOL_BUILDLINK3_MK)
HS_RESOURCE_POOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resource-pool+=	hs-resource-pool>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-resource-pool+=	hs-resource-pool>=0.4.0.0nb3
BUILDLINK_PKGSRCDIR.hs-resource-pool?=		../../devel/hs-resource-pool

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_RESOURCE_POOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resource-pool
