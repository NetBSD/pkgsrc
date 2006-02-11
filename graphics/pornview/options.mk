# $NetBSD: options.mk,v 1.1.1.1 2006/02/11 13:06:43 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pornview
PKG_SUPPORTED_OPTIONS=		exif
PKG_OPTIONS_OPTIONAL_GROUPS=	movie
PKG_OPTIONS_GROUP.movie=	mplayer xine
PKG_SUGGESTED_OPTIONS=		exif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexif)
CONFIGURE_ARGS+=	--enable-exif
.else
CONFIGURE_ARGS+=	--disable-exif
.endif

.if !empty(PKG_OPTIONS:Mmplayer)
DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
.elif !empty(PKG_OPTIONS:Mxine)
.  include "../../multimedia/xine-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xine
.endif
