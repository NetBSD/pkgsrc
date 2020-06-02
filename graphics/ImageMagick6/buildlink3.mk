# $NetBSD: buildlink3.mk,v 1.19 2020/06/02 08:22:42 adam Exp $

BUILDLINK_TREE+=	ImageMagick6

.if !defined(IMAGEMAGICK6_BUILDLINK3_MK)
IMAGEMAGICK6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ImageMagick6+=	ImageMagick6>=5.5.7.11nb1
BUILDLINK_ABI_DEPENDS.ImageMagick6+=	ImageMagick6>=6.9.11.7nb2
BUILDLINK_PKGSRCDIR.ImageMagick6?=	../../graphics/ImageMagick6
pkgbase := ImageMagick6
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ImageMagick6:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick6:Mjp2)
.include "../../graphics/openjpeg/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick6:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick6:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick6:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif

.PHONY: ImageMagick6-preconfigure
pre-configure: ImageMagick6-preconfigure
ImageMagick6-preconfigure:
	cp ${PREFIX}/lib/pkgconfig/ImageMagick++-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/ImageMagick++.pc
	cp ${PREFIX}/lib/pkgconfig/ImageMagick-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/ImageMagick.pc
	cp ${PREFIX}/lib/pkgconfig/Magick++-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/Magick++.pc
	cp ${PREFIX}/lib/pkgconfig/MagickCore-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/MagickCore.pc
	cp ${PREFIX}/lib/pkgconfig/MagickWand-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/MagickWand.pc
	cp ${PREFIX}/lib/pkgconfig/Wand-6.Q16.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/Wand.pc

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # IMAGEMAGICK6_BUILDLINK3_MK

BUILDLINK_TREE+=	-ImageMagick6
