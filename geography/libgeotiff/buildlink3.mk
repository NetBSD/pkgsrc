# $NetBSD: buildlink3.mk,v 1.26 2025/10/05 19:26:00 js Exp $

BUILDLINK_TREE+=	libgeotiff

.if !defined(LIBGEOTIFF_BUILDLINK3_MK)
LIBGEOTIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgeotiff+=	libgeotiff>=1.5.1
BUILDLINK_ABI_DEPENDS.libgeotiff?=	libgeotiff>=1.7.4nb6
BUILDLINK_PKGSRCDIR.libgeotiff?=	../../geography/libgeotiff

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LIBGEOTIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgeotiff
