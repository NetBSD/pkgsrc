# $NetBSD: buildlink3.mk,v 1.9 2023/11/02 06:37:06 pho Exp $

BUILDLINK_TREE+=	retrie

.if !defined(RETRIE_BUILDLINK3_MK)
RETRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.retrie+=	retrie>=1.2.2
BUILDLINK_ABI_DEPENDS.retrie+=	retrie>=1.2.2nb1
BUILDLINK_PKGSRCDIR.retrie?=	../../devel/retrie

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-random-shuffle/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.endif	# RETRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-retrie
