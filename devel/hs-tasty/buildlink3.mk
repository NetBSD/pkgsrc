# $NetBSD: buildlink3.mk,v 1.13 2023/11/02 06:36:58 pho Exp $

BUILDLINK_TREE+=	hs-tasty

.if !defined(HS_TASTY_BUILDLINK3_MK)
HS_TASTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty+=	hs-tasty>=1.5
BUILDLINK_ABI_DEPENDS.hs-tasty+=	hs-tasty>=1.5nb1
BUILDLINK_PKGSRCDIR.hs-tasty?=		../../devel/hs-tasty

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.endif	# HS_TASTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty
