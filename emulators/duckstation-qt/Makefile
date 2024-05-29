# $NetBSD: Makefile,v 1.6 2024/05/29 16:32:26 adam Exp $

PKGREVISION= 4
.include "../../emulators/duckstation-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/duckstation-/duckstation-qt-/g}
COMMENT=	PlayStation emulator aiming for the best accuracy (Qt version)

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/duckstation
INSTALLATION_DIRS+=	share/duckstation/translations
INSTALLATION_DIRS+=	share/pixmaps

NOT_PAX_MPROTECT_SAFE+=	bin/duckstation-qt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/bin/duckstation-qt \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/duckstation-qt.desktop \
		${DESTDIR}${PREFIX}/share/applications/duckstation-qt.desktop
	${INSTALL_DATA} ${WRKSRC}/data/resources/images/duck.png \
		${DESTDIR}${PREFIX}/share/pixmaps/duckstation.png
	cd ${WRKSRC}/data/resources && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/duckstation
	cd ${WRKSRC}/${CMAKE_BUILD_DIR}/bin/translations && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/duckstation/translations

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
