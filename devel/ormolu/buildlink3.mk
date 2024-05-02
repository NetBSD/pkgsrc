# $NetBSD: buildlink3.mk,v 1.9 2024/05/02 04:12:34 pho Exp $

BUILDLINK_TREE+=	ormolu

.if !defined(ORMOLU_BUILDLINK3_MK)
ORMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ormolu+=	ormolu>=0.7.4
BUILDLINK_ABI_DEPENDS.ormolu+=	ormolu>=0.7.4.0
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
