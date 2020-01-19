# $NetBSD: Makefile,v 1.4 2020/01/19 00:26:18 nia Exp $

DISTNAME=	snow-20130616
CATEGORIES=	security
MASTER_SITES=	http://www.darkside.com.au/snow/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.darkside.com.au/snow/index.html
COMMENT=	Whitespace steganography program
LICENSE=	gnu-gpl-v2

CONFLICTS+=	STk-[0-9]*

BUILD_TARGET=	snow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snow ${DESTDIR}${PREFIX}/bin/snow
	${INSTALL_MAN} ${WRKSRC}/snow.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snow.1

.include "../../mk/bsd.pkg.mk"
