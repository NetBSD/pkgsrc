# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:16 joerg Exp $

BUILDLINK_TREE+=	beecrypt

.if !defined(BEECRYPT_BUILDLINK3_MK)
BEECRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.beecrypt+=	beecrypt>=3.0.0
BUILDLINK_ABI_DEPENDS.beecrypt+=	beecrypt>=3.0.0nb1
BUILDLINK_PKGSRCDIR.beecrypt?=	../../security/beecrypt
.endif # BEECRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-beecrypt
