# $NetBSD: options.mk,v 1.14 2024/01/27 02:09:19 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc introspection
PKG_SUGGESTED_OPTIONS=	doc introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc introspection

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	gtk-doc>=1.32nb9:../../textproc/gtk-doc
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
MESON_ARGS+=	-Dintrospection=enabled
.include "../../devel/glib2/buildlink3.mk"
# XXX This should be TOOL_DEPENDS, no?
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif
