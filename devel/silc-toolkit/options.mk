# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:36 dillo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.silc-toolkit
PKG_SUPPORTED_OPTIONS=	debug inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
