# $NetBSD: options.mk,v 1.2 2022/12/03 08:46:39 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cunit
PKG_SUPPORTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curses

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../devel/ncurses/buildlink3.mk"
PLIST.curses=		yes
USE_NCURSES=		yes
CONFIGURE_ARGS+=	--enable-curses
.endif
