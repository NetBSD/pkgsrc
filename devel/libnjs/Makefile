# $NetBSD: Makefile,v 1.1 2023/05/17 16:44:51 osa Exp $

PKGNAME=	libnjs-${VERSION}
VERSION=	0.7.12
DISTNAME=	njs-${VERSION}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nginx/}

MAINTAINER=	osa@NetBSD.org
HOMEPAGE=	https://nginx.org/en/docs/njs/
COMMENT=	NGINX JavaScript static library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	include lib/pkgconfig

do-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} libnjs

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/njs_auto_config.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libnjs.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/build/njs.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
