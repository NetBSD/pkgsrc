# $NetBSD: options.mk,v 1.14 2009/01/09 03:32:08 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
#PKG_SUPPORTED_OPTIONS=	anthy canna curses eb gnome gtk kde m17nlib qt prime sj3 wnn x11
PKG_SUPPORTED_OPTIONS=	anthy canna curses eb gnome gtk kde m17nlib qt prime x11
PKG_SUGGESTED_OPTIONS=	anthy canna curses gtk x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		helperdata uim-dict-gtk
PLIST_VARS+=		anthy canna gnome gtk kde m17nlib prime qt sj3 wnn x11

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../devel/ncurses/buildlink3.mk"	# XXXUEBAYASI setupterm in ncurses is needed
#.include "../../mk/curses.buildlink3.mk"	# XXXUEBAYASI for FEP
.else
.endif

.if !empty(PKG_OPTIONS:Manthy)
.  include "../../inputmethod/anthy/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dict
PLIST.anthy=		yes
.  if !empty(PKG_OPTIONS:Mgtk)
PLIST.helperdata=	yes
PLIST.uim-dict-gtk=	yes
.  endif
.else
CONFIGURE_ARGS+=	--without-anthy
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
PLIST.canna=		yes
.endif

.if !empty(PKG_OPTIONS:Meb)
.include "../../textproc/eb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-eb
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.  include "../../x11/gnome-panel/buildlink3.mk"
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnome-applet
.endif

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mgnome)
.include "../../x11/gtk2/modules.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if !empty(PKG_OPTIONS:Mkde)
.  include "../../x11/kdelibs3/buildlink3.mk"
.  include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde-applet
PLIST.kde=		yes
.endif

.if !empty(PKG_OPTIONS:Mm17nlib)
.  include "../../devel/m17n-lib/buildlink3.mk"
PLIST.m17nlib=		yes
.else
CONFIGURE_ARGS+=	--without-m17nlib
.endif

.if !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mkde)
.  include "../../x11/qt3-libs/buildlink3.mk"
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools
CONFIGURE_ARGS+=	--with-qt CXXFLAGS=-lc
# This option don't work.  Need immodule patch for Qt3(uim-1.4.x not support Qt4)
#CONFIGURE_ARGS+=	--with-qt-immodule
PLIST.helperdata=	yes
PLIST.qt=		yes
.endif

.if !empty(PKG_OPTIONS:Mprime)
.  include "../../inputmethod/prime/buildlink3.mk"
CONFIGURE_ARGS+=	--with-prime
PLIST.prime=		yes
.endif

#.if !empty(PKG_OPTIONS:Msj3)
#.  include "../../inputmethod/sj3-lib/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-sj3
#CONFIGURE_ARGS+=	SJ3_CFLAGS=-I${BUILDLINK_PREFIX.sj3-lib}/includes
#CONFIGURE_ARGS+=	SJ3_LIBS="-L${BUILDLINK_PREFIX.sj3-lib}/lib -lsj3lib"
#PLIST.sj3=		yes
#.endif

#.if !empty(PKG_OPTIONS:Mwnn)
#.  include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-wnn
#CONFIGURE_ARGS+=	--with-wnn-includes=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/include/wnn
#CONFIGURE_ARGS+=	--with-wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
#PLIST.wnn=		yes
#.endif
