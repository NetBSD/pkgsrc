# $NetBSD: options.mk,v 1.1 2016/03/09 23:21:29 nros Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qconf
PKG_OPTIONS_REQUIRED_GROUPS= 	qt
PKG_OPTIONS_GROUP.qt =		qt4 qt5
PKG_SUGGESTED_OPTIONS=		qt4
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-tools/buildlink3.mk"
.endif
