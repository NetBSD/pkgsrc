# $NetBSD: buildlink3.mk,v 1.108 2022/01/18 17:42:25 gdt Exp $

BUILDLINK_TREE+=	osg

.if !defined(OSG_BUILDLINK3_MK)
OSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osg+=	osg>=2.8.3
BUILDLINK_ABI_DEPENDS.osg+=	osg>=3.6.5nb16
BUILDLINK_PKGSRCDIR.osg?=	../../graphics/osg

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif

pkgbase := osg
.include "../../mk/pkg-build-options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.osg:Mgdal}
.include "../../geography/gdal-lib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.osg:Mpdf}
.include "../../print/poppler-glib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.osg:Msvg}
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.endif	# OSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-osg
