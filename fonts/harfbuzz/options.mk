# $NetBSD: options.mk,v 1.10 2020/11/06 15:06:49 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc introspection
PKG_SUGGESTED_OPTIONS=	doc introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc introspection

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
.include "../../textproc/gtk-doc/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=	-Dintrospection=enabled
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif
