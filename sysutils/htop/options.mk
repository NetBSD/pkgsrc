# $NetBSD: options.mk,v 1.3 2024/05/06 08:27:55 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.htop

PKG_OPTIONS_REQUIRED_GROUPS+=	curses
PKG_OPTIONS_GROUP.curses=	curses ncurses

PKG_SUGGESTED_OPTIONS=		curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
. include "../../devel/ncurses/buildlink3.mk"
.else
. include "../../mk/curses.buildlink3.mk"
. if ${CURSES_TYPE} != "ncurses"
# See netbsd/README.md
CONFIGURE_ARGS+=		--disable-unicode
. endif
.endif
