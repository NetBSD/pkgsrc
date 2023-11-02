# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:37:05 pho Exp $

BUILDLINK_TREE+=	ormolu

.if !defined(ORMOLU_BUILDLINK3_MK)
ORMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ormolu+=	ormolu>=0.7.3
BUILDLINK_ABI_DEPENDS.ormolu+=	ormolu>=0.7.3.0nb1
BUILDLINK_PKGSRCDIR.ormolu?=	../../devel/ormolu

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.endif	# ORMOLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ormolu
