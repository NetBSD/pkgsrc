# $NetBSD: options.mk,v 1.1 2014/11/18 13:20:35 mef Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.texmaker
PKG_SUPPORTED_OPTIONS=	qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.else
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.endif
