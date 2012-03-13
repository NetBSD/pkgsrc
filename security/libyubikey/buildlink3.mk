# $NetBSD: buildlink3.mk,v 1.2 2012/03/13 15:25:33 pettai Exp $

BUILDLINK_TREE+=	libyubikey

.if !defined(LIBYUBIKEY_BUILDLINK3_MK)
LIBYUBIKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyubikey+=	libyubikey>=1.7
BUILDLINK_PKGSRCDIR.libyubikey?=	../../security/libyubikey
.endif	# LIBYUBIKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyubikey
