# $NetBSD: Makefile,v 1.1 2020/09/29 02:56:05 khorben Exp $

PKGNAME=	deepstate-afl-${VERSION}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	afl-[0-9]*:../../devel/afl
DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_ARGS+=	-DDEEPSTATE_AFL=ON
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${PREFIX:Q}/bin/afl-gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${PREFIX:Q}/bin/afl-g++

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_AFL.a ${DESTDIR}${PREFIX}/lib

.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
