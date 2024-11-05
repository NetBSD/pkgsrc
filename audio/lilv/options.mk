# $NetBSD: options.mk,v 1.4 2024/11/05 18:22:30 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lilv
PKG_SUPPORTED_OPTIONS=	doc tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxygen>0:../../textproc/py-sphinxygen
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
.else
MESON_ARGS+=	-Dtests=disabled
.endif
