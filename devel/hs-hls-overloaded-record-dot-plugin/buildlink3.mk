# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 15:16:34 pho Exp $

BUILDLINK_TREE+=	hs-hls-overloaded-record-dot-plugin

.if !defined(HS_HLS_OVERLOADED_RECORD_DOT_PLUGIN_BUILDLINK3_MK)
HS_HLS_OVERLOADED_RECORD_DOT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-overloaded-record-dot-plugin+=	hs-hls-overloaded-record-dot-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-overloaded-record-dot-plugin+=	hs-hls-overloaded-record-dot-plugin>=2.4.0.0
BUILDLINK_PKGSRCDIR.hs-hls-overloaded-record-dot-plugin?=	../../devel/hs-hls-overloaded-record-dot-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_OVERLOADED_RECORD_DOT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-overloaded-record-dot-plugin
