# $NetBSD: Makefile,v 1.3 2012/10/23 18:16:58 asau Exp $

DISTNAME=	snow
PKGNAME=	snow-20060213
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.darkside.com.au/snow/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.darkside.com.au/snow/index.html
COMMENT=	Whitespace steganography program
LICENSE=	gnu-gpl-v2

CONFLICTS+=	STk-[0-9]*

WRKSRC=		${WRKDIR}/snow
BUILD_TARGET=	snow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snow ${DESTDIR}${PREFIX}/bin/snow
	${INSTALL_MAN} ${WRKSRC}/snow.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snow.1

.include "../../mk/bsd.pkg.mk"
