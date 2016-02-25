# $NetBSD: options.mk,v 1.2 2016/02/25 12:12:48 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmemcached
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

#PKG_SUGGESTED_OPTIONS.SunOS+=	dtrace

.include "../../mk/bsd.options.mk"

###
### Cyrus SASL support
###
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--enable-sasl
.  include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

###
### DTrace support
###
#.if !empty(PKG_OPTIONS:Mdtrace)
#CONFIGURE_ARGS+=	--enable-dtrace
#.endif
