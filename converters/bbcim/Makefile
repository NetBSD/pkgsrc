# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:21 jmmv Exp $
#

DISTNAME=       bbcim095-5
PKGNAME=        bbcim-0.95b5
WRKSRC=		${WRKDIR}/bbcim
CATEGORIES=	converters
MASTER_SITES=	http://www.nvg.ntnu.no/bbc/util/
EXTRACT_SUFX=	.zip

MAINTAINER=	skrll@netbsd.org
COMMENT=	file and diskimage conversion utility for BBC Micro software

MAN_PAGE=	${FILESDIR}/bbcim.1

do-build:
	(cd ${WRKSRC} && ${WRKSRC}/mkbbcim)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbcim ${PREFIX}/bin/
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
