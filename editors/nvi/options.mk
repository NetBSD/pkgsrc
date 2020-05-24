# $NetBSD: options.mk,v 1.4 2020/05/24 05:22:01 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi
PKG_SUPPORTED_OPTIONS+=	wide-curses
PKG_SUGGESTED_OPTIONS+=	wide-curses
PKG_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support
###
.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-widechar
.endif
