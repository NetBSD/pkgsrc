# $NetBSD: buildlink3.mk,v 1.11 2023/10/31 14:02:15 pho Exp $

BUILDLINK_TREE+=	hs-hls-call-hierarchy-plugin

.if !defined(HS_HLS_CALL_HIERARCHY_PLUGIN_BUILDLINK3_MK)
HS_HLS_CALL_HIERARCHY_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-call-hierarchy-plugin+=	hs-hls-call-hierarchy-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-call-hierarchy-plugin+=	hs-hls-call-hierarchy-plugin>=2.4.0.0
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
