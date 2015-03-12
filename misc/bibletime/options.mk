# $NetBSD: options.mk,v 1.1 2015/03/12 13:54:30 nros Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bibletime
PKG_OPTIONS_REQUIRED_GROUPS= 	qt
PKG_OPTIONS_GROUP.qt=		qt4 qt5
PKG_SUGGESTED_OPTIONS=		qt4
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif
