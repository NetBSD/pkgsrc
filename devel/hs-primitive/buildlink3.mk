# $NetBSD: buildlink3.mk,v 1.4 2015/12/13 14:06:53 szptvlfn Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-primitive+=	hs-primitive>=0.6.1.0
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../devel/hs-primitive

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
