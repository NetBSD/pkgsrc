# $NetBSD: Makefile,v 1.6 2014/02/01 02:07:11 markd Exp $

DISTNAME=	phonon-backend-vlc-0.7.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-vlc/0.7.1/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://phonon.kde.org/
COMMENT=	Multimedia API for KDE and QT - VLC backend
LICENSE=	gnu-lgpl-v2.1

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
#CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../multimedia/vlc2/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
