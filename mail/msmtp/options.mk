# $NetBSD: options.mk,v 1.6 2005/05/31 10:01:38 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp
PKG_SUPPORTED_OPTIONS=	gnutls gsasl inet6 ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

# GNUtls support
.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=gnutls
.endif

# GNUsasl support
.if !empty(PKG_OPTIONS:Mgsasl)
.include "../../security/gsasl/buildlink3.mk"
.endif

# OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

# Disable any SSL support
.if empty(PKG_OPTIONS:Mgnutls) && empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--disable-ssl
.endif
