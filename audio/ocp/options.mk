# $NetBSD: options.mk,v 1.3 2012/10/23 10:31:39 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocp
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

# broken (crashes at startup)
.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl=yes
PLIST.sdl=		yes
PLIST.desktop=		yes
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x11=yes
PLIST.x11=		yes
PLIST.desktop=		yes
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x11
.endif
