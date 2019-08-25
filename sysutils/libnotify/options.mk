# $NetBSD: options.mk,v 1.7 2019/08/25 11:54:34 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc introspection
PKG_SUGGESTED_OPTIONS=	introspection
PLIST_VARS+=		doc introspection

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

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
MESON_ARGS+=		-Dintrospection=enabled
.else
MESON_ARGS+=		-Dintrospection=disabled
.endif
