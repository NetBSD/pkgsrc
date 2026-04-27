# $NetBSD: Makefile,v 1.2 2026/04/27 10:32:03 wiz Exp $

DISTNAME=	souffle-2.5
GITHUB_TAG=	${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=souffle-lang/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://souffle-lang.github.io/
COMMENT=	Variant of Datalog
LICENSE=	upl-1.0

USE_TOOLS+=		flex bison pkg-config git
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
PTHREAD_AUTO_VARS=	yes

CMAKE_GENERATORS_INCOMPATIBLE=	make

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=	-DSOUFFLE_COMPILE_PY_COMPILER=${CXX:Q}

# XXX Find a better way of patching .buildlink
# paths in bin/souffle-compile.py.
CMAKE_CONFIGURE_ARGS+=	-DBUILDLINK_DIR=${BUILDLINK_DIR}
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG}

# Tests take a long time to finish, you can instead
# run them inside a sandboxed shell and pass -j N:
# make build-env
# cd cmake-pkgsrc-build && ctest -j 32
# ^D
TEST_TARGET=		test

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
