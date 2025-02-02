# $NetBSD: buildlink3.mk,v 1.20 2025/02/02 13:05:30 pho Exp $

BUILDLINK_TREE+=	hs-vector-algorithms

.if !defined(HS_VECTOR_ALGORITHMS_BUILDLINK3_MK)
HS_VECTOR_ALGORITHMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.9.0
BUILDLINK_ABI_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.9.0.3nb1
BUILDLINK_PKGSRCDIR.hs-vector-algorithms?=	../../devel/hs-vector-algorithms

.include "../../devel/hs-bitvec/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_ALGORITHMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-algorithms
