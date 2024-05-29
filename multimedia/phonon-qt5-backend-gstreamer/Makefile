# $NetBSD: Makefile,v 1.44 2024/05/29 16:33:47 adam Exp $

DISTNAME=	phonon-backend-gstreamer-4.10.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-gstreamer/4.10.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Phonon
COMMENT=	Multimedia API for KF5 - GStreamer backend
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

CMAKE_ARGS+=	-DKDE_INSTALL_QTPLUGINDIR=${QTDIR}/plugins

#WRKSRC=		${WRKDIR}/phonon-gstreamer-4.9.1

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"

TOOL_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules
DEPENDS+=	phonon-backend-gstreamer-shared-${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
