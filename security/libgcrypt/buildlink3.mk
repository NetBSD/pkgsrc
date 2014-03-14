# $NetBSD: buildlink3.mk,v 1.17 2014/03/14 13:39:07 gdt Exp $

BUILDLINK_TREE+=	libgcrypt

.if !defined(LIBGCRYPT_BUILDLINK3_MK)
LIBGCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.0
BUILDLINK_ABI_DEPENDS.libgcrypt+=	libgcrypt>=1.6.0
BUILDLINK_PKGSRCDIR.libgcrypt?=	../../security/libgcrypt

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBGCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcrypt
