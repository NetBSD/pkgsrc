# $NetBSD: options.mk,v 1.5 2021/04/12 11:16:11 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-glib
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS+=	introspection
PLIST_VARS+=		introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=		-Dintrospection=true
PLIST.introspection=	yes
.else
MESON_ARGS+=		-Dintrospection=false
.endif
