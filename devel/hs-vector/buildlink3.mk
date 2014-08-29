# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:08:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.10.11
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.10.11.0
BUILDLINK_PKGSRCDIR.hs-vector?=	../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
