# $NetBSD: options.mk,v 1.3 2019/10/27 14:51:51 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qjackctl
PKG_OPTIONS_REQUIRED_GROUPS= qt
PKG_OPTIONS_GROUP.qt= 	qt5
PKG_SUGGESTED_OPTIONS=	qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=        --with-qt5=${QTDIR}
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.  if ${OPSYS} != "Darwin"
.	include "../../x11/qt5-qtx11extras/buildlink3.mk"
.  endif
.endif
