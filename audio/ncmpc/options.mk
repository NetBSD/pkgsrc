# $NetBSD: options.mk,v 1.3 2017/01/04 16:54:33 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ncmpc
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"
.include "../../mk/curses.buildlink3.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+= --disable-wide
.endif
