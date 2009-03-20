# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	libcomprex

.if !defined(LIBCOMPREX_BUILDLINK3_MK)
LIBCOMPREX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcomprex+=		libcomprex>=0.3.2
BUILDLINK_ABI_DEPENDS.libcomprex+=	libcomprex>=0.3.3nb3
BUILDLINK_PKGSRCDIR.libcomprex?=	../../archivers/libcomprex

.include "../../www/curl/buildlink3.mk"
.endif # LIBCOMPREX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcomprex
