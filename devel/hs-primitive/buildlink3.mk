# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:08:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.5.3
BUILDLINK_ABI_DEPENDS.hs-primitive+=	hs-primitive>=0.5.3.0
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../devel/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
