# $NetBSD: Makefile,v 1.2 2024/08/25 06:18:37 wiz Exp $

DISTNAME=	rapidcheck-0.0.0.20220314
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=emil-e/}
GITHUB_PROJECT=	rapidcheck
GITHUB_TAG=	8fafda42e732164db58003e542196e94a28481f9

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	QuickCheck clone for C++
HOMEPAGE=	https://github.com/emil-e/rapidcheck
LICENSE=	2-clause-bsd

TEST_DEPENDS=	catch2-[0-9]*:../../devel/catch2

USE_LANGUAGES+=	c c++11
USE_TOOLS+=	cmake

#CXXFLAGS+=	-I${WRKSRC}/extras/catch/include # only to fix tests (rapidcheck/catch.h)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POSITION_INDEPENDENT_CODE=True
CMAKE_CONFIGURE_ARGS+=	-DRC_ENABLE_EXAMPLES=Off
CMAKE_CONFIGURE_ARGS+=	-DRC_ENABLE_TESTS=Off
CMAKE_CONFIGURE_ARGS+=	-DRC_INSTALL_ALL_EXTRAS=On

#do-test: # broken: https://github.com/emil-e/rapidcheck/issues/242
#	@cd ${BUILD_WRKSRC} && \
#		${SETENV} ${CONFIGURE_ENV} cmake ${CMAKE_CONFIGURE_ARGS} -DRC_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH:Q} && \
#		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${BUILD_TARGET} && \
#		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
