# $NetBSD: options.mk,v 1.3 2026/05/09 12:22:24 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgudev
PKG_SUPPORTED_OPTIONS=	introspection vapi
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		introspection vapi

#
# Build GObject Introspection data
#
.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection=	build
MESON_ARGS+=	-Dintrospection=enabled
.  include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif

#
# Generate Vala bindings
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=enabled
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=		yes
.else
MESON_ARGS+=    -Dvapi=disabled
.endif
