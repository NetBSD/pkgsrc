# $NetBSD: options.mk,v 1.8 2022/06/07 18:07:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
PLIST.doc=		yes
MESON_ARGS+=		-Ddocbook_docs=enabled
MESON_ARGS+=		-Dgtk_doc=true
.else
MESON_ARGS+=		-Ddocbook_docs=disabled
MESON_ARGS+=		-Dgtk_doc=false
.endif
