# $NetBSD: options.mk,v 1.1 2025/02/07 03:15:05 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.screen

PKG_OPTIONS_OPTIONAL_GROUPS=	curses
PKG_OPTIONS_GROUP.curses=	curses ncurses pdcurses

PKG_SUPPORTED_OPTIONS=		# undef

.include "../../mk/bsd.options.mk"

###
### Override the default curses implementation
###
.if !empty(PKG_OPTIONS:Mcurses)
CURSES_DEFAULT=	curses
.endif

.if !empty(PKG_OPTIONS:Mncurses)
CURSES_DEFAULT=		ncurses
CONFIGURE_ARGS+=	--enable-colors256
.endif

.if !empty(PKG_OPTIONS:Mpdcurses)
CURSES_DEFAULT=		pdcurses
CONFIGURE_ARGS+=	--enable-colors256
.endif

.include "../../mk/curses.buildlink3.mk"
