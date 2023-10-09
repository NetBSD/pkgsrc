# $NetBSD: buildlink3.mk,v 1.5 2023/10/09 04:54:35 pho Exp $

BUILDLINK_TREE+=	hs-vector-instances

.if !defined(HS_VECTOR_INSTANCES_BUILDLINK3_MK)
HS_VECTOR_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-instances+=	hs-vector-instances>=3.4
BUILDLINK_ABI_DEPENDS.hs-vector-instances+=	hs-vector-instances>=3.4nb4
BUILDLINK_PKGSRCDIR.hs-vector-instances?=	../../devel/hs-vector-instances

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-keys/buildlink3.mk"
.include "../../devel/hs-pointed/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_VECTOR_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-instances
