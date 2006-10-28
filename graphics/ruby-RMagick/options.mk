# $NetBSD: options.mk,v 1.1 2006/10/28 02:04:31 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.rmagick
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	graphicsmagick imagemagick
PKG_SUGGESTED_OPTIONS=		graphicsmagick

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.  include "../../graphics/GraphicsMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--with-graphics-magick
.elif !empty(PKG_OPTIONS:Mimagemagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--without-graphics-magick
.endif
