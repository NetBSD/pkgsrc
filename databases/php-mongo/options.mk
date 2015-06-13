# $NetBSD: options.mk,v 1.1 2015/06/13 13:48:37 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mongo
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-mongo-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mongo-sasl
.endif
