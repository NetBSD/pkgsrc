# $NetBSD: options.mk,v 1.1 2017/05/11 13:54:27 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=		static

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dynamic
.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--disable-dynamic
LDFLAGS+=		-static
.else
PLIST.dynamic=		yes
.endif
