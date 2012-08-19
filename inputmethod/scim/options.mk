# $NetBSD: options.mk,v 1.1 2012/08/19 08:09:08 obache Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.scim
PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk gtk3
PKG_SUPPORTED_OPTIONS=		qt
PKG_SUGGESTED_OPTIONS=		gtk

PLIST_VARS+=	gtk2 gtk3 qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
GTK2_IMMODULES=		yes
.include "../../x11/gtk2/modules.mk"
CONFIGURE_ARGS+=	--enable-gtk2-immodule
PLIST.gtk2=		yes
.else
CONFIGURE_ARGS+=	--enable-gtk2-immodule=no
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
GTK3_IMMODULES=		yes
.include "../../x11/gtk3/modules.mk"
CONFIGURE_ARGS+=	--enable-gtk3-immodule
PLIST.gtk3=		yes
.else
CONFIGURE_ARGS+=	--enable-gtk3-immodule=no
.endif

#.if !empty(PKG_OPTIONS:Mqt3)
#.include "../../x11/qt3-libs/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-qt3-immodule
#PLIST.qt=		yes
#.else
#CONFIGURE_ARGS+=	--disable-qt3-immodule
#.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-qt4-immodule
CONFIGURE_ARGS+=	--with-qt4-im-module-dir=${QTDIR}/plugins/inputmethods
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--disable-qt4-immodule
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--with-gtk-version=3
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gtk-version=2
.include "../../x11/gtk2/buildlink3.mk"
.endif
