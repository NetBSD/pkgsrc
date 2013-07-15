# $NetBSD: options.mk,v 1.1 2013/07/15 01:33:09 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.clutter-gtk
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mintrospection)
USE_TOOLS+=		gmake
PLIST.introspection=	yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.3
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
