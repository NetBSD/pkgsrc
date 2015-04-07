# $NetBSD: options.mk,v 1.2 2015/04/07 23:09:39 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-memcached
PKG_SUPPORTED_OPTIONS=	igbinary sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Migbinary)
.include "../../lang/php/phpversion.mk" 
DEPENDS+=		${PHP_PKG_PREFIX}-igbinary-[0-9]*:../../devel/php-igbinary
CONFIGURE_ARGS+=	--enable-memcached-igbinary
.else
CONFIGURE_ARGS+=	--disable-memcached-igbinary
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-memcached-sasl
.else
CONFIGURE_ARGS+=	--disable-memcached-sasl
.endif
