# $NetBSD: buildlink3.mk,v 1.13 2023/11/08 13:18:47 wiz Exp $

BUILDLINK_TREE+=	hs-hls-qualify-imported-names-plugin

.if !defined(HS_HLS_QUALIFY_IMPORTED_NAMES_PLUGIN_BUILDLINK3_MK)
HS_HLS_QUALIFY_IMPORTED_NAMES_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-qualify-imported-names-plugin+=	hs-hls-qualify-imported-names-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-qualify-imported-names-plugin+=	hs-hls-qualify-imported-names-plugin>=2.4.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hls-qualify-imported-names-plugin?=	../../devel/hs-hls-qualify-imported-names-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_QUALIFY_IMPORTED_NAMES_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-qualify-imported-names-plugin
