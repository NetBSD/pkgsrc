# $NetBSD: buildlink3.mk,v 1.11 2013/04/01 16:03:31 wiz Exp $

BUILDLINK_TREE+=	libzip

.if !defined(LIBZIP_BUILDLINK3_MK)
LIBZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzip+=	libzip>=0.7.1
BUILDLINK_ABI_DEPENDS.libzip+=	libzip>=0.11
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip

BUILDLINK_INCDIRS.libzip=	include lib/libzip/include

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzip
