# $NetBSD: options.mk,v 1.6 2022/06/28 10:40:39 nia Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cogl
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-gdk-pixbuf
CONFIGURE_ARGS+=	--with-gl-libname=libGL
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.4
.include "../../x11/libXcomposite/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.2
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS.Darwin+=	--with-quartz-image
.include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == Darwin
PLIST.osx=		yes
.  endif
.endif
