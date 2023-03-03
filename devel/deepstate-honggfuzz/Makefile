# $NetBSD: Makefile,v 1.4 2023/03/03 09:25:27 wiz Exp $

PKGNAME=	deepstate-honggfuzz-${VERSION}
PKGREVISION=	1

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	honggfuzz-[0-9]*:../../devel/honggfuzz
DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_ARGS+=	-DDEEPSTATE_HONGGFUZZ=ON
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${PREFIX}/bin/hfuzz-gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${PREFIX}/bin/hfuzz-g++

PYTHON_VERSIONS_INCOMPATIBLE=	311

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_HFUZZ.a ${DESTDIR}${PREFIX}/lib

.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
