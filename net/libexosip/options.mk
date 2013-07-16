# $NetBSD: options.mk,v 1.1 2013/07/16 02:12:26 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libeXosip2
PKG_SUPPORTED_OPTIONS=	openssl
PKG_SUGGESTED_OPTIONS+=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif
