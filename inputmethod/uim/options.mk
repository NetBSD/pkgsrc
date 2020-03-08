# $NetBSD: options.mk,v 1.37 2020/03/08 08:59:08 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
PKG_SUPPORTED_OPTIONS=	gtk2 gtk3 qt5 xim
PKG_SUGGESTED_OPTIONS=	gtk2 gtk3 qt5 xim

PKG_OPTIONS_LEGACY_OPTS+=	gtk:gtk2

.include "../../mk/bsd.options.mk"

PLIST_SRC+=		PLIST

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST_SRC+=		PLIST.gtk2
GTK2_IMMODULES=		YES
.include "../../x11/gtk2/modules.mk"
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST_SRC+=		PLIST.gtk3
GTK3_IMMODULES=		YES
.include "../../x11/gtk3/modules.mk"
.else
CONFIGURE_ARGS+=	--without-gtk3
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk3
UIM_PREF_PROGRAM=	uim-pref-gtk3
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk
UIM_PREF_PROGRAM=	uim-pref-gtk
.endif

.if !empty(PKG_OPTIONS:Mqt5)
PLIST_SRC+=		PLIST.qt5
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt5-immodule
.else
CONFIGURE_ARGS+=	--without-qt5-immodule
.endif

.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.else
SUBST_CLASSES+=		xim
SUBST_STAGE.xim=	pre-configure
SUBST_FILES.xim=	configure
SUBST_SED.xim=		-e 's;use_xim="yes";use_xim="no";g'
.endif
