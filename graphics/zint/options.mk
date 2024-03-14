# $NetBSD: options.mk,v 1.1 2024/03/14 12:24:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zint
PKG_SUPPORTED_OPTIONS+=	qt5
PKG_SUGGESTED_OPTIONS+=	qt5

# TODO: add qt6 support
#CMAKE_ARGS+=	-DZINT_QT6=ON

PLIST_VARS+=	qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5=	yes
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif
