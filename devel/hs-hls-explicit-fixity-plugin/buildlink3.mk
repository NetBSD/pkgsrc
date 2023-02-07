# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:38 pho Exp $

BUILDLINK_TREE+=	hs-hls-explicit-fixity-plugin

.if !defined(HS_HLS_EXPLICIT_FIXITY_PLUGIN_BUILDLINK3_MK)
HS_HLS_EXPLICIT_FIXITY_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-explicit-fixity-plugin+=	hs-hls-explicit-fixity-plugin>=1.1.0
BUILDLINK_API_DEPENDS.hs-hls-explicit-fixity-plugin+=	hs-hls-explicit-fixity-plugin>=1.1.0.0
BUILDLINK_ABI_DEPENDS.hs-hls-explicit-fixity-plugin?=	hs-hls-explicit-fixity-plugin>=1.1.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-explicit-fixity-plugin?=	../../devel/hs-hls-explicit-fixity-plugin

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.endif	# HS_HLS_EXPLICIT_FIXITY_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-explicit-fixity-plugin
