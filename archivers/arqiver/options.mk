# $NetBSD: options.mk,v 1.1 2023/09/06 11:21:59 pin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.arqiver
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
CMAKE_ARGS+=	-DENABLE_QT5=OFF
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.endif
