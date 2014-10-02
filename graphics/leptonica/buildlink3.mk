# $NetBSD: buildlink3.mk,v 1.1 2014/10/02 07:23:56 adam Exp $

BUILDLINK_TREE+=	leptonica

.if !defined(LEPTONICA_BUILDLINK3_MK)
LEPTONICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leptonica+=	leptonica>=1.71
BUILDLINK_PKGSRCDIR.leptonica?=		../../graphics/leptonica

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LEPTONICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-leptonica
