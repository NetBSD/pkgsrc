# $NetBSD: Makefile,v 1.1.1.1 2007/10/29 09:57:28 agc Exp $

DISTNAME=	snow
PKGNAME=	snow-20060213
CATEGORIES=	security
MASTER_SITES=	http://www.darkside.com.au/snow/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.darkside.com.au/snow/index.html
COMMENT=	Whitespace steganography program

WRKSRC=		${WRKDIR}/snow
BUILD_TARGET=	snow
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snow ${DESTDIR}${PREFIX}/bin/snow
	${INSTALL_MAN} ${WRKSRC}/snow.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snow.1

.include "../../mk/bsd.pkg.mk"
