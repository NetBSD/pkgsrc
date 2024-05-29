# $NetBSD: Makefile,v 1.28 2024/05/29 16:31:25 adam Exp $

DISTNAME=	spotify-qt-3.11
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kraxarn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kraxarn/spotify-qt/
COMMENT=	Lightweight Spotify client using Qt
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

DEPENDS+=	librespot-[0-9]*:../../audio/librespot

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
