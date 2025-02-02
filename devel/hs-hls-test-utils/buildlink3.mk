# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:10 pho Exp $

BUILDLINK_TREE+=	hs-hls-test-utils

.if !defined(HS_HLS_TEST_UTILS_BUILDLINK3_MK)
HS_HLS_TEST_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hls-test-utils+=	hs-hls-test-utils>=2.9.0
BUILDLINK_ABI_DEPENDS.hs-hls-test-utils+=	hs-hls-test-utils>=2.9.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hls-test-utils?=		../../devel/hs-hls-test-utils

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-test/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-neat-interpolation/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-tasty-expected-failure/buildlink3.mk"
.include "../../devel/hs-tasty-golden/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-tasty-rerun/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-text-rope/buildlink3.mk"
.endif	# HS_HLS_TEST_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hls-test-utils
