# $NetBSD: buildlink3.mk,v 1.6 2022/11/23 16:18:38 adam Exp $

BUILDLINK_TREE+=	hs-hls-explicit-imports-plugin

.if !defined(HS_HLS_EXPLICIT_IMPORTS_PLUGIN_BUILDLINK3_MK)
HS_HLS_EXPLICIT_IMPORTS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-explicit-imports-plugin+=	hs-hls-explicit-imports-plugin>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-hls-explicit-imports-plugin+=	hs-hls-explicit-imports-plugin>=1.0.2.0nb5
BUILDLINK_PKGSRCDIR.hs-hls-explicit-imports-plugin?=	../../devel/hs-hls-explicit-imports-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_EXPLICIT_IMPORTS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-explicit-imports-plugin
