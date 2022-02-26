# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:46 pho Exp $

BUILDLINK_TREE+=	floskell

.if !defined(FLOSKELL_BUILDLINK3_MK)
FLOSKELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.floskell+=	floskell>=0.10.6
BUILDLINK_ABI_DEPENDS.floskell+=	floskell>=0.10.6nb1
BUILDLINK_PKGSRCDIR.floskell?=		../../devel/floskell

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-monad-dijkstra/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.endif	# FLOSKELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-floskell
