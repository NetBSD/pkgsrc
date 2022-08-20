# $NetBSD: buildlink3.mk,v 1.16 2022/08/20 08:08:19 wiz Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-vector+=	hs-vector>=0.13.0.0
BUILDLINK_PKGSRCDIR.hs-vector?=		../../devel/hs-vector

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector-stream/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
