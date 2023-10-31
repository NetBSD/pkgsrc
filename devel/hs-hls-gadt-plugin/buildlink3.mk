# $NetBSD: buildlink3.mk,v 1.5 2023/10/31 13:24:30 pho Exp $

BUILDLINK_TREE+=	hs-hls-gadt-plugin

.if !defined(HS_HLS_GADT_PLUGIN_BUILDLINK3_MK)
HS_HLS_GADT_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-gadt-plugin+=	hs-hls-gadt-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-gadt-plugin+=	hs-hls-gadt-plugin>=2.4.0.0
BUILDLINK_PKGSRCDIR.hs-hls-gadt-plugin?=	../../devel/hs-hls-gadt-plugin

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-hls-refactor-plugin/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_GADT_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-gadt-plugin
