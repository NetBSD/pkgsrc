# $NetBSD: buildlink3.mk,v 1.13 2023/02/07 01:40:37 pho Exp $

BUILDLINK_TREE+=	hs-haskell-src-exts

.if !defined(HS_HASKELL_SRC_EXTS_BUILDLINK3_MK)
HS_HASKELL_SRC_EXTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.23.1
BUILDLINK_ABI_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.23.1nb5
BUILDLINK_PKGSRCDIR.hs-haskell-src-exts?=	../../devel/hs-haskell-src-exts
.endif	# HS_HASKELL_SRC_EXTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskell-src-exts
