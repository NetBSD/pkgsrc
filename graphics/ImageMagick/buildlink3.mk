# $NetBSD: buildlink3.mk,v 1.2 2004/03/02 10:31:48 adam Exp $
#
# This Makefile fragment is included by packages that use ImageMagick.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMAGEMAGICK_BUILDLINK3_MK:=	${IMAGEMAGICK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ImageMagick
.endif

.if !empty(IMAGEMAGICK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ImageMagick
BUILDLINK_DEPENDS.ImageMagick+=		ImageMagick>=5.5.7.11nb1
BUILDLINK_PKGSRCDIR.ImageMagick?=	../../graphics/ImageMagick

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif # IMAGEMAGICK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
