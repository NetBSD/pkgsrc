# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 23:14:48 jschauma Exp $
#

DISTNAME=	fortunes-calvin-0.1
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/misc.html
COMMENT=	Fortunes from the famous Calvin & Hobbes comic strips

BUILD_DEPENDS+=	fortune-strfile-*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME} ${PREFIX}/share/games/fortune/calvin
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}.dat ${PREFIX}/share/games/fortune/calvin.dat

.include "../../mk/bsd.pkg.mk"
