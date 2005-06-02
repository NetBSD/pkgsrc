# $NetBSD: options.mk,v 1.1 2005/06/02 22:21:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircII
PKG_SUPPORTED_OPTIONS=	# only socks group
PKG_OPTIONS_OPTIONAL_GROUPS=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

# Include SOCKS firewall support
.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.socks4}
.endif
.if !empty(PKG_OPTIONS:Msocks5)
.include "../../net/socks5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks5=${BUILDLINK_PREFIX.socks5}
.endif
