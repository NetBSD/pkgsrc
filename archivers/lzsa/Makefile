# $NetBSD: Makefile,v 1.1 2023/11/27 02:21:51 thorpej Exp $

DISTNAME=	lzsa-1.4.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=emmanuel-marty/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/emmanuel-marty/lzsa
COMMENT=	Compression algorithm designed for 8-bit systems
LICENSE=	zlib

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzsa ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
