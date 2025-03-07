# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:52:31 pho Exp $

BUILDLINK_TREE+=	hs-haskell-src-meta

.if !defined(HS_HASKELL_SRC_META_BUILDLINK3_MK)
HS_HASKELL_SRC_META_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskell-src-meta+=	hs-haskell-src-meta>=0.8.15
BUILDLINK_ABI_DEPENDS.hs-haskell-src-meta+=	hs-haskell-src-meta>=0.8.15
BUILDLINK_PKGSRCDIR.hs-haskell-src-meta?=	../../devel/hs-haskell-src-meta

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-th-orphans/buildlink3.mk"
.endif	# HS_HASKELL_SRC_META_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskell-src-meta
