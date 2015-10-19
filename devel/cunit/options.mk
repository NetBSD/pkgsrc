# $NetBSD: options.mk,v 1.1 2015/10/19 08:32:39 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cunit
PKG_SUPPORTED_OPTIONS=	curses
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curses

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../devel/ncurses/buildlink3.mk"
PLIST.curses=		yes
USE_NCURSES=		yes
CONFIGURE_ARGS+=	--enable-curses
LDFLAGS+=		-lcurses
CFLAGS+=		-DNCURSES_OPAQUE=0
.endif
