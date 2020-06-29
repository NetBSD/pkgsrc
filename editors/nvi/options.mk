# $NetBSD: options.mk,v 1.5 2020/06/29 18:53:26 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi
PKG_SUPPORTED_OPTIONS+=	wide-curses
PKG_SUGGESTED_OPTIONS+=	wide-curses
PKG_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-widechar
.endif
