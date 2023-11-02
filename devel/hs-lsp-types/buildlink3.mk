# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:45 pho Exp $

BUILDLINK_TREE+=	hs-lsp-types

.if !defined(HS_LSP_TYPES_BUILDLINK3_MK)
HS_LSP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lsp-types+=	hs-lsp-types>=2.0.2
BUILDLINK_ABI_DEPENDS.hs-lsp-types+=	hs-lsp-types>=2.0.2.0nb1
BUILDLINK_PKGSRCDIR.hs-lsp-types?=	../../devel/hs-lsp-types

# lib:lsp-types
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../converters/hs-lens-aeson/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../devel/hs-row-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:metamodel
.include "../../devel/hs-file-embed/buildlink3.mk"
.endif	# HS_LSP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lsp-types
