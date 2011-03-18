# $NetBSD: buildlink3.mk,v 1.9 2011/03/18 13:49:38 wiz Exp $

BUILDLINK_TREE+=	libzip

.if !defined(LIBZIP_BUILDLINK3_MK)
LIBZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzip+=	libzip>=0.7.1
BUILDLINK_ABI_DEPENDS.libzip+=	libzip>=0.10
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzip
