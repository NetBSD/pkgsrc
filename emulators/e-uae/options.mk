# $NetBSD: options.mk,v 1.4 2012/10/23 10:24:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e-uae
PKG_SUPPORTED_OPTIONS=	gtk sdl x11
PKG_SUGGESTED_OPTIONS=	gtk sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=	pkg-config
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl --with-sdl-gfx
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif
