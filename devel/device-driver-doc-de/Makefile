# $NetBSD: Makefile,v 1.5 2006/10/04 21:35:58 wiz Exp $

DISTNAME=	NetBSD-treiber_schreiben
PKGNAME=	device-driver-doc-de-20030729
CATEGORIES=	devel
MASTER_SITES=	https://www.unixag-kl.fh-kl.de/~jkunz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unixag-kl.fh-kl.de/~jkunz/
COMMENT=	Device driver documentation in German

NO_BUILD=	yes
USE_TOOLS+=	gunzip

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/device-driver-doc-de
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.pdf.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.pdf.gz
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.ps.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.ps.gz

.include "../../mk/bsd.pkg.mk"
