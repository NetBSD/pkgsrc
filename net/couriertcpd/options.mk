# $NetBSD: options.mk,v 1.3 2019/09/26 11:36:55 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.couriertcpd
PKG_SUPPORTED_OPTIONS=		inet6
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
