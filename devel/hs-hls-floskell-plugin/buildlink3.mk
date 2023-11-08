# $NetBSD: buildlink3.mk,v 1.13 2023/11/08 13:18:46 wiz Exp $

BUILDLINK_TREE+=	hs-hls-floskell-plugin

.if !defined(HS_HLS_FLOSKELL_PLUGIN_BUILDLINK3_MK)
HS_HLS_FLOSKELL_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-floskell-plugin+=	hs-hls-floskell-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-floskell-plugin+=	hs-hls-floskell-plugin>=2.4.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hls-floskell-plugin?=	../../devel/hs-hls-floskell-plugin

.include "../../devel/floskell/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.endif	# HS_HLS_FLOSKELL_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-floskell-plugin
