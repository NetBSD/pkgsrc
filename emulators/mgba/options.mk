# $NetBSD: options.mk,v 1.5 2020/06/19 13:06:35 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba

PKG_SUPPORTED_OPTIONS+=	ffmpeg qt5 opengl
PKG_SUGGESTED_OPTIONS+=	ffmpeg qt5 opengl

PLIST_SRC+=	PLIST
PLIST_VARS+=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DUSE_FFMPEG=ON
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes
CMAKE_ARGS+=	-DBUILD_QT=ON
# We probably don't actually want Qt5Multimedia.
# It's an option as an audio output, but SDL supports many more pkgsrc
# platforms natively, without going via PulseAudio.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Multimedia=TRUE
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
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
