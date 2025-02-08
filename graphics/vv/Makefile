# $NetBSD: Makefile,v 1.4 2025/02/08 18:45:21 pho Exp $

DISTNAME=	vv-3.1.0.20250208
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=wolfpld/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	84747114964a84aa7b9f1495cfc580b98817fac2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wolfpld/vv/
COMMENT=	View images in your terminal
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20
# needs <format> which was added in 13, despite being in C++ 20
GCC_REQD+=		13
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS+=	bin share/doc/vv

# 'master' as of 2025-02-08
GITHUB_SUBMODULES+=	wolfpld tracy 9b7d53a979f0734deebb07d0135f5400af12a576 tracy
CMAKE_CONFIGURE_ARGS+=	-DCPM_tracy_SOURCE=${WRKSRC}/tracy
# hash from CMakeLists.txt
GITHUB_SUBMODULES+=	nothings stb 2e2bef463a5b53ddf8bb788e25da6b8506314c08 stb
CMAKE_CONFIGURE_ARGS+=	-DCPM_stb_SOURCE=${WRKSRC}/stb

# Turn off -march=native that is enabled by default.
CMAKE_CONFIGURE_ARGS+=	-DMARCH_NATIVE:BOOL=OFF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/vv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/vv/

.include "../../devel/cmake/build.mk"
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
