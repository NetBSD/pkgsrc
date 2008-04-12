# $NetBSD: options.mk,v 1.12 2008/04/12 22:43:02 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
PKG_SUPPORTED_OPTIONS=	anthy canna eb gtk qt kde
PKG_SUGGESTED_OPTIONS=	anthy canna gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		helperdata uim-dict-gtk
PLIST_VARS+=		anthy canna gtk kde qt

.if !empty(PKG_OPTIONS:Manthy)
.  include "../../inputmethod/anthy/buildlink3.mk"
CONFIGURE_ARGS+=	--with-anthy --enable-dict
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
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Meb)
.include "../../textproc/eb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-eb
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/modules.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk2
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

.if !empty(PKG_OPTIONS:Mkde)
.  include "../../x11/kdelibs3/buildlink3.mk"
.  include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde-applet=yes
PLIST.kde=		yes
.endif
