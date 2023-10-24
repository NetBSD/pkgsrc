# $NetBSD: buildlink3.mk,v 1.2 2023/10/24 22:10:59 wiz Exp $

BUILDLINK_TREE+=	scrypt

.if !defined(SCRYPT_BUILDLINK3_MK)
SCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scrypt+=	scrypt>=1.3.0nb2
BUILDLINK_ABI_DEPENDS.scrypt?=	scrypt>=1.3.1nb1
BUILDLINK_PKGSRCDIR.scrypt?=	../../security/scrypt

.include "../../security/openssl/buildlink3.mk"
.endif	# SCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-scrypt
