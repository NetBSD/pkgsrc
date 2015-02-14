# $NetBSD: buildlink3.mk,v 1.2 2015/02/14 04:57:28 pho Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.7.6
BUILDLINK_ABI_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.7.6nb1
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../devel/hs-QuickCheck

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tf-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
