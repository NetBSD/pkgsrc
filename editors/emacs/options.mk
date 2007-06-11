# $NetBSD: options.mk,v 1.1 2007/06/11 13:57:16 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs
PKG_OPTIONS_REQUIRED_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk motif xaw nox11
PKG_SUGGESTED_OPTIONS=	xaw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mxaw)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.elif !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
USE_TOOLS+=		pkg-config
.elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif

# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_API_DEPENDS.libungif+=	libungif>=4.1.0.1
.endif

.if !empty(PKG_OPTIONS:Mnox11)
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
.endif
