# $NetBSD: Makefile,v 1.2 2016/10/26 10:50:33 fhajny Exp $

DISTNAME=	mapcode-cpp-2.4.0
PKGNAME=	${DISTNAME:S/-cpp//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=mapcode-foundation/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/mapcode-foundation/mapcode-cpp/
COMMENT=	Mapcode Library for C/C++
LICENSE=	apache-2.0

GITHUB_PROJECT=	mapcode-cpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++

# Included CMakeLists is nonsensical
# USE_CMAKE=	yes

PTHREAD_AUTO_VARS=	yes

INSTALLATION_DIRS=	bin include lib

do-build:
	cd ${WRKSRC}/utility && ${CXX} ${CXXFLAGS} mapcode.cpp -o mapcode
	cd ${WRKSRC}/mapcodelib && ${CC} ${CFLAGS} -fPIC -shared ${LDFLAGS} mapcoder.c -o libmapcode.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utility/mapcode ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mapcodelib/mapcoder.h ${DESTDIR}${PREFIX}/include/mapcode.h
	${INSTALL_LIB} ${WRKSRC}/mapcodelib/libmapcode.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
