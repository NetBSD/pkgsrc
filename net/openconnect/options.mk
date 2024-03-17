# $NetBSD: options.mk,v 1.1 2024/03/17 11:24:34 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openconnect
PKG_SUPPORTED_OPTIONS=		libproxy

.include "../../mk/compiler.mk"

# libproxy requires C++11 support.
.if !${CC_VERSION:Mgcc-[1-3].*} && !${CC_VERSION:Mgcc-4.[0-6].*}
PKG_SUGGESTED_OPTIONS=		libproxy
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibproxy)
.  include "../../www/libproxy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libproxy
.endif
