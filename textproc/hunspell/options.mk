# $NetBSD: options.mk,v 1.6 2017/01/04 13:19:56 roy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		# empty

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
INCOMPAT_CURSES=		NetBSD-[0-4].*-*
.include "../../mk/curses.buildlink3.mk"
.if !empty(PKG_OPTIONS:Mwide-curses)
CPPFLAGS.SunOS+=		-D_XPG6
.endif
