# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:13 wiz Exp $

BUILDLINK_TREE+=	fourmolu

.if !defined(FOURMOLU_BUILDLINK3_MK)
FOURMOLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fourmolu+=	fourmolu>=0.5.0
BUILDLINK_ABI_DEPENDS.fourmolu+=	fourmolu>=0.5.0.1nb3
BUILDLINK_PKGSRCDIR.fourmolu?=		../../devel/fourmolu

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../textproc/hs-HsYAML-aeson/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.endif	# FOURMOLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-fourmolu
