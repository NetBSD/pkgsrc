# $NetBSD: buildlink3.mk,v 1.1 2023/01/31 19:12:45 pho Exp $

BUILDLINK_TREE+=	hs-hls-refactor-plugin

.if !defined(HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK)
HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-refactor-plugin+=	hs-hls-refactor-plugin>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-hls-refactor-plugin+=	hs-hls-refactor-plugin>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-hls-refactor-plugin?=	../../devel/hs-hls-refactor-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-text-rope/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-refactor-plugin
