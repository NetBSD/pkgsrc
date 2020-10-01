# $NetBSD: buildlink3.mk,v 1.3 2020/10/01 19:34:09 sjmulder Exp $

BUILDLINK_TREE+=	libxls

.if !defined(LIBXLS_BUILDLINK3_MK)
LIBXLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxls+=	libxls>=1.6.1
BUILDLINK_PKGSRCDIR.libxls?=	../../textproc/libxls

.include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libxls
