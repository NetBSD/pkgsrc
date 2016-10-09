# $NetBSD: options.mk,v 1.3 2016/10/09 03:41:56 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
PLIST_SRC+=	PLIST.x11
.  include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  include "../../x11/gtkmm/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
