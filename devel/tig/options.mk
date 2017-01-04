# $NetBSD: options.mk,v 1.3 2017/01/04 18:16:32 roy Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.tig
PKG_SUPPORTED_OPTIONS=	wide-curses
###
###	Git commit messages often contain UTF-8, so we default
###	to this here.
###
PKG_SUGGESTED_OPTIONS+=	wide-curses

.include "../../mk/bsd.options.mk"

USE_CURSES=		getsyx
.include "../../mk/curses.buildlink3.mk"
