# $NetBSD: options.mk,v 1.9 2020/09/04 10:50:08 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc icu introspection
PKG_SUGGESTED_OPTIONS=	doc icu introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc icu introspection

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
.include "../../textproc/gtk-doc/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
MESON_ARGS+=	-Dicu=enabled
PLIST.icu=		yes
.else
MESON_ARGS+=	-Dicu=disabled
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=	-Dintrospection=enabled
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif
