# $NetBSD: buildlink3.mk,v 1.1 2023/01/31 10:04:25 pho Exp $

BUILDLINK_TREE+=	hs-hls-cabal-plugin

.if !defined(HS_HLS_CABAL_PLUGIN_BUILDLINK3_MK)
HS_HLS_CABAL_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-cabal-plugin+=	hs-hls-cabal-plugin>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-hls-cabal-plugin+=	hs-hls-cabal-plugin>=0.1.0.0
BUILDLINK_PKGSRCDIR.hs-hls-cabal-plugin?=	../../devel/hs-hls-cabal-plugin

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_CABAL_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-cabal-plugin
