# $NetBSD: options.mk,v 1.6 2020/06/29 19:30:04 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi
PKG_SUPPORTED_OPTIONS+=	wide-curses
PKG_SUGGESTED_OPTIONS+=	wide-curses
PKG_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support
###
.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-widechar
.endif
