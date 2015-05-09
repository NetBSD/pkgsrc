# $NetBSD: buildlink3.mk,v 1.5 2015/05/09 11:22:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-algorithms

.if !defined(HS_VECTOR_ALGORITHMS_BUILDLINK3_MK)
HS_VECTOR_ALGORITHMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.6.0
BUILDLINK_ABI_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.6.0.3nb3
BUILDLINK_PKGSRCDIR.hs-vector-algorithms?=	../../devel/hs-vector-algorithms

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../math/hs-mwc-random/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_ALGORITHMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-algorithms
