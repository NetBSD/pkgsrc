# $NetBSD: Makefile,v 1.5 2020/04/12 08:28:45 adam Exp $

DISTNAME=	openrct2-0.2.4
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenRCT2/}
GITHUB_PROJECT=	OpenRCT2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenRCT2/OpenRCT2/
COMMENT=	Open source reimplementation of RollerCoaster Tycoon 2
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++17

# C++17
GCC_REQD+=	7

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

CXXFLAGS+=	-DORCT2_RESOURCE_DIR=\"${PREFIX}/share/openrct2\"

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
