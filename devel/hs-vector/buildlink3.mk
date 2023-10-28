# $NetBSD: buildlink3.mk,v 1.19 2023/10/28 17:01:01 pho Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.13.1
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.13.1.0
BUILDLINK_PKGSRCDIR.hs-vector?=		../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector-stream/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
