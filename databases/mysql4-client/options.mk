# $NetBSD: options.mk,v 1.3 2008/03/26 13:22:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql4-client

PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
