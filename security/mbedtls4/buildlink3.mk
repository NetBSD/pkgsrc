# $NetBSD: buildlink3.mk,v 1.2 2026/01/22 22:46:35 wiz Exp $

BUILDLINK_TREE+=	mbedtls4

.if !defined(MBEDTLS4_BUILDLINK3_MK)
MBEDTLS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls4+=	mbedtls4>=4.0.0
BUILDLINK_ABI_DEPENDS.mbedtls4?=	mbedtls4>=4.0.0
BUILDLINK_PKGSRCDIR.mbedtls4?=		../../security/mbedtls4

.endif	# MBEDTLS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls4
