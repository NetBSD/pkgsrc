# $NetBSD: options.mk,v 1.1 2026/07/06 00:48:50 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.suil
PKG_SUPPORTED_OPTIONS=	doc tests
.if !exists(/System/Library/Frameworks/Cocoa.framework)
PKG_SUPPORTED_OPTIONS+=	gtk3 qt5
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc gtk3 qt5

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-lv2-theme>0:../../textproc/py-sphinx-lv2-theme
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxygen>0:../../textproc/py-sphinxygen
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
MESON_ARGS+=	-Dgtk3=enabled
PLIST.gtk3=	yes
.else
MESON_ARGS+=	-Dgtk3=disabled
.endif

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
MESON_ARGS+=	-Dqt5=enabled
PLIST.qt5=	yes
.else
MESON_ARGS+=	-Dqt5=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
.else
MESON_ARGS+=	-Dtests=disabled
.endif
