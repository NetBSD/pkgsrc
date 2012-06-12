# $NetBSD: options.mk,v 1.2 2012/06/12 15:45:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dhcp
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### Enable ipv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-dhcpv6
.else
CONFIGURE_ARGS+=	--disable-dhcpv6
.endif
