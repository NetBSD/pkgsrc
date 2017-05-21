# $NetBSD: options.mk,v 1.33 2017/05/21 09:12:34 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
PKG_SUPPORTED_OPTIONS=	anthy canna curl eb expat ffi gnome gnome3 gtk gtk3 m17nlib openssl prime sj3 sqlite uim-fep wnn4 xim
PKG_SUPPORTED_OPTIONS+=	editline
PKG_OPTIONS_OPTIONAL_GROUPS=	kde qt
PKG_OPTIONS_GROUP.kde=	kde kde3
PKG_OPTIONS_GROUP.qt=	qt qt3
PKG_SUGGESTED_OPTIONS=	anthy expat gtk gtk3 prime uim-fep xim

# Store installed modules
UIM_MODULES=		skk tutcode byeoru latin elatin xmload pyload \
			viqr ipa-x-sampa look ajax-ime social-ime \
			google-cgiapi-jp baidu-olime-jp

CHECK_BUILTIN.editline:=	yes
.include "../../devel/editline/builtin.mk"
CHECK_BUILTIN.editline:=	no
.if !empty(USE_BUILTIN.editline:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS+=	editline
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
.  if !empty(PKG_OPTIONS:Mqt3) || !empty(PKG_OPTIONS:Mkde3)
PKG_FAIL_REASON+=	"'qt' conflict with 'qt3' or 'kde3' option"
.  endif
.endif
.if !empty(PKG_OPTIONS:Mqt3)
.  if !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mkde)
PKG_FAIL_REASON+=	"'qt3' conflict with 'qt' or 'kde' option"
.  endif
.endif

PLIST_VARS+=		helperdata uim-dict-gtk uim-dict-gtk3 uim-dict-helperdata fep
PLIST_VARS+=		anthy curl eb expat ffi gnome gnome3 gtk gtk3 kde kde3 m17nlib openssl qt qt3 sqlite wnn xim
PLIST_VARS+=		canna prime sj3
PLIST_VARS+=		editline

.if !empty(PKG_OPTIONS:Meditline)
PLIST.editline=		yes
.include "../../devel/editline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libedit=${BUILDLINK_PREFIX.editline}
.else
CONFIGURE_ARGS+=	--with-libedit=no
.endif


.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
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
CONFIGURE_ARGS+=	--with-anthy-utf8
PLIST.anthy=		yes
UIM_MODULES+=		anthy anthy-utf8
.else
CONFIGURE_ARGS+=	--without-anthy
.endif

.if !empty(PKG_OPTIONS:Mcanna)
CONFIGURE_ARGS+=	--with-canna
UIM_MODULES+=		canna
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curl
PLIST.curl=		yes
.endif

.if !empty(PKG_OPTIONS:Meb)
.include "../../textproc/eb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-eb
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFBASE}/eb.conf
PLIST.eb=		yes
.endif

# For uim-yahoo-jp
.if !empty(PKG_OPTIONS:Mexpat)
.  include "../../textproc/expat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
PLIST.expat=		yes
UIM_MODULES+=		yahoo-jp
.endif

.if !empty(PKG_OPTIONS:Mffi)
.  include "../../devel/libffi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ffi
PLIST.ffi=		yes
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.  include "../../x11/gnome-panel/buildlink3.mk"
.  include "../../devel/libgnomeui/buildlink3.mk"
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnome-applet
.endif

# No gnome3 packages
#.if !empty(PKG_OPTIONS:Mgnome3)
#.  include "../../x11/gnome-panel/buildlink3.mk"
#.  include "../../devel/libgnomeui/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-gnome3-applet
#PLIST.gnome3=		yes
#.endif

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mgnome)
GTK2_IMMODULES=		YES
.include "../../x11/gtk2/modules.mk"
PLIST.gtk=		yes
.  if !empty(PKG_OPTIONS:Manthy) || !empty(PKG_OPTIONS:Mcanna)
.    if !empty(PKG_OPTIONS:Mcanna)
.      include "../../inputmethod/canna-lib/buildlink3.mk"
.    endif
CONFIGURE_ARGS+=	--enable-dict
PLIST.uim-dict-gtk=	yes
PLIST.uim-dict-helperdata=	yes
.  endif
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if !empty(PKG_OPTIONS:Mgtk3) || !empty(PKG_OPTIONS:Mgnome3)
GTK3_IMMODULES=		YES
.include "../../x11/gtk3/modules.mk"
PLIST.gtk3=		yes
.  if !empty(PKG_OPTIONS:Manthy) || !empty(PKG_OPTIONS:Mcanna)
.    if !empty(PKG_OPTIONS:Mcanna)
.      include "../../inputmethod/canna-lib/buildlink3.mk"
.    endif
CONFIGURE_ARGS+=	--enable-dict
PLIST.uim-dict-gtk3=	yes
PLIST.uim-dict-helperdata=	yes
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkde3)
.  include "../../x11/kdelibs3/buildlink3.mk"
.  include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde-applet
PLIST.kde3=		yes
.endif

.if !empty(PKG_OPTIONS:Mkde)
.  include "../../x11/kdelibs4/buildlink3.mk"
.  include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde4-applet
PLIST.kde=		yes
.else
CONFIGURE_ARGS+=	--disable-kde4-applet
.endif

.if !empty(PKG_OPTIONS:Mm17nlib)
.  include "../../devel/m17n-lib/buildlink3.mk"
DEPENDS+=		{m17n-db>=1.6.5,m17n-contrib-[0-9]*}:../../misc/m17n-db
PLIST.m17nlib=		yes
INSTALL_TEMPLATES+=	INSTALL.m17nlib
DEINSTALL_TEMPLATES+=	DEINSTALL.m17nlib
CHECK_FILES_SKIP+=	${PREFIX}/share/uim/pixmaps/m17n-.*\.png
UIM_MODULES+=		m17nlib
.else
CONFIGURE_ARGS+=	--without-m17nlib
.endif

.if !empty(PKG_OPTIONS:Mqt3) || !empty(PKG_OPTIONS:Mkde3)
.  include "../../x11/qt3-libs/buildlink3.mk"
.  include "../../x11/qt3-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt CXXFLAGS=-lc
PLIST.helperdata=	yes
PLIST.qt3=		yes
.endif

.if !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mkde)
.  include "../../x11/qt4-libs/buildlink3.mk"
.  include "../../x11/qt4-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt4 --with-qt4-immodule
PLIST.helperdata=	yes
PLIST.qt=		yes
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl
# XXX: https://bugs.freedesktop.org/show_bug.cgi?id=30249
#CONFIGURE_ARGS+=	--with-openssl-dir=${SSLBASE:Q}
PLIST.openssl=		yes
.endif

.if !empty(PKG_OPTIONS:Mprime)
CONFIGURE_ARGS+=	--with-prime
PLIST.prime=		yes
UIM_MODULES+=		prime
.endif

.if !empty(PKG_OPTIONS:Msj3)
CONFIGURE_ARGS+=	--with-sj3
PLIST.sj3=		yes
UIM_MODULES+=		sj3
.endif

# For input prediction
.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3
PLIST.sqlite=		yes
.endif

.if !empty(PKG_OPTIONS:Mwnn4)
.  include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wnn
CONFIGURE_ARGS+=	--with-wnn-includes=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/include/wnn
CONFIGURE_ARGS+=	--with-wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
CPPFLAGS+=		-DWNNENVDIR=\"${BUILDLINK_PREFIX.ja-FreeWnn-lib}/share/wnn\"
PLIST.wnn=		yes
UIM_MODULES+=		wnn
.endif

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk
.elif !empty(PKG_OPTIONS:Mgtk3) || !empty(PKG_OPTIONS:Mgnome3)
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk3
.elif !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=	--enable-default-toolkit=qt4
.elif !empty(PKG_OPTIONS:Mqt3) || !empty(PKG_OPTIONS:Mkde3)
CONFIGURE_ARGS+=	--enable-default-toolkit=qt
.endif
