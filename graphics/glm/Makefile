# $NetBSD: Makefile,v 1.3 2014/10/13 21:47:59 ryoon Exp $
#

DISTNAME=	glm-0.9.5.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogl-math/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://glm.g-truc.net/
COMMENT=	C++ mathematics library for graphics programming
LICENSE=	mit

WRKSRC=		${WRKDIR}/glm

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
