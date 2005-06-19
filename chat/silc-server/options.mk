# $NetBSD: options.mk,v 1.3 2005/06/19 01:22:17 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.silc-server
PKG_SUPPORTED_OPTIONS=	debug inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
