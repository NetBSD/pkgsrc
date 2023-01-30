# $NetBSD: buildlink3.mk,v 1.5 2023/01/30 04:01:17 pho Exp $

BUILDLINK_TREE+=	hs-hls-graph

.if !defined(HS_HLS_GRAPH_BUILDLINK3_MK)
HS_HLS_GRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-graph+=	hs-hls-graph>=1.9.0
BUILDLINK_ABI_DEPENDS.hs-hls-graph+=	hs-hls-graph>=1.9.0.0
BUILDLINK_PKGSRCDIR.hs-hls-graph?=	../../devel/hs-hls-graph

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-focus/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-js-dgtable/buildlink3.mk"
.include "../../www/hs-js-flot/buildlink3.mk"
.include "../../www/hs-js-jquery/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-stm-containers/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_GRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-graph
