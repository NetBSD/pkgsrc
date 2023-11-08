# $NetBSD: buildlink3.mk,v 1.13 2023/11/08 13:18:47 wiz Exp $

BUILDLINK_TREE+=	hs-hls-fourmolu-plugin

.if !defined(HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK)
HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-fourmolu-plugin+=	hs-hls-fourmolu-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-fourmolu-plugin+=	hs-hls-fourmolu-plugin>=2.4.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hls-fourmolu-plugin?=	../../devel/hs-hls-fourmolu-plugin

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.include "../../devel/fourmolu/buildlink3.mk"
.endif	# HS_HLS_FOURMOLU_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-fourmolu-plugin
