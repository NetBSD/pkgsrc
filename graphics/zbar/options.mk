# $NetBSD: options.mk,v 1.1 2019/12/06 08:03:00 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zbar
PKG_SUPPORTED_OPTIONS=	imagemagick x11
PKG_SUGGESTED_OPTIONS=	imagemagick x11

.include "../../mk/bsd.options.mk"

#
# ImageMagick support
#
PLIST_VARS+=	imagemagick
.if !empty(PKG_OPTIONS:Mimagemagick)
PLIST.imagemagick=	yes
CONFIGURE_ARGS+=	--with-imagemagick
.  include "../../graphics/ImageMagick/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-imagemagick
.endif

#
# X11 support
#
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xshm
CONFIGURE_ARGS+=	--with-xv
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXv/buildlink3.mk"
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libSM/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--without-xshm
CONFIGURE_ARGS+=	--without-xv
.endif
