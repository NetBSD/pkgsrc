# $NetBSD: options.mk,v 1.1 2015/10/21 16:37:22 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongo-tools
PKG_SUPPORTED_OPTIONS=	sasl ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
MONGO_TAGS+=		sasl
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
MONGO_TAGS+=		ssl
.include "../../security/openssl/buildlink3.mk"
.endif
