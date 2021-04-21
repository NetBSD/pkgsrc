# $NetBSD: options.mk,v 1.6 2021/04/21 19:52:29 cirnatdan Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-glib
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS+=	introspection
PLIST_VARS+=		introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=		-Dintrospection=enabled
PLIST.introspection=	yes
.else
MESON_ARGS+=		-Dintrospection=disabled
.endif
