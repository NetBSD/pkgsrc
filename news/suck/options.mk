# $NetBSD: options.mk,v 1.1 2005/12/02 17:04:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.suck
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
.include "../../net/socks5/buildlink3.mk"
.endif
