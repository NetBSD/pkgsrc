# $NetBSD: options.mk,v 1.2 2005/01/10 20:59:43 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qpopper
PKG_SUPPORTED_OPTIONS=	inet6 ssl

.if !defined(PKG_OPTIONS.qpopper)
PKG_DEFAULT_OPTIONS+=	ssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.endif
