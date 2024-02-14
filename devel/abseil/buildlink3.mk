# $NetBSD: buildlink3.mk,v 1.7 2024/02/14 21:45:28 adam Exp $

BUILDLINK_TREE+=	abseil

.if !defined(ABSEIL_BUILDLINK3_MK)
ABSEIL_BUILDLINK3_MK:=

# .buildlink/include/absl/base/policy_checks.h:57:2:
# error: #error "This package requires GCC 7 or higher."
GCC_REQD+=	7

USE_CXX_FEATURES+=	c++14 filesystem

BUILDLINK_API_DEPENDS.abseil+=	abseil>=20220623.0
BUILDLINK_ABI_DEPENDS.abseil+=	abseil>=20240116.0
BUILDLINK_PKGSRCDIR.abseil?=	../../devel/abseil
.endif	# ABSEIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-abseil
