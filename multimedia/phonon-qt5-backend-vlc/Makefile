# $NetBSD: Makefile,v 1.43 2024/05/29 16:33:47 adam Exp $

DISTNAME=	phonon-backend-vlc-0.11.2
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-vlc/0.11.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF5 - VLC backend
HOMEPAGE=	https://community.kde.org/Phonon
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

CMAKE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../multimedia/vlc/buildlink3.mk"
TOOL_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
