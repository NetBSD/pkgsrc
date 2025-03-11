# $NetBSD: buildlink3.mk,v 1.12 2025/03/11 12:37:03 nia Exp $

BUILDLINK_TREE+=	libheif

.if !defined(LIBHEIF_BUILDLINK3_MK)
LIBHEIF_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++20

BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.8.0
BUILDLINK_ABI_DEPENDS.libheif+=	libheif>=1.19.5nb1
BUILDLINK_PKGSRCDIR.libheif?=	../../graphics/libheif

.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.endif	# LIBHEIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libheif
