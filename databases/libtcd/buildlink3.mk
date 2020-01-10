# $NetBSD: buildlink3.mk,v 1.1 2020/01/10 16:57:24 plunky Exp $

BUILDLINK_TREE+=	libtcd

.if !defined(LIBTCD_BUILDLINK3_MK)
LIBTCD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtcd+=	libtcd>=2.2.7
BUILDLINK_PKGSRCDIR.libtcd?=	../../databases/libtcd

.endif	# LIBTCD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtcd
