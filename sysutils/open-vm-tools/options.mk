# $NetBSD: options.mk,v 1.4 2016/11/21 00:14:16 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
PLIST_SRC+=	PLIST.x11
MESSAGE_SRC+=	MESSAGE.x11
.  include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  include "../../x11/gtkmm/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
