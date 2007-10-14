# $NetBSD: options.mk,v 1.1 2007/10/14 04:53:35 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vile
PKG_SUPPORTED_OPTIONS=	ncursesw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=ncursesw
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
