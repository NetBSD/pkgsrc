# $NetBSD: options.mk,v 1.1 2005/03/08 09:33:19 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ssmtp
PKG_DEFAULT_OPTIONS=	ssl
PKG_SUPPORTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.include "../../security/openssl/buildlink3.mk"
.endif
