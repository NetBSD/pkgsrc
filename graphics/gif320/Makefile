# $NetBSD: Makefile,v 1.5 2004/01/20 12:18:16 agc Exp $
#

DISTNAME=	gif320-3.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.maths.tcd.ie/pub/sboyle/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	GIF file viewer for use with VT-320 terminals

ALL_TARGET=	# empty
WRKSRC=		${WRKDIR}/gif320

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gif320 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gif320.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README.VMS ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/gif320

.include "../../mk/bsd.pkg.mk"
