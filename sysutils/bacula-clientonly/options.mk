# $NetBSD: options.mk,v 1.3 2008/09/30 15:20:30 joerg Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula-clientonly
PKG_SUPPORTED_OPTIONS=		bacula-static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbacula-static)
CONFIGURE_ARGS+=	--enable-static-cons
CONFIGURE_ARGS+=	--enable-static-dir
CONFIGURE_ARGS+=	--enable-static-fd
CONFIGURE_ARGS+=	--enable-static-sd
CONFIGURE_ARGS+=	--enable-static-tools
PLIST_SUBST+=		STATIC=
.else
PLIST_SUBST+=		STATIC="@comment "
.endif

