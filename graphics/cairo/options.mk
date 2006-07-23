# $NetBSD: options.mk,v 1.1 2006/07/23 04:07:34 minskim Exp $

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
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xlib --disable-xlib-xrender
PLIST_SUBST+=		X11="@comment "
.endif
