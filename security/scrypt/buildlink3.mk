# $NetBSD: buildlink3.mk,v 1.1 2020/02/28 11:19:53 wiz Exp $

BUILDLINK_TREE+=	scrypt

.if !defined(SCRYPT_BUILDLINK3_MK)
SCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scrypt+=	scrypt>=1.3.0nb2
BUILDLINK_PKGSRCDIR.scrypt?=	../../security/scrypt

.include "../../security/openssl/buildlink3.mk"
.endif	# SCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-scrypt
