# $NetBSD: buildlink3.mk,v 1.24 2025/03/05 03:39:35 pho Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.13.2
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.13.2.0nb2
BUILDLINK_PKGSRCDIR.hs-vector?=		../../devel/hs-vector

# lib:vector
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector-stream/buildlink3.mk"

# lib:benchmarks-O2
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"

.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
