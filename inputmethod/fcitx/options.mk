# $NetBSD: options.mk,v 1.1 2019/04/27 03:20:32 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx

PKG_SUPPORTED_OPTIONS+=	qt4
PLIST_VARS+=		qt4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt4)
BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4
CMAKE_ARGS+=	-DENABLE_QT_IM_MODULE=ON
CMAKE_ARGS+=	-DENABLE_QT_GUI=ON
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
PLIST.qt4=	yes
.else
CMAKE_ARGS+=	-DENABLE_QT=OFF
CMAKE_ARGS+=	-DENABLE_QT_IM_MODULE=OFF
CMAKE_ARGS+=	-DENABLE_QT_GUI=OFF
.endif
