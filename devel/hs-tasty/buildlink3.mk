# $NetBSD: buildlink3.mk,v 1.14 2024/05/09 01:32:14 pho Exp $

BUILDLINK_TREE+=	hs-tasty

.if !defined(HS_TASTY_BUILDLINK3_MK)
HS_TASTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty+=	hs-tasty>=1.5
BUILDLINK_ABI_DEPENDS.hs-tasty+=	hs-tasty>=1.5nb2
BUILDLINK_PKGSRCDIR.hs-tasty?=		../../devel/hs-tasty

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.endif	# HS_TASTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty
