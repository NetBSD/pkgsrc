# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:29 rillig Exp $

BUILDLINK_TREE+=	libmcrypt

.if !defined(LIBMCRYPT_BUILDLINK3_MK)
LIBMCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmcrypt+=	libmcrypt>=2.5.6
BUILDLINK_ABI_DEPENDS.libmcrypt+=	libmcrypt>=2.5.7nb1
BUILDLINK_PKGSRCDIR.libmcrypt?=		../../security/libmcrypt
.endif # LIBMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmcrypt
