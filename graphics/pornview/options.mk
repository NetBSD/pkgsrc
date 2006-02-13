# $NetBSD: options.mk,v 1.3 2006/02/13 15:32:31 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pornview
PKG_SUPPORTED_OPTIONS=		exif gtk1
PKG_OPTIONS_OPTIONAL_GROUPS=	movie
PKG_OPTIONS_GROUP.movie=	mplayer xine
PKG_SUGGESTED_OPTIONS=		exif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexif)
CONFIGURE_ARGS+=	--enable-exif
.else
CONFIGURE_ARGS+=	--disable-exif
.endif

.if !empty(PKG_OPTIONS:Mgtk1)
CONFIGURE_ARGS+=	--without-gtk2
.  include "../../graphics/gdk-pixbuf/buildlink3.mk"
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gtk2
USE_TOOLS+=		pkg-config
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmplayer)
DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
.elif !empty(PKG_OPTIONS:Mxine)
.  include "../../multimedia/xine-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xine
.endif
