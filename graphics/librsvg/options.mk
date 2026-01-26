# $NetBSD: options.mk,v 1.1 2026/01/26 21:32:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.librsvg
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

# Install API documentation
.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
# Requires rst2man to generate rsvg-convert.1
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# Requires gi-docgen to generate HTML format API documentation
TOOL_DEPENDS+=		${PYPKGPREFIX}-gi-docgen>=2022.1nb1:../../devel/py-gi-docgen
PRINT_PLIST_AWK+=	{ if (/^share\/doc/) $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^man\/man1\/rsvg-convert.1/) $$0 = "$${PLIST.doc}" $$0 }
MESON_ARGS+=		-Ddocs=enabled
.else
MESON_ARGS+=		-Ddocs=disabled
.endif
