# $NetBSD: buildlink3.mk,v 1.5 2022/09/07 06:50:47 pho Exp $

BUILDLINK_TREE+=	hs-hls-selection-range-plugin

.if !defined(HS_HLS_SELECTION_RANGE_PLUGIN_BUILDLINK3_MK)
HS_HLS_SELECTION_RANGE_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-selection-range-plugin+=	hs-hls-selection-range-plugin>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-hls-selection-range-plugin+=	hs-hls-selection-range-plugin>=1.0.0.0nb4
BUILDLINK_PKGSRCDIR.hs-hls-selection-range-plugin?=	../../devel/hs-hls-selection-range-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.endif	# HS_HLS_SELECTION_RANGE_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-selection-range-plugin
