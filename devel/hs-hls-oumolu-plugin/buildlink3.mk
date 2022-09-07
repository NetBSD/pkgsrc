# $NetBSD: buildlink3.mk,v 1.5 2022/09/07 06:50:47 pho Exp $

BUILDLINK_TREE+=	hs-hls-ormolu-plugin

.if !defined(HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK)
HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-ormolu-plugin+=	hs-hls-ormolu-plugin>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-hls-ormolu-plugin+=	hs-hls-ormolu-plugin>=1.0.2.0nb4
BUILDLINK_PKGSRCDIR.hs-hls-ormolu-plugin?=	../../devel/hs-hls-oumolu-plugin

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/ormolu/buildlink3.mk"
.endif	# HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-ormolu-plugin
