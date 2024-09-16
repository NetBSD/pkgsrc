# $NetBSD: buildlink3.mk,v 1.8 2024/09/16 07:20:15 adam Exp $

BUILDLINK_TREE+=	libheif

.if !defined(LIBHEIF_BUILDLINK3_MK)
LIBHEIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.8.0
BUILDLINK_ABI_DEPENDS.libheif+=	libheif>=1.18.2nb2
BUILDLINK_PKGSRCDIR.libheif?=	../../graphics/libheif

.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.endif	# LIBHEIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libheif
