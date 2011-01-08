# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/08 20:43:38 markd Exp $

BUILDLINK_TREE+=	libblkid

.if !defined(LIBBLKID_BUILDLINK3_MK)
LIBBLKID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libblkid+=	libblkid>=2.18
BUILDLINK_PKGSRCDIR.libblkid?=	../../devel/libblkid

.include "../../devel/libuuid/buildlink3.mk"
.endif	# LIBBLKID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libblkid
