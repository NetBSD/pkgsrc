# $NetBSD: options.mk,v 1.2 2013/02/18 10:17:20 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

# ndb-cluster does not configure with cmake
PKG_SUPPORTED_OPTIONS+=	embedded-server ndb-cluster ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=no
.endif
