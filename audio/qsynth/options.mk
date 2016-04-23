# $NetBSD: options.mk,v 1.1 2016/04/23 12:32:47 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qsynth
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt = 	qt4 qt5
PKG_SUGGESTED_OPTIONS=	qt4
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=        --with-qt5=${QTDIR:Q}
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.	include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.endif

.if !empty(PKG_OPTIONS:Mqt4)
CONFIGURE_ARGS+=        --with-qt4=${QTDIR:Q}
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif
