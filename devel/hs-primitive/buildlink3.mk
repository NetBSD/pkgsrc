# $NetBSD: buildlink3.mk,v 1.14 2023/02/07 01:40:46 pho Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.7.3
BUILDLINK_ABI_DEPENDS.hs-primitive+=	hs-primitive>=0.7.4.0nb1
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../devel/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
