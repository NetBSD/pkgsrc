# $NetBSD: Makefile,v 1.32 2026/01/04 10:50:10 wiz Exp $

DISTNAME=	njs-0.9.1
PKGREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nginx/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nginx.org/en/docs/njs
COMMENT=	NGINX JavaScript command line utility
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

HAS_CONFIGURE=	yes
# lang/quickjs needs to be update to a recent snapshot, so
# disable it for now
CONFIGURE_ARGS+=	--cc-opt="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--ld-opt="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-quickjs
CONFIGURE_ARGS+=	--no-quickjs

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS+=	bin

do-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${DESTDIR}${PREFIX}/bin/njs

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
