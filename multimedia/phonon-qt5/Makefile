# $NetBSD: Makefile,v 1.74 2026/01/07 08:48:11 wiz Exp $

DISTNAME=	phonon-4.12.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/4.12.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF5
HOMEPAGE=	https://community.kde.org/Phonon
LICENSE=	gnu-lgpl-v2.1


USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins
CMAKE_CONFIGURE_ARGS+=	-DECM_MKSPECS_INSTALL_DIR=${QTDIR}/mkspecs/modules
CMAKE_CONFIGURE_ARGS+=	-DPHONON_BUILD_QT6=OFF
CMAKE_CONFIGURE_ARGS+=	-DPHONON_BUILD_SETTINGS=OFF

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		cmake-pkgsrc-build/phonon4qt5.pc

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

# locale files conflict with qt6 version
post-install:
	rm -rf ${DESTDIR}${PREFIX}/share

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.10.1nb2
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
