# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=       bbcim095-5
PKGNAME=        bbcim-0.95b5
CATEGORIES=	converters
MASTER_SITES=	http://www.nvg.ntnu.no/bbc/util/
EXTRACT_SUFX=	.zip

MAINTAINER=	skrll@NetBSD.org
COMMENT=	File and diskimage conversion utility for BBC Micro software

WRKSRC=		${WRKDIR}/bbcim
MAN_PAGE=	${FILESDIR}/bbcim.1

INSTALLATION_DIRS=	bin man/man1

do-build:
	(cd ${WRKSRC} && ${WRKSRC}/mkbbcim)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbcim ${PREFIX}/bin/
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
