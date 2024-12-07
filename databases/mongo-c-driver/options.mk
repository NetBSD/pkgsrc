# $NetBSD: options.mk,v 1.4 2024/12/07 18:03:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongo-c-driver
PKG_SUPPORTED_OPTIONS=	sasl ssl
PKG_SUGGESTED_OPTIONS=	ssl

PLIST_VARS+=	sasl ssl

.include "../../mk/bsd.options.mk"

# Enable SASL support
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SASL=CYRUS
PLIST.sasl=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SASL=OFF
.endif

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SSL=OPENSSL
PLIST.ssl=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SSL=OFF
.endif
