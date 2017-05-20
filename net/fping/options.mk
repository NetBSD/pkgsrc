# $NetBSD: options.mk,v 1.2 2017/05/20 11:25:50 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fping
PKG_SUPPORTED_OPTIONS=	inet6

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
