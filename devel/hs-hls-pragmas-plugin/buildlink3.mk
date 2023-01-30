# $NetBSD: buildlink3.mk,v 1.7 2023/01/30 09:29:12 pho Exp $

BUILDLINK_TREE+=	hs-hls-pragmas-plugin

.if !defined(HS_HLS_PRAGMAS_PLUGIN_BUILDLINK3_MK)
HS_HLS_PRAGMAS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-pragmas-plugin+=	hs-hls-pragmas-plugin>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-hls-pragmas-plugin+=	hs-hls-pragmas-plugin>=1.0.4.0
BUILDLINK_PKGSRCDIR.hs-hls-pragmas-plugin?=	../../devel/hs-hls-pragmas-plugin

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../textproc/hs-fuzzy/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_PRAGMAS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-pragmas-plugin
