# $NetBSD: buildlink3.mk,v 1.1 2021/06/24 13:55:26 nia Exp $

BUILDLINK_TREE+=	libuecc

.if !defined(LIBUECC_BUILDLINK3_MK)
LIBUECC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuecc+=	libuecc>=7
BUILDLINK_PKGSRCDIR.libuecc?=	../../security/libuecc
.endif	# LIBUECC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuecc
