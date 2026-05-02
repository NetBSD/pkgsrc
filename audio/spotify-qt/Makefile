# $NetBSD: Makefile,v 1.43 2026/05/02 18:17:51 pin Exp $

DISTNAME=	spotify-qt-4.0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kraxarn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kraxarn/spotify-qt/
COMMENT=	Lightweight Spotify client using Qt
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

DEPENDS+=	librespot-[0-9]*:../../audio/librespot

.include "../../devel/cmake/build.mk"

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
