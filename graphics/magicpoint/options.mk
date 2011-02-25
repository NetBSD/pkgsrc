# $NetBSD: options.mk,v 1.2 2011/02/25 17:02:53 wiz Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.magicpoint
PKG_SUPPORTED_OPTIONS=	freetype vflib xft2
PKG_SUGGESTED_OPTIONS=	xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-freetype
MGP_TFONT=	% %
MGP_VFONT=	# empty
.include "../../graphics/freetype-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if !empty(PKG_OPTIONS:Mvflib)
CONFIGURE_ARGS+=	--enable-vflib
MGP_TFONT=	# empty
MGP_VFONT=	% %
.include "../../print/ja-vflib-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vflib
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft2
MGP_XFONT=	# empty
MGP_TFONT=	% %
MGP_VFONT=	% %

.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft2
.endif

.include "../../graphics/imlib2/buildlink3.mk"


#
# fall back defaults
#
MGP_VFONT?=	% %
MGP_TFONT?=	% %
MGP_XFONT?=	% %
