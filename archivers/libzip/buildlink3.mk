# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	libzip

.if !defined(LIBZIP_BUILDLINK3_MK)
LIBZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzip+=	libzip>=0.7.1
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzip
