# $NetBSD: Makefile,v 1.7 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	glm-0.9.9.8
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_GITHUB:=g-truc/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://glm.g-truc.net/
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

USE_TOOLS+=	pax

GLM_DIR=		include/glm
INSTALLATION_DIRS=	${GLM_DIR}

do-install:
	${RUN}cd ${WRKSRC}/glm && \
		${CHMOD} 644 *hpp detail/* ext/* gtc/* gtx/* simd/*
	${RUN}cd ${WRKSRC}/glm && \
		pax -rw *hpp detail ext gtc gtx simd \
			${DESTDIR}${PREFIX}/${GLM_DIR}

# for test target
USE_CMAKE=     yes
USE_LANGUAGES=	c c++
do-test:
	${RUN}cd ${WRKSRC} && \
		cmake -DGLM_TEST_MODE=ON CMakeLists.txt && \
		make

.include "../../mk/bsd.pkg.mk"
