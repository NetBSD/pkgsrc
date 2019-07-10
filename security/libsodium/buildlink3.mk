# $NetBSD: buildlink3.mk,v 1.3 2019/07/10 12:56:50 schmonz Exp $

BUILDLINK_TREE+=	libsodium

.if !defined(LIBSODIUM_BUILDLINK3_MK)
LIBSODIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsodium+=	libsodium>=0.3
BUILDLINK_PKGSRCDIR.libsodium?=		../../security/libsodium
BUILDLINK_INCDIRS.libsodium+=		include
BUILDLINK_INCDIRS.libsodium+=		include/sodium
.endif	# LIBSODIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsodium
