# $NetBSD: options.mk,v 1.8 2014/11/27 15:32:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kchmviewer
PKG_SUPPORTED_OPTIONS=	kde4

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
