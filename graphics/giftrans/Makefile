# $NetBSD: Makefile,v 1.6 2003/07/17 21:40:50 grant Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
WRKSRC=		${WRKDIR}/usr/src/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/Linux/woven/html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://ion.le.ac.uk/~mar5/giftrans.html
COMMENT=	Manipulate GIF89a images' transparency, comment and other data

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
