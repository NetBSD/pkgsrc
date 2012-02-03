# $NetBSD: options.mk,v 1.6 2012/02/03 09:57:19 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula-clientonly
PKG_SUPPORTED_OPTIONS=		bacula-static ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbacula-static)
CONFIGURE_ARGS+=	--enable-static-cons
CONFIGURE_ARGS+=	--enable-static-dir
CONFIGURE_ARGS+=	--enable-static-fd
CONFIGURE_ARGS+=	--enable-static-sd
CONFIGURE_ARGS+=	--enable-static-tools
CONFIGURE_ARGS+=	--disable-libtool
PLIST_SUBST+=		STATIC=
.else
PLIST_SUBST+=		STATIC="@comment "
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.endif
