# $NetBSD: buildlink3.mk,v 1.20 2025/03/05 03:39:24 pho Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.9.0
BUILDLINK_ABI_DEPENDS.hs-primitive+=	hs-primitive>=0.9.0.0nb4
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../devel/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
