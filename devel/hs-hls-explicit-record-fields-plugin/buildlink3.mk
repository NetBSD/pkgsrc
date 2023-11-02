# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:37 pho Exp $

BUILDLINK_TREE+=	hs-hls-explicit-record-fields-plugin

.if !defined(HS_HLS_EXPLICIT_RECORD_FIELDS_PLUGIN_BUILDLINK3_MK)
HS_HLS_EXPLICIT_RECORD_FIELDS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-explicit-record-fields-plugin+=	hs-hls-explicit-record-fields-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-explicit-record-fields-plugin+=	hs-hls-explicit-record-fields-plugin>=2.4.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-explicit-record-fields-plugin?=	../../devel/hs-hls-explicit-record-fields-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_EXPLICIT_RECORD_FIELDS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-explicit-record-fields-plugin
