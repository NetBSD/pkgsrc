# $NetBSD: Makefile,v 1.1.1.1 1999/07/04 00:48:03 hubertf Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/Linux/woven/html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://ion.le.ac.uk/~mar5/giftrans.html

WRKSRC=		${WRKDIR}/usr/src/${PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
