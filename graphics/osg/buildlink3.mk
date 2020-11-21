# $NetBSD: buildlink3.mk,v 1.93 2020/11/21 09:34:53 wiz Exp $

BUILDLINK_TREE+=	osg

.if !defined(OSG_BUILDLINK3_MK)
OSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osg+=	osg>=2.8.3
BUILDLINK_ABI_DEPENDS.osg+=	osg>=3.4.1nb36
BUILDLINK_PKGSRCDIR.osg?=	../../graphics/osg

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif

pkgbase := osg
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.osg:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mffmpeg)
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mfreetype)
.include "../../graphics/freetype2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mgdal)
.include "../../geography/gdal-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mlua)
.include "../../lang/lua52/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.osg:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
.endif
.endif	# OSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-osg
