# $NetBSD: options.mk,v 1.3 2004/11/17 19:56:49 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp
PKG_SUPPORTED_OPTIONS=	gnutls inet6 ssl gsasl nossl

.if !defined(PKG_OPTIONS.msmtp)
PKG_DEFAULT_OPTIONS+=	inet6 ssl
.endif

.include "../../mk/bsd.options.mk"

###
### GNUtls support.
###
.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

###
### OpenSSL support.
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.endif

###
### GNUsasl support.
###
.if !empty(PKG_OPTIONS:Mgsasl)
.include "../../security/gsasl/buildlink3.mk"
.endif

###
### No SSL support.
###
.if !empty(PKG_OPTIONS:Mnossl)
CONFIGURE_ARGS+=	--disable-ssl
.endif
