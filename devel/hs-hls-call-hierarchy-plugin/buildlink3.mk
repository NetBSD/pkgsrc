# $NetBSD: buildlink3.mk,v 1.6 2022/11/23 16:18:38 adam Exp $

BUILDLINK_TREE+=	hs-hls-call-hierarchy-plugin

.if !defined(HS_HLS_CALL_HIERARCHY_PLUGIN_BUILDLINK3_MK)
HS_HLS_CALL_HIERARCHY_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-call-hierarchy-plugin+=	hs-hls-call-hierarchy-plugin>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-hls-call-hierarchy-plugin+=	hs-hls-call-hierarchy-plugin>=1.0.2.0nb5
BUILDLINK_PKGSRCDIR.hs-hls-call-hierarchy-plugin?=	../../devel/hs-hls-call-hierarchy-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_CALL_HIERARCHY_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-call-hierarchy-plugin
