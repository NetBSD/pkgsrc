# $NetBSD: buildlink3.mk,v 1.5 2023/01/27 14:35:00 pho Exp $

BUILDLINK_TREE+=	fourmolu

.if !defined(FOURMOLU_BUILDLINK3_MK)
FOURMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fourmolu+=	fourmolu>=0.10.1
BUILDLINK_ABI_DEPENDS.fourmolu+=	fourmolu>=0.10.1.0
BUILDLINK_PKGSRCDIR.fourmolu?=		../../devel/fourmolu

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.endif	# FOURMOLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-fourmolu
