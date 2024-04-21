# $NetBSD: options.mk,v 1.1 2024/04/21 15:00:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vinagre
PKG_SUPPORTED_OPTIONS=	avahi telepathy

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+= --without-avahi
.endif

PLIST_VARS+= telepathy
.if !empty(PKG_OPTIONS:Mtelepathy)
CONFIGURE_ARGS+= --with-telepathy
.include "../../chat/telepathy-glib/buildlink3.mk"
PLIST.telepathy= yes
.else
CONFIGURE_ARGS+= --without-telepathy
.endif
