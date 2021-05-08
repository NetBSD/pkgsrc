# $NetBSD: options.mk,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mariadb-client

PKG_SUPPORTED_OPTIONS+=	embedded-server ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SSL=system
.else
CMAKE_ARGS+=	-DWITH_SSL=no
.endif
