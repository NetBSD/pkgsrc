# $NetBSD: options.mk,v 1.1 2020/08/19 16:32:40 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redis
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
MAKE_ENV+=		BUILD_TLS=yes
.endif
