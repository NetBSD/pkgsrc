# $NetBSD: options.mk,v 1.2 2013/10/16 20:26:23 roy Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.tig
PKG_SUPPORTED_OPTIONS=	wide-curses
###
###	Git commit messages often contain UTF-8, so we default
###	to this here.
###
PKG_SUGGESTED_OPTIONS+=	wide-curses

.include "../../mk/bsd.options.mk"

# NetBSD curses does not implemet getsyx or setsyx
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
