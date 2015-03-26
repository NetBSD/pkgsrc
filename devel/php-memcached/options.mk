# $NetBSD: options.mk,v 1.1 2015/03/26 03:32:33 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-memcached
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-memcached-sasl
.else
CONFIGURE_ARGS+=	--disable-memcached-sasl
.endif
