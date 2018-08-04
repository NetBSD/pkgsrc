# $NetBSD: options.mk,v 1.1 2018/08/04 01:05:10 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.osg
PKG_SUPPORTED_OPTIONS+=	curl ffmpeg freetype gdal jasper libxml2 lua
PKG_SUPPORTED_OPTIONS+=	openexr pdf sdl2 svg xrandr
PKG_SUGGESTED_OPTIONS+=	ffmpeg freetype xrandr

PLIST_VARS+=		curl ffmpeg freetype gdal jasper lua openexr pdf svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
PLIST.curl=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_CURL=TRUE
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg4/buildlink3.mk"
PLIST.ffmpeg=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_FFmpeg=TRUE
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
.include "../../graphics/freetype2/buildlink3.mk"
PLIST.freetype=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Freetype=TRUE
.endif

.if !empty(PKG_OPTIONS:Mgdal)
.include "../../geography/gdal-lib/buildlink3.mk"
PLIST.gdal=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GDAL=TRUE
.endif

.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Jasper=TRUE
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua52/buildlink3.mk"
PLIST.lua=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Lua52=TRUE
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
PLIST.openexr=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_OpenEXR=TRUE
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
PLIST.pdf=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Poppler-glib=TRUE
.endif

.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SDL2=TRUE
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_RSVG=TRUE
.endif

.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
.else
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibXml2=TRUE
.endif
