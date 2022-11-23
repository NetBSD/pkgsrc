# $NetBSD: buildlink3.mk,v 1.6 2022/11/23 16:18:38 adam Exp $

BUILDLINK_TREE+=	hs-hls-fourmolu-plugin

.if !defined(HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK)
HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-fourmolu-plugin+=	hs-hls-fourmolu-plugin>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-hls-fourmolu-plugin+=	hs-hls-fourmolu-plugin>=1.0.2.0nb5
BUILDLINK_PKGSRCDIR.hs-hls-fourmolu-plugin?=	../../devel/hs-hls-fourmolu-plugin

.include "../../devel/fourmolu/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.endif	# HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-fourmolu-plugin
