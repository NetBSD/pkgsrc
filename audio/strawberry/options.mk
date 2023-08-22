# $NetBSD: options.mk,v 1.2 2023/08/22 20:26:29 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.strawberry
PKG_SUPPORTED_OPTIONS=		pulseaudio
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DLIBPULSE=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DLIBPULSE=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5) || !empty(PKG_OPTIONS:Mqt6)
.  if !empty(PKG_OPTIONS:Mqt5)
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
CMAKE_ARGS+=	-DBUILD_WITH_QT5=ON
CMAKE_ARGS+=	-DBUILD_WITH_QT6=OFF
.    include "../../x11/qt5-qtbase/buildlink3.mk"
.    if ${OPSYS} != "Darwin"
.      include "../../x11/qt5-qtx11extras/buildlink3.mk"
.    else
.      include "../../x11/qt5-qtmacextras/buildlink3.mk"
.    endif
.  elif !empty(PKG_OPTIONS:Mqt6)
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
CMAKE_ARGS+=	-DBUILD_WITH_QT5=OFF
CMAKE_ARGS+=	-DBUILD_WITH_QT6=ON
.    include "../../x11/qt6-qtbase/buildlink3.mk"
.  endif
.endif
