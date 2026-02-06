# $NetBSD: Makefile,v 1.3 2026/02/06 10:05:28 wiz Exp $

DISTNAME=	phonon-4.12.0
PKGNAME=	${DISTNAME:S/-/-qt6-/}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/4.12.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF6
HOMEPAGE=	https://community.kde.org/Phonon
LICENSE=	gnu-lgpl-v2.1


USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins
CMAKE_CONFIGURE_ARGS+=	-DECM_MKSPECS_INSTALL_DIR=${QTDIR}/mkspecs/modules
CMAKE_CONFIGURE_ARGS+=	-DPHONON_BUILD_QT5=OFF

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		cmake-pkgsrc-build/phonon4qt6.pc

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
