# $NetBSD: buildlink3.mk,v 1.1 2020/11/27 10:19:38 schmonz Exp $

BUILDLINK_TREE+=	libretls

.if !defined(LIBRETLS_BUILDLINK3_MK)
LIBRETLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libretls+=	libretls>=3.3.0
BUILDLINK_PKGSRCDIR.libretls?=		../../security/libretls

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBRETLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libretls
