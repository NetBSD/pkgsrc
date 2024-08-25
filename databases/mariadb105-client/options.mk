# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-client

PKG_SUPPORTED_OPTIONS+=	ssl
PKG_SUGGESTED_OPTIONS+=	ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=system
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=no
.endif
