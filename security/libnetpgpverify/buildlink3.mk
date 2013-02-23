# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/02/23 21:04:26 agc Exp $

BUILDLINK_TREE+=	libnetpgpverify

.if !defined(LIBNETPGPVERIFY_BUILDLINK3_MK)
LIBNETPGPVERIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnetpgpverify+=	libnetpgpverify>=20120928
BUILDLINK_PKGSRCDIR.libnetpgpverify?=	../../security/libnetpgpverify

.endif	# LIBNETPGPVERIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnetpgpverify
