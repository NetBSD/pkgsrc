# $NetBSD: options.mk,v 1.2 2019/11/04 21:13:01 rillig Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-asn1-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
