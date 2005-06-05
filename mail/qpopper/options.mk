# $NetBSD: options.mk,v 1.3.2.1 2005/06/05 18:35:25 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qpopper
PKG_SUPPORTED_OPTIONS=	inet6 ssl PAM

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
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Please note this is currently experimental for platforms that support it
.if !empty(PKG_OPTIONS:MPAM)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=        --with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif
