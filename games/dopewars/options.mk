# $NetBSD: options.mk,v 1.1 2006/02/14 21:40:44 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dopewars
PKG_SUPPORTED_OPTIONS=	curses gtk
PKG_SUGGESTED_OPTIONS=	curses gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-curses-client
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gui-client
CONFIGURE_ARGS+=	--enable-gui-server
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui-client
CONFIGURE_ARGS+=	--disable-glib2
.  include "../../devel/glib/buildlink3.mk"
.endif
