# $NetBSD: buildlink3.mk,v 1.13 2022/08/20 08:08:19 wiz Exp $

BUILDLINK_TREE+=	hs-vector-algorithms

.if !defined(HS_VECTOR_ALGORITHMS_BUILDLINK3_MK)
HS_VECTOR_ALGORITHMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.8.0.4nb5
BUILDLINK_PKGSRCDIR.hs-vector-algorithms?=	../../devel/hs-vector-algorithms

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_ALGORITHMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-algorithms
