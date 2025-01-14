# $NetBSD: Makefile,v 1.25 2025/01/14 17:45:00 osa Exp $

DISTNAME=	njs-0.8.9
CATEGORIES=	lang www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nginx/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	osa@NetBSD.org
HOMEPAGE=	https://nginx.org/en/docs/njs
COMMENT=	NGINX JavaScript command line utility
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

HAS_CONFIGURE=	yes
# lang/quickjs needs to be update to a recent snapshot, so
# disable it for now
#CONFIGURE_ARGS+=	--cc-opt="-I${LOCALBASE}/include/quickjs"
#CONFIGURE_ARGS+=	--ld-opt="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-quickjs
CONFIGURE_ARGS+=	--no-quickjs

INSTALLATION_DIRS+=	bin

do-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${DESTDIR}${PREFIX}/bin/njs

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
