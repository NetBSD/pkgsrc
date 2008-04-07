# $NetBSD: Makefile,v 1.7 2008/04/07 16:57:42 joerg Exp $

DISTNAME=	NetBSD-treiber_schreiben
PKGNAME=	device-driver-doc-de-20030729
CATEGORIES=	devel
MASTER_SITES=	https://www.unixag-kl.fh-kl.de/~jkunz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unixag-kl.fh-kl.de/~jkunz/
COMMENT=	Device driver documentation in German

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_TOOLS+=	gunzip

INSTALLATION_DIRS=	share/device-driver-doc-de

do-install:
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.pdf.gz ${DESTDIR}${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${DESTDIR}${PREFIX}/share/device-driver-doc-de/treiber_schreiben.pdf.gz
	${INSTALL_DATA} ${WRKSRC}/treiber_schreiben.ps.gz ${DESTDIR}${PREFIX}/share/device-driver-doc-de
	${GUNZIP_CMD} ${DESTDIR}${PREFIX}/share/device-driver-doc-de/treiber_schreiben.ps.gz

.include "../../mk/bsd.pkg.mk"
