# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:21 rillig Exp $

DISTNAME=	glm-0.9.7.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=g-truc/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://glm.g-truc.net/
COMMENT=	C++ mathematics library for graphics programming
LICENSE=	mit
# in "Happy Bunny" variation, adding:
# Restrictions: By making use of the Software for military purposes,
# you choose to make a Bunny unhappy.

NO_BUILD=	yes
NO_CONFIGURE=	yes

USE_TOOLS+=	pax

GLM_DIR=		include/glm
INSTALLATION_DIRS=	${GLM_DIR}

do-install:
	${RUN}cd ${WRKSRC}/glm && \
		${CHMOD} 644 *hpp detail/* gtc/* gtx/*
	${RUN}cd ${WRKSRC}/glm && \
		pax -rw *hpp detail gtc gtx \
			${DESTDIR}${PREFIX}/${GLM_DIR}

# for test target
USE_LANGUAGES=	c c++
do-test:
	${RUN}cd ${WRKSRC} && \
		cmake -DGLM_TEST_MODE=ON CMakeLists.txt && \
		make

.include "../../mk/bsd.pkg.mk"
