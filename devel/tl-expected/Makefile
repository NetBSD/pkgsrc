# $NetBSD: Makefile,v 1.2 2020/05/25 11:44:25 nia Exp $

DISTNAME=	tl-expected-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=TartanLlama/}
GITHUB_PROJECT=	expected
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DEFAULT_DISTFILES} add-tl.cmake
SITES.add-tl.cmake= \
	https://raw.githubusercontent.com/TartanLlama/tl-cmake/284c6a3f0f61823cc3871b0f193e8df699e2c4ce/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TartanLlama/expected
COMMENT=	C++11/14/17 std::expected with functional-style extensions
LICENSE=	cc0-1.0-universal

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DEXPECTED_ENABLE_TESTS=OFF
CMAKE_ARGS+=	-DFETCHCONTENT_SOURCE_DIR_TL_CMAKE=${WRKSRC}/cmake/tl-cmake

pre-configure:
	${MKDIR} -p ${WRKSRC}/cmake/tl-cmake
	${CP} ${WRKDIR}/add-tl.cmake ${WRKSRC}/cmake/tl-cmake

.include "../../mk/bsd.pkg.mk"
