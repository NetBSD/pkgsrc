# $NetBSD: Makefile,v 1.7 2018/12/15 21:12:21 wiz Exp $

DISTNAME=	mapcode-cpp-2.5.4
PKGNAME=	${DISTNAME:S/-cpp//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=mapcode-foundation/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/mapcode-foundation/mapcode-cpp/
COMMENT=	Mapcode Library for C/C++
LICENSE=	apache-2.0

GITHUB_PROJECT=	mapcode-cpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++

# Included CMakeLists is nonsensical
USE_CMAKE=	yes

CMAKE_ARGS+=		-DCMAKE_BINARY_DIR=${WRKSRC}/build

LDFLAGS+=		-lm

PTHREAD_AUTO_VARS=	yes

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/mapcodelib/mapcoder.h ${DESTDIR}${PREFIX}/include/mapcode.h
	${INSTALL_PROGRAM} ${WRKSRC}/build/mapcode ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/build/libmapcode.so ${DESTDIR}${PREFIX}/lib

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} LD_LIBRARY_PATH=${WRKSRC}/build ../build/unittest

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
