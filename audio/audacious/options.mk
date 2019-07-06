# $NetBSD: options.mk,v 1.1 2019/07/06 13:17:00 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacious
PKG_OPTIONS_OPTIONAL_GROUPS=	ui
PKG_OPTIONS_GROUP.ui=		qt5 gtk2
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_SUGGESTED_OPTIONS+=		dbus qt5 gtk2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus gtk qt

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes
CONFIGURE_ARGS+=	--enable-qt
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk=	yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
