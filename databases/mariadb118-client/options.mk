# $NetBSD: options.mk,v 1.1 2025/06/07 08:58:42 nia Exp $

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
