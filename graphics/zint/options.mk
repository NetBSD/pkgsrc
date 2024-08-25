# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zint
PKG_SUPPORTED_OPTIONS+=	qt5
PKG_SUGGESTED_OPTIONS+=	qt5

# TODO: add qt6 support
#CMAKE_CONFIGURE_ARGS+=	-DZINT_QT6=ON

PLIST_VARS+=	qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5=	yes
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif
