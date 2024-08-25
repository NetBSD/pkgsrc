# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:47 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vcmi

PKG_SUPPORTED_OPTIONS=		luajit

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
.  include "../../x11/qt6-qtbase/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LAUNCHER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_EDITOR=OFF
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
.  include "../../lang/lua51/buildlink3.mk"
.endif
