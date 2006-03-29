# $NetBSD: options.mk,v 1.1 2006/03/29 22:14:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.MyPasswordSafe
PKG_SUGGESTED_OPTIONS=	qt3
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=	qt3 # qt4 - not yet

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt3)
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif
