# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 17:55:54 pho Exp $

BUILDLINK_TREE+=	hs-tasty-rerun

.if !defined(HS_TASTY_RERUN_BUILDLINK3_MK)
HS_TASTY_RERUN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-rerun+=	hs-tasty-rerun>=1.1.19
BUILDLINK_ABI_DEPENDS.hs-tasty-rerun+=	hs-tasty-rerun>=1.1.19
BUILDLINK_PKGSRCDIR.hs-tasty-rerun?=	../../devel/hs-tasty-rerun

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.endif	# HS_TASTY_RERUN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-rerun
