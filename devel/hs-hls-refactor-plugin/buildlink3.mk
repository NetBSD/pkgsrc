# $NetBSD: buildlink3.mk,v 1.7 2023/11/08 13:18:47 wiz Exp $

BUILDLINK_TREE+=	hs-hls-refactor-plugin

.if !defined(HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK)
HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-refactor-plugin+=	hs-hls-refactor-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-refactor-plugin+=	hs-hls-refactor-plugin>=2.4.0.0nb2
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
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../textproc/hs-regex-applicative/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-text-rope/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_REFACTOR_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-refactor-plugin
