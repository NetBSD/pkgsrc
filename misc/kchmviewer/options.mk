# $NetBSD: options.mk,v 1.4 2009/10/02 22:45:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kchmviewer
PKG_SUPPORTED_OPTIONS=	kde4

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		kde4
.if !empty(PKG_OPTIONS:Mkde4)
USE_CMAKE=		yes
BUILD_DEPENDS+=		automoc4-[0-9]*:../../devel/automoc4
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
PLIST.kde4=		yes
.else

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kchmviewer ${DESTDIR}${PREFIX}/bin
.endif
