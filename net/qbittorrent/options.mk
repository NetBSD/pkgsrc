# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:07 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qbittorrent
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DQT6=OFF
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt6)
CMAKE_CONFIGURE_ARGS+=	-DQT6=ON
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
.  include "../../graphics/qt6-qtsvg/buildlink3.mk"
.  include "../../x11/qt6-qtbase/buildlink3.mk"
.endif
