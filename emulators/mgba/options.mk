# $NetBSD: options.mk,v 1.3 2020/01/25 19:26:18 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba

PKG_SUPPORTED_OPTIONS+=	ffmpeg imagemagick qt5 opengl
PKG_SUGGESTED_OPTIONS+=	ffmpeg imagemagick qt5 opengl

PLIST_SRC+=	PLIST
PLIST_VARS+=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DUSE_FFMPEG=ON
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
CMAKE_ARGS+=	-DUSE_MAGICK=ON
.include "../../graphics/ImageMagick/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_MAGICK=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes
CMAKE_ARGS+=	-DBUILD_QT=ON
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_QT=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DBUILD_GL=ON
CMAKE_ARGS+=	-DUSE_EPOXY=ON
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_GL=OFF
CMAKE_ARGS+=	-DUSE_EPOXY=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl) && !empty(PKG_OPTIONS:Mqt5)
PLIST_SRC+=	PLIST.shaders
.endif
