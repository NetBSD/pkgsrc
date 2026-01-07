# $NetBSD: Makefile,v 1.54 2026/01/07 08:48:11 wiz Exp $

DISTNAME=	phonon-backend-vlc-0.12.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-vlc/0.12.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF5 - VLC backend
HOMEPAGE=	https://community.kde.org/Phonon
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins
CMAKE_CONFIGURE_ARGS+=	-DPHONON_BUILD_QT6=OFF

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

# locale files conflict with qt6 version
post-install:
	rm -rf ${DESTDIR}${PREFIX}/share

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../multimedia/vlc/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
