# $NetBSD: Makefile,v 1.2 2026/06/20 00:52:49 nia Exp $

DISTNAME=	lzsa-1.4.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=emmanuel-marty/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/emmanuel-marty/lzsa
COMMENT=	Compression algorithm designed for 8-bit systems
LICENSE=	zlib

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

INSTALLATION_DIRS=	bin

pre-patch:
	dos2unix ${WRKSRC}/src/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzsa ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
