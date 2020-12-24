# $NetBSD: Makefile,v 1.2 2020/12/24 04:29:58 mef Exp $

PKGNAME=	deepstate-libfuzzer-${VERSION}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate
BUILD_DEPENDS+=	clang-[0-9]*:../../lang/clang

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_ARGS+=	-DDEEPSTATE_LIBFUZZER=ON
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CLANGBASE:Q}/bin/clang
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CLANGBASE:Q}/bin/clang++

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_LF.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/compiler/clang.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
