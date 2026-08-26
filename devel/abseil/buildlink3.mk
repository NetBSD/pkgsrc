# $NetBSD: buildlink3.mk,v 1.14 2026/08/26 10:09:07 adam Exp $

BUILDLINK_TREE+=	abseil

.if !defined(ABSEIL_BUILDLINK3_MK)
ABSEIL_BUILDLINK3_MK:=

# .buildlink/include/absl/base/policy_checks.h:57:2:
# error: #error "This package requires GCC 10 or higher."
GCC_REQD+=	10

USE_CXX_FEATURES+=	c++17 filesystem

BUILDLINK_API_DEPENDS.abseil+=	abseil>=20220623.0
BUILDLINK_ABI_DEPENDS.abseil+=	abseil>=20260817.0
BUILDLINK_PKGSRCDIR.abseil?=	../../devel/abseil
.endif	# ABSEIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-abseil
