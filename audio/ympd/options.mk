# $NetBSD: options.mk,v 1.1 2021/07/20 06:37:18 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ympd
PKG_SUPPORTED_OPTIONS=	inet6 ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CMAKE_ARGS+=	-DWITH_IPV6=ON
.else
CMAKE_ARGS+=	-DWITH_IPV6=OFF
.endif

.if !empty(PKG_OPTIONS:Mssl)
CMAKE_ARGS+=	-DWITH_SSL=ON
.  include "../../security/openssl/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_SSL=OFF
.endif
