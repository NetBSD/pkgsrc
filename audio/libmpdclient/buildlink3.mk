# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:23:47 wiz Exp $

BUILDLINK_TREE+=	libmpdclient

.if !defined(LIBMPDCLIENT_BUILDLINK3_MK)
LIBMPDCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.4
BUILDLINK_ABI_DEPENDS.libmpdclient?=	libmpdclient>=2.20nb1
BUILDLINK_PKGSRCDIR.libmpdclient?=	../../audio/libmpdclient
.endif	# LIBMPDCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpdclient
