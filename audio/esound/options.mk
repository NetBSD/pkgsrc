# $NetBSD: options.mk,v 1.3 2012/09/08 18:58:43 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.esound
PKG_SUPPORTED_OPTIONS=	inet6 arts
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts --disable-artstest
.endif
