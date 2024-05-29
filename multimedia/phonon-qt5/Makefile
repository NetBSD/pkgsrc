# $NetBSD: Makefile,v 1.62 2024/05/29 16:33:47 adam Exp $

DISTNAME=	phonon-4.11.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	20
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/4.11.1/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF5
HOMEPAGE=	https://community.kde.org/Phonon
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
CMAKE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins
CMAKE_ARGS+=	-DECM_MKSPECS_INSTALL_DIR=${QTDIR}/mkspecs/modules

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		_build/phonon4qt5.pc

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

TOOL_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

BUILDLINK_ABI_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.10.1nb2
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
