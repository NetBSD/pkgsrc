# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:40 pho Exp $

BUILDLINK_TREE+=	hs-hls-retrie-plugin

.if !defined(HS_HLS_RETRIE_PLUGIN_BUILDLINK3_MK)
HS_HLS_RETRIE_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-retrie-plugin+=	hs-hls-retrie-plugin>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-hls-retrie-plugin+=	hs-hls-retrie-plugin>=1.0.3.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-retrie-plugin?=	../../devel/hs-hls-retrie-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_RETRIE_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-retrie-plugin
