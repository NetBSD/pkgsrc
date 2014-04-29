# $NetBSD: buildlink3.mk,v 1.1 2014/04/29 20:03:06 wiz Exp $

BUILDLINK_TREE+=	libisofs

.if !defined(LIBISOFS_BUILDLINK3_MK)
LIBISOFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisofs+=	libisofs>=1.1.6
BUILDLINK_PKGSRCDIR.libisofs?=	../../sysutils/libisofs

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisofs
