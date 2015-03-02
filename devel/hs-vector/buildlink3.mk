# $NetBSD: buildlink3.mk,v 1.5 2015/03/02 23:44:43 pho Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.10.12
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.10.12.2
BUILDLINK_PKGSRCDIR.hs-vector?=	../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
