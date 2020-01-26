# $NetBSD: Makefile,v 1.9 2020/01/26 17:31:15 rillig Exp $
#

DISTNAME=	fortunes-futurama-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netmeister.org/misc.html
COMMENT=	Fortunes from the Futurama animated TV series

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

DIST_SUBDIR=	${PKGNAME_NOREV}nb1
STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/games/fortune/futurama
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.dat \
		${DESTDIR}${PREFIX}/share/games/fortune/futurama.dat

.include "../../mk/bsd.pkg.mk"
