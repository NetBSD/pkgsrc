# $NetBSD: options.mk,v 1.1 2005/12/02 17:02:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ncftp2
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

# Include SOCKS firewall support
.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+= 	--enable-socks
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+= 	--enable-socks5
.include "../../net/socks5/buildlink3.mk"
.endif
