# $NetBSD: Makefile,v 1.1 2015/11/13 16:20:32 wiz Exp $

DISTNAME=	zopfli-1.0.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/zopfli/
COMMENT=	Very good but slow deflate/zlib compression
LICENSE=	apache-2.0

BUILD_TARGET=	zopfli zopflipng
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin share/doc/zopfli

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} zopfli zopflipng ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_DATA} README* ${DESTDIR}${PREFIX}/share/doc/zopfli

.include "../../mk/bsd.pkg.mk"
