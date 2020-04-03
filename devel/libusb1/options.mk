# $NetBSD: options.mk,v 1.1 2020/04/03 20:32:57 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libusb1
PKG_SUPPORTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-log
.endif
