# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:40 pho Exp $

BUILDLINK_TREE+=	hs-hls-rename-plugin

.if !defined(HS_HLS_RENAME_PLUGIN_BUILDLINK3_MK)
HS_HLS_RENAME_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-rename-plugin+=	hs-hls-rename-plugin>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-hls-rename-plugin+=	hs-hls-rename-plugin>=2.4.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-rename-plugin?=	../../devel/hs-hls-rename-plugin

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-hls-refactor-plugin/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_RENAME_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-rename-plugin
