# $NetBSD: options.mk,v 1.2 2014/12/02 12:16:29 mef Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.texmaker
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt = qt4 qt5
PKG_SUGGESTED_OPTIONS=	qt4
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.endif
