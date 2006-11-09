# $NetBSD: Makefile,v 1.4 2006/11/09 08:36:46 rillig Exp $
#

DISTNAME=	fortunes-calvin-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/misc.html
COMMENT=	Fortunes from the famous Calvin & Hobbes comic strips

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PREFIX}/share/games/fortune/calvin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.dat ${PREFIX}/share/games/fortune/calvin.dat

.include "../../mk/bsd.pkg.mk"
