# $NetBSD: Makefile,v 1.2 2005/11/11 19:39:15 jschauma Exp $
#

DISTNAME=	fortunes-h2g2-0.1
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/misc.html
COMMENT=	Fortunes from Douglas Adams' "Hitchiker's Guide to the Galaxy"

BUILD_DEPENDS+=	fortune-strfile-*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME} ${PREFIX}/share/games/fortune/h2g2
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}.dat ${PREFIX}/share/games/fortune/h2g2.dat

.include "../../mk/bsd.pkg.mk"
