# $NetBSD: options.mk,v 1.3 2018/09/21 14:27:37 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.slrn
PKG_SUPPORTED_OPTIONS=		canlock ssl uulib
PKG_SUGGESTED_OPTIONS=		canlock ssl uulib

.include "../../mk/bsd.options.mk"

###
### canlock support
###
.if !empty(PKG_OPTIONS:Mcanlock)
.  include "../../news/libcanlock/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canlock=${BUILDLINK_PREFIX.libcanlock}
.else
CONFIGURE_ARGS+=	--without-canlock
.endif

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
