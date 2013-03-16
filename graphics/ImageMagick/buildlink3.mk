# $NetBSD: buildlink3.mk,v 1.47 2013/03/16 22:40:25 dholland Exp $

BUILDLINK_TREE+=	ImageMagick

.if !defined(IMAGEMAGICK_BUILDLINK3_MK)
IMAGEMAGICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=5.5.7.11nb1
BUILDLINK_ABI_DEPENDS.ImageMagick+=	ImageMagick>=6.7.9.10nb3
BUILDLINK_PKGSRCDIR.ImageMagick?=	../../graphics/ImageMagick

pkgbase := ImageMagick
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ImageMagick:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick:Mghostscript)
.include "../../print/ghostscript/ghostscript.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.ImageMagick:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # IMAGEMAGICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ImageMagick
