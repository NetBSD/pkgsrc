# $NetBSD: options.mk,v 1.11 2022/06/04 13:49:15 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc introspection
PKG_SUGGESTED_OPTIONS=	doc introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc introspection

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
BUILDLINK_API_DEPENDS.gtk-doc=	gtk-doc>=1.32nb9
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
