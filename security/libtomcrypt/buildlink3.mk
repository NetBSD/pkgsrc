# $NetBSD: buildlink3.mk,v 1.3 2014/03/14 22:38:39 agc Exp $

BUILDLINK_TREE+=	libtomcrypt

.if !defined(LIBTOMCRYPT_BUILDLINK3_MK)
LIBTOMCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtomcrypt+=	libtomcrypt>=1.17nb2
BUILDLINK_PKGSRCDIR.libtomcrypt?=	../../security/libtomcrypt

.include "../../math/ltm/buildlink3.mk"

.endif	# LIBTOMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtomcrypt
