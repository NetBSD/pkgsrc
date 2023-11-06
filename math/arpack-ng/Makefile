# $NetBSD: Makefile,v 1.9 2023/11/06 10:57:52 adam Exp $

DISTNAME=	arpack-ng-3.9.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=opencollab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opencollab/arpack-ng
COMMENT=	Library of subroutines to solve eigenvalue problems
LICENSE=	original-bsd

USE_LANGUAGES=	c fortran

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DBLA_PREFER_PKGCONFIG=true
CMAKE_ARGS+=	-DBLA_PKGCONFIG_BLAS=${BLAS_PC}

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=	test

.include "options.mk"

INSTALLATION_DIRS=	lib

.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
