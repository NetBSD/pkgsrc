# $NetBSD: options.mk,v 1.10 2021/11/15 22:01:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer1
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=		-D introspection=disabled
.endif
