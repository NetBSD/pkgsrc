# $NetBSD: options.mk,v 1.2 2014/01/04 13:47:38 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.clutter-gtk
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mintrospection)
USE_TOOLS+=		gmake
PLIST.introspection=	yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.12
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
