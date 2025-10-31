# $NetBSD: options.mk,v 1.2 2025/10/31 22:44:40 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libvips
PKG_SUPPORTED_OPTIONS=	introspection x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11

# meson will find libs if they are installed,
# so it makes sense to explicitly disable them
# if they are not going to be used

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.else
MESON_ARGS+=	-Drsvg=disabled
MESON_ARGS+=	-Dpoppler=disabled
MESON_ARGS+=	-Dpoppler-module=disabled
.endif
