# $NetBSD: buildlink3.mk,v 1.5 2020/01/01 03:44:06 pho Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.13.2
BUILDLINK_ABI_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.13.2
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../devel/hs-QuickCheck

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-splitmix/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
