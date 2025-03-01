# $NetBSD: options.mk,v 1.1 2025/03/01 17:22:13 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gqrx
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DFORCE_QT5=ON
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.  include "../../x11/qt5-qtsvg/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt6)
CMAKE_CONFIGURE_ARGS+=	-DFORCE_QT6=ON
.  include "../../graphics/qt6-qtsvg/buildlink3.mk"
.  include "../../x11/qt6-qtbase/buildlink3.mk"
.else
PKG_FAIL_REASON=	"One of qt5 or qt6 options must be selected."
.endif
