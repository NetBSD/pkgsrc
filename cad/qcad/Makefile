# $NetBSD: Makefile,v 1.132 2026/01/07 08:45:58 wiz Exp $

DISTNAME=		qcad-3.32.3.4
PKGREVISION=		2
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=qcad/}
EXTRACT_USING=		bsdtar
GITHUB_TAG=		v${PKGVERSION_NOREV}

GITHUB_SUBMODULES=	qcad qtjsapi ${GITHUB_TAG} src/qtjsapi \
			qcad qcadjsapi ${GITHUB_TAG} src/qcadjsapi

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.qcad.org/
COMMENT=		2D CAD system
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		cmake find pax
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	scripts/Help/ShowReadme/ShowReadme.js
SUBST_FILES.paths+=	src/core/RS.cpp src/core/RSettings.cpp
SUBST_VARS.paths=	PREFIX

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications \
			share/icons/hicolor/scalable/apps \
			share/icons/hicolor/512x512/apps \
			share/icons/hicolor/256x256/apps \
			share/icons/hicolor/64x64/apps \
			lib/qcad/plugins/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/qcad \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qcad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qcad.svg
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/qcad.svg
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/qcad.png
	${INSTALL_DATA} ${WRKSRC}/scripts/qcad_icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/qcad.png
	${INSTALL_DATA} ${WRKSRC}/support/doc/api/qcad_icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps/qcad.png
	${INSTALL_MAN} ${WRKSRC}/qcad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/src/qcad/plugins/libqcadjsapi.so \
	    ${DESTDIR}${PREFIX}/lib/${PKGBASE}/plugins
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/src/qtjsapi/out/libqtjsapi.so \
	    ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/${CMAKE_BUILD_DIR}/release && ${PAX} -rwpm \
	    lib*.so ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ${PAX} -rwpm plugins \
	    ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	${FIND} ${WRKSRC}/scripts \( -name \*.orig -or -name .gitignore \) -delete
	cd ${WRKSRC} && ${PAX} -rwpm \
	    fonts linetypes patterns scripts themes ts \
	    ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	cd ${WRKSRC} && ${PAX} -rwpm \
	    readme.txt examples libraries \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
