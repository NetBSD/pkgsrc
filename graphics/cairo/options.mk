# $NetBSD: options.mk,v 1.17 2016/02/17 10:05:41 dbj Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo
PKG_SUPPORTED_OPTIONS=	x11 xcb
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
.endif
PKG_SUGGESTED_OPTIONS=	x11 xcb

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 xcb quartz

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
CONFIGURE_ARGS+=	--disable-xcb
.  endif

.else
CONFIGURE_ARGS+=	--disable-xlib
CONFIGURE_ARGS+=	--disable-xlib-xrender
CONFIGURE_ARGS+=	--disable-xcb
.endif

###
### Quartz backend
###
# Quartz backend interacts badly with our library stack. The most
# notable issue is that when quartz-font is enabled, cairo will never
# use fontconfig but instead uses CoreGraphics API to find fonts in
# system-default font paths; as a result, any fonts installed with
# pkgsrc will never be found. OTOH fontconfig by default searches for
# fonts in MacOS X system-default paths too so sticking with it will
# not be a problem.
.if !empty(PKG_OPTIONS:Mquartz)
CONFIGURE_ARGS+=	--enable-quartz
CONFIGURE_ARGS+=	--enable-quartz-font
CONFIGURE_ARGS+=	--enable-quartz-image
PLIST.quartz=		yes
WARNINGS+=		"You have enabled Quartz backend. No fonts installed with pkgsrc will be found."
.else
CONFIGURE_ARGS+=	--disable-quartz
CONFIGURE_ARGS+=	--disable-quartz-font
CONFIGURE_ARGS+=	--disable-quartz-image
.endif
