# $NetBSD: options.mk,v 1.3 2021/01/26 22:12:08 fcambus Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dopewars
PKG_SUPPORTED_OPTIONS=	curses gtk
PKG_SUGGESTED_OPTIONS=	curses gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-curses-client
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gui-client
CONFIGURE_ARGS+=	--enable-gui-server
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui-client
.  include "../../devel/glib2/buildlink3.mk"
.endif
