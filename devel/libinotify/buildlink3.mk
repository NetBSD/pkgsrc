# $NetBSD: buildlink3.mk,v 1.1 2013/05/16 00:07:48 rodent Exp $

BUILDLINK_TREE+=	libinotify

.if !defined(LIBINOTIFY_BUILDLINK3_MK)
LIBINOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinotify+=	libinotify>=0.0
BUILDLINK_PKGSRCDIR.libinotify?=	../../devel/libinotify
.endif	# LIBINOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinotify
