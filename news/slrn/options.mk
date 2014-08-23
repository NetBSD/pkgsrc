# $NetBSD: options.mk,v 1.2 2014/08/23 09:34:48 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.slrn
PKG_SUPPORTED_OPTIONS=		ssl uulib
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### uulib support
###
.if !empty(PKG_OPTIONS:Muulib)
.  include "../../converters/uulib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-uu=${BUILDLINK_PREFIX.uulib}
.else
CONFIGURE_ARGS+=	--without-uu
.endif
