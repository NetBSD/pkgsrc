# $NetBSD: Makefile,v 1.24 2026/09/02 19:02:57 wiz Exp $

# not a release, but we want the change fixing the build with libjxl 0.12.0
DISTNAME=	moderncore-20260719
PKGNAME=	${DISTNAME:S/moderncore-/vv-3.2./}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=wolfpld/}
GITHUB_PROJECT=	moderncore
#GITHUB_TAG=	${DISTNAME:S/moderncore-//}
GITHUB_TAG=	5b775746c6d152cd3cfc2896576ec888a30d4b73

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wolfpld/moderncore/
COMMENT=	View images in your terminal
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20
# needs <format> which was added in 13, despite being in C++ 20
GCC_REQD+=		13
USE_TOOLS+=		git pkg-config
INSTALLATION_DIRS+=	share/doc/vv

# https://github.com/wolfpld/vv/issues/14#issuecomment-2660992164
JPEG_ACCEPTED=		libjpeg-turbo

# 'master' as of 2026-07-04
GITHUB_SUBMODULES+=	wolfpld tracy 853fff614eb2deffd7c86853b517c8021a3efd1f tracy
CMAKE_CONFIGURE_ARGS+=	-DCPM_tracy_SOURCE=${WRKSRC}/tracy
# hash from CMakeLists.txt
GITHUB_SUBMODULES+=	nothings stb f1c79c02822848a9bed4315b12c8c8f3761e1296 stb
CMAKE_CONFIGURE_ARGS+=	-DCPM_stb_SOURCE=${WRKSRC}/stb

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_SKIP_RPATH=OFF
# don't build wayland-using iv viewer
CMAKE_CONFIGURE_ARGS+=	-DBUILD_IV=OFF

# Turn off -march=native that is enabled by default.
CMAKE_CONFIGURE_ARGS+=	-DMARCH_NATIVE:BOOL=OFF

pre-configure:
	${ECHO} ${GITHUB_TAG:C/(.......).*/\1/} > ${WRKSRC}/git-commit-id

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/vv/

.include "../../devel/cmake/build.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../converters/aklomp-base64/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
