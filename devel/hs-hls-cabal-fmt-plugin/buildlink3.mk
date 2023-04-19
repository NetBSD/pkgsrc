# $NetBSD: buildlink3.mk,v 1.3 2023/04/19 08:08:11 adam Exp $

BUILDLINK_TREE+=	hs-hls-cabal-fmt-plugin

.if !defined(HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK)
HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-cabal-fmt-plugin+=	hs-hls-cabal-fmt-plugin>=0.1.0
BUILDLINK_API_DEPENDS.hs-hls-cabal-fmt-plugin+=	hs-hls-cabal-fmt-plugin>=0.1.0.0
BUILDLINK_ABI_DEPENDS.hs-hls-cabal-fmt-plugin?=	hs-hls-cabal-fmt-plugin>=0.1.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hls-cabal-fmt-plugin?=	../../devel/hs-hls-cabal-fmt-plugin

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.endif	# HS_HLS_CABAL_FMT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-cabal-fmt-plugin
