# $NetBSD: options.mk,v 1.8 2021/05/03 09:46:59 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.include "../../devel/ncursesw/buildlink3.mk"
CPPFLAGS.SunOS+=		-D_XPG6
.else
.include "../../mk/curses.buildlink3.mk"
.endif
