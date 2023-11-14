# $NetBSD: options.mk,v 1.24 2023/11/14 13:48:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo
PKG_SUPPORTED_OPTIONS=	x11 xcb
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
PKG_SUGGESTED_OPTIONS+=	quartz
.else
PKG_SUGGESTED_OPTIONS=	x11 xcb
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11 xcb quartz

###
### X11 and XCB support (XCB implies X11)
###
.if !empty(PKG_OPTIONS:Mx11) || !empty(PKG_OPTIONS:Mxcb)
PLIST.x11=	yes
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"

.  if !empty(PKG_OPTIONS:Mxcb)
PLIST.xcb=	yes
.    include "../../x11/libxcb/buildlink3.mk"
.  endif
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
PLIST.quartz=	yes
WARNINGS+=	"You have enabled Quartz backend. No fonts installed with pkgsrc will be found."
.endif
