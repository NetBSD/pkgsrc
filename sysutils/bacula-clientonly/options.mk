# $NetBSD: options.mk,v 1.5 2011/08/17 20:23:11 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula-clientonly
PKG_SUPPORTED_OPTIONS=		bacula-static

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
