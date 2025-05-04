# $NetBSD: options.mk,v 1.4 2025/05/04 05:55:49 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.upower

PKG_SUPPORTED_OPTIONS+=	introspection polkit
PKG_SUGGESTED_OPTIONS=	introspection polkit

PLIST_VARS+=		introspection polkit

.include "../../mk/bsd.options.mk"

###
### Build GObject Introspection data
###
.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+= build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=    -Dintrospection=enabled
PLIST.introspection=	yes
.else
MESON_ARGS+=    -Dintrospection=disabled
.endif

###
### Polkit support in UPower Daemon
###
.if !empty(PKG_OPTIONS:Mpolkit)
.  include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=	-Dpolkit=enabled
PLIST.polkit=	yes
.else
MESON_ARGS+=    -Dpolkit=disabled
.endif
