# $NetBSD: options.mk,v 1.1 2023/02/01 20:18:14 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.kid3
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_ARGS+=		-DQt5Core_DIR:PATH=${QTDIR}
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.endif
