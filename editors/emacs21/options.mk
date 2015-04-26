# $NetBSD: options.mk,v 1.5 2015/04/26 05:54:30 mef Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=		x11
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	motif xaw xaw3d
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

###
### Treat "xaw3d" as a special case of "xaw".
###
.if !empty(PKG_OPTIONS:Mxaw3d)
XAW_TYPE=		3d
PKG_OPTIONS:=		${PKG_OPTIONS:Nxaw3d}
PKG_OPTIONS+=		xaw
.endif

###
### Any of the "toolkit" options implies "x11".
###
.if !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Xaw X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
PKG_OPTIONS+=		xaw
.  endif
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../mk/jpeg.buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../graphics/giflib/buildlink3.mk"

CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
.else
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.endif

###
### Support using Xaw (Lucid) X11 widgets.
###
.if !empty(PKG_OPTIONS:Mxaw)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif
