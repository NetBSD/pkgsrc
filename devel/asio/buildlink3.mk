# $NetBSD: buildlink3.mk,v 1.3 2020/01/18 21:48:02 jperkin Exp $

BUILDLINK_TREE+=	asio

.if !defined(ASIO_BUILDLINK3_MK)
ASIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.asio+=	asio>=1.10.4
BUILDLINK_ABI_DEPENDS.asio+=	asio>=1.10.8nb2
BUILDLINK_PKGSRCDIR.asio?=	../../devel/asio
BUILDLINK_DEPMETHOD.asio?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# ASIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-asio
