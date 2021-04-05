# $NetBSD: options.mk,v 1.1 2021/04/05 08:49:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bmp
PKG_SUPPORTED_OPTIONS=	inet6 xmms-eq
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mxmms-eq)
CONFIGURE_ARGS+=	--with-xmms-eq
.endif

