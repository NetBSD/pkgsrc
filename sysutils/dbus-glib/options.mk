# $NetBSD: options.mk,v 1.1 2009/02/24 15:42:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus-glib
PKG_SUPPORTED_OPTIONS+=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-tests
CONFIGURE_ARGS+=	--enable-verbose-mode
.endif
