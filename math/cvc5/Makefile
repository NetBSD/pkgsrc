# $NetBSD: Makefile,v 1.4 2026/07/03 22:03:50 alnsn Exp $

DISTNAME=	cvc5-1.3.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=cvc5/}
GITHUB_TAG=	cvc5-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cvc5.github.io/
COMMENT=	Automatic theorem prover for SMT (Satisfiability Modulo Theories)
LICENSE=	modified-bsd

USE_TOOLS+=	git
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Production
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_PYTHON_VENV=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_POLY=ON

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.9:../../devel/py-pyparsing

TEST_TARGET=	check
CVC5_BUILD_SRC=	${WRKSRC}/${CMAKE_BUILD_DIR}/src
TEST_ENV+=	LD_LIBRARY_PATH=${CVC5_BUILD_SRC}:${CVC5_BUILD_SRC}/parser:${CVC5_BUILD_SRC}/main

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/cadical/buildlink3.mk"
.include "../../math/libpoly/buildlink3.mk"
.include "../../math/symfpu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
