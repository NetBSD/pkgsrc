# $NetBSD: options.mk,v 1.7 2024/03/02 10:33:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nano
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
### XXX netbsd curses is unacceptable due to PR pkg/57749
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
