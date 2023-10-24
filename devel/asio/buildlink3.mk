# $NetBSD: buildlink3.mk,v 1.5 2023/10/24 22:08:42 wiz Exp $

BUILDLINK_TREE+=	asio

.if !defined(ASIO_BUILDLINK3_MK)
ASIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.asio+=	asio>=1.10.4
BUILDLINK_ABI_DEPENDS.asio+=	asio>=1.24.0nb1
BUILDLINK_PKGSRCDIR.asio?=	../../devel/asio
BUILDLINK_DEPMETHOD.asio?=	build

.include "../../security/openssl/buildlink3.mk"
.endif	# ASIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-asio
