# $NetBSD: buildlink3.mk,v 1.6 2023/10/31 03:20:47 pho Exp $

BUILDLINK_TREE+=	hs-vector-instances

.if !defined(HS_VECTOR_INSTANCES_BUILDLINK3_MK)
HS_VECTOR_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-instances+=	hs-vector-instances>=3.4.2
BUILDLINK_ABI_DEPENDS.hs-vector-instances+=	hs-vector-instances>=3.4.2
BUILDLINK_PKGSRCDIR.hs-vector-instances?=	../../devel/hs-vector-instances

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-keys/buildlink3.mk"
.include "../../devel/hs-pointed/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_VECTOR_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-instances
