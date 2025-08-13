# $NetBSD: buildlink3.mk,v 1.7 2025/08/13 11:07:01 pho Exp $

BUILDLINK_TREE+=	hs-tasty-quickcheck

.if !defined(HS_TASTY_QUICKCHECK_BUILDLINK3_MK)
HS_TASTY_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-quickcheck+=	hs-tasty-quickcheck>=0.11.1
BUILDLINK_ABI_DEPENDS.hs-tasty-quickcheck+=	hs-tasty-quickcheck>=0.11.1nb3
BUILDLINK_PKGSRCDIR.hs-tasty-quickcheck?=	../../devel/hs-tasty-quickcheck

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.endif	# HS_TASTY_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-quickcheck
