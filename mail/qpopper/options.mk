# $NetBSD: options.mk,v 1.4 2005/05/31 10:01:38 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qpopper
PKG_SUPPORTED_OPTIONS=	inet6 ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
