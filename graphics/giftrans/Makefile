# $NetBSD: Makefile,v 1.4 2003/03/29 12:41:16 jmmv Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
WRKSRC=		${WRKDIR}/usr/src/${PKGNAME}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/Linux/woven/html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://ion.le.ac.uk/~mar5/giftrans.html
COMMENT=	Manipulate GIF89a images' transparency, comment and other data

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
