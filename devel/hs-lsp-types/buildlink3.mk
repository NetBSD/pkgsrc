# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:17 wiz Exp $

BUILDLINK_TREE+=	hs-lsp-types

.if !defined(HS_LSP_TYPES_BUILDLINK3_MK)
HS_LSP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lsp-types+=	hs-lsp-types>=1.4.0
BUILDLINK_ABI_DEPENDS.hs-lsp-types+=	hs-lsp-types>=1.4.0.1nb2
BUILDLINK_PKGSRCDIR.hs-lsp-types?=	../../devel/hs-lsp-types

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-rope-utf16-splay/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_LSP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lsp-types
