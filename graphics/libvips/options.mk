# $NetBSD: options.mk,v 1.1 2025/08/20 16:47:24 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libvips
PKG_SUPPORTED_OPTIONS=	tiff introspection
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# meson will find libs if they are installed,
# so it makes sense to explicitly disabled them
# if they are not going to be used

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.else
MESON_ARGS+= -Dtiff=disabled
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+= -Dintrospection=disabled
.endif
