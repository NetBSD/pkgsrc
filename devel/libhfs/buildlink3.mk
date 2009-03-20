# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libhfs

.if !defined(LIBHFS_BUILDLINK3_MK)
LIBHFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhfs+=	libhfs>=3.2.6nb1
BUILDLINK_PKGSRCDIR.libhfs?=	../../devel/libhfs
.endif # LIBHFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhfs
