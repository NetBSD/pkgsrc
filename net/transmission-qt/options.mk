# $NetBSD: options.mk,v 1.1 2023/02/13 11:26:29 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.transmission-qt
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif
