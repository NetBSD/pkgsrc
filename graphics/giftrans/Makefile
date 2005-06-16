# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/Linux/woven/html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ion.le.ac.uk/~mar5/giftrans.html
COMMENT=	Manipulate GIF89a images' transparency, comment and other data

WRKSRC=		${WRKDIR}/usr/src/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
