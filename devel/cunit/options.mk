# $NetBSD: options.mk,v 1.3 2024/05/06 08:33:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cunit
PKG_SUPPORTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curses

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../devel/ncurses/buildlink3.mk"
PLIST.curses=		yes
CONFIGURE_ARGS+=	--enable-curses
.endif
