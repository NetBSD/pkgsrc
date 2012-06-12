# $NetBSD: options.mk,v 1.5 2012/06/12 15:46:02 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vino
PKG_SUPPORTED_OPTIONS+=	avahi inet6 telepathy
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mtelepathy)
CONFIGURE_ARGS+=	--enable-telepathy
.include "../../chat/telepathy-glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-telepathy
.endif
