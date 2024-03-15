# $NetBSD: options.mk,v 1.8 2024/03/15 17:35:50 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nano
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
# Handled by curses.mk.
.endif
