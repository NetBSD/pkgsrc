# $NetBSD: buildlink3.mk,v 1.49 2025/04/19 07:57:27 wiz Exp $

BUILDLINK_TREE+=	libcomprex

.if !defined(LIBCOMPREX_BUILDLINK3_MK)
LIBCOMPREX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcomprex+=	libcomprex>=0.3.2
BUILDLINK_ABI_DEPENDS.libcomprex+=	libcomprex>=0.3.3nb39
BUILDLINK_PKGSRCDIR.libcomprex?=	../../archivers/libcomprex

.include "../../www/curl/buildlink3.mk"
.endif # LIBCOMPREX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcomprex
