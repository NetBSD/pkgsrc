# $NetBSD: options.mk,v 1.2 2006/11/06 11:28:02 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glitz
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
LIBS.Darwin+=	-lXext
PLIST_SUBST+=	X11=""
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-glx
PLIST_SUBST+=	X11="@comment "
.endif
