# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:25 pho Exp $

BUILDLINK_TREE+=	hs-tasty-expected-failure

.if !defined(HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK)
HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-expected-failure+=	hs-tasty-expected-failure>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-tasty-expected-failure+=	hs-tasty-expected-failure>=0.12.3nb1
BUILDLINK_PKGSRCDIR.hs-tasty-expected-failure?=		../../devel/hs-tasty-expected-failure

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.endif	# HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-expected-failure
