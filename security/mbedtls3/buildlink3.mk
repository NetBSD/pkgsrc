# $NetBSD: buildlink3.mk,v 1.3 2023/04/25 21:42:17 wiz Exp $

BUILDLINK_TREE+=	mbedtls3

.if !defined(MBEDTLS3_BUILDLINK3_MK)
MBEDTLS3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mbedtls3+=	mbedtls3>=3.4.0
BUILDLINK_PKGSRCDIR.mbedtls3?=		../../security/mbedtls3

.endif	# MBEDTLS3_BUILDLINK3_MK

BUILDLINK_TREE+=	-mbedtls3
