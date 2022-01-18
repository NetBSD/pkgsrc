# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:13 pho Exp $

BUILDLINK_TREE+=	hs-tasty

.if !defined(HS_TASTY_BUILDLINK3_MK)
HS_TASTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty+=	hs-tasty>=1.4.1
BUILDLINK_ABI_DEPENDS.hs-tasty+=	hs-tasty>=1.4.1nb2
BUILDLINK_PKGSRCDIR.hs-tasty?=		../../devel/hs-tasty

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../textproc/hs-wcwidth/buildlink3.mk"
.endif	# HS_TASTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty
