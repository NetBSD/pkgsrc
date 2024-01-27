# $NetBSD: options.mk,v 1.13 2024/01/27 02:08:36 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	gtk-doc>=1.32nb9:../../textproc/gtk-doc
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif
