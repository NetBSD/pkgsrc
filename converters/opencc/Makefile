# $NetBSD: Makefile,v 1.11 2026/01/07 19:32:04 adam Exp $

DISTNAME=	opencc-1.1.9
CATEGORIES=	converters chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=BYVoid/}
GITHUB_PROJECT=	OpenCC
GITHUB_TAG=	ver.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opencc.byvoid.com/
COMMENT=	Convertion between Traditional and Simplified Chinese
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/OpenCC-${GITHUB_TAG}

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	opencc.pc.in

CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_DARTS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_MARISA=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_PYBIND11=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_RAPIDJSON=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_TCLAP=ON

USE_GCC_RUNTIME=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
TEST_TARGET=	test

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/cmake/build.mk"
.include "../../devel/darts/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/tclap/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
