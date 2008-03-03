# $NetBSD: Makefile,v 1.13 2008/03/03 05:51:07 jlam Exp $
#

DISTNAME=	bbcim095-5
PKGNAME=	bbcim-0.95b5
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.nvg.ntnu.no/bbc/util/
EXTRACT_SUFX=	.zip

MAINTAINER=	skrll@NetBSD.org
COMMENT=	File and diskimage conversion utility for BBC Micro software

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/bbcim
MAN_PAGE=	${FILESDIR}/bbcim.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	(cd ${WRKSRC} && ${WRKSRC}/mkbbcim)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbcim ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MAN_PAGE} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
