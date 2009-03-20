# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libmcrypt

.if !defined(LIBMCRYPT_BUILDLINK3_MK)
LIBMCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmcrypt+=	libmcrypt>=2.5.6
BUILDLINK_ABI_DEPENDS.libmcrypt+=	libmcrypt>=2.5.7nb1
BUILDLINK_PKGSRCDIR.libmcrypt?=	../../security/libmcrypt
.endif # LIBMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmcrypt
