# $NetBSD: options.mk,v 1.1 2004/12/18 03:59:30 grant Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qpopper
PKG_SUPPORTED_OPTIONS=	inet6 ssl

.if !defined(PKG_OPTIONS.qpopper)
PKG_DEFAULT_OPTIONS+=	inet6 ssl
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
