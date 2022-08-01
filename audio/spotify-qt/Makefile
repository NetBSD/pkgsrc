# $NetBSD: Makefile,v 1.15 2022/08/01 08:12:45 pin Exp $

DISTNAME=	spotify-qt-3.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kraxarn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kraxarn/spotify-qt/
COMMENT=	Lightweight Spotify client using Qt
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	librespot-[0-9]*:../../audio/librespot

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
