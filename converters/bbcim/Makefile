# $NetBSD: Makefile,v 1.1.1.1 2000/06/07 19:05:20 skrll Exp $
#

DISTNAME=       bbcim095-5
PKGNAME=        bbcim-0.95b5
CATEGORIES=	converters
MASTER_SITES=	http://www.nvg.ntnu.no/bbc/util/
EXTRACT_SUFX=	.zip

MAINTAINER=	skrll@netbsd.org

BUILD_DEPENDS+=	unzip:../../archivers/unzip

EXTRACT_CMD=	unzip -Loq ${DOWNLOADED_DISTFILE}

WRKSRC=		${WRKDIR}/bbcim
MAN_PAGE=	${PKGDIR}/bbcim.1

do-build:
	(cd ${WRKSRC} && ${WRKSRC}/mkbbcim)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbcim ${PREFIX}/bin/
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
