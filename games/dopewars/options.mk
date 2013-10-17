# $NetBSD: options.mk,v 1.2 2013/10/17 09:44:57 roy Exp $

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
CONFIGURE_ARGS+=	--disable-glib2
.  include "../../devel/glib/buildlink3.mk"
.endif
