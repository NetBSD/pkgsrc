# $NetBSD: buildlink3.mk,v 1.2 2014/10/30 23:34:52 wiz Exp $

BUILDLINK_TREE+=	libunistring

.if !defined(LIBUNISTRING_BUILDLINK3_MK)
LIBUNISTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunistring+=	libunistring>=0.9.3
BUILDLINK_ABI_DEPENDS.libunistring?=	libunistring>=0.9.4
BUILDLINK_PKGSRCDIR.libunistring?=	../../textproc/libunistring

.endif	# LIBUNISTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunistring
