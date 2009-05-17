# $NetBSD: options.mk,v 1.16 2009/05/17 05:06:02 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
#PKG_SUPPORTED_OPTIONS=	anthy canna eb gnome gtk kde m17nlib qt prime sj3 uim-fep wnn xim
PKG_SUPPORTED_OPTIONS=	anthy canna eb gnome gtk kde m17nlib qt prime uim-fep xim
PKG_SUGGESTED_OPTIONS=	anthy canna gtk uim-fep xim

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		helperdata uim-dict-gtk fep
PLIST_VARS+=		anthy canna gnome gtk kde m17nlib prime qt sj3 wnn xim

.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
PLIST.xim=		yes
.else
SUBST_CLASSES+=		xim
SUBST_STAGE.xim=	pre-configure
SUBST_FILES.xim=	configure
SUBST_SED.xim=		-e 's;use_xim="yes";use_xim="no";g'
.endif

.if !empty(PKG_OPTIONS:Muim-fep)
USE_NCURSES=		YES	# setupterm, clear_screen, clr_eos
.include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fep
PLIST.fep=		yes
.else
CONFIGURE_ARGS+=	--disable-fep
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
.  include "../../devel/libgnomeui/buildlink3.mk"
CFLAGS+=		-I$(BUILDLINK_PREFIX.libgnomeui)/include/libgnomeui-2.0
BUILDLINK_TRANSFORM+=	l:panel-applet-2:panel-applet-2:gnomeui-2
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnome-applet
.endif

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mgnome)
GTK2_IMMODULES=		YES
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
.  include "../../x11/qt3-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt CXXFLAGS=-lc
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
