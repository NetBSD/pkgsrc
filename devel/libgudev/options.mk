# $NetBSD: options.mk,v 1.1 2026/04/25 19:35:46 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgudev
PKG_SUPPORTED_OPTIONS=	introspection vapi
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		introspection vapi

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mintrospection)
MESON_ARGS+=	-Dintrospection=enabled
.  include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif

#
# Generate Vala API file
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=enabled
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=		yes
.else
MESON_ARGS+=    -Dvapi=disabled
.endif
