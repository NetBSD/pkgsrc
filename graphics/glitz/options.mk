# $NetBSD: options.mk,v 1.4 2026/11/25 14:42:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glitz
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
LIBS.Darwin+=	-lXext
PLIST.x11=	yes
.include "../../mk/mesa.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-glx
.endif
