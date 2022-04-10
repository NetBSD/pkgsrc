# $NetBSD: options.mk,v 1.3 2022/04/10 22:42:26 tnn Exp $

### Set options
PKG_OPTIONS_VAR=			PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=			dbus gnutls imagemagick jansson svg xaw3d xml
# xaw3d is only valid with tookit = xaw

PKG_OPTIONS_OPTIONAL_GROUPS+=		window-system
PKG_OPTIONS_GROUP.window-system=	x11 nextstep

PKG_OPTIONS_OPTIONAL_GROUPS+=		toolkit
PKG_SUGGESTED_OPTIONS.Darwin=		nextstep
#  --with-x-toolkit=KIT    use an X toolkit (KIT one of: yes or gtk2,
#                          gtk3, xaw or lucid or athena, motif, no)
# gtk in next line implies gtk2, xaw = athena = lucid
PKG_OPTIONS_GROUP.toolkit=		gtk gtk2 gtk3 motif xaw
# gtk2 and gtk has the same effect
# gtk3 is default in the logic below (even not included in SUGGESTED_=)
# gtk* will be ignored for nextstep even shown as selected.

# imagemagick is disabled because of stability/security
# svg is omitted because it is rarely needed and heavyweight due to the rust dependency
# xaw3d is omitted because it is only valid with xaw
PKG_SUGGESTED_OPTIONS=	dbus gnutls gtk3 jansson xml x11

.include "../../mk/bsd.options.mk"

### ---	 Check window-system independent options first
###
### Support D-BUS
###
.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

###
### Support JSON
###
.if !empty(PKG_OPTIONS:Mjansson)
.  include "../../textproc/jansson/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-json
.endif

###
### Support XML2
###
.if !empty(PKG_OPTIONS:Mxml)
USE_TOOLS+=		pkg-config
BUILDLINK_API_DEPENDS.libxml2+= libxml2>=2.6.17
.include "../../textproc/libxml2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xml2
.endif

###
### Support gnutls
###
.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

###
### Check non nextstep (implies x11) options
###
### x11 is selected (as SUGGESTED above)
###
.if !empty(PKG_OPTIONS:Mx11)
###
### on OSX the configure script will select the "nextstep" window system
### unless you explicitly tell it not to.  this should not impact other
### platforms.
###
CONFIGURE_ARGS+=	--without-ns

###
### Support SVG
###
.  if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-rsvg
.  endif

###
### Support ImageMagick (not recognized for now, sorry)
###
.  if !empty(PKG_OPTIONS:Mimagemagick)
.include "../../graphics/ImageMagick/buildlink3.mk"
# DEPENDS+=	py[0-9]*-wand-[0-9]*:../../graphics/py-wand
.  else
CONFIGURE_ARGS+=	--without-imagemagick
.  endif

###
### Support Xaw3d (This is only valid with Lucid Toolkit)
###
.  if !empty(PKG_OPTIONS:Mxaw3d)
.include "../../x11/libXaw3d/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-xaw3d
.  endif

###
### Toolkit selection
###
.  if (empty(PKG_OPTIONS:Mxaw) && \
       empty(PKG_OPTIONS:Mgtk) && \
       empty(PKG_OPTIONS:Mgtk2) && \
       empty(PKG_OPTIONS:Mmotif))
# defaults to gtk3
USE_TOOLS+=		pkg-config
.include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk3
.  elif !empty(PKG_OPTIONS:Mgtk2) || !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk2
.  elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.  elif !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.  endif

###
### End of Check non nextstep (implies x11) options

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"


###
### Support using NextStep (Cocoa or GNUstep) windowing system
###
#  If you check the variable system-configuration-options after Emacs is
#  built, you may see many x11 related configurations. But if you have
#  --without-x there, all other x11 related configurations were ignored.
#
.elif !empty(PKG_OPTIONS:Mnextstep)
.  if exists(/System/Library/Frameworks/Cocoa.framework)
APPLICATIONS_DIR=	Applications
PLIST_SRC+=		PLIST.cocoa
CHECK_WRKREF_SKIP+=	Applications/Emacs.app/Contents/MacOS/Emacs
CHECK_WRKREF_SKIP+=	Applications/Emacs.app/Contents/MacOS/libexec/Emacs.pdmp
.  else
.include "../../x11/gnustep-gui/buildlink3.mk"
MAKE_FILE=		Makefile
APPLICATIONS_DIR=	share/GNUstep/Local/Applications
PLIST_SRC+=		PLIST.gnustep
CHECK_WRKREF_SKIP+=	share/GNUstep/Local/Applications/Emacs.app/Emacs
.  endif
# more args for nextstep
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-ns
CONFIGURE_ARGS+=	--disable-ns-self-contained

INSTALLATION_DIRS+=	${APPLICATIONS_DIR}
USE_TOOLS+=		pax

post-install:
	cd ${WRKSRC}/nextstep && \
		pax -rw -pp -pm Emacs.app ${DESTDIR}${PREFIX}/${APPLICATIONS_DIR}

.else  # no window system
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
.endif

# Local Variables:
# mode: outline-minor
# outline-regexp: "\\(.[ \t]*\\(if\\|endif\\|else\\|elif\\|include.*options\\|PKG_SUGGES\\)\\)\\|### .\\|# Local"
# End:
