# $NetBSD: buildlink3.mk,v 1.1 2013/02/28 15:47:41 agc Exp $

BUILDLINK_TREE+=	libsodium

.if !defined(LIBSODIUM_BUILDLINK3_MK)
LIBSODIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsodium+=	libsodium>=0.3
BUILDLINK_PKGSRCDIR.libsodium?=	../../security/libsodium
.endif	# LIBSODIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsodium
