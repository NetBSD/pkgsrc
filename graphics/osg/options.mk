# $NetBSD: options.mk,v 1.2 2021/01/16 14:44:50 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.osg
PKG_SUPPORTED_OPTIONS+=	gdal pdf svg
PLIST_VARS+=		gdal pdf svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgdal)
.include "../../geography/gdal-lib/buildlink3.mk"
PLIST.gdal=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GDAL=TRUE
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
PLIST.pdf=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Poppler-glib=TRUE
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_RSVG=TRUE
.endif
