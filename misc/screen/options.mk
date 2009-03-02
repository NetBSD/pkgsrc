# $NetBSD: options.mk,v 1.1 2009/03/02 21:11:49 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.screen

PKG_OPTIONS_OPTIONAL_GROUPS=	curses
PKG_OPTIONS_GROUP.curses=	curses ncurses pdcurses

PKG_SUPPORTED_OPTIONS=		# undef

.include "../../mk/bsd.options.mk"

###
### Override the default curses implemenation
###
.if !empty(PKG_OPTIONS:Mcurses)
CURSES_DEFAULT=	curses
.endif

.if !empty(PKG_OPTIONS:Mncurses)
CURSES_DEFAULT=	ncurses
.endif

.if !empty(PKG_OPTIONS:Mpdcurses)
CURSES_DEFAULT=	pdcurses
.endif
