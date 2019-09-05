# $NetBSD: options.mk,v 1.5 2019/09/05 08:07:25 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.texmaker
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt= qt5
PKG_SUGGESTED_OPTIONS=	qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif
