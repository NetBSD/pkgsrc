# $NetBSD: buildlink3.mk,v 1.9 2023/08/14 05:25:08 wiz Exp $

BUILDLINK_TREE+=	beecrypt

.if !defined(BEECRYPT_BUILDLINK3_MK)
BEECRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.beecrypt+=	beecrypt>=3.0.0
BUILDLINK_ABI_DEPENDS.beecrypt+=	beecrypt>=4.1.1nb1
BUILDLINK_PKGSRCDIR.beecrypt?=		../../security/beecrypt
.endif # BEECRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-beecrypt
