# $NetBSD: buildlink3.mk,v 1.7 2015/12/13 14:08:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.11.0
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.11.0.0
BUILDLINK_PKGSRCDIR.hs-vector?=	../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
