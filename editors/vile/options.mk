# $NetBSD: options.mk,v 1.3 2012/07/20 14:38:51 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vile
PKG_SUPPORTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=ncursesw
.else
.  include "../../mk/curses.buildlink3.mk"
.endif
