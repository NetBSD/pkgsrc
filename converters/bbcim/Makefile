# $NetBSD: Makefile,v 1.2 2001/02/16 13:59:23 wiz Exp $
#

DISTNAME=       bbcim095-5
PKGNAME=        bbcim-0.95b5
CATEGORIES=	converters
MASTER_SITES=	http://www.nvg.ntnu.no/bbc/util/
EXTRACT_SUFX=	.zip

MAINTAINER=	skrll@netbsd.org
COMMENT=	file and diskimage conversion utility for BBC Micro software

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
