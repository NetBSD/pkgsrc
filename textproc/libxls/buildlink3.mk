# $NetBSD: buildlink3.mk,v 1.4 2025/01/31 23:39:00 sjmulder Exp $

BUILDLINK_TREE+=	libxls

.if !defined(LIBXLS_BUILDLINK3_MK)
LIBXLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxls+=	libxls>=1.6.1
BUILDLINK_ABI_DEPENDS.libxls+=	libxls>=1.6.1
BUILDLINK_PKGSRCDIR.libxls?=	../../textproc/libxls

.include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libxls
