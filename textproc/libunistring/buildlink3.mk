# $NetBSD: buildlink3.mk,v 1.1 2012/12/06 00:10:26 gdt Exp $

BUILDLINK_TREE+=	libunistring

.if !defined(LIBUNISTRING_BUILDLINK3_MK)
LIBUNISTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunistring+=	libunistring>=0.9.3
BUILDLINK_PKGSRCDIR.libunistring?=	../../textproc/libunistring

.endif	# LIBUNISTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunistring
