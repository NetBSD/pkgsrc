# $NetBSD: buildlink3.mk,v 1.1 2023/02/01 01:56:02 pho Exp $

BUILDLINK_TREE+=	hs-hls-code-range-plugin

.if !defined(HS_HLS_CODE_RANGE_PLUGIN_BUILDLINK3_MK)
HS_HLS_CODE_RANGE_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-code-range-plugin+=	hs-hls-code-range-plugin>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-hls-code-range-plugin+=	hs-hls-code-range-plugin>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-hls-code-range-plugin?=		../../devel/hs-hls-code-range-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HLS_CODE_RANGE_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-code-range-plugin
