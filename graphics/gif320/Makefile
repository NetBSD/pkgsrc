# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=	gif320-3.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.maths.tcd.ie/pub/sboyle/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	GIF file viewer for use with VT-320 terminals

BUILD_TARGET=	# empty
WRKSRC=		${WRKDIR}/gif320

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gif320 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gif320.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README.VMS ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/gif320

.include "../../mk/bsd.pkg.mk"
