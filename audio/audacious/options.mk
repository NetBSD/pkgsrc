# $NetBSD: options.mk,v 1.4 2022/05/18 15:09:55 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS+=		gtk2 qt5 dbus
PKG_SUGGESTED_OPTIONS+=		gtk2 qt5 dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus
.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
USE_TOOLS+=	gdbus-codegen
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

PLIST_VARS+=	gtk2
.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk2+=	yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

PLIST_VARS+=	qt5
.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5+=	yes
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.if empty(PKG_OPTIONS:Mgtk2) && empty(PKG_OPTIONS:Mqt5)
PKG_FAIL_REASON+=	"Must select at least one GUI option!"
.endif
