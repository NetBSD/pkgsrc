# $NetBSD: options.mk,v 1.5 2019/06/08 10:40:56 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nano
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses
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
