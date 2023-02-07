# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:43 pho Exp $

BUILDLINK_TREE+=	hs-microlens-ghc

.if !defined(HS_MICROLENS_GHC_BUILDLINK3_MK)
HS_MICROLENS_GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microlens-ghc+=	hs-microlens-ghc>=0.4.13
BUILDLINK_ABI_DEPENDS.hs-microlens-ghc+=	hs-microlens-ghc>=0.4.13.1nb2
BUILDLINK_PKGSRCDIR.hs-microlens-ghc?=		../../devel/hs-microlens-ghc

.include "../../devel/hs-microlens/buildlink3.mk"
.endif	# HS_MICROLENS_GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microlens-ghc
