# $NetBSD: options.mk,v 1.5 2008/04/16 00:09:39 bjs Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.aria2

PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_OPTIONS_GROUP.asyncns=	ares cares
PKG_OPTIONS_REQUIRED_GROUPS=	ssl asyncns
PKG_SUGGESTED_OPTIONS=		ssl cares
###
### XXX Remove this in the future [2008-04-15 bjs]
###
.if !empty(PKG_OPTIONS.aria2:U:Maria2-metalink) || \
	!empty(PKG_DEFAULT_OPTIONS:U:Maria2-metalink)
PKG_OPTIONS_DEPRECATED_WARNINGS+=\
	"NOTE:	The aria2-metalink option is deprecated; this package"\
"	now supports the metalink protocol by default."
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--without-gnutls
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gnutls
CONFIGURE_ARGS+=	--without-openssl
.  include "../../security/gnutls/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mcares)
CONFIGURE_ARGS+=	--with-libcares-prefix=${BUILDLINK_PREFIX.libcares:Q}
.  include "../../net/libcares/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mares)
CONFIGURE_ARGS+=	--with-libares-prefix=${BUILDLINK_PREFIX.libares:Q}
.endif
