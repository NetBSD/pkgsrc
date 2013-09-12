# $NetBSD: options.mk,v 1.1 2013/09/12 14:21:27 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmemcached
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

#.if ${OPSYS} == "SunOS"
#PKG_SUGGESTED_OPTIONS+=	dtrace
#.endif

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
