# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:39:58 pho Exp $

BUILDLINK_TREE+=	hs-fuzzy

.if !defined(HS_FUZZY_BUILDLINK3_MK)
HS_FUZZY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fuzzy+=	hs-fuzzy>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-fuzzy+=	hs-fuzzy>=0.1.1.0nb3
BUILDLINK_PKGSRCDIR.hs-fuzzy?=		../../textproc/hs-fuzzy

.include "../../math/hs-monoid-subclasses/buildlink3.mk"
.endif	# HS_FUZZY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fuzzy
