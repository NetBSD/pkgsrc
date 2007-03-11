# $NetBSD: options.mk,v 1.1 2007/03/11 16:28:39 grant Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.php
PKG_SUPPORTED_OPTIONS+=	ssl
PKG_SUGGESTED_OPTIONS+= ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
