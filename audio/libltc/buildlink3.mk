# $NetBSD: buildlink3.mk,v 1.1 2021/09/11 10:29:15 nia Exp $

BUILDLINK_TREE+=	libltc

.if !defined(LIBLTC_BUILDLINK3_MK)
LIBLTC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libltc+=	libltc>=1.3.1
BUILDLINK_PKGSRCDIR.libltc?=	../../audio/libltc
.endif	# LIBLTC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libltc
