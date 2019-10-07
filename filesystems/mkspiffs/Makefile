# $NetBSD: Makefile,v 1.1 2019/10/07 10:13:16 bouyer Exp $

VERSION=	0.2.3
DISTNAME=	mkspiffs-${VERSION}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=igrr/}
GITHUB_TAG=	${VERSION}

DISTFILES=	${DEFAULT_DISTFILES}

SPIFFS=		spiffs-f5e26c4e933189593a71c6b82cda381a7b21e41c
DISTFILES+=	${SPIFFS}.tar.gz
SITES.spiffs-f5e26c4e933189593a71c6b82cda381a7b21e41c.tar.gz= -https://github.com/pellepl/spiffs/archive/f5e26c4e933189593a71c6b82cda381a7b21e41c.tar.gz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://github.com/igrr/mkspiffs
COMMENT=	Tool to build and unpack SPIFFS images
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_ENV+=	TARGET_OS=NetBSD VERSION=${VERSION}

INSTALLATION_DIRS=	bin

post-extract:
	${RM} -r ${WRKSRC}/spiffs
	${CP} -r ${WRKDIR}/${SPIFFS} ${WRKSRC}/spiffs

do-build:
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} clean
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist \
	    BUILD_CONFIG_NAME="-arduino-esp8266" \
	    CPPFLAGS="${CPPFLAGS} -DSPIFFS_USE_MAGIC_LENGTH=0 -DSPIFFS_ALIGNED_OBJECT_INDEX_TABLES=1"
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} clean
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist \
	    BUILD_CONFIG_NAME="-arduino-esp32" \
	    CPPFLAGS="${CPPFLAGS} -DSPIFFS_OBJ_META_LEN=4"
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} clean
	cd ${WRKSRC} && \
	  env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist \
	    BUILD_CONFIG_NAME="-esp-idf" \
	    CPPFLAGS="${CPPFLAGS} -DSPIFFS_OBJ_META_LEN=4"

do-install:
.for i in arduino-esp32 arduino-esp8266 esp-idf generic
	${INSTALL_PROGRAM} ${WRKSRC}/mkspiffs-${VERSION}-$i-${OPSYS}/mkspiffs ${DESTDIR}${PREFIX}/bin/mkspiffs-$i
.endfor

.include "../../mk/bsd.pkg.mk"
