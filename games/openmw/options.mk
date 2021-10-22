# $NetBSD: options.mk,v 1.3 2021/10/22 22:43:11 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openmw
PKG_SUPPORTED_OPTIONS=		qt5
PKG_SUGGESTED_OPTIONS=		qt5

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gui

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.gui=	yes
CMAKE_ARGS+=	-DDESIRED_QT_VERSION=5
CONF_FILES+=	${EGDIR}/defaults-cs.bin ${PKG_SYSCONFDIR}/defaults-cs.bin
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_LAUNCHER=OFF
CMAKE_ARGS+=	-DBUILD_OPENCS=OFF
CMAKE_ARGS+=	-DBUILD_WIZARD=OFF
.endif
