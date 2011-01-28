# $NetBSD: options.mk,v 1.2 2011/01/28 08:29:34 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.udns
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
