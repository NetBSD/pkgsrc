# $NetBSD: Makefile,v 1.1.1.1 2005/01/18 17:51:19 peter Exp $

DISTNAME=	qstat-2.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qstat/}

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.qstat.org/
COMMENT=	Program that gathers real-time statistics from game servers

NO_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/template/* ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_DATA} ${WRKSRC}/contrib.cfg ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/qstat.cfg ${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
