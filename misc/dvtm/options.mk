# $NetBSD: options.mk,v 1.1.1.1 2008/03/09 17:20:47 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dvtm
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

USE_NCURSES=	yes	# mouse extensions (not X/Open Curses compliant)

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
BUILD_TARGET=	unicode
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
