# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 14:59:02 pho Exp $

BUILDLINK_TREE+=	hs-hls-eval-plugin

.if !defined(HS_HLS_EVAL_PLUGIN_BUILDLINK3_MK)
HS_HLS_EVAL_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-eval-plugin+=	hs-hls-eval-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-eval-plugin+=	hs-hls-eval-plugin>=2.4.0.0
BUILDLINK_PKGSRCDIR.hs-hls-eval-plugin?=	../../devel/hs-hls-eval-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-pretty-simple/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_EVAL_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-eval-plugin
