# $NetBSD: buildlink3.mk,v 1.27 2018/08/16 18:54:26 adam Exp $

BUILDLINK_TREE+=	libcomprex

.if !defined(LIBCOMPREX_BUILDLINK3_MK)
LIBCOMPREX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcomprex+=	libcomprex>=0.3.2
BUILDLINK_ABI_DEPENDS.libcomprex+=	libcomprex>=0.3.3nb16
BUILDLINK_PKGSRCDIR.libcomprex?=	../../archivers/libcomprex

.include "../../www/curl/buildlink3.mk"
.endif # LIBCOMPREX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcomprex
