# $NetBSD: buildlink3.mk,v 1.1 2019/02/11 21:55:27 leot Exp $

BUILDLINK_TREE+=	libxls

.if !defined(LIBXLS_BUILDLINK3_MK)
LIBXLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxls+=	libxls>=1.5.0
BUILDLINK_PKGSRCDIR.libxls?=	../../textproc/libxls

.include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libxls
