# $NetBSD: Makefile,v 1.17 2026/04/07 11:39:00 tsutsui Exp $

DISTNAME=	zxing-cpp-3.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DZXING_EXAMPLES=OFF
# enable old (deprecated in 3.0) API, for libreoffice
CMAKE_CONFIGURE_ARGS+=	-DZXING_WRITERS=BOTH
# use pkgsrc zint
CMAKE_CONFIGURE_ARGS+=	-DZXING_USE_BUNDLED_ZINT=OFF

### gcc-12.5.0 of NetBSD/i386 11.0 gets ICE due to PCH.
.include "../../mk/compiler.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-*i386} && ${CC_VERSION:Mgcc-12.*}
CMAKE_CONFIGURE_ARGS+=	-DZXING_DISABLE_PCH=ON
.endif

# needs C++20, but users of the library are fine with c++17 as of 3.0.1
USE_CXX_FEATURES+=	c++20

PKGCONFIG_OVERRIDE+=	core/zxing.pc.in

STB_REV=	2fb8c5a3deb2110c89669f8d6f36e5833b556b44
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	stb-${STB_REV}.tar.gz

SITES.stb-${STB_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=nothings/}stb/archive/${STB_REV}.tar.gz

pre-configure:
	${MKDIR} -p ${WRKSRC}/${CMAKE_BUILD_DIR}/_deps
	${LN} -sf ${WRKDIR}/stb-${STB_REV} ${WRKSRC}/${CMAKE_BUILD_DIR}/_deps/stb-src

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.zint+=	zint>=2.16.0
.include "../../graphics/zint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
