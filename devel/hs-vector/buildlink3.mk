# $NetBSD: buildlink3.mk,v 1.6 2015/05/09 11:22:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.10.12
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.10.12.2nb1
BUILDLINK_PKGSRCDIR.hs-vector?=	../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
