# $NetBSD: options.mk,v 1.3 2023/11/01 01:05:54 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.caja
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_SRC+=	PLIST

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection
PLIST_SRC+=	PLIST.introspection
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif
