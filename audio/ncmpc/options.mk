# $NetBSD: options.mk,v 1.1 2009/02/07 18:45:15 jakllsch Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ncmpc
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
