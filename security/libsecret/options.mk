# $NetBSD: options.mk,v 1.1 2016/12/01 12:51:12 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsecret
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
