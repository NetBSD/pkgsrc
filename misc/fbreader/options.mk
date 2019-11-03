# $NetBSD: options.mk,v 1.4 2019/11/03 17:04:21 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fbreader
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk2 qt4
PKG_SUPPORTED_OPTIONS=		debug
PKG_SUGGESTED_OPTIONS=		qt4

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

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
MAKE_ENV+=	UI_TYPE=qt4
.endif
