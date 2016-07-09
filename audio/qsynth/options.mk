# $NetBSD: options.mk,v 1.2 2016/07/09 11:46:04 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qsynth
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt= 	qt4 qt5
PKG_SUGGESTED_OPTIONS=	qt4
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=        --with-qt5=${QTDIR}
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.  if ${OPSYS} != "Darwin"
.	include "../../x11/qt5-qtx11extras/buildlink3.mk"
.  endif
.endif

.if !empty(PKG_OPTIONS:Mqt4)
CONFIGURE_ARGS+=        --with-qt4=${QTDIR}
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif
