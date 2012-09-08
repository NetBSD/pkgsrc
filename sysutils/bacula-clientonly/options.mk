# $NetBSD: options.mk,v 1.8 2012/09/08 12:36:57 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula-clientonly
# bacula-static is broken -- see PR 42954
PKG_SUPPORTED_OPTIONS=		ssl

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
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
