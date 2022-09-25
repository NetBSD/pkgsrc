# $NetBSD: options.mk,v 1.1 2022/09/25 09:53:28 kim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.htop

PKG_OPTIONS_REQUIRED_GROUPS+=	curses
PKG_OPTIONS_GROUP.curses=	curses wide-curses

PKG_SUGGESTED_OPTIONS=		curses

.include "../../mk/bsd.options.mk"
