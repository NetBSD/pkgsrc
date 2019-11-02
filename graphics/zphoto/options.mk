# $NetBSD: options.mk,v 1.7 2019/11/02 22:38:06 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zphoto
PKG_SUPPORTED_OPTIONS=		zip
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	imlib2 imagemagick
PKG_SUGGESTED_OPTIONS=		imlib2
PKG_OPTIONS_LEGACY_OPTS+=	magick:imagemagick

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
.  include "../../graphics/imlib2/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-magick
.  if !empty(PKG_BUILD_OPTIONS.imlib2:Mx11)
CONFIGURE_ARGS+=	--with-x
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-x
.  endif
.elif !empty(PKG_OPTIONS:Mmagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Mzip)
USE_TOOLS+=		zip:run
.else
CONFIGURE_ARGS+=	--disable-zip
.endif

#.if !empty(PKG_OPTIONS:Mavifile)
#.include "../../wip/avifile-devel/buildlink3.mk"
#BUILDLINK_API_DEPENDS.avifile-devel+=	avifile-devel>=0.7.34
#.else
#CONFIGURE_ARGS+=	--disable-avifile
#.endif
