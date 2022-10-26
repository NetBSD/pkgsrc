# $NetBSD: buildlink3.mk,v 1.3 2022/10/26 10:31:08 wiz Exp $

BUILDLINK_TREE+=	libunistring

.if !defined(LIBUNISTRING_BUILDLINK3_MK)
LIBUNISTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunistring+=	libunistring>=0.9.3
BUILDLINK_ABI_DEPENDS.libunistring?=	libunistring>=1.1
BUILDLINK_PKGSRCDIR.libunistring?=	../../textproc/libunistring

.endif	# LIBUNISTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunistring
