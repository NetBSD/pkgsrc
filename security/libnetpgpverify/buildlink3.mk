# $NetBSD: buildlink3.mk,v 1.3 2015/09/01 19:41:17 agc Exp $

BUILDLINK_TREE+=	libnetpgpverify

.if !defined(LIBNETPGPVERIFY_BUILDLINK3_MK)
LIBNETPGPVERIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnetpgpverify+=	libnetpgpverify>=20150901
BUILDLINK_PKGSRCDIR.libnetpgpverify?=	../../security/libnetpgpverify

.endif	# LIBNETPGPVERIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnetpgpverify
