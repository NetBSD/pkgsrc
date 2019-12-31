# $NetBSD: buildlink3.mk,v 1.3 2019/12/31 08:12:48 pho Exp $

BUILDLINK_TREE+=	hs-ghc-paths

.if !defined(HS_GHC_PATHS_BUILDLINK3_MK)
HS_GHC_PATHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-paths+=	hs-ghc-paths>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-ghc-paths+=	hs-ghc-paths>=0.1.0.12
BUILDLINK_PKGSRCDIR.hs-ghc-paths?=	../../devel/hs-ghc-paths
.endif	# HS_GHC_PATHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-paths
