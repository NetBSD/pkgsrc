# $NetBSD: options.mk,v 1.5 2017/02/20 09:19:27 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	icu x11
PKG_SUGGESTED_OPTIONS=	icu x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-icu
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST_SRC+=	PLIST.x11
MESSAGE_SRC+=	MESSAGE.x11
.  include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../x11/gtkmm/buildlink3.mk"
.  include "../../x11/libXtst/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
