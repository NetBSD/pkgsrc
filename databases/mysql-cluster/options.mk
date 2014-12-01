# $NetBSD: options.mk,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-cluster

PKG_SUPPORTED_OPTIONS+=	dtrace ssl
PKG_SUGGESTED_OPTIONS+=	ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=no
.endif

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_ARGS+=		-DENABLE_DTRACE=ON
.endif
