# $NetBSD: buildlink3.mk,v 1.8 2023/10/21 17:10:33 gdt Exp $

BUILDLINK_TREE+=	leptonica

.if !defined(LEPTONICA_BUILDLINK3_MK)
LEPTONICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leptonica+=	leptonica>=1.71
BUILDLINK_ABI_DEPENDS.leptonica+=	leptonica>=1.83.1nb1
BUILDLINK_PKGSRCDIR.leptonica?=		../../graphics/leptonica

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LEPTONICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-leptonica
