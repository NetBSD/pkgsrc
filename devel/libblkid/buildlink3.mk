# $NetBSD: buildlink3.mk,v 1.2 2017/12/08 08:03:35 adam Exp $

BUILDLINK_TREE+=	libblkid

.if !defined(LIBBLKID_BUILDLINK3_MK)
LIBBLKID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libblkid+=	libblkid>=2.18
BUILDLINK_PKGSRCDIR.libblkid?=		../../devel/libblkid

.endif	# LIBBLKID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libblkid
