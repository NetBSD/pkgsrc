# $NetBSD: Makefile,v 1.3 2006/11/09 08:44:04 rillig Exp $
#

DISTNAME=	fortunes-futurama-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/misc.html
COMMENT=	Fortunes from the Futurama animated TV series

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/games/fortune/futurama
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.dat ${PREFIX}/share/games/fortune/futurama.dat

.include "../../mk/bsd.pkg.mk"
