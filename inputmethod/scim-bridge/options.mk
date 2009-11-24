# $NetBSD: options.mk,v 1.1.1.1 2009/11/24 11:49:44 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.scim-bridge
PKG_SUPPORTED_OPTIONS=	gtk qt
PKG_SUGGESTED_OPTIONS=	gtk

PLIST_VARS+=	gtk qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
GTK2_IMMODULES=		yes
.include "../../x11/gtk2/modules.mk"
CONFIGURE_ARGS+=	--enable-gtk2-immodule
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--enable-gtk2-immodule=no
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
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--disable-qt4-immodule
.endif
