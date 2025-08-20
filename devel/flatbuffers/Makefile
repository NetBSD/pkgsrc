# $NetBSD: Makefile,v 1.8 2025/08/20 11:34:51 wiz Exp $

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

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DFLATBUFFERS_BUILD_SHAREDLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

USE_CXX_FEATURES+=	c++11

BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/flatbuffers/flatbuffers.h.orig
	${RM} -f ${DESTDIR}${PREFIX}/include/flatbuffers/reflection.h.orig

.include "../../mk/bsd.pkg.mk"
