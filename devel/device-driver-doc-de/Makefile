# $NetBSD: Makefile,v 1.1.1.1 2003/07/29 12:44:39 agc Exp $

DISTNAME=	NetBSD-treiber_schreiben
PKGNAME=	device-driver-doc-de-20030729
CATEGORIES=	devel
MASTER_SITES=	http://www.unixag-kl.fh-kl.de/~jkunz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unixag-kl.fh-kl.de/~jkunz/
COMMENT=	Device driver documentation in German

NO_BUILD=	# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/device-driver-doc-de
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.pdf.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.pdf.gz
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.ps.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.ps.gz

.include "../../mk/bsd.pkg.mk"
