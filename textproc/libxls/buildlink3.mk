# $NetBSD: buildlink3.mk,v 1.2 2020/07/14 12:48:58 sjmulder Exp $

BUILDLINK_TREE+=	libxls

.if !defined(LIBXLS_BUILDLINK3_MK)
LIBXLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxls+=	libxls>=1.5.3
BUILDLINK_PKGSRCDIR.libxls?=	../../textproc/libxls

.include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libxls
