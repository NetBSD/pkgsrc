# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:01 pho Exp $

BUILDLINK_TREE+=	hs-lsp

.if !defined(HS_LSP_BUILDLINK3_MK)
HS_LSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lsp+=	hs-lsp>=1.4.0
BUILDLINK_ABI_DEPENDS.hs-lsp+=	hs-lsp>=1.4.0.0nb1
BUILDLINK_PKGSRCDIR.hs-lsp?=	../../devel/hs-lsp

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-sorted-list/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid/buildlink3.mk"
.endif	# HS_LSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lsp
