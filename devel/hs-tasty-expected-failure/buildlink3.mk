# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:39:31 pho Exp $

BUILDLINK_TREE+=	hs-tasty-expected-failure

.if !defined(HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK)
HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-expected-failure+=	hs-tasty-expected-failure>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-tasty-expected-failure+=	hs-tasty-expected-failure>=0.12.3nb2
BUILDLINK_PKGSRCDIR.hs-tasty-expected-failure?=		../../devel/hs-tasty-expected-failure

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.endif	# HS_TASTY_EXPECTED_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-expected-failure
