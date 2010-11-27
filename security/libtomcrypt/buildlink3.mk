# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/27 06:11:57 agc Exp $

BUILDLINK_TREE+=	libtomcrypt

.if !defined(LIBTOMCRYPT_BUILDLINK3_MK)
LIBTOMCRYPT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libtomcrypt?=	build

BUILDLINK_API_DEPENDS.libtomcrypt+=	libtomcrypt>=1.17
BUILDLINK_PKGSRCDIR.libtomcrypt?=	../../security/libtomcrypt

.include "../../math/ltm/buildlink3.mk"

.endif	# LIBTOMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtomcrypt
