# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:40 pho Exp $

BUILDLINK_TREE+=	hs-hls-splice-plugin

.if !defined(HS_HLS_SPLICE_PLUGIN_BUILDLINK3_MK)
HS_HLS_SPLICE_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-splice-plugin+=	hs-hls-splice-plugin>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-hls-splice-plugin+=	hs-hls-splice-plugin>=1.0.3.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-splice-plugin?=	../../devel/hs-hls-splice-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-hls-refactor-plugin/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_SPLICE_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-splice-plugin
