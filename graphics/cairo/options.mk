# $NetBSD: options.mk,v 1.2 2006/11/06 09:46:41 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-xlib --enable-xlib-xrender
PLIST_SUBST+=		X11=""
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xlib --disable-xlib-xrender
PLIST_SUBST+=		X11="@comment "
.endif
