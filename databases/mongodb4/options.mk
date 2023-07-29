# $NetBSD: options.mk,v 1.1 2023/07/29 11:51:15 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_BUILD_ARGS+=		--ssl=on
SCONS_BUILD_ARGS+=		--ssl-provider=openssl
.else
SCONS_BUILD_ARGS+=		--ssl=off
.endif
