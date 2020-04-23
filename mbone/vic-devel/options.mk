# $NetBSD: options.mk,v 1.5 2020/04/23 15:25:43 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vic
PKG_SUPPORTED_OPTIONS=		inet6
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

## IPv6 support
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
