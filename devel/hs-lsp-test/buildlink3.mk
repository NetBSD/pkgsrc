# $NetBSD: buildlink3.mk,v 1.1 2025/01/31 14:01:21 pho Exp $

BUILDLINK_TREE+=	hs-lsp-test

.if !defined(HS_LSP_TEST_BUILDLINK3_MK)
HS_LSP_TEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lsp-test+=	hs-lsp-test>=0.17.1
BUILDLINK_ABI_DEPENDS.hs-lsp-test+=	hs-lsp-test>=0.17.1.1
BUILDLINK_PKGSRCDIR.hs-lsp-test?=	../../devel/hs-lsp-test

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../sysutils/hs-co-log-core/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-parse/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../converters/hs-lens-aeson/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.endif	# HS_LSP_TEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lsp-test
