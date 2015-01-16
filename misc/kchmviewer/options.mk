# $NetBSD: options.mk,v 1.9 2015/01/16 10:46:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kchmviewer
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=	qt4 kde4 qt5
PKG_SUGGESTED_OPTIONS=	qt5

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		kde4
.if !empty(PKG_OPTIONS:Mkde4)
USE_CMAKE=		yes
USE_TOOLS+=		msgfmt
BUILD_DEPENDS+=		automoc4-[0-9]*:../../devel/automoc4
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
PLIST.kde4=		yes
.else

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake
	cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake
	cd ${WRKSRC}/lib/libebook && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kchmviewer ${DESTDIR}${PREFIX}/bin
.endif

.if !empty(PKG_OPTIONS:Mqt4)
BUILDLINK_API_DEPENDS.qt4-libs+=        qt4-libs>=4.5.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif
