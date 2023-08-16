# $NetBSD: Makefile,v 1.6 2023/08/16 07:52:04 nia Exp $

DISTNAME=	flatbuffers-1.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://google.github.io/flatbuffers/
COMMENT=	Memory efficient serialization library
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DFLATBUFFERS_BUILD_SHAREDLIB=ON

USE_CXX_FEATURES+=	c++11

BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/flatbuffers/flatbuffers.h.orig
	${RM} -f ${DESTDIR}${PREFIX}/include/flatbuffers/reflection.h.orig

.include "../../mk/bsd.pkg.mk"
