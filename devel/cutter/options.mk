# $NetBSD: options.mk,v 1.3 2014/02/08 12:14:32 obache Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.cutter
PKG_SUPPORTED_OPTIONS=	goffice gstreamer gtk2 libsoup pdf
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	goffice gst gtk pdf soup

###
### PDF support
###
.if !empty(PKG_OPTIONS:Mpdf)
.include "../../devel/pango/buildlink3.mk"
PLIST.pdf=		yes
.endif

###
### goffice support
###
.if !empty(PKG_OPTIONS:Mgoffice)
.include "../../misc/goffice0.8/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-goffice
PLIST.gtk=		yes
PLIST.pdf=		yes
.else
CONFIGURE_ARGS+=	--disable-goffice
.endif

###
### gstreamer support
###
.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer1/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gstreamer
PLIST.gst=		yes
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

###
### gtk2 support
###
.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtktest
PLIST.gtk=		yes
PLIST.pdf=		yes
.else
CONFIGURE_ARGS+=	--disable-gtktest
.endif

###
###
### libsoup support
###
.if !empty(PKG_OPTIONS:Mlibsoup)
.  include "../../net/libsoup24/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libsoup
PLIST.soup=		yes
.else
CONFIGURE_ARGS+=	--disable-libsoup
.endif
