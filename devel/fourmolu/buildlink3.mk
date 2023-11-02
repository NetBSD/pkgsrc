# $NetBSD: buildlink3.mk,v 1.9 2023/11/02 06:36:15 pho Exp $

BUILDLINK_TREE+=	fourmolu

.if !defined(FOURMOLU_BUILDLINK3_MK)
FOURMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fourmolu+=	fourmolu>=0.14.1
BUILDLINK_ABI_DEPENDS.fourmolu+=	fourmolu>=0.14.1.0nb1
BUILDLINK_PKGSRCDIR.fourmolu?=		../../devel/fourmolu

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# FOURMOLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-fourmolu
