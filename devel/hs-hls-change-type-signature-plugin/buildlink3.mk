# $NetBSD: buildlink3.mk,v 1.1 2023/01/31 17:22:07 pho Exp $

BUILDLINK_TREE+=	hs-hls-change-type-signature-plugin

.if !defined(HS_HLS_CHANGE_TYPE_SIGNATURE_PLUGIN_BUILDLINK3_MK)
HS_HLS_CHANGE_TYPE_SIGNATURE_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-change-type-signature-plugin+=	hs-hls-change-type-signature-plugin>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-hls-change-type-signature-plugin+=	hs-hls-change-type-signature-plugin>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-hls-change-type-signature-plugin?=	../../devel/hs-hls-change-type-signature-plugin

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HLS_CHANGE_TYPE_SIGNATURE_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-change-type-signature-plugin
