# $NetBSD: buildlink3.mk,v 1.2 2023/10/24 22:10:51 wiz Exp $

BUILDLINK_TREE+=	libretls

.if !defined(LIBRETLS_BUILDLINK3_MK)
LIBRETLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libretls+=	libretls>=3.3.0
BUILDLINK_ABI_DEPENDS.libretls?=		libretls>=3.7.0nb1
BUILDLINK_PKGSRCDIR.libretls?=		../../security/libretls

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBRETLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libretls
