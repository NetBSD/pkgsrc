# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:28 rillig Exp $

BUILDLINK_TREE+=	beecrypt

.if !defined(BEECRYPT_BUILDLINK3_MK)
BEECRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.beecrypt+=	beecrypt>=3.0.0
BUILDLINK_ABI_DEPENDS.beecrypt+=	beecrypt>=3.0.0nb1
BUILDLINK_PKGSRCDIR.beecrypt?=		../../security/beecrypt
.endif # BEECRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-beecrypt
