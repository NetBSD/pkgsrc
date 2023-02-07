# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:39 pho Exp $

BUILDLINK_TREE+=	hs-hls-hlint-plugin

.if !defined(HS_HLS_HLINT_PLUGIN_BUILDLINK3_MK)
HS_HLS_HLINT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-hlint-plugin+=	hs-hls-hlint-plugin>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-hls-hlint-plugin+=	hs-hls-hlint-plugin>=1.1.1.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-hlint-plugin?=	../../devel/hs-hls-hlint-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hlint/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-apply-refact/buildlink3.mk"
.endif	# HS_HLS_HLINT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-hlint-plugin
