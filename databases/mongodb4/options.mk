# $NetBSD: options.mk,v 1.2 2024/01/27 08:32:31 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_BUILD_ARGS+=		--ssl=on
#SCONS_BUILD_ARGS+=		--ssl-provider=openssl
.else
SCONS_BUILD_ARGS+=		--ssl=off
.endif
