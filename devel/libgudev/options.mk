# $NetBSD: options.mk,v 1.4 2026/05/15 17:00:55 wiz Exp $

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
TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection
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
