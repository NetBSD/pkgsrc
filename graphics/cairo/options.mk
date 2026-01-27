# $NetBSD: options.mk,v 1.28 2026/01/27 08:31:50 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo
PKG_SUPPORTED_OPTIONS=	lzo x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
PKG_SUGGESTED_OPTIONS+=	quartz
.else
PKG_SUGGESTED_OPTIONS=	x11
.endif
PKG_SUGGESTED_OPTIONS+=	lzo

# remove after 2026Q2
PKG_OPTIONS_LEGACY_OPTS+=	xcb:x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11 quartz

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
.endif

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
MESON_ARGS+=		-Dxlib=enabled
MESON_ARGS+=		-Dxcb=enabled
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.else
MESON_ARGS+=		-Dxlib=disabled
MESON_ARGS+=		-Dxcb=disabled
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
PLIST.quartz=		yes
WARNINGS+=		"You have enabled Quartz backend. No fonts installed with pkgsrc will be found."
MESON_ARGS+=		-Dquartz=enabled
.else
MESON_ARGS+=		-Dquartz=disabled
.endif
