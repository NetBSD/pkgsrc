# $NetBSD: buildlink3.mk,v 1.1 2026/01/22 19:29:11 js Exp $

BUILDLINK_TREE+=	mbedtls4

.if !defined(MBEDTLS3_BUILDLINK3_MK)
MBEDTLS3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls4+=	mbedtls4>=4.0.0
BUILDLINK_ABI_DEPENDS.mbedtls4?=	mbedtls4>=4.0.0
BUILDLINK_PKGSRCDIR.mbedtls4?=		../../security/mbedtls4

.endif	# MBEDTLS3_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls4
