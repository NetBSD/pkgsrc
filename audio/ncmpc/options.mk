# $NetBSD: options.mk,v 1.4 2019/09/14 12:19:40 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ncmpc
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"
.include "../../mk/curses.buildlink3.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
MESON_ARGS+=	-Dcurses=ncursesw
.else
MESON_ARGS+=	-Dcurses=ncurses
.endif
