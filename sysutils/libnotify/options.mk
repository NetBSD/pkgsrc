# $NetBSD: options.mk,v 1.6 2019/08/23 18:24:39 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
PLIST.doc=		yes
MESON_ARGS+=		-Ddocbook_docs=enabled
.else
MESON_ARGS+=		-Ddocbook_docs=disabled
.endif
