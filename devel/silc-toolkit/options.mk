# $NetBSD: options.mk,v 1.1 2005/04/08 15:45:24 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.silc-toolkit
PKG_SUPPORTED_OPTIONS=	debug inet6
PKG_DEFAULT_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
