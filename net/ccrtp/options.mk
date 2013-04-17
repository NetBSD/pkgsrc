# $NetBSD: options.mk,v 1.1 2013/04/17 00:54:16 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ccrtp
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
