# $NetBSD: buildlink3.mk,v 1.28 2026/02/06 10:04:55 wiz Exp $

BUILDLINK_TREE+=	libgeotiff

.if !defined(LIBGEOTIFF_BUILDLINK3_MK)
LIBGEOTIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgeotiff+=	libgeotiff>=1.5.1
BUILDLINK_ABI_DEPENDS.libgeotiff?=	libgeotiff>=1.7.4nb8
BUILDLINK_PKGSRCDIR.libgeotiff?=	../../geography/libgeotiff

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LIBGEOTIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgeotiff
