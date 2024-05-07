# $NetBSD: Makefile,v 1.7 2024/05/07 13:43:55 osa Exp $

DISTNAME=	njs-0.8.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	-${MASTER_SITE_GITHUB:=nginx/njs/archive/0.8.2.tar.gz}

MAINTAINER=	osa@NetBSD.org
HOMEPAGE=	https://nginx.org/en/docs/njs/
COMMENT=	NGINX JavaScript static library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	include lib/pkgconfig

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Fix NJS pkg-config
SUBST_FILES.fix-pc=	auto/make
SUBST_NOOP_OK.fix-pc=	yes
SUBST_SED.fix-pc=	-e 's|%%LOCALBASE%%|${LOCALBASE}|'

do-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} libnjs

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/njs_auto_config.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libnjs.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/build/njs.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
