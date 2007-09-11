# $NetBSD: options.mk,v 1.1.1.1 2007/09/11 17:40:29 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	ncurses ncursesw
PKG_SUGGESTED_OPTIONS=		ncurses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
.endif
