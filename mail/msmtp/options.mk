# $NetBSD: options.mk,v 1.5 2005/04/04 08:45:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp
PKG_DEFAULT_OPTIONS=	ssl
PKG_SUPPORTED_OPTIONS=	gnutls gsasl inet6 ssl

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
