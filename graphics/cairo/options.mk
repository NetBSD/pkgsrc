# $NetBSD: options.mk,v 1.15 2013/08/31 22:19:32 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo
PKG_SUPPORTED_OPTIONS=	x11 xcb
PKG_SUGGESTED_OPTIONS=	x11 xcb

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 xcb

###
### X11 and XCB support (XCB implies X11)
###
.if !empty(PKG_OPTIONS:Mx11) || !empty(PKG_OPTIONS:Mxcb)
CONFIGURE_ARGS+=	--enable-xlib
CONFIGURE_ARGS+=	--enable-xlib-xrender
PLIST.x11=		yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt+=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"

.  if !empty(PKG_OPTIONS:Mxcb)
CONFIGURE_ARGS+=	--enable-xcb
PLIST.xcb=		yes
.  include "../../x11/libxcb/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--enable-xcb=no
.  endif

.else
CONFIGURE_ARGS+=	--disable-xlib
CONFIGURE_ARGS+=	--disable-xlib-xrender
.endif
