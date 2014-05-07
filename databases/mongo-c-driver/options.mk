# $NetBSD: options.mk,v 1.1 2014/05/07 15:47:00 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongo-c-driver

PKG_SUPPORTED_OPTIONS+=	sasl ssl
PKG_SUGGESTED_OPTIONS+=	#

.include "../../mk/bsd.options.mk"

# Enable SASL support
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-sasl=yes
CONFIGURE_ENV+=		SASL_CFLAGS=""
CONFIGURE_ENV+=		SASL_LIBS="-lsasl2"
.else
CONFIGURE_ARGS+=	--enable-sasl=no
.endif

PLIST_VARS+=	ssl

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=yes
PLIST.ssl=		yes
.else
CONFIGURE_ARGS+=	--enable-ssl=no
.endif
