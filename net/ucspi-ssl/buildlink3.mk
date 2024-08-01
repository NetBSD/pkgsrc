# $NetBSD: buildlink3.mk,v 1.1 2024/08/01 11:48:16 schmonz Exp $

BUILDLINK_TREE+=	ucspi-ssl

.if !defined(UCSPI_SSL_BUILDLINK3_MK)
UCSPI_SSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucspi-ssl+=	ucspi-ssl>=0.999.12.10nb1
BUILDLINK_PKGSRCDIR.ucspi-ssl?=		../../net/ucspi-ssl
BUILDLINK_DEPMETHOD.ucspi-ssl?=		build
.endif	# UCSPI_SSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucspi-ssl
