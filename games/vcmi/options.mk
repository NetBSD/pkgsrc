# $NetBSD: options.mk,v 1.3 2026/05/07 17:16:19 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vcmi
PKG_SUPPORTED_OPTIONS=		luajit qt6
PKG_OPTIONS_OPTIONAL_GROUPS+=	gui
PKG_OPTIONS_GROUP.gui+=		qt5 qt6
PKG_SUGGESTED_OPTIONS+=		qt5

.include "../../lang/LuaJIT2/platform.mk"
.if ${PLATFORM_SUPPORTS_LUAJIT:tl} == "yes"
PKG_SUGGESTED_OPTIONS+=		luajit
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt
.if !empty(PKG_OPTIONS:Mqt6)
PLIST.qt=	yes
.  include "../../devel/qt6-qttools/buildlink3.mk"
.  include "../../graphics/qt6-qtsvg/buildlink3.mk"
.  include "../../x11/qt6-qtbase/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.  include "../../x11/qt5-qtsvg/buildlink3.mk"
.  include "../../x11/qt5-qttools/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LAUNCHER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_EDITOR=OFF
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
.  include "../../lang/lua51/buildlink3.mk"
.endif
