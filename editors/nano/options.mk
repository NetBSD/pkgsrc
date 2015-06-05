# $NetBSD: options.mk,v 1.4 2015/06/05 01:32:38 wiedi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nano
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_SUGGESTED_OPTIONS=	wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../mk/curses.buildlink3.mk"
.endif
