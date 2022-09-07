# $NetBSD: buildlink3.mk,v 1.3 2022/09/07 06:50:49 pho Exp $

BUILDLINK_TREE+=	ormolu

.if !defined(ORMOLU_BUILDLINK3_MK)
ORMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ormolu+=	ormolu>=0.4.0
BUILDLINK_ABI_DEPENDS.ormolu+=	ormolu>=0.4.0.0nb3
BUILDLINK_PKGSRCDIR.ormolu?=	../../devel/ormolu

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.endif	# ORMOLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ormolu
