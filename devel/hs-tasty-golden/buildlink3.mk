# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:25 pho Exp $

BUILDLINK_TREE+=	hs-tasty-golden

.if !defined(HS_TASTY_GOLDEN_BUILDLINK3_MK)
HS_TASTY_GOLDEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-golden+=	hs-tasty-golden>=2.3.5
BUILDLINK_ABI_DEPENDS.hs-tasty-golden+=	hs-tasty-golden>=2.3.5nb1
BUILDLINK_PKGSRCDIR.hs-tasty-golden?=	../../devel/hs-tasty-golden

.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../sysutils/hs-typed-process/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.endif	# HS_TASTY_GOLDEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-golden
