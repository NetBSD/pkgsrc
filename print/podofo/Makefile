# $NetBSD: Makefile,v 1.34 2020/03/20 11:58:15 nia Exp $

DISTNAME=	podofo-0.9.6
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=podofo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://podofo.sourceforge.net/
COMMENT=	Library to work with the PDF file format
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DPODOFO_BUILD_SHARED:BOOL=TRUE
CMAKE_ARGS+=	-DPODOFO_BUILD_STATIC:BOOL=TRUE
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FT2BUILD:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FTHEADER:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2/config
CMAKE_ARGS+=	-DFREETYPE_LIB_PATHS:PATH=${BUILDLINK_PREFIX.freetype2}/lib

# Avoid building unit tests.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_CppUnit=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LUA=TRUE

.include "options.mk"

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
