# $NetBSD: options.mk,v 1.2 2026/06/09 16:28:09 nia Exp $

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
