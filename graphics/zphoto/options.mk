# $NetBSD: options.mk,v 1.1.1.1 2006/08/12 16:20:35 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zphoto
PKG_SUPPORTED_OPTIONS=	zip wx
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	imlib2 magick
PKG_SUGGESTED_OPTIONS=	imlib2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
.  include "../../graphics/imlib2/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-magick
.elif !empty(PKG_OPTIONS:Mmagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Mzip)
DEPENDS+=	zip-[0-9]*:../../archivers/zip
.else
CONFIGURE_ARGS+=	--disable-zip
.endif

#.if !empty(PKG_OPTIONS:Mavifile)
#.include "../../wip/avifile-devel/buildlink3.mk"
#BUILDLINK_API_DEPENDS.avifile-devel+=	avifile-devel>=0.7.34
#.else
#CONFIGURE_ARGS+=	--disable-avifile
#.endif

.if !empty(PKG_OPTIONS:Mwx)
.include "../../x11/wxGTK/buildlink3.mk"
PLIST_SUBST+=		WX_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-wx
PLIST_SUBST+=		WX_COMMENT="@comment "
.endif
