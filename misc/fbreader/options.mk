# $NetBSD: options.mk,v 1.2 2012/10/01 12:40:36 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fbreader
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=	gtk2 qt3 qt4 # qt3 is untested
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	qt4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_ENV+=	TARGET_STATUS=debug
.else
MAKE_ENV+=	TARGET_STATUS=release
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
MAKE_ENV+=	UI_TYPE=gtk
USE_TOOLS+=	pkg-config
.endif

.if !empty(PKG_OPTIONS:Mqt3)
.include "../../x11/qt3-libs/buildlink3.mk"
MAKE_ENV+=	UI_TYPE=qt
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
MAKE_ENV+=	UI_TYPE=qt4
.endif
