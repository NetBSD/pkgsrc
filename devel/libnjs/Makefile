# $NetBSD: Makefile,v 1.16 2025/01/05 18:13:19 osa Exp $

DISTNAME=	njs-0.8.8
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nginx/}
GITHUB_PROJECT=	njs

MAINTAINER=	osa@NetBSD.org
HOMEPAGE=	https://nginx.org/en/docs/njs/
COMMENT=	NGINX JavaScript static library
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c

HAS_CONFIGURE=	yes
# lang/quickjs needs to be update to a recent snapshot, so
# disable it for now
#CONFIGURE_ARGS+=	--cc-opt="-I${LOCALBASE}/include/quickjs"
#CONFIGURE_ARGS+=	--ld-opt="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-quickjs
CONFIGURE_ARGS+=	--no-quickjs

INSTALLATION_DIRS=	include lib/pkgconfig

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Fix NJS pkg-config
SUBST_FILES.fix-pc=	src/njs.pc.in
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
