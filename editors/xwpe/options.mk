# $NetBSD: options.mk,v 1.1 2026/11/15 13:14:45 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xwpe
PKG_SUPPORTED_OPTIONS=	pango x11 xft2
PKG_SUGGESTED_OPTIONS=	x11 xft2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

# Xft expects X11 support.
# Use the X11_REQUIRED variable to handle this.
X11_REQUIRED?=	# empty

#
# Use cairo+pango to enable vector rendering.
#
.if !empty(PKG_OPTIONS:Mpango)
.  if empty(PKG_OPTIONS:Mx11)
PKG_FAIL_REASON+=       "pango option requires x11 support."
.  else
.    include "../../devel/pango/buildlink3.mk"
.    include "../../graphics/cairo/buildlink3.mk"
.  endif
.endif

#
# Enable Xft support.
#
.if !empty(PKG_OPTIONS:Mxft2)
X11_REQUIRED=   yes
.  if empty(PKG_OPTIONS:Mx11)
PKG_FAIL_REASON+=       "xft2 option requires x11 support."
.  else
.    include "../../x11/libXft/buildlink3.mk"
.  endif
.endif

#
# X11 support.
# Required to build the GUI client.
#
.if !empty(PKG_OPTIONS:Mx11) || ${X11_REQUIRED:tl} == "yes"
PLIST.x11=		yes
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libSM/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
