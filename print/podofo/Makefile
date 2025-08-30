# $NetBSD: Makefile,v 1.52 2025/08/30 22:46:11 wiz Exp $

# \todo Update to 1.0.1, from github, and needing c++17.
DISTNAME=	podofo-0.9.8
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=podofo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/podofo/podofo/
#OLD_HOMEPAGE=	http://podofo.sourceforge.net/
COMMENT=	Library to work with the PDF file format
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

USE_LANGUAGES=		c c++
#USE_CXX_FEATURES=	c++17

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DPODOFO_BUILD_SHARED=ON
CMAKE_CONFIGURE_ARGS+=	-DPODOFO_BUILD_STATIC=ON
CMAKE_CONFIGURE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FT2BUILD:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CMAKE_CONFIGURE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FTHEADER:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2/config
CMAKE_CONFIGURE_ARGS+=	-DFREETYPE_LIB_PATHS:PATH=${BUILDLINK_PREFIX.freetype2}/lib

# Avoid building unit tests.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_CppUnit=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LUA=TRUE

# Podofo uses thread_local, which is a C++11 feature, but does not
# appropriately set -std=c++11.
USE_CXX_FEATURES+=	c++11
FORCE_CXX_STD+=		c++11

.include "options.mk"

.include "../../devel/cmake/build.mk"
# tests-depend on cppunit (for unit tests)
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
