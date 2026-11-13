# $NetBSD: buildlink3.mk,v 1.22 2026/11/13 14:39:12 pho Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.9.0
BUILDLINK_ABI_DEPENDS.hs-primitive+=	hs-primitive>=0.9.0.0nb6
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../devel/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
