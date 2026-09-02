# $NetBSD: Makefile,v 1.55 2026/09/02 19:02:25 wiz Exp $

# use file name generated when clicking on the 'Source code' download
# link at https://www.widelands.org/wiki/Download/
DISTNAME=	widelands-v1.3.1
PKGNAME=	${DISTNAME:S/-v/-/}
PKGREVISION=	3
CATEGORIES=	games
# direct links time out
#MASTER_SITES=	-https://codeberg.org/wl/widelands/archive/v1.3.1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.widelands.org/
COMMENT=	Fantasy real-time strategy game inspired by Settlers II
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_BASEDIR=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_DATADIR=${PREFIX}/share/widelands
CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_BINDIR=${PREFIX}/bin

# Silence spam from asio headers
BUILDLINK_TRANSFORM+=	rm:-Wold-style-cast

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/widelands

WRKSRC=		${WRKDIR}/widelands

.include "../../mk/bsd.prefs.mk"

post-install:
	${MV}	${DESTDIR}${PREFIX}/VERSION \
		${DESTDIR}${PREFIX}/ChangeLog \
		${DESTDIR}${PREFIX}/CREDITS \
		${DESTDIR}${PREFIX}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/widelands

.include "../../archivers/minizip/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/asio/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
