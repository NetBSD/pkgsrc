# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:42 pho Exp $

BUILDLINK_TREE+=	hs-fuzzy

.if !defined(HS_FUZZY_BUILDLINK3_MK)
HS_FUZZY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fuzzy+=	hs-fuzzy>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-fuzzy+=	hs-fuzzy>=0.1.1.0nb1
BUILDLINK_PKGSRCDIR.hs-fuzzy?=		../../textproc/hs-fuzzy

.include "../../math/hs-monoid-subclasses/buildlink3.mk"
.endif	# HS_FUZZY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fuzzy
