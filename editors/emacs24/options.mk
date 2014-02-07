# $NetBSD: options.mk,v 1.4 2014/02/07 08:56:52 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=	dbus xft2 svg xml gnutls
PKG_OPTIONS_OPTIONAL_GROUPS+= window-system
PKG_OPTIONS_GROUP.window-system= x11 nextstep
PKG_OPTIONS_OPTIONAL_GROUPS+= toolkit
PKG_OPTIONS_GROUP.toolkit= gtk2 gtk3 motif xaw
PKG_SUGGESTED_OPTIONS=	dbus svg x11 xft2

.include "../../mk/bsd.options.mk"

###
### Support D-BUS
###
.  if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-dbus
.  endif

###
### Support XML2
###
.  if !empty(PKG_OPTIONS:Mxml)
USE_TOOLS+=		pkg-config
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.17
.include "../../textproc/libxml2/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-xml2
.  endif

###
### Support GnuTLS
###
.  if !empty(PKG_OPTIONS:Mgnutls)
USE_TOOLS+=		pkg-config
.include "../../security/gnutls/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-gnutls
.  endif

###
### Support SVG
###
.  if !empty(PKG_OPTIONS:Msvg) && empty(PKG_OPTIONS:Mnextstep)
.include "../../graphics/librsvg/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-rsvg
.  endif

###
### Any of the "toolkit" options with no window-system option implies "x11"
###
.if !empty(PKG_OPTIONS:Mgtk2) || !empty(PKG_OPTIONS:Mgtk3) || !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw) || !empty(PKG_OPTIONS:Mxft2)
.  if empty(PKG_OPTIONS:Mx11) && empty(PKG_OPTIONS:Mnextstep)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using GTK if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mgtk2) && empty(PKG_OPTIONS:Mgtk3) && empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
PKG_OPTIONS+=		gtk3
.  endif
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

###
### Enable font backend
###
.  if !empty(PKG_OPTIONS:Mxft2)
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libotf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../devel/m17n-lib/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-xft --without-otf --without-m17n-flt
.  endif

###
### Support using GTK3 X11 widgets.
###
.  if !empty(PKG_OPTIONS:Mgtk3)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk3

###
### Support using GTK2 X11 widgets.
###
.  elif !empty(PKG_OPTIONS:Mgtk2)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk2

###
### Support using Motif X11 widgets.
###
.  elif !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif

###
### Support using Xaw (Lucid) X11 widgets.
###
.  elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.  endif

###
### Support using NextStep (Cocoa or GNUstep) windowing system
###
.elif !empty(PKG_OPTIONS:Mnextstep)
.  if exists(/System/Library/Frameworks/Cocoa.framework)
APPLICATIONS_DIR=	Applications
PLIST_SRC+=		PLIST.cocoa
CHECK_WRKREF_SKIP+=	Applications/Emacs.app/Contents/MacOS/Emacs
.  else
.include "../../x11/gnustep-gui/buildlink3.mk"
MAKE_FILE=		Makefile
APPLICATIONS_DIR=	share/GNUstep/Local/Applications
PLIST_SRC+=		PLIST.gnustep
.  endif
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-ns
CONFIGURE_ARGS+=	--disable-ns-self-contained

INSTALLATION_DIRS+=	${APPLICATIONS_DIR}
USE_TOOLS+=		pax

post-install:
	cd ${WRKSRC}/nextstep && \
		pax -rw -pp -pm Emacs.app ${DESTDIR}${PREFIX}/${APPLICATIONS_DIR}

.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
.endif
