# $NetBSD: options.mk,v 1.1 2009/09/08 08:40:26 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ntp4
PKG_SUPPORTED_OPTIONS=	inet6

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
