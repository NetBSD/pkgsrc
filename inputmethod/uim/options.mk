# $NetBSD: options.mk,v 1.19 2010/02/15 13:56:17 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
#PKG_SUPPORTED_OPTIONS=	anthy canna eb gnome gtk m17nlib prime sj3 uim-fep wnn xim
PKG_SUPPORTED_OPTIONS=	anthy canna eb gnome gtk m17nlib prime sj3 uim-fep xim
PKG_OPTIONS_OPTIONAL_GROUPS=	kde qt
PKG_OPTIONS_GROUP.kde=	kde kde4
PKG_OPTIONS_GROUP.qt=	qt qt4
PKG_SUGGESTED_OPTIONS=	anthy canna gtk uim-fep xim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt4)
.  if !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mkde)
PKG_FAIL_REASON+=	"'qt4' conflict with 'qt' or 'kde' option"
.  endif
.endif
.if !empty(PKG_OPTIONS:Mqt)
.  if !empty(PKG_OPTIONS:Mqt4) || !empty(PKG_OPTIONS:Mkde4)
PKG_FAIL_REASON+=	"'qt' conflict with 'qt4' or 'kde4' option"
.  endif
.endif

PLIST_VARS+=		helperdata uim-dict-gtk fep
PLIST_VARS+=		anthy canna gnome gtk kde kde4 m17nlib prime qt qt4 sj3 wnn xim

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
INSTALLATION_DIRS+=	share/doc/uim/uim-fep

post-install: install-fep-doc

.PHONY: install-fep-doc
install-fep-doc:
	${INSTALL_DATA} ${WRKSRC}/fep/README ${DESTDIR}${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${DESTDIR}${PREFIX}/share/doc/uim/uim-fep
.else
CONFIGURE_ARGS+=	--disable-fep
.endif

.if !empty(PKG_OPTIONS:Manthy)
.  include "../../inputmethod/anthy/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dict --with-anthy-utf8
PLIST.anthy=		yes
.  if !empty(PKG_OPTIONS:Mgtk)
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
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf
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

.if !empty(PKG_OPTIONS:Mkde4)
.  include "../../x11/kdelibs4/buildlink3.mk"
.  include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde4-applet
PLIST.kde4=		yes
.else
CONFIGURE_ARGS+=	--disable-kde4-applet
.endif

.if !empty(PKG_OPTIONS:Mm17nlib)
.  include "../../devel/m17n-lib/buildlink3.mk"
DEPENDS+=		m17n-contrib-[0-9]*:../../misc/m17n-contrib
PLIST.m17nlib=		yes
INSTALL_TEMPLATES+=	INSTALL.m17nlib
DEINSTALL_TEMPLATES+=	DEINSTALL.m17nlib
CHECK_FILES_SKIP+=	${PREFIX}/share/uim/pixmaps/m17n-.*\.png
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

.if !empty(PKG_OPTIONS:Mqt4) || !empty(PKG_OPTIONS:Mkde4)
.  include "../../x11/qt4-libs/buildlink3.mk"
.  include "../../x11/qt4-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt4 --with-qt4-immodule
PLIST.helperdata=	yes
PLIST.qt4=		yes
.endif

.if !empty(PKG_OPTIONS:Mprime)
.  include "../../inputmethod/prime/buildlink3.mk"
CONFIGURE_ARGS+=	--with-prime
PLIST.prime=		yes
.endif

.if !empty(PKG_OPTIONS:Msj3)
.  include "../../inputmethod/sj3-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sj3
CONFIGURE_ARGS+=	SJ3_CFLAGS=-I${BUILDLINK_PREFIX.sj3-lib}/includes
CONFIGURE_ARGS+=	SJ3_LIBS="-L${BUILDLINK_PREFIX.sj3-lib}/lib -lsj3lib"
PLIST.sj3=		yes
.endif

#.if !empty(PKG_OPTIONS:Mwnn)
#.  include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-wnn
#CONFIGURE_ARGS+=	--with-wnn-includes=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/include/wnn
#CONFIGURE_ARGS+=	--with-wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
#PLIST.wnn=		yes
#.endif
