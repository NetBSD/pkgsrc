# $NetBSD: Makefile,v 1.60 2024/05/29 16:32:42 adam Exp $

PKGNAME=	openrct2-0.4.11
PKGREVISION=	2
CATEGORIES=	games

DIST_SUBDIR=	openrct2-${PKGVERSION_NOREV}

DISTFILES=	openrct.tar.gz
DISTFILES+=	title-sequences.zip
DISTFILES+=	objects.zip
DISTFILES+=	opensound.zip
DISTFILES+=	openmusic.zip
DISTFILES+=	replays.zip

EXTRACT_ONLY+=	openrct.tar.gz

SITES.openrct.tar.gz= \
	-https://github.com/OpenRCT2/OpenRCT2/archive/refs/tags/v${PKGVERSION_NOREV}.tar.gz

# these versions come from CMakeLists.txt

SITES.title-sequences.zip= \
	https://github.com/OpenRCT2/title-sequences/releases/download/v0.4.6/

SITES.objects.zip= \
	https://github.com/OpenRCT2/objects/releases/download/v1.4.4/

SITES.opensound.zip= \
	https://github.com/OpenRCT2/OpenSoundEffects/releases/download/v1.0.5/

SITES.openmusic.zip= \
	https://github.com/OpenRCT2/OpenMusic/releases/download/v1.5/

SITES.replays.zip= \
	https://github.com/OpenRCT2/replays/releases/download/v0.0.79/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenRCT2/OpenRCT2/
COMMENT=	Open source reimplementation of RollerCoaster Tycoon 2
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/OpenRCT2-${PKGVERSION_NOREV}

USE_TOOLS+=	pkg-config unzip
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER_AR="/usr/bin/ar"
CMAKE_ARGS+=	-DDISABLE_DISCORD_RPC=ON
CMAKE_ARGS+=	-DDISABLE_GOOGLE_BENCHMARK=ON
CMAKE_ARGS+=	-DMACOS_USE_DEPENDENCIES=OFF
CMAKE_ARGS+=	-DMACOS_BUNDLE=OFF

CMAKE_ARGS+=	-DDOWNLOAD_TITLE_SEQUENCES=OFF
CMAKE_ARGS+=	-DDOWNLOAD_OBJECTS=OFF
CMAKE_ARGS+=	-DDOWNLOAD_OPENSFX=OFF
CMAKE_ARGS+=	-DDOWNLOAD_OPENMSX=OFF

CXXFLAGS+=	-DORCT2_RESOURCE_DIR=\"${PREFIX}/share/openrct2\"

USE_CXX_FEATURES=	c++20

CHECK_WRKREF_SKIP+=	share/*

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		doc
SUBST_STAGE.doc=	pre-configure
SUBST_MESSAGE.doc=	Fixing documentation path.
SUBST_FILES.doc=	src/openrct2/platform/Platform.macOS.mm
SUBST_VARS.doc=		PREFIX

post-extract:
	unzip -d ${WRKSRC}/data/object ${DISTDIR}/${DIST_SUBDIR}/objects.zip
	unzip -d ${WRKSRC}/data/sequence ${DISTDIR}/${DIST_SUBDIR}/title-sequences.zip
	unzip -d ${WRKSRC}/data ${DISTDIR}/${DIST_SUBDIR}/opensound.zip
	unzip -d ${WRKSRC}/data ${DISTDIR}/${DIST_SUBDIR}/openmusic.zip
	unzip -d ${WRKSRC}/test/tests/testdata/replays \
		${DISTDIR}/${DIST_SUBDIR}/replays.zip

.include "../../devel/cmake/build.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
