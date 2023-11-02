# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:39 pho Exp $

BUILDLINK_TREE+=	hs-hls-ormolu-plugin

.if !defined(HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK)
HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-ormolu-plugin+=	hs-hls-ormolu-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-ormolu-plugin+=	hs-hls-ormolu-plugin>=2.4.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-ormolu-plugin?=	../../devel/hs-hls-ormolu-plugin

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/ormolu/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.endif	# HS_HLS_ORMOLU_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-ormolu-plugin
