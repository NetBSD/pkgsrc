# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:35 pho Exp $

BUILDLINK_TREE+=	hs-natural-arithmetic

.if !defined(HS_NATURAL_ARITHMETIC_BUILDLINK3_MK)
HS_NATURAL_ARITHMETIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-natural-arithmetic+=	hs-natural-arithmetic>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-natural-arithmetic+=	hs-natural-arithmetic>=0.2.1.0nb2
BUILDLINK_PKGSRCDIR.hs-natural-arithmetic?=	../../math/hs-natural-arithmetic

.include "../../devel/hs-unlifted/buildlink3.mk"
.endif	# HS_NATURAL_ARITHMETIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-natural-arithmetic
