# $NetBSD: options.mk,v 1.1 2008/06/08 16:29:28 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rdesktop
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

###
### Support both IPv6 and IPv4 connections.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGE+=	--with-ipv6
.endif
