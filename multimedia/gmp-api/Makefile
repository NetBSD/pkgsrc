# $NetBSD: Makefile,v 1.2 2015/04/04 16:15:05 tnn Exp $

DISTNAME=	gmp-api-38.0
CATEGORIES=	multimedia www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_TAG=	2b8954c5dde595152d34dd378952e26aabb02dc3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.mozilla.org/GeckoMediaPlugins
COMMENT=	Headers for developing Gecko Media Plugins
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	include/gmp-api

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include/gmp-api

.include "../../mk/bsd.pkg.mk"
