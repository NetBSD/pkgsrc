# $NetBSD: options.mk,v 1.1 2016/12/01 12:33:55 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gst1-base
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection
.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=yes
.else
CONFIGURE_ARGS+=--disable-introspection
.endif
