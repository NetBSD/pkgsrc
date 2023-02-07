# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:40:40 pho Exp $

BUILDLINK_TREE+=	hs-hls-refine-imports-plugin

.if !defined(HS_HLS_REFINE_IMPORTS_PLUGIN_BUILDLINK3_MK)
HS_HLS_REFINE_IMPORTS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-refine-imports-plugin+=	hs-hls-refine-imports-plugin>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-hls-refine-imports-plugin+=	hs-hls-refine-imports-plugin>=1.0.4.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-refine-imports-plugin?=	../../devel/hs-hls-refine-imports-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_REFINE_IMPORTS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-refine-imports-plugin
