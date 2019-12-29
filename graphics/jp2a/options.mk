# $NetBSD: options.mk,v 1.1 2019/12/29 21:31:34 ng0 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jp2a
PKG_SUPPORTED_OPTIONS=	curl curses
PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--enable-curl
.include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-termlib
.else
CONFIGURE_ARGS+=	--disable-termlib
.endif
