# $NetBSD: buildlink3.mk,v 1.10 2020/01/11 08:50:16 pho Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.12.0
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.12.0.3
BUILDLINK_PKGSRCDIR.hs-vector?=		../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
