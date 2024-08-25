# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ympd
PKG_SUPPORTED_OPTIONS=	inet6 ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CMAKE_CONFIGURE_ARGS+=	-DWITH_IPV6=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_IPV6=OFF
.endif

.if !empty(PKG_OPTIONS:Mssl)
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=ON
.  include "../../security/openssl/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=OFF
.endif
