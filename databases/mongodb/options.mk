# $NetBSD: options.mk,v 1.5 2020/02/01 20:00:08 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_ARGS+=		--ssl=on
SCONS_ARGS+=		--ssl-provider=openssl
.else
SCONS_ARGS+=		--ssl=off
.endif
