# $NetBSD: options.mk,v 1.1 2026/01/17 21:33:08 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxmlb
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

PRINT_PLIST_AWK+=	{ if (/^share\/gtk-doc/) $$0 = "$${PLIST.doc}" $$0 }
.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
PLIST.doc=		yes
.else
MESON_ARGS+=		-Dgtkdoc=false
.endif
