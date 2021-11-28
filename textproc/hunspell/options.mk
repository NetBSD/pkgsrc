# $NetBSD: options.mk,v 1.9 2021/11/28 19:24:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell

# handled by curses framework
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		wide-curses

.include "../../mk/bsd.options.mk"
