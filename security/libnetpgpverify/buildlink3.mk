# $NetBSD: buildlink3.mk,v 1.2 2014/02/16 17:15:48 agc Exp $

BUILDLINK_TREE+=	libnetpgpverify

.if !defined(LIBNETPGPVERIFY_BUILDLINK3_MK)
LIBNETPGPVERIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnetpgpverify+=	libnetpgpverify>=20140210
BUILDLINK_PKGSRCDIR.libnetpgpverify?=	../../security/libnetpgpverify

.endif	# LIBNETPGPVERIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnetpgpverify
