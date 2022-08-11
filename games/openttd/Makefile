# $NetBSD: Makefile,v 1.106 2022/08/11 05:08:33 gutteridge Exp $

DISTNAME=	openttd-12.2-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

# C++17
GCC_REQD+=	8 # std::charconv

BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DPERSONAL_DIR=.openttd
CMAKE_ARGS+=	-DSHARED_DIR=${VARBASE}/games/openttd
CMAKE_ARGS+=	-DGLOBAL_DIR=${PREFIX}/share/openttd
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=bin
CMAKE_ARGS+=	-DCMAKE_INSTALL_DATADIR=share
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Allegro=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Grfcodec=ON

BUILDLINK_TRANSFORM+=	opt:-std=c++17:-std=gnu++17 # alloca
BUILDLINK_TRANSFORM+=	opt:-std=c++1z:-std=gnu++1z # alloca

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
