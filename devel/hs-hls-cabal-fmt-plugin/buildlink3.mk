# $NetBSD: buildlink3.mk,v 1.5 2023/10/31 14:18:30 pho Exp $

BUILDLINK_TREE+=	hs-hls-cabal-fmt-plugin

.if !defined(HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK)
HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-cabal-fmt-plugin+=	hs-hls-cabal-fmt-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-cabal-fmt-plugin?=	hs-hls-cabal-fmt-plugin>=2.4.0.0
BUILDLINK_PKGSRCDIR.hs-hls-cabal-fmt-plugin?=	../../devel/hs-hls-cabal-fmt-plugin

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.endif	# HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-cabal-fmt-plugin
