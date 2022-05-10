# $NetBSD: options.mk,v 1.3 2022/05/10 11:51:17 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ttt
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.prefs.mk"

.if ${IPV6_READY:tl} == "yes"
PKG_SUGGESTED_OPTIONS+= inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
