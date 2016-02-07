# $NetBSD: buildlink3.mk,v 1.2 2016/02/07 10:59:18 adam Exp $

BUILDLINK_TREE+=	libsodium

.if !defined(LIBSODIUM_BUILDLINK3_MK)
LIBSODIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsodium+=	libsodium>=0.3
BUILDLINK_PKGSRCDIR.libsodium?=		../../security/libsodium
.endif	# LIBSODIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsodium
