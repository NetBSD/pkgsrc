# $NetBSD: buildlink3.mk,v 1.1 2019/09/02 13:40:05 nia Exp $

BUILDLINK_TREE+=	libuninameslist

.if !defined(LIBUNINAMESLIST_BUILDLINK3_MK)
LIBUNINAMESLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuninameslist+=	libuninameslist>=20190701
BUILDLINK_PKGSRCDIR.libuninameslist?=	../../textproc/libuninameslist
.endif	# LIBUNINAMESLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuninameslist
