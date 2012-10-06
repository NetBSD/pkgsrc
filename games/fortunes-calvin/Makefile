# $NetBSD: Makefile,v 1.9 2012/10/06 11:54:38 asau Exp $
#

DISTNAME=	fortunes-calvin-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/misc.html
COMMENT=	Fortunes from the famous Calvin & Hobbes comic strips

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

DIST_SUBDIR=	${PKGNAME_NOREV}nb1
STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/games/fortune/calvin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.dat \
		${DESTDIR}${PREFIX}/share/games/fortune/calvin.dat

.include "../../mk/bsd.pkg.mk"
