# $NetBSD: buildlink3.mk,v 1.2 2011/03/10 10:02:34 drochner Exp $

BUILDLINK_TREE+=	libtomcrypt

.if !defined(LIBTOMCRYPT_BUILDLINK3_MK)
LIBTOMCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtomcrypt+=	libtomcrypt>=1.17
BUILDLINK_PKGSRCDIR.libtomcrypt?=	../../security/libtomcrypt

.include "../../math/ltm/buildlink3.mk"

.endif	# LIBTOMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtomcrypt
