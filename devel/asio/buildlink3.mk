# $NetBSD: buildlink3.mk,v 1.4 2021/08/10 19:24:22 prlw1 Exp $

BUILDLINK_TREE+=	asio

.if !defined(ASIO_BUILDLINK3_MK)
ASIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.asio+=	asio>=1.10.4
BUILDLINK_ABI_DEPENDS.asio+=	asio>=1.10.8nb2
BUILDLINK_PKGSRCDIR.asio?=	../../devel/asio
BUILDLINK_DEPMETHOD.asio?=	build

.include "../../security/openssl/buildlink3.mk"
.endif	# ASIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-asio
