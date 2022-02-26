# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:57 pho Exp $

BUILDLINK_TREE+=	hs-hls-alternate-number-format-plugin

.if !defined(HS_HLS_ALTERNATE_NUMBER_FORMAT_PLUGIN_BUILDLINK3_MK)
HS_HLS_ALTERNATE_NUMBER_FORMAT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-alternate-number-format-plugin+=	hs-hls-alternate-number-format-plugin>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-hls-alternate-number-format-plugin+=	hs-hls-alternate-number-format-plugin>=1.0.1.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-alternate-number-format-plugin?=	../../devel/hs-hls-alternate-number-format-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_ALTERNATE_NUMBER_FORMAT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-alternate-number-format-plugin
