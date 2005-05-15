# $NetBSD: Makefile,v 1.2 2005/05/15 22:02:26 jlam Exp $

DISTNAME=	NetBSD-treiber_schreiben
PKGNAME=	device-driver-doc-de-20030729
CATEGORIES=	devel
MASTER_SITES=	http://www.unixag-kl.fh-kl.de/~jkunz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unixag-kl.fh-kl.de/~jkunz/
COMMENT=	Device driver documentation in German

NO_BUILD=		yes
PKGSRC_USE_TOOLS+=	gunzip

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/device-driver-doc-de
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.pdf.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.pdf.gz
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.ps.gz ${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${PREFIX}/share/device-driver-doc-de/treiber_schreiben.ps.gz

.include "../../mk/bsd.pkg.mk"
