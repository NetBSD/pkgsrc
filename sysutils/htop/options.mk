# $NetBSD: options.mk,v 1.2 2022/10/04 07:14:57 kim Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.htop

PKG_OPTIONS_REQUIRED_GROUPS+=	curses
PKG_OPTIONS_GROUP.curses=	curses ncurses

PKG_SUGGESTED_OPTIONS=		curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
. include "../../devel/ncursesw/buildlink3.mk"
.else
. include "../../mk/curses.buildlink3.mk"
. if ${CURSES_TYPE} != "ncursesw"
# See netbsd/README.md
CONFIGURE_ARGS+=		--disable-unicode
. endif
.endif
