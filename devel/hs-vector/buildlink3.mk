# $NetBSD: buildlink3.mk,v 1.12 2022/01/18 02:48:15 pho Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.12.0
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.12.0.3nb2
BUILDLINK_PKGSRCDIR.hs-vector?=		../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
